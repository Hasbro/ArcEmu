--[[
********************************
*                              *
*      The Moon Project        *
*                              *
********************************

This software is provided as free and open source by the
staff of The Moon Project, in accordance with 
the GPL license. This means we provide the software we have 
created freely and it has been thoroughly tested to work for 
the developers, but NO GUARANTEE is made it will work for you 
as well. Please give credit where credit is due, if modifying,
redistributing and/or using this software. Thank you.

Staff of Moon Project, Feb 2008
~~End of License Agreement
--Moon April 2008]]

function SunbladeMagister_OnCombat(Unit, Event)
Unit:RegisterEvent("SunbladeMagister_Frostbolt", 3000, 40)
Unit:RegisterEvent("SunbladeMagister_ArcaneNova", 3000, 40)
end

function SunbladeMagister_Frostbolt(Unit, Event)
Unit:FullCastSpellOnTarget(46035, Unit:GetRandomPlayer(1))
end

function SunbladeMagister_ArcaneNova(Unit, Event)
ArcaneFlip=math.random(1, 6)
if ArcaneFlip==1 then
Unit:FullCastSpellOnTarget(46036, Unit:GetRandomPlayer(7))
else
ArcaneFlip=nil
end
end

function SunbladeMagister_LeaveCombat(Unit, Event)
Unit:RemoveEvents()
end

function SunbladeMagister_Died(Unit, Event)
Unit:RemoveEvents()
end


RegisterUnitEvent(24685, 1, "SunbladeMagister_OnCombat")
RegisterUnitEvent(24685, 2, "SunbladeMagister_LeaveCombat")
RegisterUnitEvent(24685, 4, "SunbladeMagister_Died")