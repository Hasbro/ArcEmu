#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL Gryphon1Gossip : public GossipScript
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

void Gryphon1Gossip::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
    uint32 TextID = 50000;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);

	Menu->AddItem( 1, "Fly me to up!", 1 );
    if(AutoSend)
        Menu->SendTo(Plr);
}

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, Plr); \
    Menu->SendTo(Plr);

void Gryphon1Gossip::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

        Plr->SafeTeleport(609, 0, 2348.983643f, -5669.406250f, 382.240479f, 0.620915f);
}

void Gryphon1Gossip::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupGryphon1Gossip(ScriptMgr * mgr)
{
	GossipScript * ps = (GossipScript*) new Gryphon1Gossip();
    mgr->register_gossip_script(28906, ps);      // The Magic Man
}
