--High Priest Thekal AI.
function Thekal_MortalCleave(pUnit, event)
     pUnit:FullCastSpellOnTarget(22859, pUnit:GetMainTank())
end

function Thekal_Silence(pUnit, event)
     pUnit:FullCastSpellOnTarget(22666, pUnit:GetRandomPlayer(4))
end

function Thekal_Slash(pUnit, event)
     pUnit:FullCastSpellOnTarget(24192, pUnit:GetMainTank())
end

function Thekal_ForcePunch(pUnit, event)
     pUnit:FullCastSpellOnTarget(24189, pUnit:GetMainTank())
     pUnit:WipeThreatList()
     pUnit:ModThreat(pUnit:GetRandomPlayer(0), 1000)
end

function Thekal_PhaseTwo(pUnit, event)
     if pUnit:GetHealthPct() <= 50 then
      local tbl=pUnit:GetInRangeFriends()
        pUnit:CastSpell(24169)
        pUnit:RegisterEvent("Thekal_Slash", math.random(16000, 20000), 0)
        pUnit:RegisterEvent("Thekal_ForcePunch", math.random(26000, 32000), 0)
     end
end
        

function Thekal_OnEnterCombat(pUnit, event)
     pUnit:SendChatMessage(14, 0, "Shirvallah, fill me with your RAGE!")
     pUnit:RegisterEvent("Thekal_MortalCleave", math.random(15000, 20000), 0)
     pUnit:RegisterEvent("Thekal_Silence", math.random(16000, 22000), 0)
     pUnit:RegisterEvent("Thekal_PhaseTwo", 1000, 0)
end

RegisterUnitEvent(14509, 1, "Thekal_OnEnterCombat")

function Thekal_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(14509, 2, "Thekal_OnWipe")

function Thekal_OnDie(pUnit, event)
     pUnit:RemoveEvents()
     pUnit:RegisterEvent("Thekal_DeathCheck", 10000, 0)
end

RegisterUnitEvent(14509, 4, "Thekal_OnDie")