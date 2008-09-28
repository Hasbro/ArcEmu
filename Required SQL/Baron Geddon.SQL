INSERT INTO `creature_names`
  (entry, name, subname, info_str, Flags1, type, family, rank, unk4, spelldataid, male_displayid, female_displayid, male_displayid2, female_displayid2, unknown_float1, unknown_float2, civilian, leader)
VALUES
  (70100, "Unknown", "", "", 0, 7, 0, 0, 0, NULL, 0, 0, 0, 0, 1, 1, NULL, NULL);

INSERT INTO `creature_proto`
  (entry, minlevel, maxlevel, faction, minhealth, maxhealth, mana, scale, npcflags, attacktime, attacktype, mindamage, maxdamage, rangedattacktime, rangedmindamage, rangedmaxdamage, mountdisplayid, equipmodel1, equipinfo1, equipslot1, equipmodel2, equipinfo2, equipslot2, equipmodel3, equipinfo3, equipslot3, respawntime, armor, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, combat_reach, bounding_radius, auras, boss, money, invisibility_type, death_state, walk_speed, run_speed, fly_speed, extra_a9_flags)
VALUES
  (70100, 70, 70, 14, 10000000, 10000000, 100000, 1, 0, 9000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, "", 0, 0, 0, 0, 2.5, 8, 14, 0);

UPDATE `creature_proto` SET `attacktype`='2' WHERE (`entry`='12056');



