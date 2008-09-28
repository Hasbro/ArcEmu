function Sulfuron_OnCombat(Unit,event)
	Unit:RegisterEvent("Sulfuron_Spells", 10000, 0)
	Unit:RegisterEvent("Sulfuron_Inspire", 15000, 0)
end

function Sulfuron_OnWipe(Unit,event)
	Unit:RemoveEvents()
end
function Sulfuron_OnDied(Unit,event)
	Unit:RemoveEvents()
end
function Sulfuron_Spells(Unit)
	local plr = Unit:GetRandomPlayer(0)
	local rand = math.random(1,3)
	if rand == 1 then
		Unit:FullCastSpell(19780)
	elseif rand == 2 then
		Unit:FullCastSpell(19978)
	elseif rand == 3  and plr ~= nil then
		Unit:FullCastSpellOnTarget(19781,plr)
	end
end
function Sulfuron_Inspire(Unit)
        local tbl=Unit:GetInRangeFriends()
	for k,v in pairs(tbl) do
		if v:GetEntry() == 11662 then
			local players={}
			table.insert(players, v)
			local player=math.random(1, table.getn(players))
			Unit:CastSpellOnTarget(19779,players[player])
		end
	end
end

RegisterUnitEvent(12098,1,"Sulfuron_OnCombat")
RegisterUnitEvent(12098,2,"Sulfuron_OnWipe")
RegisterUnitEvent(12098,4,"Sulfuron_OnDied")

--[[
	PRIESTS AI
	]]

function Sulfuron_PriestCombat(Unit,event)
	Unit:RegisterEvent("Sulfuron_PriestSpells", 10000, 0)
	Unit:RegisterEvent("Sulfuron_PriestHeal", 15000, 0)
end
function Sulfuron_PriestWipe(Unit,event)
	Unit:RemoveEvents()
end
function Sulfuron_PriestDied(Unit,event)
	Unit:RemoveEvents()
end
function Sulfuron_PriestSpells(Unit,event)
	local plr = Unit:GetRandomPlayer(0)
	local rand = math.random(1,2)
	if rand == 1 and plr ~= nil then
		Unit:CastSpell(23952,plr)
	elseif rand == 2 and plr ~= nil then
		Unit:CastSpell(20294, plr)
	end
end
function Sulfuron_PriestHeal(Unit)
	local tbl = Unit:GetInRangeFriends()
	for k,v in pairs(tbl) do
		local playerstwo={}
                table.insert(playerstwo, v)
                local playertwo=math.random(1, table.getn(playerstwo))
		Unit:FullCastSpellOnTarget(36144, playerstwo[playertwo])
	end
end

RegisterUnitEvent(11662,1,"Sulfuron_PriestCombat")
RegisterUnitEvent(11662,2,"Sulfuron_PriestWipe")
RegisterUnitEvent(11662,4,"Sulfuron_PriestDied")
