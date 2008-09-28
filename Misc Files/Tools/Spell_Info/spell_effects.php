<?php
// \/ CHANGE THIS \/
mysql_connect( "localhost" , "root" , "" );
mysql_select_db( "ascent_spell" );
// ^ CHANGE THAT ^

require "spell_effects_res.php";

if( isset( $_GET["id"] ) )
$idlist = $_GET["id"];
else
$idlist = "133";
$q = mysql_query( "SELECT *,`m_id` AS `Id`,`m_name_lang_0` AS `Name` FROM `dbc_spell` WHERE `m_id` = " . $idlist );
if( !mysql_num_rows( $q ) )
{
print "<html>
<head>
<title>Spell: None</title>
</head>
<body>
<b>Spell System</b> by Supalosa<br />
<b><font color=\"red\">Spell not found</font></b><br />
<b>Spell ID:</b> <form method=\"get\" action=\"spell_effects.php\"><input type=\"text\" name=\"id\" value=\"" . $idlist . "\" />
<input type=\"submit\" value=\"Go\" /></form><br />

";
print "</table>
</body>
</html>";
}
else
{
$r = mysql_fetch_assoc( $q );

print "<html>
<head>
<title>Spell: " . $r["Name"] . " (" . $r["Id"] . ")</title>
</head>
<body>
<b>Spell System</b> by Supalosa<br />
<b>Spell ID:</b> <form method=\"get\" action=\"spell_effects.php\"><input type=\"text\" name=\"id\" value=\"" . $idlist . "\" />
<input type=\"submit\" value=\"Go\" /></form><br />
<h2>" . $r["Name"] . "</h2>
<i>";
$dq = mysql_query( "SELECT `spellText` FROM `spell_wotlk_text` WHERE `spellId` = '" . $idlist . "'" );
if( mysql_num_rows( $dq ) )
{
	print str_replace( "\n" , "<br />" , mysql_result( $dq , 0 , 0 ) );
}
print "</i><br />
<b>Spell ID:</b> " . $r["Id"] . "<br />
";

$eff = array();



for( $i = 0 ; $i <= 2 ; $i ++ )
{
	$eff[$i] = $SPELL_EFFECTS[$r["m_effect_" . $i]];
	// extra shit
	if( $r["m_effect_" . $i] == 6 ) // apply aura
	{
		$eff[$i] .= ": " . $SPELL_AURAS[$r["m_effectAura_" . $i]] . " [" . $r["m_effectAura_" . $i] . "]<br />\n";		
	}
	else
	$eff[$i] .= "<br />\n";
	
		$eff[$i] .= "Value: " . ( $r["m_effectBasePoints_" . $i] + 1 ) . "<br />\n";
		$eff[$i] .= "Misc Value: " . $r["m_effectMiscValue_" . $i] . "<br />\n";
		if( $r["m_effectTriggerSpell_" . $i] )
		$eff[$i] .= "Trigger Spell: <a href=\"spell_effects.php?id=" . $r["m_effectTriggerSpell_" . $i] . "\">" . $r["m_effectTriggerSpell_" . $i] . "</a><br />\n";
		
}
	print "
<table width=\"100%\" border=\"1\">
	<tr>
		<td><b>Effect 1:</b></td>
		<td>" . $eff[0] . "</td>
	</tr>
	<tr>
		<td><b>Effect 2:</b></td>
		<td>" . $eff[1] . "</td>
	</tr>
	<tr>
		<td><b>Effect 3:</b></td>
		<td>" . $eff[2] . "</td>
	</tr>\n";

print "</table>
</body>
</html>";
}
// 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072
// 0 1 2 3 4 5  6   7   8   9   10   11   12   13   14    15    16    17
// we can assume that group "19" [524288] is Frost spells... although Ice lance is not part of this group for some reason.
// but ice lance is in group "17" [131072], and no other crittable Mage spells are in this, so...

// fire spells come under group 0 [1], 1[2] . 2[4] , 4 [16], 22 [4194304]

// 524288 | 131072 | 0 | 1 | 2 | 4 | 22 | 12 | 29 | 11
?>