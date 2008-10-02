function ModSpeed()
	result=".modify speed "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModHP()
	result=".modify hp "..ModifyEditBox:GetText();
	outSAY(result);
end

--[[function ModManaRageEnergy()
localizedClass, englishClass = UnitClass("target");
if englishClass == nil or UnitIsPlayer("target")==false then
	localizedClass, englishClass = UnitClass("player");
end
--local UnitClass("player") = UnitClass("player")
	if englishClass == "DRUID" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "HUNTER" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "MAGE" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "PALADIN" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "PRIEST" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "ROGUE" then
	result="modify energy "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "SHAMAN" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "WARLOCK" then
	result="modify mana "..ModifyEditBox:GetText();
	outSAY(result);
	elseif englishClass == "WARRIOR" then
	result="modify rage "..ModifyEditBox:GetText();
	outSAY(result);
end
end]]

function ModMana()
	result=".modify mana "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModEnergy()
	result=".modify energy "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModRage()
	result=".modify rage "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModResistance()
	result=".modify holy "..ModifyEditBox:GetText();
	outSAY(result);
    result=".modify fire "..ModifyEditBox:GetText();
	outSAY(result);
    result=".modify nature "..ModifyEditBox:GetText();
	outSAY(result);
    result=".modify frost "..ModifyEditBox:GetText();
	outSAY(result);
    result=".modify shadow "..ModifyEditBox:GetText();
	outSAY(result);
    result=".modify arcane "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModArmor()
	result=".modify armor "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModDamage()
	result=".modify damage "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModDisplay()
	result=".modify displayid "..ModifyEditBox:GetText();
	outSAY(result);
end

function Demorph()
	result=".demorph"
	outSAY(result);
end

function ModSpeed()
	result=".modify speed "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModScale()
	result=".modify scale "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModSpirit()
	result=".modify spirit "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModTP()
	result=".modify talentpoints "..ModifyEditBox:GetText();
	outSAY(result);
end

function ModFaction()
result=".modify faction "..ModifyEditBox:GetText();
outSAY(result);
end
