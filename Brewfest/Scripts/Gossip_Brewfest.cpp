/* 
===============================
The Brewfest Project
Author: Nexis
===============================
*/

#include "StdAfx.h"
#include "Setup.h"


/* =============================================================================================================== */

// Brewfest Setup Crew
#define BARK_BREWFEST_SETUP_CREW_1		"Brewfest is almost here!"
#define BARK_BREWFEST_SETUP_CREW_2		"I can't wait until we're done setting up. Then I can kick back and enjoy the festivities."
#define BARK_BREWFEST_SETUP_CREW_3		"Brewfest is a non-stop party. Setting up for it, though, is non-stop work!"
#define BARK_BREWFEST_SETUP_CREW_4		"Won't be long now until the Brewfest starts! Come back later and check to see if we're done."
#define BARK_BREWFEST_SETUP_CREW_5		"Can't you see I've got work to do here?"

class BrewfestSetupCrew_Bark : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BrewfestSetupCrew_Bark);
	BrewfestSetupCrew_Bark(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		RegisterAIUpdateEvent(120000); 			// Start initial update after: 2mins
	}

	void AIUpdate()
	{
		int randGossip;
			randGossip=rand()%5;
			switch (randGossip)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_BREWFEST_SETUP_CREW_1 );
			break;

			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_BREWFEST_SETUP_CREW_2 );
			break;

			case 2:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_BREWFEST_SETUP_CREW_3 );
			break;

			case 3:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_BREWFEST_SETUP_CREW_4 );
			break;

			case 4:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_BREWFEST_SETUP_CREW_5 );
			break;
			}
			
		int rndTimer;
		rndTimer = rand() % 480 + 180; 			// Generate a random value between: 3-8mins
		rndTimer = rndTimer * 1000; 			// Convert to milliseconds
		ModifyAIUpdateEvent(rndTimer); 			// Modify timer to new random value
	}
};

/* =============================================================================================================== */

void SetupBrewfestBarker(ScriptMgr * mgr)
{
	mgr->register_creature_script(23504, &BrewfestSetupCrew_Bark::Create); 				// Brewfest Setup Crew
}