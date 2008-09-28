#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL RuneChangerGossip : public GossipScript
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

void RuneChangerGossip::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
	if(Plr->getClass() != DKNIGHT) // Lol nubs
	{
		Plr->GetSession()->SendNotification("You aren't a Death Knight.");
		return;
	}
	
	if(Plr->CombatStatus.IsInCombat()) // We cant change runes in combat
	{
		Plr->GetSession()->SendNotification("You are in combat.");
		return;
	}
	
	GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);

	Menu->AddItem( 1, "Change my first rune!", 1 );
	Menu->AddItem( 2, "Change my second rune!", 5 );
	Menu->AddItem( 3, "Change my third rune!", 9 );
	Menu->AddItem( 4, "Change my fourth rune!", 13 );
	Menu->AddItem( 5, "Change my fifth rune!", 17 );
	Menu->AddItem( 6, "Change my sixth rune!", 21 );
	//Menu->AddItem( 7, "Change my seventh rune!", 25 ); // NYI
	//Menu->AddItem( 8, "Change my eighth rune!", 29 ); // NYI

    if(AutoSend)
        Menu->SendTo(Plr);
}

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, Plr); \
    Menu->SendTo(Plr);

void RuneChangerGossip::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	if(Plr->CombatStatus.IsInCombat()) // Escape check
	{
		Plr->GetSession()->SendNotification("You are in combat.");
		return;
	}

    switch(IntId)
    {	
	case 0:     // RETURN TO SENDER
		GossipHello(pObject, Plr, true);
		break;
	case 1:		// RUNE ONE MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 2 );
					Menu->AddItem( 1, "Give me a unholy rune!", 3 );
					Menu->AddItem( 1, "Give me a frost rune!", 4 );
					Menu->SendTo(Plr);	
			}
		}break;
    case 2:		// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_1, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_1, 0);
		Plr->Gossip_Complete();
		break;
	case 3:		// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_1, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_1, 1);
		Plr->Gossip_Complete();
		break;
	case 4:		// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_1, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_1, 2);
		Plr->Gossip_Complete();
		break;
	case 5:		// RUNE TWO MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 6 );
					Menu->AddItem( 1, "Give me a unholy rune!", 7 );
					Menu->AddItem( 1, "Give me a frost rune!", 8 );
					Menu->SendTo(Plr);
			}
		}break;
	case 6:		// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_2, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_2, 0);
		Plr->Gossip_Complete();
		break;
	case 7:		// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_2, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_2, 1);
		Plr->Gossip_Complete();
		break;
	case 8:		// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_2, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_2, 2);
		Plr->Gossip_Complete();
		break;
	case 9:		// RUNE THREE MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 10 );
					Menu->AddItem( 1, "Give me a unholy rune!", 11 );
					Menu->AddItem( 1, "Give me a frost rune!", 12 );
					Menu->SendTo(Plr);
			}
		}break;
	case 10:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_3, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_3, 0);
		Plr->Gossip_Complete();
		break;
	case 11:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_3, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_3, 1);
		Plr->Gossip_Complete();
		break;
	case 12:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_3, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_3, 2);
		Plr->Gossip_Complete();
		break;
	case 13:	// RUNE FOUR MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 14 );
					Menu->AddItem( 1, "Give me a unholy rune!", 15 );
					Menu->AddItem( 1, "Give me a frost rune!", 16 );
					Menu->SendTo(Plr);
			}
		}break;
	case 14:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_4, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_4, 0);
		Plr->Gossip_Complete();
		break;
	case 15:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_4, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_4, 1);
		Plr->Gossip_Complete();
		break;
	case 16:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_4, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_4, 2);
		Plr->Gossip_Complete();
		break;
	case 17:	// RUNE FIVE MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 18 );
					Menu->AddItem( 1, "Give me a unholy rune!", 19 );
					Menu->AddItem( 1, "Give me a frost rune!", 20 );
					Menu->SendTo(Plr);
			}
		}break;
	case 18:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_5, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_5, 0);
		Plr->Gossip_Complete();
		break;
	case 19:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_5, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_5, 1);
		Plr->Gossip_Complete();
		break;
	case 20:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_5, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_5, 2);
		Plr->Gossip_Complete();
		break;
	case 21:	// RUNE SIX MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 22 );
					Menu->AddItem( 1, "Give me a unholy rune!", 23 );
					Menu->AddItem( 1, "Give me a frost rune!", 24 );
					Menu->SendTo(Plr);
			}
		}break;
	case 22:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_6, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_6, 0);
		Plr->Gossip_Complete();
		break;
	case 23:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_6, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_6, 1);
		Plr->Gossip_Complete();
		break;
	case 24:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_6, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_6, 2);
		Plr->Gossip_Complete();
		break;
	/*case 25:	// RUNE SEVEN MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 26 );
					Menu->AddItem( 1, "Give me a unholy rune!", 27 );
					Menu->AddItem( 1, "Give me a frost rune!", 28 );
					Menu->SendTo(Plr);
			}
		}break;
	case 26:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_7, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_7, 0);
		Plr->Gossip_Complete();
		break;
	case 27:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_7, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_7, 1);
		Plr->Gossip_Complete();
		break;
	case 28:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_7, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_7, 2);
		Plr->Gossip_Complete();
		break;
	case 29:	// RUNE EIGHT MENU
		{
			if(Plr->GetUInt32Value(PLAYER_FIELD_RUNES_1) > 3) // Cheeky, cheeky.
			{
				Plr->GetSession()->SendNotification("Rune has not regenerated yet.");
				Plr->Gossip_Complete();
				return;
			}
			else
			{
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 50000, Plr);
					Menu->AddItem( 1, "Give me a blood rune!", 30 );
					Menu->AddItem( 1, "Give me a unholy rune!", 31 );
					Menu->AddItem( 1, "Give me a frost rune!", 32 );
					Menu->SendTo(Plr);
			}
		}break;
	case 30:	// BLOOD
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_8, 0);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_8, 0);
		Plr->Gossip_Complete();
		break;
	case 31:	// UNHOLY
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_8, 1);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_8, 1);
		Plr->Gossip_Complete();
		break;
	case 28:	// FROST
		Plr->SetUInt32Value(PLAYER_FIELD_RUNES_8, 2);
		Plr->SetUInt32Value(PLAYER_FIELD_BASE_RUNES_8, 2);
		Plr->Gossip_Complete();
		break;*/
    }
}

void RuneChangerGossip::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupRuneChangerGossip(ScriptMgr * mgr)
{
	GossipScript * rcg = (GossipScript*) new RuneChangerGossip();
    mgr->register_item_gossip_script(2946, rcg);      // Rune Changer
}
