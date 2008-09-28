#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL Gryphon2Gossip : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* Plr);
	void Destroy()
	{
		delete this;
	}
};

void Gryphon2Gossip::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
    uint32 TextID = 50000;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);

	Menu->AddItem( 1, "Fly me to down!", 1 );
    if(AutoSend)
        Menu->SendTo(Plr);
}

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, Plr); \
    Menu->SendTo(Plr);

void Gryphon2Gossip::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

        Plr->SafeTeleport(609, 0, 2415.442627f, -5732.698730f, 153.921982f, 3.641609f);
}

void Gryphon2Gossip::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupGryphon2Gossip(ScriptMgr * mgr)
{
	GossipScript * ps = (GossipScript*) new Gryphon2Gossip();
    mgr->register_gossip_script(28864, ps);      // The Magic Man
}
