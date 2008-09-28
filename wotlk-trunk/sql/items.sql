CREATE TABLE `items` (
  `entry` int(10) NOT NULL default '0',
  `class` int(10) NOT NULL default '0',
  `subclass` int(10) NOT NULL default '0',
  `field4` int(10) NOT NULL default '-1',
  `name1` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `name2` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `name3` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `name4` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `displayid` int(10) NOT NULL default '0',
  `quality` int(10) NOT NULL default '0',
  `flags` int(10) NOT NULL default '0',
  `buyprice` int(10) NOT NULL default '0',
  `sellprice` int(10) NOT NULL default '0',
  `inventorytype` int(10) NOT NULL default '0',
  `allowableclass` int(10) NOT NULL default '-1',
  `allowablerace` int(10) NOT NULL default '-1',
  `itemlevel` int(10) NOT NULL default '0',
  `requiredlevel` int(10) NOT NULL default '0',
  `RequiredSkill` int(10) NOT NULL default '0',
  `RequiredSkillRank` int(10) NOT NULL default '0',
  `RequiredSkillSubRank` int(10) NOT NULL default '0',
  `RequiredPlayerRank1` int(10) NOT NULL default '0',
  `RequiredPlayerRank2` int(10) NOT NULL default '0',
  `RequiredFaction` int(10) NOT NULL default '0',
  `RequiredFactionStanding` int(10) NOT NULL default '0',
  `unique` int(10) NOT NULL default '0',
  `maxcount` int(10) NOT NULL default '0',
  `ContainerSlots` int(10) NOT NULL default '0',
  `stat_type1` int(10) NOT NULL default '0',
  `stat_value1` int(11) NOT NULL default '0',
  `stat_type2` int(10) NOT NULL default '0',
  `stat_value2` int(11) NOT NULL default '0',
  `stat_type3` int(10) NOT NULL default '0',
  `stat_value3` int(11) NOT NULL default '0',
  `stat_type4` int(10) NOT NULL default '0',
  `stat_value4` int(11) NOT NULL default '0',
  `stat_type5` int(10) NOT NULL default '0',
  `stat_value5` int(11) NOT NULL default '0',
  `stat_type6` int(10) NOT NULL default '0',
  `stat_value6` int(11) NOT NULL default '0',
  `stat_type7` int(10) NOT NULL default '0',
  `stat_value7` int(11) NOT NULL default '0',
  `stat_type8` int(10) NOT NULL default '0',
  `stat_value8` int(11) NOT NULL default '0',
  `stat_type9` int(10) NOT NULL default '0',
  `stat_value9` int(11) NOT NULL default '0',
  `stat_type10` int(10) NOT NULL default '0',
  `stat_value10` int(11) NOT NULL default '0',
  `dmg_min1` float NOT NULL default '0',
  `dmg_max1` float NOT NULL default '0',
  `dmg_type1` int(10) NOT NULL default '0',
  `dmg_min2` float NOT NULL default '0',
  `dmg_max2` float NOT NULL default '0',
  `dmg_type2` int(10) NOT NULL default '0',
  `dmg_min3` float NOT NULL default '0',
  `dmg_max3` float NOT NULL default '0',
  `dmg_type3` int(10) NOT NULL default '0',
  `dmg_min4` float NOT NULL default '0',
  `dmg_max4` float NOT NULL default '0',
  `dmg_type4` int(10) NOT NULL default '0',
  `dmg_min5` float NOT NULL default '0',
  `dmg_max5` float NOT NULL default '0',
  `dmg_type5` int(10) NOT NULL default '0',
  `armor` int(10) NOT NULL default '0',
  `holy_res` int(10) NOT NULL default '0',
  `fire_res` int(10) NOT NULL default '0',
  `nature_res` int(10) NOT NULL default '0',
  `frost_res` int(10) NOT NULL default '0',
  `shadow_res` int(10) NOT NULL default '0',
  `arcane_res` int(10) NOT NULL default '0',
  `delay` int(10) NOT NULL default '0',
  `ammo_type` int(10) NOT NULL default '0',
  `range` float NOT NULL default '0',
  `spellid_1` int(10) NOT NULL default '0',
  `spelltrigger_1` int(10) NOT NULL default '0',
  `spellcharges_1` int(11) NOT NULL default '0',
  `spellcooldown_1` int(11) NOT NULL default '0',
  `spellcategory_1` int(10) NOT NULL default '0',
  `spellcategorycooldown_1` int(11) NOT NULL default '0',
  `spellid_2` int(10) NOT NULL default '0',
  `spelltrigger_2` int(10) NOT NULL default '0',
  `spellcharges_2` int(11) NOT NULL default '0',
  `spellcooldown_2` int(11) NOT NULL default '0',
  `spellcategory_2` int(10) NOT NULL default '0',
  `spellcategorycooldown_2` int(11) NOT NULL default '0',
  `spellid_3` int(10) NOT NULL default '0',
  `spelltrigger_3` int(10) NOT NULL default '0',
  `spellcharges_3` int(11) NOT NULL default '0',
  `spellcooldown_3` int(11) NOT NULL default '0',
  `spellcategory_3` int(10) NOT NULL default '0',
  `spellcategorycooldown_3` int(11) NOT NULL default '0',
  `spellid_4` int(10) NOT NULL default '0',
  `spelltrigger_4` int(10) NOT NULL default '0',
  `spellcharges_4` int(11) NOT NULL default '0',
  `spellcooldown_4` int(11) NOT NULL default '0',
  `spellcategory_4` int(10) NOT NULL default '0',
  `spellcategorycooldown_4` int(11) NOT NULL default '0',
  `spellid_5` int(10) NOT NULL default '0',
  `spelltrigger_5` int(10) NOT NULL default '0',
  `spellcharges_5` int(11) NOT NULL default '0',
  `spellcooldown_5` int(11) NOT NULL default '0',
  `spellcategory_5` int(10) NOT NULL default '0',
  `spellcategorycooldown_5` int(11) NOT NULL default '0',
  `bonding` int(10) NOT NULL default '0',
  `description` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `page_id` int(10) NOT NULL default '0',
  `page_language` int(10) NOT NULL default '0',
  `page_material` int(10) NOT NULL default '0',
  `quest_id` int(10) NOT NULL default '0',
  `lock_id` int(10) NOT NULL default '0',
  `lock_material` int(10) NOT NULL default '-1',
  `sheathID` int(10) NOT NULL default '0',
  `randomprop` int(30) NOT NULL default '0',
  `unk203_1` int(10) NOT NULL default '0',
  `block` int(10) NOT NULL default '0',
  `itemset` int(10) NOT NULL default '0',
  `MaxDurability` int(10) NOT NULL default '0',
  `ZoneNameID` int(10) NOT NULL default '0',
  `mapid` int(10) NOT NULL default '0',
  `bagfamily` int(10) NOT NULL default '0',
  `TotemCategory` int(10) NOT NULL default '0',
  `socket_color_1` int(10) NOT NULL default '0',
  `unk201_3` int(10) NOT NULL default '0',
  `socket_color_2` int(10) NOT NULL default '0',
  `unk201_5` int(10) NOT NULL default '0',
  `socket_color_3` int(10) NOT NULL default '0',
  `unk201_7` int(10) NOT NULL default '0',
  `socket_bonus` int(10) NOT NULL default '0',
  `GemProperties` int(10) NOT NULL default '0',
  `ItemExtendedCost` int(10) NOT NULL default '0',
  `ArenaRankRequirement` int(30) NOT NULL default '0',
  `ReqDisenchantSkill` int(10) NOT NULL default '0',
  `unk2` int(10) NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;


INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34648, 4, 4, -1, "Dread Greaves", "", "", "", 49733, 2, 0, 0, 0, 8, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 10, 3, 7, 7, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34649, 4, 4, -1, "Gauntlets of Suffering", "", "", "", 49731, 2, 0, 0, 0, 10, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 15, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 356, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34650, 4, 4, -1, "Breastplate of Anguish", "", "", "", 49735, 2, 0, 0, 0, 5, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 20, 7, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 570, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34651, 4, 4, -1, "Exhumed Girdle", "", "", "", 49737, 2, 0, 0, 0, 6, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34652, 4, 4, -1, "Doomsday Skullcap", "", "", "", 49736, 2, 0, 0, 0, 1, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 15, 7, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 463, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34653, 4, 4, -1, "Hyperion Vambraces", "", "", "", 49740, 2, 0, 0, 0, 9, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 7, 7, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 249, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34655, 4, 4, -1, "Overlord's Pauldrons", "", "", "", 49876, 2, 0, 0, 0, 3, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 11, 3, 9, 7, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 427, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34657, 3, -1, -1, "Choker of Damnation", "", "", "", 6539, 2, 0, 0, 0, 2, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 9, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34658, 3, -1, -1, "Plague Band", "", "", "", 963, 2, 0, 0, 0, 11, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 11, 7, 4, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34659, 4, 1, -1, "Cloak of Malice", "", "", "", 49738, 2, 0, 0, 0, 16, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 12, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34661, 2, 8, -1, "Massacre Sword", "", "", "", 49742, 3, 0, 0, 0, 17, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3100, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (34689, 9, 10, -1, "Design: Chaotic Skyfire Diamond", "", "", "", 6270, 3, 64, 120000, 30000, 0, -1, -1, 73, 0, 755, 365, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44793, 0, -1, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 1, "", 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (38145, 4, 4, -1, "Harbinger Legplates", "", "", "", 49732, 2, 0, 0, 0, 7, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 13, 3, 10, 7, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 499, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `items`
  (entry, class, subclass, field4, name1, name2, name3, name4, displayid, quality, flags, buyprice, sellprice, inventorytype, allowableclass, allowablerace, itemlevel, requiredlevel, RequiredSkill, RequiredSkillRank, RequiredSkillSubRank, RequiredPlayerRank1, RequiredPlayerRank2, RequiredFaction, RequiredFactionStanding, `unique`, maxcount, ContainerSlots, stat_type1, stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, dmg_min3, dmg_max3, dmg_type3, dmg_min4, dmg_max4, dmg_type4, dmg_min5, dmg_max5, dmg_type5, armor, holy_res, fire_res, nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, range, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, page_id, page_language, page_material, quest_id, lock_id, lock_material, sheathID, randomprop, unk203_1, block, itemset, MaxDurability, ZoneNameID, mapid, bagfamily, TotemCategory, socket_color_1, unk201_3, socket_color_2, unk201_5, socket_color_3, unk201_7, socket_bonus, GemProperties, ItemExtendedCost, ArenaRankRequirement, ReqDisenchantSkill, unk2)
VALUES
  (38147, 3, -1, -1, "Corrupted Band", "", "", "", 963, 2, 0, 0, 0, 11, -1, -1, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 11, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
