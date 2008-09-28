/*
MySQL Data Transfer
Source Host: 208.43.24.90
Source Database: world20x
Target Host: 208.43.24.90
Target Database: world20x
Date: 5/28/2008 3:49:03 PM
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for worldmap_info
-- ----------------------------
CREATE TABLE `worldmap_info` (
  `entry` int(10) unsigned NOT NULL default '0',
  `screenid` int(10) unsigned default '0',
  `type` int(10) unsigned default '0',
  `maxplayers` int(10) unsigned default '0',
  `minlevel` int(10) unsigned default '1',
  `repopx` float default '0',
  `repopy` float default '0',
  `repopz` float default '0',
  `repopentry` int(10) unsigned default '0',
  `area_name` varchar(100) character set utf8 collate utf8_unicode_ci default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `cooldown` int(10) unsigned NOT NULL default '0',
  `lvl_mod_a` int(10) unsigned NOT NULL default '0',
  `required_quest` int(10) unsigned NOT NULL default '0',
  `required_item` int(10) unsigned NOT NULL default '0',
  `heroic_keyid_1` int(30) NOT NULL default '0',
  `heroic_keyid_2` int(30) NOT NULL default '0',
  `viewingDistance` float NOT NULL default '80',
  `required_checkpoint` int(30) NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `worldmap_info` VALUES ('0', '0', '0', '0', '1', '0', '0', '0', '0', 'Eastern Kingdoms', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('1', '1', '0', '0', '1', '0', '0', '0', '1', 'Kalimdor', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('30', '30', '3', '80', '51', '0', '0', '0', '0', 'Alterac Valley', '3', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('33', '204', '2', '5', '14', '-229.49', '1576.35', '78.8909', '0', 'Shadowfang Keep', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('34', '34', '2', '5', '15', '-8769.86', '842.181', '89.8765', '0', 'The Stockades', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('35', '194', '2', '5', '1', '0', '0', '0', '0', 'Stormwind Vault - UNUSED', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('36', '36', '2', '5', '13', '-11208.4', '1673.85', '24.6245', '0', 'The Deadmines', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('43', '143', '2', '5', '13', '-753.596', '-2212.78', '21.5403', '1', 'Wailing Caverns', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('47', '188', '2', '5', '19', '-4456.7', '-1655.99', '86.1095', '1', 'Razorfen Kraul', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('48', '196', '2', '5', '19', '4252.37', '756.974', '-23.0632', '1', 'Blackfathom Deeps', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('70', '144', '2', '5', '29', '-6606.48', '-3762.19', '266.91', '0', 'Uldaman', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('90', '193', '2', '5', '23', '-5081.82', '719.549', '260.554', '0', 'Gnomeregan', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('109', '109', '2', '5', '45', '-10184.9', '-3992.84', '-109.194', '0', 'The Sunken Temple', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('129', '145', '2', '5', '30', '-4666.52', '-2536.82', '86.9671', '1', 'Razorfen Downs', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('169', '169', '0', '0', '1', '-2128.12', '-1005.89', '132.213', '169', 'EmeraldDream', '1', '0', '0', '0', '0', '0', '0', '800', '0');
INSERT INTO `worldmap_info` VALUES ('189', '42', '2', '5', '25', '2870.97', '-759.845', '160.333', '0', 'The Scarlet Monastery', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('209', '146', '2', '5', '35', '-6773.49', '-2889.77', '15.1063', '1', 'Zul\'Farrak', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('229', '189', '1', '10', '55', '-7518.19', '-1239.13', '287.243', '0', 'Blackrock Spire', '3', '120000', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('230', '103', '2', '5', '48', '-7176.63', '-937.667', '170.206', '0', 'Blackrock Depths', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('249', '61', '1', '40', '60', '-4768.61', '-3752.11', '53.4317', '1', 'Onyxia\'s Lair', '3', '432000', '0', '0', '16309', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('269', '269', '4', '5', '68', '-8770.08', '-4171.7', '-210.158', '1', 'Opening of the Dark Portal', '9', '7200', '0', '0', '0', '30635', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('289', '102', '2', '5', '53', '1282.05', '-2548.73', '85.3994', '0', 'Scholomance', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('309', '161', '1', '20', '51', '-11915.8', '-1236.43', '96.1502', '0', 'Zul\'Gurub', '3', '259200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('329', '101', '2', '5', '53', '3237.46', '-4060.6', '112.01', '0', 'Stratholme', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('349', '81', '2', '5', '36', '-1443.48', '1973.36', '85.491', '1', 'Maraudon', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('369', '369', '0', '0', '1', '0', '0', '0', '0', 'Deeprun Tram', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('389', '195', '2', '5', '8', '1818.4', '-4427.26', '-10.4478', '1', 'Ragefire Chasm', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('409', '192', '1', '40', '58', '-7510.31', '-1041.63', '180.912', '0', 'Molten Core', '3', '604800', '0', '7848', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('429', '82', '2', '5', '50', '-4278.76', '1332.49', '161.214', '1', 'Dire Maul', '3', '7200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('449', '181', '0', '0', '1', '-8761.85', '848.557', '87.8052', '0', 'Alliance Military Barracks', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('450', '182', '0', '0', '1', '1643.36', '-4233.6', '56.1557', '1', 'Horde Military Barracks', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('469', '141', '1', '40', '60', '-7655.63', '-1221.93', '287.798', '0', 'Blackwing Lair', '3', '604800', '0', '7761', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('489', '489', '3', '20', '10', '0', '0', '0', '0', 'Warsong Gulch', '0', '0', '0', '0', '0', '0', '0', '120', '0');
INSERT INTO `worldmap_info` VALUES ('509', '184', '1', '20', '60', '-8134.79', '1525.9', '6.1904', '1', 'Ruins of Ahn\'Qiraj', '3', '259200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('529', '529', '3', '30', '20', '0', '0', '0', '0', 'Arathi Basin ', '0', '0', '0', '0', '0', '0', '0', '120', '0');
INSERT INTO `worldmap_info` VALUES ('530', '530', '0', '0', '58', '0', '0', '0', '530', 'Outlands', '9', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('531', '531', '1', '40', '60', '-8231.33', '2010.6', '129.861', '1', 'Temple of Ahn\'Qiraj', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('532', '532', '1', '10', '70', '-11112.9', '-2005.89', '49.3307', '0', 'Karazhan', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('533', '533', '1', '40', '60', '3005.87', '-3435.01', '293.882', '533', 'Naxxramas', '3', '604800', '0', '9122', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('534', '534', '1', '25', '70', '-8178.25', '-4184.74', '-168.4', '1', 'The Battle for Mount Hyjal', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('540', '540', '4', '5', '67', '-310.402', '3082.47', '-3.73108', '530', 'The Shattered Halls', '3', '7200', '0', '0', '0', '30637', '30622', '80', '0');
INSERT INTO `worldmap_info` VALUES ('542', '542', '4', '5', '58', '-301.116', '3161.07', '31.7029', '530', 'The Blood Furnace', '3', '7200', '9', '0', '0', '30637', '30622', '80', '0');
INSERT INTO `worldmap_info` VALUES ('543', '543', '4', '5', '58', '-362.679', '3076.29', '-15.0364', '530', 'Hellfire Ramparts', '3', '7200', '10', '0', '0', '30637', '30622', '80', '0');
INSERT INTO `worldmap_info` VALUES ('544', '544', '1', '25', '70', '-313.679', '3088.35', '-116.502', '530', 'Magtheridon\'s Lair', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('545', '545', '4', '5', '62', '816.87', '6935.02', '-80.5606', '530', 'The Steam Vaults', '3', '7200', '0', '0', '0', '30623', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('546', '546', '4', '5', '60', '777.089', '6763.45', '-72.0662', '530', 'The Underbog', '3', '7200', '7', '0', '0', '30623', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('547', '547', '4', '5', '60', '719.508', '6999.34', '-73.0743', '530', 'The Slave Pens', '3', '7200', '8', '0', '0', '30623', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('548', '548', '1', '25', '70', '783.103', '6866.53', '-65.9414', '530', 'Serpentshrine Cavern', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('550', '550', '1', '25', '70', '3087.31', '1373.79', '184.643', '530', 'Tempest Keep', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('552', '552', '4', '5', '68', '3312.09', '1331.89', '505.559', '530', 'The Arcatraz', '3', '7200', '0', '0', '0', '30634', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('553', '553', '4', '5', '68', '3365.84', '1519.15', '179.541', '530', 'The Botanica', '3', '7200', '0', '0', '0', '30634', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('554', '554', '4', '5', '68', '2863.4', '1546.33', '252.159', '530', 'The Mechanar', '3', '7200', '0', '0', '0', '30634', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('555', '555', '4', '5', '65', '-3637.51', '4940.85', '-101.047', '530', 'Shadow Labyrinth', '3', '7200', '0', '0', '0', '30633', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('556', '556', '4', '5', '64', '-3361.9', '4666.01', '-101.048', '530', 'Sethekk Halls', '3', '7200', '3', '0', '0', '30633', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('557', '557', '4', '5', '62', '-3083.3', '4942.84', '-101.048', '530', 'Mana-Tombs', '3', '7200', '6', '0', '0', '30633', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('558', '558', '4', '5', '60', '-3361.87', '5220.98', '-101.048', '530', 'Auchenai Crypts', '3', '7200', '5', '0', '0', '30633', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('560', '560', '4', '5', '62', '-8343.69', '-4057.43', '207.924', '1', 'Escape from Durnholde', '3', '7200', '0', '0', '0', '30635', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('562', '562', '3', '10', '10', '0', '0', '0', '0', 'Blade\'s Edge Arena', '0', '0', '0', '0', '0', '0', '0', '120', '0');
INSERT INTO `worldmap_info` VALUES ('564', '564', '1', '25', '70', '-3653.51', '317.493', '36.1671', '530', 'Black Temple', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('565', '565', '1', '25', '70', '3549.8', '5085.97', '2.46332', '530', 'Gruul\'s Lair', '3', '604800', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('568', '568', '1', '10', '70', '119.152', '1761.11', '42.8081', '568', 'Zul\'Aman', '3', '259200', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('13', '13', '0', '0', '1', '0', '0', '0', '0', 'Testing', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('25', '25', '0', '0', '1', '0', '0', '0', '0', 'Scott Test', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('29', '29', '0', '0', '1', '0', '0', '0', '0', 'CashTest', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('37', '37', '0', '0', '1', '0', '0', '0', '0', 'Azshara Crater', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('42', '42', '0', '0', '1', '0', '0', '0', '0', 'Collins Test', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('44', '44', '0', '0', '1', '0', '0', '0', '0', '<unused> Monastery', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('451', '451', '0', '0', '1', '0', '0', '0', '0', 'Development Land', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('582', '582', '0', '0', '1', '0', '0', '0', '0', 'Transport: Ruttheran to Auberdine', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('584', '584', '0', '0', '1', '0', '0', '0', '0', 'Transport: Menethil to Theramore', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('586', '586', '0', '0', '1', '0', '0', '0', '0', 'Transport: Exodar to Auberdine', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('587', '587', '0', '0', '1', '0', '0', '0', '0', 'Transport: Feathermoon Ferry', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('588', '589', '0', '0', '1', '0', '0', '0', '0', 'Transport: Menethil to Auberdine', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('589', '588', '0', '0', '1', '0', '0', '0', '0', 'Transport: Orgrimmar to GromGol', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('590', '590', '0', '0', '1', '0', '0', '0', '0', 'Transport: GromGol to Undercity', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('591', '591', '0', '0', '1', '0', '0', '0', '0', 'Transport: Undercity to Orgrimmar', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('593', '593', '0', '0', '1', '0', '0', '0', '0', 'Transport: Booty Bay to Ratchet', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('566', '566', '3', '30', '61', '0', '0', '0', '0', 'Eye of the Storm', '0', '0', '0', '0', '0', '0', '0', '120', '0');
INSERT INTO `worldmap_info` VALUES ('571', '216', '0', '0', '1', '0', '0', '0', '0', 'Northrend', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('572', '217', '4', '10', '1', '0', '0', '0', '0', 'Ruins of Lordaeron', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('573', '0', '0', '0', '1', '0', '0', '0', '0', 'ExteriorTest', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('574', '220', '1', '0', '1', '0', '0', '0', '0', 'Utgarde Keep', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('575', '221', '1', '0', '1', '0', '0', '0', '0', 'Utgarde Pinnacle', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('576', '226', '1', '0', '1', '0', '0', '0', '0', 'The Nexus', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('578', '227', '1', '0', '1', '0', '0', '0', '0', 'The Oculus', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('592', '0', '0', '0', '1', '0', '0', '0', '0', 'Transport: Borean Tundra Test', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('594', '0', '0', '0', '1', '0', '0', '0', '0', 'Transport: Howling Fjord Sister Mercy (Quest)', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('595', '222', '1', '0', '1', '0', '0', '0', '0', 'The Culling of Stratholme', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('596', '0', '0', '0', '1', '0', '0', '0', '0', 'Transport: Naglfar', '1', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('597', '0', '0', '0', '1', '0', '0', '0', '0', 'Craig Test', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('598', '4', '1', '0', '1', '0', '0', '0', '0', 'Sunwell Fix (Unused)', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('599', '23', '1', '0', '1', '0', '0', '0', '0', 'Halls of Stone', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('600', '228', '1', '0', '1', '0', '0', '0', '0', 'Drak\'Tharon Keep', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('601', '229', '1', '0', '1', '0', '0', '0', '0', 'Azjol-Nerub', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('602', '216', '1', '0', '1', '0', '0', '0', '0', 'Halls of Lightning', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('603', '144', '1', '0', '1', '0', '0', '0', '0', 'Ulduar', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('604', '161', '1', '0', '1', '0', '0', '0', '0', 'Gun\'Drak', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('605', '21', '0', '0', '1', '0', '0', '0', '0', 'Development Land (non-weighted textures)', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('606', '21', '0', '0', '1', '0', '0', '0', '0', 'QA and DVD', '0', '0', '0', '0', '0', '0', '0', '80', '0');
INSERT INTO `worldmap_info` VALUES ('607', '0', '0', '0', '1', '0', '0', '0', '0', 'Northrend BG', '0', '0', '0', '0', '0', '0', '0', '80', '0');
