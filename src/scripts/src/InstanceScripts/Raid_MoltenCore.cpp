/*
 * ArcScript Scripts for Arcemu MMORPG Server
 * Copyright (C) 2008 Arcemu Team
 * Copyright (C) 2007 Moon++ <http://www.moonplusplus.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "Base.h"

/************************************************************************/
/* Raid_MoltenCore.cpp Script											*/
/************************************************************************/

#define CN_CORERAGER 11672

class CoreRagerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(CoreRagerAI, ArcScriptCreatureAI);
    CoreRagerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		// Mangle <http://www.wowhead.com/?spell=19820>
		AddSpell(19820, Target_Current, 20, 0, 20);
    }

	void OnCombatStart(Unit *pTarget)
	{
		Golemagg = GetUnit()->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(793.248f, -998.265f, -206.762f, 11988);
		ParentClass::OnCombatStart(pTarget);
	}

	void AIUpdate()
	{
		// If Health is less than 50% and Golemagg is still alive then they regain full health
		if(GetHealthPercent() <= 50 && Golemagg && Golemagg->isAlive())
		{
			Regenerate();
			Emote("Core Rager refuses to die while its master is in trouble.", Text_Emote);
		}
		ParentClass::AIUpdate();
	}

	Creature* Golemagg;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Golemagg AI Script
#define CN_GOLEMAGG					11988	

class GolemaggAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(GolemaggAI, ArcScriptBossAI);
	GolemaggAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		// Golemagg's Trust <http://www.wowhead.com/?spell=20553>
		GolemaggTrust = AddSpell(20553, Target_Self, 8, 0, 3);

		// Magma Splash <http://www.wowhead.com/?spell=13880>
		AddSpell(13880, Target_Self, 8, 0, 0);

		// Pyroblast <http://www.wowhead.com/?spell=20228>
		AddSpell(20228, Target_RandomPlayer, 8, 0, 0, 0, 40);

		// Earthquake <http://www.wowhead.com/?spell=19798>
		AddPhaseSpell(2, AddSpell(19798, Target_Self, 8, 0, 0));
	}

	void OnCombatStart(Unit *pTarget)
	{
		CoreRager1 = GetUnit()->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(783.448f, -1017.07f, -205.389f, 11672);
		CoreRager2 = GetUnit()->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(785.579f, -974.27f, -207.111f, 11672);
		ParentClass::OnCombatStart(pTarget);
	}

	void AIUpdate()
	{
		// 40 yrds
		if((CoreRager1 && CoreRager1->isAlive() && GetRangeToUnit(CoreRager1) < 40) || (CoreRager2 && CoreRager2->isAlive() && GetRangeToUnit(CoreRager2) < 40))
			GolemaggTrust->mEnabled = true;
		else
			GolemaggTrust->mEnabled = false;

		if(GetPhase() == 1 && GetHealthPercent() <= 10)
			SetPhase(2);

		ParentClass::AIUpdate();
	}

	Unit* CoreRager1;
	Unit* CoreRager2;
	SpellDesc* GolemaggTrust;
};


#define CN_SULFURON_HARBRINGER 12098

// Sulfuron Harbringer AI
class SulfuronAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(SulfuronAI, ArcScriptBossAI);
    SulfuronAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
    {
		// Demoralizing Shout
		AddSpell(19778, Target_Self, 15, 0, 30);

		// Hand of Ragnaros
		AddSpell(19780, Target_Self, 8, 0, 0);

		// Inspire
		AddSpell(19779, Target_Self, 8, 0, 10);

		// Flame Spear
		AddSpell(19781, Target_Current, 8, 0, 0);
    }
};
#define FlamewakerPriest 11662
class FlamewakerPriestAI : public ArcScriptCreatureAI
{
	ARCSCRIPT_FACTORY_FUNCTION(FlamewakerPriestAI, ArcScriptCreatureAI);
    FlamewakerPriestAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		// Dark Mending
		AddSpell(19775, Target_WoundedFriendly, 8, 2, 0);

		// Dark Strike
		AddSpell(19777, Target_Self, 12, 0, 0);

		// Immolate
		AddSpell(20294, Target_RandomPlayer, 15, 0, 20);

		// Shadow Word: Pain
		AddSpell(19776, Target_RandomPlayer, 15, 0, 15);
	}
};

// Woot DOING RAGNAROS Tha BosS

/*    * Ragnaros Summoning talk:
          o Majordomo Executus: Behold Ragnaros, the Firelord! He who was ancient when this world was young! Bow before him, mortals! Bow before your ending!
          o Ragnaros: TOO SOON! YOU HAVE AWAKENED ME TOO SOON, EXECUTUS! WHAT IS THE MEANING OF THIS INTRUSION?
          o Majordomo Executus: These mortal infidels, my lord! They have invaded your sanctum, and seek to steal your secrets!
          o Ragnaros: FOOL! YOU ALLOWED THESE INSECTS TO RUN RAMPANT THROUGH THE HALLOWED CORE, AND NOW YOU LEAD THEM TO MY VERY LAIR? YOU HAVE FAILED ME, EXECUTUS! JUSTICE SHALL BE MET, INDEED!
          o Ragnaros: NOW FOR YOU, INSECTS. BOLDLY YOU SOUGHT THE POWER OF RAGNAROS! NOW YOU SHALL SEE IT FIRSTHAND! 
    * DIE, INSECT! (When he kills the player he has aggro on)
    * BY FIRE BE PURGED! (Ranged knockback)
    * TASTE THE FLAMES OF SULFURON! (Melee knockback)
    * COME FORTH, MY SERVANTS! DEFEND YOUR MASTER! (Summoning Sons of Flame) */

#define CN_RAGNAROS 11502

#define ELEMENTAL_FIRE 20563 // 1 target
#define MAGMA_BLAST 20565 // various targets on not attacked. -> sound -> 8048 ?
#define WRATH_OF_RAGNAROS 20566  // Fly bitches fly! quote -> "Taste the Flames of Sulfuron!" -> sound 8047
#define HAMMER_OF_RAGNAROS 19780 // quote -> "By fire be purged!" -> sound 8046
#define MELT_WEAPON 21387 // 1 target
#define SUMMON_SONS_OF_FLAMES 21108 // TODO: DUMMY :P summon the sons of flames. entry = 12143 -> sound 8049,8050


//Ragnaros Submerge Visual -> 20567
//Ragnaros Emerge -> 20568

// Ragnaros AI
class RagnarosAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(RagnarosAI);
    RagnarosAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		m_elementalfire = m_wrath = m_hammer = m_meltweapon = m_summonsons = true;

        info_elementalfire = dbcSpell.LookupEntry(ELEMENTAL_FIRE);
		info_wrath = dbcSpell.LookupEntry(WRATH_OF_RAGNAROS);
		info_hammer = dbcSpell.LookupEntry(HAMMER_OF_RAGNAROS);
		info_meltweapon = dbcSpell.LookupEntry(MELT_WEAPON);
		info_summonsons = dbcSpell.LookupEntry(SUMMON_SONS_OF_FLAMES);
		_unit->Root();
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->GetAIInterface()->skip_reset_hp=true;
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
       RemoveAIUpdateEvent();
    }
    
    void OnTargetDied(Unit* mTarget)
    {
        _unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "DIE, INSECT!");
        _unit->PlaySoundToSet(8051);
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {	
	    uint32 val = RandomUInt(1000);
        SpellCast(val);
    }

    void SpellCast(uint32 val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())//_unit->getAttackTarget())
        {
			Unit *target = _unit->GetAIInterface()->GetNextTarget();
			                      
            if(m_elementalfire)
            {
                _unit->CastSpell(target, info_elementalfire, false);
                m_elementalfire = false;
                return;
            }
            
            if(m_wrath)
            {
                _unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Taste the Flames of Sulfuron!");
		        _unit->PlaySoundToSet(8047);
                _unit->CastSpell(_unit, info_wrath, false);
                m_wrath = false;
                return;
            }
            
            if(m_hammer)
            {
                _unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "By fire be purged!");
		        _unit->PlaySoundToSet(8046);
                _unit->CastSpell(_unit, info_hammer, false);
                m_hammer = false;
                return;
            }
            
            if(m_meltweapon)
            {
                _unit->CastSpell(target, info_meltweapon, false);
                m_meltweapon = false;
                return;
            }
            
            if(val >= 100 && val <= 160)
            {
                _unit->setAttackTimer(1000, false);
                m_elementalfire = true;
            }
            
            if(val > 160 && val <= 220)
            {
                _unit->setAttackTimer(1000, false);
                m_wrath = true;
            }
            
            if(val > 220 && val <= 280)
            {
                _unit->setAttackTimer(1000, false);
                m_hammer = true;
            }
            if(val > 340 && val <= 400)
            {
                _unit->setAttackTimer(1000, false);
                m_meltweapon = true;
            }
            
        }
    }

protected:

    bool m_elementalfire,m_wrath,m_hammer,m_meltweapon,m_summonsons;
    SpellEntry *info_elementalfire, *info_wrath, *info_hammer, *info_meltweapon,*info_summonsons;
};

/*
TODO:
 - Fix spells for all mob/boss (spell id, % chance, cooldowns, range, etc.)
 - Lava Spawn doesn't split
 - Core Hound packs aren't in pack, so they don't rez each other
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Molten Giant AI Script
#define CN_MOLTENGIANT			11658
#define MOLTENGIANT_SMASH		18944
#define MOLTENGIANT_KNOCKBACK	18945

class MoltenGiantAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(MoltenGiantAI, ArcScriptCreatureAI);
    MoltenGiantAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(MOLTENGIANT_SMASH, Target_Self, 10, 0, 5);
		AddSpell(MOLTENGIANT_KNOCKBACK, Target_Current, 10, 0, 5, 0, 10);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Molten Destroyer AI Script
#define CN_MOLTENDESTROYER				11659
#define MOLTENDESTROYER_MASSIVE_TREMOR	19129
#define MOLTENDESTROYER_KNOCKDOWN		20276

class MoltenDestroyerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(MoltenDestroyerAI, ArcScriptCreatureAI);
    MoltenDestroyerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(MOLTENDESTROYER_MASSIVE_TREMOR, Target_Self, 12.5f, 0, 0);
		AddSpell(MOLTENDESTROYER_KNOCKDOWN, Target_Current, 12.5f, 0, 0);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Firelord AI Script
#define CN_FIRELORD					11668
#define FIRELORD_SUMMON_LAVA_SPAWN	19392
#define FIRELORD_SOUL_BURN			19393

class FirelordAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FirelordAI, ArcScriptCreatureAI);
    FirelordAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(FIRELORD_SUMMON_LAVA_SPAWN, Target_Self, 20, 0, 10);
		AddSpell(FIRELORD_SOUL_BURN, Target_RandomPlayer, 20, 0, 5);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lava Annihilator AI Script
#define CN_LAVAANNIHILATOR 11665

class LavaAnnihilatorAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LavaAnnihilatorAI, ArcScriptCreatureAI);
    LavaAnnihilatorAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpellFunc(&SpellFunc_ClearHateList, Target_Self, 20, 0, 0);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ancient Core Hound AI Script
#define CN_ANCIENTCOREHOUND					11673
#define ANCIENTCOREHOUND_LAVA_BREATH		19272
#define ANCIENTCOREHOUND_VICIOUS_BITE		19319
#define ANCIENTCOREHOUND_GROUND_STOMP		19364
#define ANCIENTCOREHOUND_ANCIENT_DREAD		19365
#define ANCIENTCOREHOUND_ANCIENT_DESPAIR	19369
#define ANCIENTCOREHOUND_CAUTERIZING_FLAMES	19366
#define ANCIENTCOREHOUND_WITHERING_HEAT		19367
#define ANCIENTCOREHOUND_ANCIENT_HYSTERIA	19372

class AncientCoreHoundAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(AncientCoreHoundAI, ArcScriptCreatureAI);
    AncientCoreHoundAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(ANCIENTCOREHOUND_LAVA_BREATH, Target_Self, 20, 0, 3);
		AddSpell(ANCIENTCOREHOUND_VICIOUS_BITE, Target_Self, 20, 0, 0);

		//Each Ancient Core Hound have only one of the following spell
		switch( RandomUInt(5) )
		{
			case 0: AddSpell(ANCIENTCOREHOUND_GROUND_STOMP, Target_Self, 20, 0, 15); break;
			case 1: AddSpell(ANCIENTCOREHOUND_ANCIENT_DREAD, Target_Self, 20, 0, 15); break;
			case 2: AddSpell(ANCIENTCOREHOUND_ANCIENT_DESPAIR, Target_Self, 20, 0, 15); break;
			case 3: AddSpell(ANCIENTCOREHOUND_CAUTERIZING_FLAMES, Target_Self, 20, 0, 15); break;
			case 4: AddSpell(ANCIENTCOREHOUND_WITHERING_HEAT, Target_Self, 20, 0, 15); break;
			case 5: AddSpell(ANCIENTCOREHOUND_ANCIENT_HYSTERIA, Target_Self, 20, 0, 15); break;
		}
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lava Surger AI Script
#define CN_LAVASURGER		12101
#define LAVASURGER_SURGE	25787

class LavaSurgerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LavaSurgerAI, ArcScriptCreatureAI);
    LavaSurgerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(LAVASURGER_SURGE, Target_RandomUnit, 20, 0, 5, 0, 40);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Flame Imp AI Script
#define CN_FLAMEIMP			11669
#define FLAMEIMP_FIRE_NOVA	20602	

class FlameImpAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FlameImpAI, ArcScriptCreatureAI);
    FlameImpAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(FLAMEIMP_FIRE_NOVA, Target_Current, 25, 0, 0);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Core Hound AI Script
#define CN_COREHOUND			11671
#define COREHOUND_SERRATED_BITE	19771

class CoreHoundAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(CoreHoundAI, ArcScriptCreatureAI);
    CoreHoundAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(COREHOUND_SERRATED_BITE, Target_RandomPlayer, 10, 0, 0, 0, 10);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lava Reaver AI Script
#define CN_LAVAREAVER		12100
#define LAVAREAVER_CLEAVE	20691

class LavaReaverAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LavaReaverAI, ArcScriptCreatureAI);
    LavaReaverAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(LAVAREAVER_CLEAVE, Target_Current, 20, 0, 0, 0, 15);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lava Elemental AI Script
#define CN_LAVAELEMENTAL				12076
#define LAVAELEMENTAL_PYROCLAST_BARRAGE	19641

class LavaElementalAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LavaElementalAI, ArcScriptCreatureAI);
    LavaElementalAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(LAVAELEMENTAL_PYROCLAST_BARRAGE, Target_Self, 10, 0, 10);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Flameguard AI Script
#define CN_FLAMEGUARD			11667
#define FLAMEGUARD_FIRE_SHIELD	19627
#define FLAMEGUARD_FLAMES		19628

class FlameguardAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FlameguardAI, ArcScriptCreatureAI);
    FlameguardAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(FLAMEGUARD_FIRE_SHIELD, Target_Self, 100, 0, 0);
		mFlames = AddSpell(FLAMEGUARD_FLAMES, Target_Self, 0, 0, 0);
    }

	void OnDied(Unit* pKiller)
	{
		CastSpellNowNoScheduling(mFlames);
		ParentClass::OnDied(pKiller);
	}

	SpellDesc* mFlames;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Firewalker AI Script
#define CN_FIREWALKER				11666
#define FIREWALKER_MELT_ARMOR		19631
#define FIREWALKER_INCITE_FLAMES	19635
#define FIREWALKER_FIRE_BLOSSOM		19636

class FirewalkerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FirewalkerAI, ArcScriptCreatureAI);
    FirewalkerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
    {
		AddSpell(FIREWALKER_MELT_ARMOR, Target_Self, 10, 0, 0);
		AddSpell(FIREWALKER_INCITE_FLAMES, Target_Self, 10, 0, 0);
//		AddSpell(FIREWALKER_FLAME_BLOSSOM, Target_Self, 10, 0, 0);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lucifron AI Script
#define CN_LUCIFRON					12118
#define LUCIFRON_IMPEDING_DOOM		19702
#define LUCIFRON_LUCIFRONS_CURSE	19703
#define LUCIFRON_SHADOW_SHOCK		20603

class LucifronAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LucifronAI, ArcScriptBossAI);
	LucifronAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(LUCIFRON_IMPEDING_DOOM, Target_Self, 8, 0, 0);
		AddSpell(LUCIFRON_LUCIFRONS_CURSE, Target_Self, 8, 0, 0);
		AddSpell(LUCIFRON_SHADOW_SHOCK, Target_Self, 8, 0, 0);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Flamewaker Protector AI Script
#define CN_FLAMEWAKERPROTECTOR				12119
#define FLAMEWAKERPROTECTOR_CLEAVE			20691
#define FLAMEWAKERPROTECTOR_DOMINATE_MIND	20740	//to verify

class FlamewakerProtectorAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FlamewakerProtectorAI, ArcScriptCreatureAI);
	FlamewakerProtectorAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		AddSpell(FLAMEWAKERPROTECTOR_CLEAVE, Target_Current, 8, 0, 0, 0, 15);
		AddSpell(FLAMEWAKERPROTECTOR_DOMINATE_MIND, Target_RandomPlayer, 4, 0, 0, 0, 20);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Magmadar AI Script
#define CN_MAGMADAR				11982
#define MAGMADAR_MAGMA_SPIT		19450	//aura doesnt work
#define MAGMADAR_LAVA_BREATH	19272	//to verify
#define MAGMADAR_PANIC			19408
#define MAGMADAR_LAVA_BOMB		19411	//need dummy spell

class MagmadarAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(MagmadarAI, ArcScriptBossAI);
	MagmadarAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(MAGMADAR_MAGMA_SPIT, Target_Self, 8, 0, 0);
		AddSpell(MAGMADAR_LAVA_BREATH, Target_Self, 8, 0, 0);
		AddSpell(MAGMADAR_PANIC, Target_Self, 8, 0, 0);
		AddSpell(MAGMADAR_LAVA_BOMB, Target_RandomPlayer, 8, 0, 0, 0, 100);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Gehennas AI Script
#define CN_GEHENNAS				12259
#define GEHENNAS_SHADOW_BOLT	29317	//to verify
#define GEHENNAS_GEHENNAS_CURSE	19716
#define GEHENNAS_RAIN_OF_FIRE	19717

class GehennasAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(GehennasAI, ArcScriptBossAI);
	GehennasAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(GEHENNAS_SHADOW_BOLT, Target_RandomPlayer, 8, 0, 0, 0, 45);
		AddSpell(GEHENNAS_GEHENNAS_CURSE, Target_Self, 8, 0, 0);
		AddSpell(GEHENNAS_RAIN_OF_FIRE, Target_RandomDestination, 4, 0, 0, 0, 40);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Flamewaker AI Script
#define CN_FLAMEWAKER				11661
#define FLAMEWAKER_SUNDER_ARMOR		25051
#define FLAMEWAKER_FIST_OF_RAGNAROS	20277
#define FLAMEWAKER_STRIKE			11998

class FlamewakerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FlamewakerAI, ArcScriptCreatureAI);
	FlamewakerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		AddSpell(FLAMEWAKER_SUNDER_ARMOR, Target_Current, 8, 0, 0);
		AddSpell(FLAMEWAKER_FIST_OF_RAGNAROS, Target_Self, 8, 0, 0);
		AddSpell(FLAMEWAKER_STRIKE, Target_Current, 14, 0, 0);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Garr AI Script
#define CN_GARR					12057
#define GARR_ANTIMAGIC_PULSE	19492
#define GARR_MAGMA_SHACKES		19496

class GarrAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(GarrAI, ArcScriptBossAI);
	GarrAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(GARR_ANTIMAGIC_PULSE, Target_Self, 10, 0, 0);
		AddSpell(GARR_MAGMA_SHACKES, Target_Self, 10, 0, 0);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Firesworn AI Script
#define CN_FIRESWORN					12099
#define FIRESWORN_IMMOLATE				20294
#define FIRESWORN_ERUPTION				19497
#define FIRESWORN_SEPARATION_ANXIETY	23492

class FireswornAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FireswornAI, ArcScriptCreatureAI);
	FireswornAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		mGarr = NULL;

		//Spells
		AddSpell(FIRESWORN_IMMOLATE, Target_Current, 10, 0, 0, 0, 40);
		mEruption = AddSpell(FIRESWORN_ERUPTION, Target_Self, 0, 0, 0);
		mSeparationAnxiety = AddSpell(FIRESWORN_SEPARATION_ANXIETY, Target_Self, 0, 5, 5);
	}

	void OnCombatStart(Unit* pTarget)
	{
		mGarr = (ArcScriptBossAI*)GetNearestCreature(CN_GARR);
		ParentClass::OnCombatStart(pTarget);
	}

	void OnDied(Unit* pKiller)
	{
		CastSpellNowNoScheduling(mEruption);
		ParentClass::OnDied(pKiller);
	}

	void AIUpdate()
	{
		if( mGarr && mGarr->IsAlive() && GetRange(mGarr) > 100 )
		{
			CastSpell(mSeparationAnxiety);
		}
		ParentClass::AIUpdate();
	}

	SpellDesc*			mEruption;
	SpellDesc*			mSeparationAnxiety;
	ArcScriptBossAI*	mGarr;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Baron Geddon AI Script
#define CN_BARONGEDDON			12056
#define BARONGEDDON_INFERNO		19698	//35268
#define BARONGEDDON_IGNITE_MANA	19659
#define BARONGEDDON_LIVING_BOMB	20475

class BaronGeddonAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(BaronGeddonAI, ArcScriptBossAI);
	BaronGeddonAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(BARONGEDDON_INFERNO, Target_Self, 8, 0, 0);
		AddSpell(BARONGEDDON_IGNITE_MANA, Target_Self, 8, 0, 0);
		AddSpell(BARONGEDDON_LIVING_BOMB, Target_RandomPlayer, 8, 0, 0, 0, 45);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shazzrah AI Script
#define CN_SHAZZRAH					12264
#define SHAZZRAH_ARCANE_EXPLOSION	19712
#define SHAZZRAH_SHAZZRAHS_CURSE	19713
#define SHAZZRAH_MAGIC_GROUNDING	19714
#define SHAZZRAH_COUNTERSPELL		19715
#define SHAZZRAH_BLINK				29883	//dummy spell, need to be coded in core

void SpellFunc_ShazzrahBlinkArcaneExplosions(SpellDesc* pThis, ArcScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class ShazzrahAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(ShazzrahAI, ArcScriptBossAI);
	ShazzrahAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(SHAZZRAH_SHAZZRAHS_CURSE, Target_Self, 8, 0, 0);
		AddSpell(SHAZZRAH_MAGIC_GROUNDING, Target_Self, 6, 0, 0);
		AddSpell(SHAZZRAH_COUNTERSPELL, Target_Self, 6, 0, 0);

		mBlink = AddSpell(SHAZZRAH_BLINK, Target_RandomPlayer, 0, 0, 0);
		mArcaneExplosion = AddSpell(SHAZZRAH_ARCANE_EXPLOSION, Target_Self, 0, 0, 0);
		AddSpellFunc(&SpellFunc_ShazzrahBlinkArcaneExplosions, Target_Self, 8, -1, 15);
	}

	SpellDesc* mBlink;
	SpellDesc* mArcaneExplosion;
};

void SpellFunc_ShazzrahBlinkArcaneExplosions(SpellDesc* pThis, ArcScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	ShazzrahAI* Shazzrah = ( pCreatureAI ) ? (ShazzrahAI*)pCreatureAI : NULL;
	if( Shazzrah )
	{
		//Teleport blink, then cast 4 arcane explosions
		Shazzrah->CastSpell(Shazzrah->mBlink);
		for( int Iter = 0; Iter < 4; Iter++ ) Shazzrah->CastSpell(Shazzrah->mArcaneExplosion);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Register
void SetupMoltenCore(ScriptMgr* pScriptMgr)
{
    pScriptMgr->register_creature_script(CN_MOLTENGIANT, &MoltenGiantAI::Create);
    pScriptMgr->register_creature_script(CN_MOLTENDESTROYER, &MoltenDestroyerAI::Create);
    pScriptMgr->register_creature_script(CN_FIRELORD, &FirelordAI::Create);
	pScriptMgr->register_creature_script(CN_LAVAANNIHILATOR, &LavaAnnihilatorAI::Create);
	pScriptMgr->register_creature_script(CN_ANCIENTCOREHOUND, &AncientCoreHoundAI::Create);
    pScriptMgr->register_creature_script(CN_LAVASURGER, &LavaSurgerAI::Create);
    pScriptMgr->register_creature_script(CN_FLAMEIMP, &FlameImpAI::Create);
    pScriptMgr->register_creature_script(CN_COREHOUND, &CoreHoundAI::Create);
    pScriptMgr->register_creature_script(CN_LAVAREAVER, &LavaReaverAI::Create);
    pScriptMgr->register_creature_script(CN_LAVAELEMENTAL, &LavaElementalAI::Create);
    pScriptMgr->register_creature_script(CN_FLAMEGUARD, &FlameguardAI::Create);
    pScriptMgr->register_creature_script(CN_FIREWALKER, &FirewalkerAI::Create);
    pScriptMgr->register_creature_script(CN_LUCIFRON, &LucifronAI::Create);
	pScriptMgr->register_creature_script(CN_FLAMEWAKERPROTECTOR, &FlamewakerProtectorAI::Create);
    pScriptMgr->register_creature_script(CN_MAGMADAR, &MagmadarAI::Create);
    pScriptMgr->register_creature_script(CN_GEHENNAS, &GehennasAI::Create);
    pScriptMgr->register_creature_script(CN_FLAMEWAKER, &FlamewakerAI::Create);
    pScriptMgr->register_creature_script(CN_GARR, &GarrAI::Create);
    pScriptMgr->register_creature_script(CN_FIRESWORN, &FireswornAI::Create);
    pScriptMgr->register_creature_script(CN_BARONGEDDON, &BaronGeddonAI::Create);
    pScriptMgr->register_creature_script(CN_SHAZZRAH, &ShazzrahAI::Create);
    pScriptMgr->register_creature_script(CN_GOLEMAGG, &GolemaggAI::Create);
    pScriptMgr->register_creature_script(CN_CORERAGER, &CoreRagerAI::Create);

    pScriptMgr->register_creature_script(CN_SULFURON_HARBRINGER, &SulfuronAI::Create);
    pScriptMgr->register_creature_script(CN_RAGNAROS, &RagnarosAI::Create);
}
