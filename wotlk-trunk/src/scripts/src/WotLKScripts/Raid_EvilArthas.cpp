
#include "StdAfx.h"
#include "Setup.h"

// Defines!
#define NPC_EVIL_ARTHAS 38000
#define NPC_GHOST_MURADIN 38001
#define NPC_GHOST_ARTHAS 38002
#define NPC_ANUB_ARAK 38003
#define NPC_CORRUPTED_TREANT 38004
#define NPC_TREANT_MINION 38005
#define NPC_FIRST_HORSEMAN 38006
#define NPC_SECOND_HORSEMAN 38007
#define NPC_THIRD_HORSEMAN 38008
#define NPC_FOURTH_HORSEMAN 38009

// Globals!
bool m_DeathKnightsSummoned;
bool m_TreantsSummoned;
uint32 SoundTimer;

// Spawns
float AnubArakSpawns[4][4] = {
	{ 507.776001f, 86.282623f, -16.124939f, 6.239976f },
	{ 508.003143f, 91.721085f, -16.124939f, 0.113865f },
	{ 501.366974f, 91.585167f, -16.124939f, 0.102080f },
	{ 501.417999f, 86.318108f, -16.124939f, 6.149635f }
};

float DeathKnightSpawns[4][4] = {
	{ 308.939819f, 1.624439f, -16.338217f, 0.733042f },
	{ 295.427551f, 1.362994f, -16.329386f, 2.347037f },
	{ 295.176086f, -12.237996f, -16.335821f, 3.906048f },
	{ 309.168732f, -12.342413f, -16.339672f, 5.488630f }
};

float CorruptedTreantSpawns[9][4] = {
	{ 283.960571f, -218.992294f, -8.254059f, 5.623059f },
	{ 276.559082f, -243.099808f, -8.254058f, 6.003973f },
	{ 276.544250f, -229.701920f, -9.100922f, 5.921518f },
	{ 275.432404f, -220.346252f, -9.100986f, 5.438482f },
	{ 267.591827f, -237.219681f, -9.100986f, 5.740857f },
	{ 251.294525f, -227.365112f, -9.100986f, 5.497384f },
	{ 253.492920f, -216.034348f, -9.100986f, 5.630900f },
	{ 263.103455f, -211.612686f, -9.100986f, 5.690000f },
	{ 269.636719f, -212.715759f, -9.100986f, 5.917764f }
};

float RiftSpawns[6][4] = {
	{ 634.100403f, -267.725037f, -8.481714f, 1.515611f },
	{ 622.294067f, -282.728149f, -9.049104f, 1.747303f },
	{ 626.998779f, -305.483368f, -9.439840f, 1.637350f },
	{ 640.256226f, -312.059357f, -9.450818f, 1.688401f },
	{ 651.190552f, -297.958893f, -9.366961f, 1.519540f },
	{ 651.190552f, -297.958893f, -9.366961f, 1.519540f }
};

float CenterGateSpawns[4][4] = {
	{ 239.246078f, -5.369517f, -16.366811f, 3.159909f },
	{ 302.108856f, 57.187103f, -16.636698f, 1.542908f },
	{ 364.676666f, -5.349246f, -16.636721f, 6.282786f },
	{ 301.998993f, -67.912094f, -16.636730f, 4.723770f }
};


// Sounds
uint32 ArthasSoundEntries[4] = { 12729, 12730, 12731, 12728 };
uint32 ArthasSoundDelays[4] = { 1000, 36000, 47000, 64000 };

uint32 MuradinSoundDelays[4] = { 7000, 33000, 40000, 54000 };
uint32 MuradinSoundEntries[4] = { 12735, 12733, 12736, 12734 };

uint32 Horsemen[4] = { 16064, 16065, 16062, 16063 };

// Dialogues
const char * ArthasSoundDialogue[4] = {
	"Behold Muradin, our salvation... Frostmourne...",
	"I would gladly bear any curse to save my homeland!",
	"Damn the men! Nothing shall prevent me from having my revenge, old friend. Not even you. ",
	"Spare me Muradin! You weren't there to see what Mal'Ganis did to my homeland.",
};

const char * MuradinSoundDialogue[4] = {
	"Hold, lad, there's an inscription on the dais! (It's a warning) It says: Whomsoever takes up this blade shall wield power eternal. Just as the blade rends flesh, so must power scar the spirit. Oh, I should've known! The blade is cursed! Let's get the hell out of here!",
	"Isn't that a bit much lad?",
	"Oh, leave it be, Arthas! Forget this business and lead your men home!",
	"You lied to your men and betrayed the mercenaries who fought for you! What's happenin' to you, Arthas? Is vengeance all that is important to you?",
};

const char * ArthasDialoue[3] = {
	"My patience has ended!",
	"The pact is sealed!",
	"Ride or die!",
};

const char * AnubArakDialogue[3] = {
	"My might cannot be matched!",
	"By Ner'Zhul!",
	"The scourge will devour all!"
};

const char * CorruptedTreantDialogue[3] = {
	"Cenarius was a fool!",
	"Feel the scourge's ultimate corruption!",
	"This will be YOUR end!",
};

// Evil Arthas AI
#define DEATH_COIL 30741
#define UNHOLY_PRESENCE 48265

class EvilArthasAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(EvilArthasAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

	EvilArthasAI(Creature* pCreature) : CreatureAIScript(pCreature)
	{
		m_DeathKnightsSummoned = false;
		SoundTimer = 0;
		
		nrspells = 2;
		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(DEATH_COIL);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 7.0f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(UNHOLY_PRESENCE);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].perctrigger = 0.0f;
		spells[1].attackstoptimer = 1000;

		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You fools, you will perish just as Uther and Muradin did!");
	}

	void OnCombatStart(Unit* mTarget)
	{
		_unit->CastSpell(_unit, spells[1].info, spells[1].instant);
		uint32 i = RandomUInt(2);
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, ArthasDialoue[i]);
		RegisterAIUpdateEvent(1000);
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit * mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void OnSpawn()
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void AIUpdate()
	{
		float val = (float)RandomFloat(100.0f);			
		SpellCast(val);

		if(_unit->GetHealthPct() < 100)
		{
			if(m_DeathKnightsSummoned == false)
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Come forth horsemen, rid these pests from my sight.");
				for(int i = 0; i < 5; i++)
				{
					_unit->GetMapMgr()->GetInterface()->SpawnCreature(Horsemen[i], 
						DeathKnightSpawns[i][0], DeathKnightSpawns[i][1],
						DeathKnightSpawns[i][2], DeathKnightSpawns[i][3],
						true, false, _unit->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE), 50);
				}
				
				m_DeathKnightsSummoned = true;

			}
		}
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			float comulativeperc = 0;
			Unit *target = NULL;
			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					
					if(target->GetInstanceID() != _unit->GetInstanceID())
						return;

					switch(spells[i].targettype)
					{
					case TARGET_SELF:
					case TARGET_VARIOUS:
						_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
					case TARGET_ATTACKING:
						_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
					case TARGET_DESTINATION:
						_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:

	int nrspells;
};

class GhostArthasAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GhostArthasAI);

	GhostArthasAI(Creature* pCreature) : CreatureAIScript(pCreature)
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnSpawn()
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnLoad()
	{
		for(uint32 i = 0; i < 4; i++)
		{
			sEventMgr.AddEvent(static_cast<Unit*>(_unit), &Unit::SendChatMessage, uint8(CHAT_MSG_MONSTER_YELL), uint32(LANG_UNIVERSAL), (const char*)(ArthasSoundDialogue[i]), EVENT_UNIT_CHAT_MSG, uint32(ArthasSoundDelays[i]), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			sEventMgr.AddEvent(static_cast<Object*>(_unit), &Object::PlaySoundToSet, uint32(ArthasSoundEntries[i]), EVENT_UNK, uint32(ArthasSoundDelays[i]), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
	}
};

class GhostMuradinAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GhostMuradinAI);

	GhostMuradinAI(Creature* pCreature) : CreatureAIScript(pCreature)
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnSpawn()
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnLoad()
	{
		for(uint32 i = 0; i < 4; i++)
		{
			sEventMgr.AddEvent(static_cast<Unit*>(_unit), &Unit::SendChatMessage, uint8(CHAT_MSG_MONSTER_YELL), uint32(LANG_UNIVERSAL), (const char*)(MuradinSoundDialogue[i]), EVENT_UNIT_CHAT_MSG, uint32(MuradinSoundDelays[i]), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			sEventMgr.AddEvent(static_cast<Object*>(_unit), &Object::PlaySoundToSet, uint32(MuradinSoundEntries[i]), EVENT_UNK, uint32(MuradinSoundDelays[i]), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
	}
};

void SetupEvilArthasRaid(ScriptMgr * mgr)
{
	mgr->register_creature_script(NPC_EVIL_ARTHAS, &EvilArthasAI::Create);
	mgr->register_creature_script(NPC_GHOST_MURADIN, &GhostMuradinAI::Create);
	mgr->register_creature_script(NPC_GHOST_ARTHAS, &GhostArthasAI::Create);
}


