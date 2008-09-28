//#define SPELLID_ARMY_OF_THE_DEAD		42651
#define SPELLID_ARMY_OF_THE_DEAD		42650

// NOTE: ARMY OF THE DEAD NEEDS REWORKING

#include "StdAfx.h"
#include "Setup.h"

bool OnCastSpell(Player * pPlayer, SpellEntry * pSpell)
{
	uint32 m_id = pSpell->m_id;
	
	switch(m_id) // Death Knight - Hackfixes galore!
	{		
	case SPELLID_ARMY_OF_THE_DEAD: // Handle changeover
		{
			CreatureInfo * cGhoulInfo = CreatureNameStorage.LookupEntry(24207); // Ghoul info
			if(!cGhoulInfo)
				return false;
			
			CreatureProto * cGhoulProto = CreatureProtoStorage.LookupEntry(24207); // Ghoul info
			if(!cGhoulProto)
				return false;

			//Creature * cGhoul = pPlayer->create_guardian(24207,60000, pPlayer->GetOrientation() * RandomFloat(0.8f), 80);
			//cGhoul->Load(cGhoulProto, pPlayer->GetPositionX() + Rand(5.0f), pPlayer->GetPositionY() - Rand(3.0f), pPlayer->GetPositionZ());
			//cGhoul->SetInstanceID(pPlayer->GetInstanceID());
			//cGhoul->SetZoneId(pPlayer->GetZoneId());
			//cGhoul->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
			//cGhoul->m_noRespawn=true;

			//sEventMgr.AddEvent(cGhoul,&Creature::AddToWorld, pPlayer->GetMapMgr(), EVENT_UNK, 3000, 5, 0);

			return true;

		}break;
	}

	return true;
}


bool TreeDisguiseSpell(uint32 i, Spell * pSpell)
{
		if(!pSpell->p_caster) return true;

			pSpell->p_caster->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16977);
			pSpell->p_caster->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 67);
}


bool ScarletDisguiseSpell(uint32 i, Spell * pSpell)
{
			if(!pSpell->p_caster) return true;

			pSpell->p_caster->SetUInt32Value(UNIT_FIELD_DISPLAYID, 25897);
			pSpell->p_caster->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 67);
}
//This stuff needs work. Basically the first one the Death Horse the second is the Battle Maiden Ressurect
/*
bool StealHorse(Player * plr)
{
			if (Player->HasQuest == 12680)  return true;
			

}

bool EbonHoldDeath(uint32 Player * plr, Mapmgr * pMapmgr)
{

			CreatureInfo * cBattleMaidenInfo = CreatureNameStorage.LookupEntry(28534); // Checking for the Battle Maiden info
			if(!cGhoulInfo)
				return false;
			
			CreatureProto * cBattleMaidenProto = CreatureProtoStorage.LookupEntry(28534); // Checking for the Battle Maiden proto
			if(!cGhoulProto)
				return false;
			if (plr->EventDeath();)

				//How this works: Players dies on map 609 the Battlemaiden Spawns
				//The battlemaiden whispers the player with the Spirit Healer Msg(Its not your time blah blah blah
				//Battle Maiden casts Ressurect on you
				//Battlemaiden Disappears
			//Creature * cBattleMaidenProto = pPlayer->create_guardian(24207,60000, pPlayer->GetOrientation() * RandomFloat(0.8f), 80);
			//cGhoul->Load(cBattleMaidenProto, pPlayer->GetPositionX() + Rand(5.0f), pPlayer->GetPositionY() - Rand(3.0f), pPlayer->GetPositionZ());
			//cGhoul->SetInstanceID(pPlayer->GetInstanceID());
			//cGhoul->SetZoneId(pPlayer->GetZoneId());
			//cGhoul->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAGS_PVP);
			//cGhoul->m_noRespawn=true;

		//	sEventMgr.AddEvent(cGhoul,&pMapmgr::AddToWorld, pPlayer->GetMapMgr(), EVENT_UNK, 3000, 5, 0);

			

}
*/
void SetupWotLK_SpellFixes(ScriptMgr * mgr)
{
	mgr->register_dummy_spell(30298, &TreeDisguiseSpell);        // Tree Transform
	mgr->register_dummy_spell(53083, &ScarletDisguiseSpell);        // Scarlet Disguise
}