#include "StdAfx.h"
#include "Setup.h"
#define SKIP_ALLOCATOR_SHARING 1
#include <ScriptSetup.h>

extern "C" SCRIPT_DECL uint32 _exp_get_script_type()
{
	return SCRIPT_TYPE_MISC;
}

extern "C" SCRIPT_DECL void _exp_script_register(ScriptMgr* mgr)
{
    // HOOKS
	mgr->register_hook(SERVER_HOOK_EVENT_ON_CHARACTER_CREATE, (void*) &OnCharacterCreate);
	mgr->register_hook(SERVER_HOOK_EVENT_ON_FIRST_ENTER_WORLD, (void*) &OnFirstEnterWorld);
	mgr->register_hook(SERVER_HOOK_EVENT_ON_CAST_SPELL, (bool*) &OnCastSpell);
	mgr->register_hook(SERVER_HOOK_EVENT_ON_ENTER_WORLD_2, (void*) &OnEnterWorld);
	
	// AI
	SetupPortalGossip(mgr);
	SetupTeleCord(mgr);
	SetupGryphon1Gossip(mgr);
	SetupGryphon2Gossip(mgr);

	// RAIDS
	//SetupEvilArthasRaid(mgr);
}

#ifdef WIN32

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    return TRUE;
}

#endif
