/* 
===============================
The Darkmoon Faire Project
Author: Nexis
Team: Sun++ (www.sunplusplus.info)
===============================
*/

#include "StdAfx.h"
#include "Setup.h"

// Blastenheimer 5000 Ultra Cannon
class Blastenheimer5000 : public GameObjectAIScript
{
public:
	Blastenheimer5000(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject * GO) { return new Blastenheimer5000(GO); }

	void OnActivate(Player * pPlayer)
	{
		GameObject * BlastCannon = NULL;
		BlastCannon = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), 180515);
		BlastCannon->SetUInt32Value(GAMEOBJECT_FLAGS,33);
		pPlayer->CastSpell(pPlayer, 24832, true);
		pPlayer->SetMovement(MOVE_ROOT, 1);
		BlastCannon->PlaySoundToSet(8476);
		RegisterAIUpdateEvent(2200);

		Plr = pPlayer;
		Cannon = BlastCannon;
	}

	void AIUpdate()
	{
		if(Plr->GetMapId() == 530) 		// Shattrath
		{
			Plr->SafeTeleport(530, 0, -1742.640869f, 5454.712402f, -7.928009f, 4.606363f); 
		}
		else if(Plr->GetMapId() == 0) 	// Elwynn Forest
		{
			Plr->SafeTeleport(0, 0, -9569.150391f, -14.753426f, 68.051422f, 4.874008f); 
		}
		else if(Plr->GetMapId() == 1) 	// Mulgore
		{
			Plr->SafeTeleport(1, 0, -1326.711914f, 86.301125f, 133.093918f, 3.510725f); 
		}

		Plr->SetMovement(MOVE_UNROOT, 1);
		Plr->CastSpell(Plr,42867,true); // 24742
		RemoveAIUpdateEvent();
		Cannon->SetUInt32Value(GAMEOBJECT_FLAGS,0);
	}

protected:
	Player* Plr;
	GameObject* Cannon;
};

// Darkmoon Faire Music Doodad
class DarkmoonFaireMusicDoodad : public GameObjectAIScript
{
public:
	DarkmoonFaireMusicDoodad(GameObject* goinstance) : GameObjectAIScript(goinstance){RegisterAIUpdateEvent(1000);}
	static GameObjectAIScript *Create(GameObject *pGameObject) { return new DarkmoonFaireMusicDoodad(pGameObject); }

	void AIUpdate()
	{
		_gameobject->PlaySoundToSet(8440);			// Play Darkmoon Faire Music
	}
};

void SetupDarkmoonFaireObjects(ScriptMgr * mgr)
{
	mgr->register_gameobject_script(180515, &Blastenheimer5000::Create);			// Blastenheimer 5000 Ultra Cannon
	mgr->register_gameobject_script(180335, &DarkmoonFaireMusicDoodad::Create);		// Darkmoon Faire Music Doodad
}
