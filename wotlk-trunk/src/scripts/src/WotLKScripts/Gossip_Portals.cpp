#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL PortalGossip : public GossipScript
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

void PortalGossip::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
    uint32 TextID = 820;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);

	Menu->AddItem( 1, "To Shattrath!", 1 );
	Menu->AddItem( 2, "To Northrend!", 2 );
	Menu->AddItem( 11, "To Death Knight starting area!", 11 );
	Menu->AddItem( 12, "To Dalaran!", 12 );

    if(Plr->GetTeam())
	{
		Menu->AddItem( 3, "To Orgrimmar!", 3 );  
		Menu->AddItem( 4, "To the Undercity!", 4 );
		Menu->AddItem( 5, "To Thunderbluff!", 5 );
		Menu->AddItem( 6, "To Silvermoon City!", 6 );
	}
	else
	{
		Menu->AddItem( 7, "To Stormwind!", 7 );  
		Menu->AddItem( 8, "To Ironforge!", 8 );
		Menu->AddItem( 9, "To Darnassus!", 9 );
		Menu->AddItem( 10, "To the Exodar!", 10 );
	}

    if(AutoSend)
        Menu->SendTo(Plr);
}

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, Plr); \
    Menu->SendTo(Plr);

void PortalGossip::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

    switch(IntId)
    {
    case 1:     // SHATTRATH
        Plr->SafeTeleport(530, 0, -1864.063599f, 5429.958496f, -9.705295f, 0.494803f);
        break;
    case 2:     // NORTHREND
		{
		if(Plr->GetTeam())
				Plr->SafeTeleport(571, 0, 3830.976563f, 1580.578125f, 86.698738f, 2.136259f);
		else
				Plr->SafeTeleport(571, 0, 2685.214844f, -1933.735474f, 4.096734f, 5.870848f);
		}break;
    case 3:     // ORGRIMMAR
        Plr->SafeTeleport(1, 0, 1394.019287f, -4367.589355f, 25.429207f, 0.153153f);
        break;
    case 4:     // UNDERCITY
        Plr->SafeTeleport(0, 0, 1584.741577f, 240.576538f, -52.152393f, 6.275328f);
        break;
    case 5:     // THUNDERBLUFF
        Plr->SafeTeleport(1, 0, -1285.064087f, 138.103638f, 130.692917f, 5.262166f);
        break;
    case 6:     // SILVERMOON CITY
        Plr->SafeTeleport(530, 0, 9351.041016f, -7278.201172f, 14.241095f, 6.271405f);
        break;
    case 7:     // STORMWIND
        Plr->SafeTeleport(0, 0, -8913.158203f, 553.562134f, 93.830597f, 0.647953f);
        break;
    case 8:     // IRONFORGE
        Plr->SafeTeleport(0, 0, -5028.768066f, -824.816504f, 495.285126f, 5.415324f);
        break;
    case 9:     // DARNASSUS
        Plr->SafeTeleport(1, 0, 9951.899414f, 2280.443604f, 1341.394409f, 1.580230f);
        break;
    case 10:     // EXODAR
        Plr->SafeTeleport(530, 0, -3994.239990f, -11862.302734f, 0.277169f, 1.119193f);
        break;
    case 11:     // DK Start
        Plr->SafeTeleport(609, 0, 2487.19f, -5588.05f, 550.2f, 0.000000f);
        break;
	case 12:     // Dalaran
        Plr->SafeTeleport(571, 0, 5804.03f, 639.535f, 648.038f, 0.000000f);
        break;
    }
}

void PortalGossip::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupPortalGossip(ScriptMgr * mgr)
{
	GossipScript * ps = (GossipScript*) new PortalGossip();
    mgr->register_gossip_script(2, ps);      // The Magic Man
}
