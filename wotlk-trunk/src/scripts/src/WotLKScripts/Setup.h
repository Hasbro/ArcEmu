#ifndef WOTLK_SCRIPTS_SETUP_H
#define WOTLK_SCRIPTS_SETUP_H

// HOOKS
void OnCharacterCreate(Player * pPlayer);
void OnFirstEnterWorld(Player * pPlayer);
bool OnCastSpell(Player * pPlayer, SpellEntry * sp);
void OnEnterWorld(Player * pPlayer);

// AI
void SetupPortalGossip(ScriptMgr * mgr);
void Teleporter::TeleporterSystem(ScriptMgr * mgr);
void SetupGryphon1Gossip(ScriptMgr * mgr);
void SetupGryphon2Gossip(ScriptMgr * mgr);

// RAIDS
//void SetupEvilArthasRaid(ScriptMgr * mgr);

struct SP_AI_Spell{
	SpellEntry *info; // spell info
	char targettype; // 0-self , 1-attaking target, ....
	bool instant; // does it is instant or not?
	float perctrigger; // % of the cast of this spell in a total of 100% of the attacks
	int attackstoptimer; // stop the creature from attacking
	int soundid; // sound id in DBC
	std::string speech; // text displaied when spell was casted
	uint32 cooldown;	// spell cooldown
	uint32 casttime;	// "time" left to cast spell
};

enum
{
	TARGET_SELF,
	TARGET_VARIOUS,
	TARGET_ATTACKING,
	TARGET_DESTINATION,
	TARGET_SOURCE,

	//.....add
};

#endif
