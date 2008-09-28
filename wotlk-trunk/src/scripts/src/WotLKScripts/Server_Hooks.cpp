#include "StdAfx.h"
#include "Setup.h"

void OnCharacterCreate(Player * pPlayer)
{
	if (pPlayer == NULL)
		return;

		// COMMON ABILITIE
		pPlayer->addSpell(6603);
		pPlayer->addSpell(81);
		pPlayer->addSpell(81);
		pPlayer->addSpell(2382);
		pPlayer->addSpell(2479);
		pPlayer->addSpell(3365);
		pPlayer->addSpell(6233);
		pPlayer->addSpell(6246);
		pPlayer->addSpell(6247);
		pPlayer->addSpell(6477);
		pPlayer->addSpell(6478);
		pPlayer->addSpell(7266);
		pPlayer->addSpell(7267);
		pPlayer->addSpell(7355);
		pPlayer->addSpell(9125);
		pPlayer->addSpell(21651);
		pPlayer->addSpell(21652);
		pPlayer->addSpell(22027);
		pPlayer->addSpell(22810);

		// SWITCHES
		uint8 Race = pPlayer->getRace();
		uint8 Class = pPlayer->getClass();

		// RACIAL SPELL ARRAYS
		uint32 HumanRacials[5] = { 20599, 20864, 20600, 20597, 20598 };
		uint32 OrcRacials[4] = { 20574, 20573, 33697, 21563 };
		uint32 DwarfRacials[4] = { 2481, 20596, 20595, 20594 };
		uint32 NightElfRacials[4] = { 20583, 20582, 20580, 20585 };
		uint32 UndeadRacials[4] = { 20577, 5227, 7744, 20579 };
		uint32 TaurenRacials[4] = { 20552, 20550, 20551, 20549 };
		uint32 GnomeRacials[4] = { 20592, 20593, 20589, 20591 };
		uint32 TrollRacials[4] = { 20557, 26290, 20555, 20558 };
		uint32 BloodElfRacials[3] = { 28877, 822, 28734 };
		uint32 DraeneiRacials[3] = { 28875, 28880, 20579 };
		
		// ENGAGE TO HYPERSWITCH FOR RACIALS
		switch(Race)
		{
		case RACE_HUMAN:
			for(int i = 0; i < 6; i++)
				pPlayer->addSpell(HumanRacials[i]);
			break;
		case RACE_ORC:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(OrcRacials[i]);
			break;
		case RACE_DWARF:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(DwarfRacials[i]);
			break;
		case RACE_NIGHTELF:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(NightElfRacials[i]);
			break;
		case RACE_UNDEAD:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(UndeadRacials[i]);
			break;
		case RACE_TAUREN:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(TaurenRacials[i]);
			break;
		case RACE_GNOME:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(GnomeRacials[i]);
			break;
		case RACE_TROLL:
			for(int i = 0; i < 5; i++)
				pPlayer->addSpell(TrollRacials[i]);
			if(pPlayer->GetPowerType() == POWER_TYPE_RAGE)
				pPlayer->addSpell(26296);
			break;
		case RACE_BLOODELF:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(BloodElfRacials[i]);
			if(pPlayer->GetPowerType() == POWER_TYPE_MANA)
				pPlayer->addSpell(28730);
			if(pPlayer->GetPowerType() == POWER_TYPE_ENERGY)
				pPlayer->addSpell(25046);
			break;
		case RACE_DRAENEI:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(DraeneiRacials[i]);
			break;
		}

				
		// CLASS SPELL ARRAYS
		uint32 WarriorSpells[3] = { 2457, 78, 107 };
		uint32 PaladinSpells[3] = {	635, 21084, 107 };
		uint32 HunterSpells[3] = { 3018, 75, 2973 };
		uint32 RogueSpells[3] = { 2567, 2098, 1752 };
		uint32 PriestSpells[3] = { 5019, 2050, 585 };
		uint32 DeathKnightSpells[7] = { 48266, 45902, 45462, 45477, 47541, 48778, 107 };
		uint32 ShamanSpells[3] = { 107, 403, 331 };
		uint32 MageSpells[3] = { 5019, 133, 168 };
		uint32 WarlockSpells[3] = { 5019, 687, 686 };
		uint32 DruidSpells[2] = { 5176, 5185 };

		// CLASS SKILL ARRAYS
		uint32 WarriorSkills[10][3] = {
			{ 26, 0, 0 },
			{ 44, 1, 5 },
			{ 95, 1, 5 },
			{ 54, 1, 5 },
			{ 43, 1, 5 },
			{ 162, 1, 5 },
			{ 415, 0, 0 },
			{ 414, 0, 0 },
			{ 413, 0, 0 },
			{ 433, 0, 0 }
		};

		uint32 PaladinSkills[11][3] = {
			{ 44, 1, 5 },
			{ 95, 1, 5 },
			{ 54, 1, 5 },
			{ 172, 1, 5 },
			{ 160, 1, 5 },
			{ 162, 1, 5 },
			{ 415, 0, 0 },
			{ 414, 0, 0 },
			{ 413, 0, 0 },
			{ 594, 0, 0 },
			{ 433, 0, 0 }
		};

		uint32 HunterSkills[8][3] = {
			{ 44, 1, 5 },
			{ 95, 1, 5 },
			{ 46, 1, 5 },
			{ 51, 0, 0 },
			{ 415, 0, 0 },
			{ 414, 0, 0 },
			{ 162, 1, 5 },
			{ 163, 0, 0 }
		};

		uint32 RogueSkills[8][3] = {
			{ 38, 0, 0 },
			{ 95, 1, 5 },
			{ 162, 1, 5 },
			{ 176, 1, 5 },
			{ 173, 1, 5 },
			{ 253, 0, 0 },
			{ 415, 0, 0 },
			{ 414, 0, 0 }
		};

		uint32 PriestSkills[6][3] = {
			{ 54, 1, 5 },
			{ 56, 0, 0 },
			{ 95, 1, 5 },
			{ 162, 1, 5 },
			{ 228, 1, 5 },
			{ 415, 0, 0 }
		};

		uint32 DeathKnightSkills[15][3] = {
			{ 770, 0, 0 },
			{ 44, 275, 275 },
			{ 95, 275, 275 },
			{ 54, 275, 275 },
			{ 55, 275, 275 },
			{ 43, 275, 275 },
			{ 162, 275, 275 },
			{ 293, 0, 0 },
			{ 415, 0, 0 },
			{ 414, 0, 0 },
			{ 413, 0, 0 },
			{ 433, 0, 0 },
			{ 771, 0, 0 },
			{ 772, 0, 0 },
			{ 172, 275, 275 },
		};

		uint32 ShamanSkills[9][3] = {
			{ 54, 1, 5 },
			{ 95, 1, 5 },
			{ 136, 1, 5 },
			{ 162, 1, 5 },
			{ 375, 0, 0 },
			{ 374, 0, 0 },
			{ 415, 0, 0 },
			{ 414, 0, 0 },
			{ 433, 0, 0 }
		};


		uint32 MageSkills[7][3] = {
			{ 8, 0, 0 },
			{ 6, 0, 0 },
			{ 95, 1, 5 },
			{ 136, 1, 5 },
			{ 162, 1, 5 },
			{ 228, 1, 5 },
			{ 415, 0, 0 }
		};
		
		uint32 WarlockSkills[9][3] = {
			{ 8, 0, 0 },
			{ 6, 0, 0 },
			{ 95, 1, 5 },
			{ 173, 1, 5 },
			{ 162, 1, 5 },
			{ 228, 1, 5 },
			{ 415, 0, 0 },
			{ 354, 0, 0 },
			{ 593, 0, 0 }
		};

		uint32 DruidSkills[10][3] = {
			{ 8, 0, 0 },
			{ 6, 0, 0 },
			{ 95, 1, 5 },
			{ 173, 1, 5 },
			{ 136, 1, 5 },
			{ 162, 1, 5 },
			{ 414, 0, 0 },
			{ 415, 0, 0 },
			{ 573, 0, 0 },
			{ 574, 0, 0 }
		};

		// MOUNTS BY RACE (SORRY SYNRIC - NO HYPERSWITCH :P)
		// static uint32 RacialMounts[12] = { 0, 18241, 12351, 13328, 18242, 13334, 18247, 18243, 18788, 0, 28936, 29745 };
		// Item * pItem = objmgr.CreateItem(RacialMounts[pPlayer->getRace()], pPlayer);
		// pPlayer->GetItemInterface()->AddItemToFreeSlot(pItem);

		// CLASS ITEM ARRAYS
		// Structure
		// ItemID, Bag, Slot
		uint32 WarriorItems[58][3] = {
			{ 38, -1, EQUIPMENT_SLOT_BODY },		// Human Warrior Start 0
			{ 25, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 2362, -1, EQUIPMENT_SLOT_OFFHAND },
			{ 39, -1, EQUIPMENT_SLOT_LEGS },
			{ 40, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Human Warrior End 6
			{ 6125, -1, EQUIPMENT_SLOT_BODY },		// Orc Warrior Start 7
			{ 12282, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 139, -1, EQUIPMENT_SLOT_LEGS },
			{ 140, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Orc Warrior End 12
			{ 38, -1, EQUIPMENT_SLOT_BODY },		// Dwarf Warrior Start 13
			{ 12282, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 39, -1, EQUIPMENT_SLOT_LEGS },
			{ 40, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Dwarf Warrior End 18
			{ 6120, -1, EQUIPMENT_SLOT_BODY },		// Night Elf Warrior Start 19
			{ 25, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 2362, -1, EQUIPMENT_SLOT_OFFHAND },
			{ 6121, -1, EQUIPMENT_SLOT_LEGS },
			{ 40, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Night Elf Warrior End 25
			{ 6125, -1, EQUIPMENT_SLOT_BODY },		// Undead Warrior Start 26
			{ 25, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 2362, -1, EQUIPMENT_SLOT_OFFHAND },
			{ 6121, -1, EQUIPMENT_SLOT_LEGS },
			{ 6122, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Undead Warrior End 32
			{ 6125, -1, EQUIPMENT_SLOT_BODY },		// Tauren Warrior Start 33
			{ 2361, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 139, -1, EQUIPMENT_SLOT_LEGS },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Tauren Warrior End 37
			{ 38, -1, EQUIPMENT_SLOT_BODY },		// Gnome Warrior Start 38
			{ 25, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 2362, -1, EQUIPMENT_SLOT_OFFHAND },
			{ 39, -1, EQUIPMENT_SLOT_LEGS },
			{ 40, -1, EQUIPMENT_SLOT_FEET },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Gnome Warrior End 44
			{ 6125, -1, EQUIPMENT_SLOT_BODY },		// Troll Warrior Start 45
			{ 12282, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 2362, -1, EQUIPMENT_SLOT_OFFHAND },
			{ 139, -1, EQUIPMENT_SLOT_LEGS },
			{ 25861, -1, EQUIPMENT_SLOT_RANGED },
			{ 117, -1, 23 },
			{ 6948, -1, 24 },						// Troll Warrior End 51
			{ 23473, -1, EQUIPMENT_SLOT_BODY },		// Draenei Warrior Start 52
			{ 23346, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 23474, -1, EQUIPMENT_SLOT_LEGS },
			{ 23475, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 24 },
			{ 4540, -1, 23 }						// Draenei Warrior End 57
		};

		uint32 PaladinItems[27][3] = {
			{ 45, -1, EQUIPMENT_SLOT_BODY },		// Human Paladin Start 0
			{ 2361, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 44, -1, EQUIPMENT_SLOT_LEGS },
			{ 43, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Human Paladin End 6
			{ 45, -1, EQUIPMENT_SLOT_BODY },		// Dwarf Paladin Start 7
			{ 2361, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 44, -1, EQUIPMENT_SLOT_LEGS },
			{ 43, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 },						// Dwarf Paladin End 12
			{ 24143, -1, EQUIPMENT_SLOT_BODY },		// Blood Elf Paladin Start 13
			{ 23346, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 24145, -1, EQUIPMENT_SLOT_LEGS },
			{ 24146, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 20857, -1, 25 },						// Blood Elf Paladin End 19
			{ 23476, -1, EQUIPMENT_SLOT_BODY },		// Draenei Paladin Start 20
			{ 2361, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 23477, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 }						// Draenei Paladin End 25
		};

		uint32 HunterItems[68][3] = {
			{ 127, -1, EQUIPMENT_SLOT_BODY },		// Orc Hunter Start 0
			{ 37, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 6126, -1, EQUIPMENT_SLOT_LEGS },
			{ 6127, -1, EQUIPMENT_SLOT_FEET },
			{ 2504, -1, EQUIPMENT_SLOT_RANGED },
			{ 2101, -1, 19 },
			{ 2512, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Orc Hunter End 9
			{ 148, -1, EQUIPMENT_SLOT_BODY },		// Dwarf Hunter Start 10
			{ 37, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 147, -1, EQUIPMENT_SLOT_LEGS },
			{ 129, -1, EQUIPMENT_SLOT_FEET },
			{ 2508, -1, EQUIPMENT_SLOT_RANGED },
			{ 2102, -1, 19 },
			{ 2516, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 117, -1, 25 },						// Dwarf Hunter End 19
			{ 148, -1, EQUIPMENT_SLOT_BODY },		// Night Elf Hunter Start 20
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 147, -1, EQUIPMENT_SLOT_LEGS },
			{ 129, -1, EQUIPMENT_SLOT_FEET },
			{ 2504, -1, EQUIPMENT_SLOT_RANGED },
			{ 2101, -1, 19 },
			{ 2512, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 117, -1, 25 },						// Night Elf Hunter End 29
			{ 127, -1, EQUIPMENT_SLOT_BODY },		// Tauren Hunter Start 30
			{ 37, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 6126, -1, EQUIPMENT_SLOT_LEGS },
			{ 2508, -1, EQUIPMENT_SLOT_RANGED },
			{ 2102, -1, 19 },
			{ 2516, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Tauren Hunter End 38
			{ 127, -1, EQUIPMENT_SLOT_BODY },		// Troll Hunter Start 39
			{ 37, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 6126, -1, EQUIPMENT_SLOT_LEGS },
			{ 2504, -1, EQUIPMENT_SLOT_RANGED },
			{ 2101, -1, 19 },
			{ 2512, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Troll Hunter End 47
			{ 23345, -1, EQUIPMENT_SLOT_BODY },		// Draenei Hunter Start 48
			{ 25, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 23344, -1, EQUIPMENT_SLOT_LEGS },
			{ 23348, -1, EQUIPMENT_SLOT_FEET },
			{ 23347, -1, EQUIPMENT_SLOT_RANGED },
			{ 2101, -1, 19 },
			{ 2512, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 },						// Draenei Hunter End 57
			{ 20901, -1, EQUIPMENT_SLOT_BODY },		// Blood Elf Hunter Start 58
			{ 20899, -1, EQUIPMENT_SLOT_LEGS },
			{ 20900, -1, EQUIPMENT_SLOT_FEET },
			{ 20982, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 20980, -1, EQUIPMENT_SLOT_RANGED },
			{ 2101, -1, 19 },
			{ 2512, 19, 0 },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 20857, -1, 25 }						// Blood Elf Hunter End 67
		};

		uint32 RogueItems[56][3] = {
			{ 49, -1, EQUIPMENT_SLOT_BODY },		// Human Rogue Start 0
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 48, -1, EQUIPMENT_SLOT_LEGS },
			{ 47, -1, EQUIPMENT_SLOT_FEET },
			{ 28979, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 2070, -1, 24 },						// Human Rogue End 6
			{ 2105, -1, EQUIPMENT_SLOT_BODY },		// Orc Rogue Start 7
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 120, -1, EQUIPMENT_SLOT_LEGS },
			{ 121, -1, EQUIPMENT_SLOT_FEET },
			{ 25861, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 2070, -1, 24 },						// Orc Rogue End 13
			{ 49, -1, EQUIPMENT_SLOT_BODY },		// Dwarf Rogue Start 14
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 48, -1, EQUIPMENT_SLOT_LEGS },
			{ 47, -1, EQUIPMENT_SLOT_FEET },
			{ 25861, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 117, -1, 24 },						// Dwarf Rogue End 20
			{ 2105, -1, EQUIPMENT_SLOT_BODY },		// Undead Rogue Start 21
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 120, -1, EQUIPMENT_SLOT_LEGS },
			{ 121, -1, EQUIPMENT_SLOT_FEET },
			{ 28979, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 2070, -1, 24 },						// Undead Rogue End 27
			{ 49, -1, EQUIPMENT_SLOT_BODY },		// Night Elf Rogue Start 28
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 48, -1, EQUIPMENT_SLOT_LEGS },
			{ 47, -1, EQUIPMENT_SLOT_FEET },
			{ 28979, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 4540, -1, 24 },						// Night Elf Rogue End 34
			{ 49, -1, EQUIPMENT_SLOT_BODY },		// Gnome Rogue Start 35
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 48, -1, EQUIPMENT_SLOT_LEGS },
			{ 47, -1, EQUIPMENT_SLOT_FEET },
			{ 28979, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 117, -1, 24 },						// Gnome Rogue End 41
			{ 2105, -1, EQUIPMENT_SLOT_BODY },		// Troll Rogue Start 42
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 120, -1, EQUIPMENT_SLOT_LEGS },
			{ 121, -1, EQUIPMENT_SLOT_FEET },
			{ 25861, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 2070, -1, 24 },						// Troll Rogue End 48
			{ 20897, -1, EQUIPMENT_SLOT_BODY },		// Blood Elf Rogue Start 49
			{ 20982, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 20896, -1, EQUIPMENT_SLOT_LEGS },
			{ 20898, -1, EQUIPMENT_SLOT_FEET },
			{ 25861, -1, EQUIPMENT_SLOT_RANGED },
			{ 6948, -1, 23 },
			{ 20857, -1, 24 }						// Blood Elf Rogue End 55
		};

		uint32 PriestItems[54][3] = {
			{ 6098, -1, EQUIPMENT_SLOT_CHEST },		// Human Priest Start 0
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 51, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Human Priest End 7
			{ 6098, -1, EQUIPMENT_SLOT_CHEST },		// Dwarf Priest Start 8
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 51, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 },						// Dwarf Priest End 15
			{ 6144, -1, EQUIPMENT_SLOT_CHEST },		// Undead Priest Start 16
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 51, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 },						// Undead Priest End 23
			{ 6119, -1, EQUIPMENT_SLOT_CHEST },		// Night Elf Priest Start 24
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 51, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Night Elf Priest End 31
			{ 6144, -1, EQUIPMENT_SLOT_CHEST },		// Troll Priest Start 32
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 },						// Troll Priest End 38
			{ 20891, -1, EQUIPMENT_SLOT_CHEST },	// Blood Elf Priest Start 39
			{ 53, -1, EQUIPMENT_SLOT_BODY },
			{ 20981, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 52, -1, EQUIPMENT_SLOT_LEGS },
			{ 51, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 20857, -1, 25 },						// Blood Elf Priest End 46
			{ 23322, -1, EQUIPMENT_SLOT_CHEST },	// Draenei Priest Start 47
			{ 6097, -1, EQUIPMENT_SLOT_BODY },
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 }						// Draenei Priest End 53
		};

		uint32 DeathKnightItems[21][3] = {
			{ 34652, -1, EQUIPMENT_SLOT_HEAD },		// Death Knight Start 0
			{ 34657, -1, EQUIPMENT_SLOT_NECK },
			{ 34655, -1, EQUIPMENT_SLOT_SHOULDERS },
			{ 34659, -1, EQUIPMENT_SLOT_BACK },
			{ 34650, -1, EQUIPMENT_SLOT_CHEST },
			{ 45, -1, EQUIPMENT_SLOT_BODY },		
			{ 34653, -1, EQUIPMENT_SLOT_WRISTS },
			{ 34649, -1, EQUIPMENT_SLOT_HANDS },
			{ 34651, -1, EQUIPMENT_SLOT_WAIST },
			{ 34656, -1, EQUIPMENT_SLOT_LEGS },
			{ 34648, -1, EQUIPMENT_SLOT_FEET },
			{ 34658, -1, EQUIPMENT_SLOT_FINGER1 },
			{ 38147, -1, EQUIPMENT_SLOT_FINGER2 },
			{ 34661, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 38145, -1, 19 },
			{ 38145, -1, 20 },
			{ 38145, -1, 21 },
			{ 38145, -1, 22 },
			{ 6948, -1, 23 },
			{ 4540, -1, 24 },
			{ 2946, -1, 25 }						// Death Knight End 15
		};

		uint32 ShamanItems[26][3] = {
			{ 154, -1, EQUIPMENT_SLOT_BODY },		// Orc Shaman Start 0
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 153, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Orc Shaman End 6
			{ 154, -1, EQUIPMENT_SLOT_BODY },		// Tauren Shaman Start 7
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 153, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Tauren Shaman End 12
			{ 6134, -1, EQUIPMENT_SLOT_BODY },		// Troll Shaman Start 13
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 153, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Troll Shaman End 18
			{ 23345, -1, EQUIPMENT_SLOT_BODY },		// Draenei Shaman Start 19
			{ 36, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 23344, -1, EQUIPMENT_SLOT_LEGS },
			{ 23348, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 }						// Draenei Shaman End 25
		};

		uint32 MageItems[47][3] = {
			{ 6096, -1, EQUIPMENT_SLOT_BODY },		// Human Mage Start 0
			{ 56, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1395, -1, EQUIPMENT_SLOT_LEGS },
			{ 55, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Human Mage End 6
			{ 6096, -1, EQUIPMENT_SLOT_BODY },		// Undead Mage Start 7
			{ 6140, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1395, -1, EQUIPMENT_SLOT_LEGS },
			{ 55, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Undead Mage End 14
			{ 6096, -1, EQUIPMENT_SLOT_BODY },		// Gnome Mage Start 15
			{ 56, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1395, -1, EQUIPMENT_SLOT_LEGS },
			{ 55, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4536, -1, 25 },						// Gnome Mage End 22
			{ 6096, -1, EQUIPMENT_SLOT_BODY },		// Troll Mage Start 23
			{ 6140, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1395, -1, EQUIPMENT_SLOT_LEGS },
			{ 55, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 },						// Troll Mage End 30
			{ 6096, -1, EQUIPMENT_SLOT_BODY },		// Blood Elf Mage Start 31
			{ 20893, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 20894, -1, EQUIPMENT_SLOT_LEGS },
			{ 55, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 20857, -1, 25 },						// Blood Elf Mage End 38
			{ 23473, -1, EQUIPMENT_SLOT_BODY },		// Draenei Mage Start 39
			{ 23479, -1, EQUIPMENT_SLOT_CHEST },
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 23474, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 2070, -1, 25 }						// Dranei Mage End 45
		};

		uint32 WarlockItems[40][3] = {
			{ 6097, -1, EQUIPMENT_SLOT_BODY },		// Human Warlock Start 0
			{ 57, -1, EQUIPMENT_SLOT_CHEST },
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 59, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Human Warlock End 6
			{ 6129, -1, EQUIPMENT_SLOT_BODY },		// Orc Warlock Start 7
			{ 57, -1, EQUIPMENT_SLOT_CHEST },
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 59, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Orc Warlock End 14
			{ 6097, -1, EQUIPMENT_SLOT_BODY },		// Undead Warlock Start 15
			{ 57, -1, EQUIPMENT_SLOT_CHEST },
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 59, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Undead Warlock End 22
			{ 6097, -1, EQUIPMENT_SLOT_BODY },		// Gnome Warlock Start 23
			{ 57, -1, EQUIPMENT_SLOT_CHEST },
			{ 2092, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 59, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4604, -1, 25 },						// Gnome Warlock End 30
			{ 20892, -1, EQUIPMENT_SLOT_BODY },		// Blood Elf Warlock Start 31
			{ 6097, -1, EQUIPMENT_SLOT_CHEST },
			{ 20983, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 1396, -1, EQUIPMENT_SLOT_LEGS },
			{ 59, -1, EQUIPMENT_SLOT_FEET },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 20857, -1, 25 }						// Blood Elf Warlock End 38
		};

		uint32 DruidItems[12][3] = {
			{ 6123, -1, EQUIPMENT_SLOT_CHEST },		// Night Elf Druid Start 0
			{ 3661, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 6124, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4536, -1, 25 },						// Night Elf Druid 5
			{ 6139, -1, EQUIPMENT_SLOT_BODY },		// Tauren Druid Start 6
			{ 35, -1, EQUIPMENT_SLOT_MAINHAND },
			{ 6124, -1, EQUIPMENT_SLOT_LEGS },
			{ 6948, -1, 23 },
			{ 159, -1, 24 },
			{ 4540, -1, 25 }						// Tauren Druid End 11
		};

		// CLASS ACTIONBAR ARRAYS
		// Button | Action | Type | Misc
		uint32 WarriorActions[2][4] = {
			{ 72, 6603, 0, 0 },
			{ 73, 78, 0, 0 }
		};

		uint32 PaladinActions[3][4] = {
			{ 2, 635, 0, 0 },
			{ 0, 6603, 0, 0 },
			{ 1, 21084, 0, 0}
		};

		uint32 HunterActions[3][4] = {
			{ 2, 75, 0, 0 },
			{ 1, 2973, 0, 0 },
			{ 0, 6603, 0, 0 }
		};

		uint32 RogueActions[4][4] = {
			{ 1, 1752, 0, 0 },
			{ 2, 2098, 0, 0 },
			{ 3, 2764, 0, 0 },
			{ 0, 6603, 0, 0 }
		};

		uint32 PriestActions[3][4] = {
			{ 1, 585, 0, 0 },
			{ 2, 2050, 0, 0 },
			{ 0, 6603, 0, 0 }
		};

		uint32 DeathKnightActions[5][4] = {
			{ 0, 6603, 0, 0 },
			{ 1, 41230, 0, 0 },
			{ 2, 45462, 0, 0 },
			{ 3, 0, 0, 0 },
			{ 4, 0, 0, 0 }
		};

		// ENGAGE TO HYPERSWITCH FOR CLASS SPELLS
		int k;		// Class item start handler
		int kend;	// Class item end handler
		//int l;		// Race actionbar handler
		//int m;		// Class actionbar handler

		switch(Class)
		{
		case WARRIOR:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(WarriorSpells[i]);
			for(int j = 0; j < 11; j++)
				pPlayer->_AddSkillLine(WarriorSkills[j][0], WarriorSkills[j][1], WarriorSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 7;
					//for(m = 0; m < 2; m++)
						//pPlayer->setAction(HumanActions[m][0], HumanActions[m][1], HumanActions[m][2], HumanActions[m][3]);
					break;
				case RACE_ORC:
					k = 7;
					kend = 14;
					break;
				case RACE_DWARF:
					k = 13;
					kend = 19;
					break;
				case RACE_NIGHTELF:
					k = 19;
					kend = 26;
					break;
				case RACE_UNDEAD:
					k = 26;
					kend = 32;
					break;
				case RACE_TAUREN:
					k = 32;
					kend = 38;
					break;
				case RACE_GNOME:
					k = 38;
					kend = 45;
					break;
				case RACE_TROLL:
					k = 45;
					kend = 52;
					break;
				case RACE_DRAENEI:
					k = 52;
					kend = 58;
					break;
			}
			
			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(WarriorItems[k][0], pPlayer);
					
				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, WarriorItems[k][1], WarriorItems[k][2]);
			}
			break;
		case PALADIN:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(PaladinSpells[i]);
			for(int j = 0; j < 12; j++)
				pPlayer->_AddSkillLine(PaladinSkills[j][0], PaladinSkills[j][1], PaladinSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 7;
					break;
				case RACE_DWARF:
					k = 7;
					kend = 13;
					break;
				case RACE_BLOODELF:
					k = 13;
					kend = 18;
					break;
				case RACE_DRAENEI:
					k = 18;
					kend = 25;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(PaladinItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}

					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, PaladinItems[k][1], PaladinItems[k][2]);
			}
			break;
		case HUNTER:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(HunterSpells[i]);
			for(int j = 0; j < 9; j++)
				pPlayer->_AddSkillLine(HunterSkills[j][0], HunterSkills[j][1], HunterSkills[j][2]);

			switch(Race)
			{
				case RACE_ORC:
					k = 0;
					kend = 10;
					break;
				case RACE_DWARF:
					k = 10;
					kend = 20;
					break;
				case RACE_NIGHTELF:
					k = 20;
					kend = 30;
					break;
				case RACE_TAUREN:
					k = 30;
					kend = 39;
					break;
				case RACE_TROLL:
					k = 39;
					kend = 48;
					break;
				case RACE_DRAENEI:
					k = 48;
					kend = 58;
					break;
				case RACE_BLOODELF:
					k = 58;
					kend = 68;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(HunterItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}

					if(pItem->GetEntry() == 2516 || pItem->GetEntry() == 2512 || pItem->GetEntry() == 25861 || pItem->GetEntry() == 28979) // Add multiple of items
					{
						pItem->SetCount(200);
					}

					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, HunterItems[k][1], HunterItems[k][2]);
			}
			break;
		case ROGUE:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(RogueSpells[i]);
			for(int j = 0; j < 9; j++)
				pPlayer->_AddSkillLine(RogueSkills[j][0], RogueSkills[j][1], RogueSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 7;
					break;
				case RACE_ORC:
					k = 7;
					kend = 14;
					break;
				case RACE_DWARF:
					k = 14;
					kend = 21;
					break;
				case RACE_UNDEAD:
					k = 21;
					kend = 28;
					break;
				case RACE_NIGHTELF:
					k = 28;
					kend = 35;
					break;
				case RACE_GNOME:
					k = 35;
					kend = 42;
					break;
				case RACE_TROLL:
					k = 42;
					kend = 49;
					break;
				case RACE_BLOODELF:
					k = 49;
					kend = 56;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(RogueItems[k][0], pPlayer);

				if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
				{
					pItem->SetCount(4);
				}

				if(pItem->GetEntry() == 2516 || pItem->GetEntry() == 2512 || pItem->GetEntry() == 25861 || pItem->GetEntry() == 28979) // Add multiple of items
				{
					pItem->SetCount(200);
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, RogueItems[k][1], RogueItems[k][2]);
			}
			break;
		case PRIEST:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(PriestSpells[i]);
			for(int j = 0; j < 7; j++)
				pPlayer->_AddSkillLine(PriestSkills[j][0], PriestSkills[j][1], PriestSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 8;
					break;
				case RACE_DWARF:
					k = 8;
					kend = 15;
					break;
				case RACE_UNDEAD:
					k = 15;
					kend = 24;
					break;
				case RACE_NIGHTELF:
					k = 24;
					kend = 32;
					break;
				case RACE_TROLL:
					k = 32;
					kend = 39;
					break;
				case RACE_BLOODELF:
					k = 39;
					kend = 47;
					break;
				case RACE_DRAENEI:
					k = 47;
					kend = 54;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(PriestItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}

					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, PriestItems[k][1], PriestItems[k][2]);
			}
			break;
		case DKNIGHT:
			for(int i = 0; i < 8; i++)
				pPlayer->addSpell(DeathKnightSpells[i]);
			for(int j = 0; j < 15; j++)
				pPlayer->_AddSkillLine(DeathKnightSkills[j][0], DeathKnightSkills[j][1], DeathKnightSkills[j][2]);

			k = 0;
			kend = 21;

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(DeathKnightItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, DeathKnightItems[k][1], DeathKnightItems[k][2]);
			}
			break;
		case SHAMAN:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(ShamanSpells[i]);
			for(int j = 0; j < 10; j++)
				pPlayer->_AddSkillLine(ShamanSkills[j][0], ShamanSkills[j][1], ShamanSkills[j][2]);

			switch(Race)
			{
				case RACE_ORC:
					k = 0;
					kend = 7;
					break;
				case RACE_TAUREN:
					k = 7;
					kend = 13;
					break;
				case RACE_TROLL:
					k = 13;
					kend = 19;
					break;
				case RACE_DRAENEI:
					k = 19;
					kend = 25;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(ShamanItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}
					
					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, ShamanItems[k][1], ShamanItems[k][2]);
			}
			break;
		case MAGE:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(MageSpells[i]);
			for(int j = 0; j < 8; j++)
				pPlayer->_AddSkillLine(MageSkills[j][0], MageSkills[j][1], MageSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 7;
					break;
				case RACE_UNDEAD:
					k = 7;
					kend = 15;
					break;
				case RACE_GNOME:
					k = 15;
					kend = 23;
					break;
				case RACE_TROLL:
					k = 23;
					kend = 31;
					break;
				case RACE_BLOODELF:
					k = 31;
					kend = 39;
					break;
				case RACE_DRAENEI:
					k = 39;
					kend = 46;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(MageItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}
					
					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, MageItems[k][1], MageItems[k][2]);
			}
			break;
		case WARLOCK:
			for(int i = 0; i < 4; i++)
				pPlayer->addSpell(WarlockSpells[i]);
			for(int j = 0; j < 11; j++)
				pPlayer->_AddSkillLine(WarlockSkills[j][0], WarlockSkills[j][1], WarlockSkills[j][2]);

			switch(Race)
			{
				case RACE_HUMAN:
					k = 0;
					kend = 7;
					break;
				case RACE_ORC:
					k = 7;
					kend = 15;
					break;
				case RACE_UNDEAD:
					k = 15;
					kend = 23;
					break;
				case RACE_GNOME:
					k = 23;
					kend = 31;
					break;
				case RACE_BLOODELF:
					k = 31;
					kend = 39;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(WarlockItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
						pItem->SetCount(4);
					}
					
					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, WarlockItems[k][1], WarlockItems[k][2]);
			}
			break;
		case DRUID:
			for(int i = 0; i < 3; i++)
				pPlayer->addSpell(DruidSpells[i]);
			for(int j = 0; j < 11; j++)
				pPlayer->_AddSkillLine(DruidSkills[j][0], DruidSkills[j][1], DruidSkills[j][2]);

			switch(Race)
			{
				case RACE_NIGHTELF:
					k = 0;
					kend = 6;
					break;
				case RACE_TAUREN:
					k = 6;
					kend = 12;
					break;
			}

			for(k; k < kend; k++)
			{
				Item * pItem = objmgr.CreateItem(DruidItems[k][0], pPlayer);

				if(pItem)
				{
					if(pItem->GetEntry() == 2070 || pItem->GetEntry() == 4536 || pItem->GetEntry() == 4604 || pItem->GetEntry() == 20857 || pItem->GetEntry() == 4540 || pItem->GetEntry() == 117) // Add multiple of items
					{
							pItem->SetCount(4);
					}
					
					if(pItem->GetEntry() == 159) // Add multiple of items
					{
						pItem->SetCount(2);
					}
				}

				pPlayer->GetItemInterface()->SafeAddItem(pItem, DruidItems[k][1], DruidItems[k][2]);
			}
			break;
		default:
			{
			}
		}

		// TALENTS
		/*uint32 TalentTrees[12][3]=
		{
			{},					// 0	- NULL
			{ 256, 257, 26 },	// 1	- Warrior
			{ 594, 184, 267 },	// 2	- Paladin
			{ 50, 51, 163 },	// 3	- Hunter
			{ 25, 38, 39 },		// 4	- Rogue
			{ 56, 78, 613 },	// 5	- Priest
			{ 770, 771, 772 },	// 6	- Death Knight
			{ 373, 374, 375 },	// 7	- Shaman
			{ 6, 8, 237 },		// 8	- Mage
			{ 354, 355, 593 },	// 9	- Warlock
			{},					// 10	- NULL
			{ 574, 573, 134 }	// 11	- Druid
		};

		for (int i = 0; i < 4; i++)
		{
			if (TalentTrees[Class][i] == 0)
				break;

			pPlayer->_AddSkillLine(TalentTrees[Class][i], 1, 1);
		}*/
}

void OnFirstEnterWorld(Player * pPlayer)
{
	
	// SWITCHES
	uint8 Race = pPlayer->getRace();
	uint8 Class = pPlayer->getClass();
	uint32 Team = pPlayer->GetTeam();
	
	if(Team)
	{
		pPlayer->addSpell(669);
		pPlayer->_AdvanceSkillLine(109, 300);

	}
	else
	{
		pPlayer->addSpell(668);
		pPlayer->_AdvanceSkillLine(98, 300);
	}

	// LANGUAGES
	// Struct: SpellID | SkillID
	uint32 Languages[12][2]=
	{
		{ 0, 0 },			// 0	- NULL
		{ 0, 0 },			// 1	- HUMAN
		{ 0, 0 },			// 2	- ORC
		{ 672, 111 },		// 3	- DWARF
		{ 671, 113},		// 4	- NIGHTELF
		{ 17737, 673 },		// 5	- UNDEAD
		{ 670, 115 },		// 6	- TAUREN
		{ 7340, 313 },		// 7	- GNOME
		{ 7341, 315 },		// 8	- TROLL
		{ 0, 0 },			// 9	- NULL
		{ 913, 137 },		// 10	- BLOOD ELF
		{ 29932, 759 }		// 11	- DRAENEI
	};

	for (int i = 0; i < 2; i++)
	{
		if (Languages[Race][i] == 0 || 1 || 2 || 9)
			break;

		pPlayer->addSpell(Languages[Race][i]);
	}
		
	for (int j = 1; j < 3; j++)
	{
		if (Languages[Race][j] == 0)
			break;

		pPlayer->_AdvanceSkillLine(Languages[Race][j], 300);	
	}
}

void OnEnterWorld(Player * pPlayer)
{
	if(pPlayer->getClass() == DKNIGHT)
	{
		if(pPlayer->HasSpell(25902))
			pPlayer->removeSpell(25902, true, false, 0); // Lol bye shock-knights

		Item * pItem = objmgr.CreateItem(2946, pPlayer); // Can never be too safe
		if(!pItem)
			return;
		else
		{
			if(pPlayer->GetItemInterface()->GetItemCount(2946, false) > 0)
			{
				return;
			}
			else
			{
				if(!pPlayer->GetItemInterface()->AddItemToFreeSlot(pItem))
				{
					pPlayer->GetSession()->SendNotification("Could not add: DTG Rune Manager. No free slots. Please free up a slot and relog.");
					return;
				}
			}
		}
	}
}