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

RegisterUnitEvent(12056,1,"BGeddon_OnCombat")
RegisterUnitEvent(12056,2,"BGeddon_OnWipe")
RegisterUnitEvent(12056,4,"BGeddon_OnDied")

function BGeddon_OnCombat(Unit,event)
	Unit:RegisterEvent("BGeddon_LivingBomb",math.random(22000,30000), 0)
	Unit:RegisterEvent("BGeddon_Amargeddon", 1000, 0)
end
function BGeddon_OnWipe(Unit,event)
	Unit:RemoveEvents()
end
function BGeddon_OnDied(Unit,event)
	Unit:RemoveEvents()
end

function BGeddon_LivingBombBoom(Unit,event)
	local args=getvars(Unit)
	if args.livingbombtarget:HasAura(20475) == true then
		Unit:SpawnCreature(70100, args.livingbombtarget:GetX(), args.livingbombtarget:GetY(), args.livingbombtarget:GetZ(), 90, 14, 0)
	end
end

function BGeddon_LivingBomb(Unit)
	setvars(Unit, {livingbombtarget = Unit:GetRandomPlayer(0)})
	local args=getvars(Unit)
	if args.livingbombtarget ~= nil then
		Unit:FullCastSpellOnTarget(20475, args.livingbombtarget)
		Unit:RegisterEvent("BGeddon_LivingBombBoom", 7900, 1)
	end
end
function BGeddon_Amargeddon(Unit,event)
	if Unit:GetHealthPct() <= 2 then
		Unit:FullCastSpell(20478)
	end
end

function LivingBomb(Unit, event)
	Unit:DisableRespawn(1)
	Unit:CastSpell(20476)
	Unit:Despawn(10, 0)
end

RegisterUnitEvent(70100, 18, "LivingBomb")