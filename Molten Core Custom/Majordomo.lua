function Majordomo_BlastWave(pUnit, event)
     pUnit:FullCastSpell(36278)
end

function Majordomo_FireballTwo(pUnit, event)
     if player:HasAura(38010) == true then
     pUnit:FullCastSpellOnTarget(20678, players[player])
     else
     pUnit:FullCastSpellOnTarget(29925, players[player])
     end
end

function Majordomo_Fireball(pUnit, event)
     if player:HasAura(38010) == true then
     pUnit:FullCastSpellOnTarget(20678, player)
     else
     pUnit:FullCastSpellOnTarget(29925, player)
     end
end

function Majordomo_MarkOfShadow(pUnit, event)
     player=pUnit:GetRandomPlayer(0)
     if player:IsAlive() == true then
     pUnit:SendChatMessage(16, 0, "Majordomo Executus marks "..player:GetName().." for elimination!")
     pUnit:FullCastSpellOnTarget(38010, player)
     pUnit:RegisterEvent("Majordomo_Fireball", 4000, 1)
     else
     local tbl=pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     	if v:IsAlive() == true then
        players={}
        table.insert(players, v)
        player=math.random(1, table.getn(players))
        pUnit:SendChatMessage(16, 0, "Majordomo Executus marks "..players[player]:GetName().." for elimination!")
        pUnit:FullCastSpellOnTarget(38010, players[player])
        end
     end
     pUnit:RegisterEvent("Majordomo_FireballTwo", 4000, 1)
	 end
end

function Majordomo_FireballVolley(pUnit, event)
     pUnit:CastSpell(38836)
     pUnit:RegisterEvent("Majordomo_BlastWave", math.random(18000, 22000), 0)
     pUnit:RegisterEvent("Majordomo_MarkOfShadow", 11500, 0)
     pUnit:RegisterEvent("Majordomo_PhaseTwo", 60000, 1)
end

function Majordomo_PhaseTwo(pUnit, event)
     pUnit:RemoveEvents()
     pUnit:SendChatMessage(16, 0, "Majordomo Executus marks everybody for elimination!")
     local tbl=pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     	pUnit:FullCastSpellOnTarget(38010, v)
     end
     pUnit:RegisterEvent("Majordomo_FireballVolley", 10000, 1)
end

function Majordomo_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Majordomo_BlastWave", math.random(18000, 22000), 0)
     pUnit:RegisterEvent("Majordomo_MarkOfShadow", 11500, 0)
     pUnit:RegisterEvent("Majordomo_PhaseTwo", 60000, 1)
end

RegisterUnitEvent(12018, 1, "Majordomo_OnEnterCombat")

function Majordomo_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(12018, 2, "Majordomo_OnWipe")