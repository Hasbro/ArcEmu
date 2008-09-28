--[[********************************
*                                                            *
* The LUA++ Scripting Project        *
*                                                            *
********************************

This software is provided as free and open source by the
staff of The LUA++ Scripting Project, in accordance with 
the AGPL license. This means we provide the software we have 
created freely and it has been thoroughly tested to work for 
the developers, but NO GUARANTEE is made it will work for you 
as well. Please give credit where credit is due, if modifying,
redistributing and/or using this software. Thank you.

~~End of License Agreement
-- LUA++ staff, March 26, 2008. ]]
--[[
	GEHENNAS AI
	]]
math.randomseed(os.time())

RegisterUnitEvent(12259,1,"Gehennas_OnCombat")
RegisterUnitEvent(12259,2,"Gehennas_OnWipe")
RegisterUnitEvent(12259,4,"Gehennas_OnDied")

function Gehennas_ShadowboltVolley(Unit, event)
     Unit:FullCastSpell(32963)
end

function Gehennas_OnCombat(Unit,event)
	Unit:RegisterEvent("GehennasSpells", 13000, 0)
	Unit:RegisterEvent("Gehennas_ShadowboltVolley", 20000, 0)
end
function Gehennas_OnDied(Unit,event)
	Unit:RemoveEvents()
end
function Gehennas_OnWipe(Unit,event)
	Unit:RemoveEvents()
end
	
function GehennasSpells(Unit,event)
	local rand = math.random(1,3)
	local plr = Unit:GetRandomPlayer(0)
	if rand == 1 and Unit:GetInRangePlayersCount() > 1 then
		local notmaintank=Unit:GetRandomPlayer(0)
		if notmaintank ~= Unit:GetMainTank() then
		Unit:FullCastSpellOnTarget(19729,notmaintank)
		else
		repeat
		local notmaintank=Unit:GetRandomPlayer(0)
		until notmaintank ~= Unit:GetMainTank()
		Unit:FullCastSpellOnTarget(19729, notmaintank)
		end
	elseif rand == 2 and plr ~= nil then
		Unit:CastSpellAoF(plr:GetX(),plr:GetY(),plr:GetZ(),19717)
	elseif rand == 3 then
		Unit:CastSpell(19716)
	end
end
