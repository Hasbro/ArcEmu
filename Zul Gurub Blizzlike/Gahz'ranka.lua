function Gahz_Frostbreath(pUnit, event)
     pUnit:FullCastSpell(16099)
     pUnit:RegisterEvent("Gahz_Frostbreath", math.random(22000, 26000), 1)
end

function Gahz_Slam(pUnit, event)
     pUnit:FullCastSpell(24326)
end

function Gahz_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Gahz_Frostbreath", math.random(16000, 20000), 1)
     pUnit:RegisterEvent("Gahz_Slam", 25000, 0)
end

RegisterUnitEvent(15114, 1, "Gahz_OnEnterCombat")

function Gahz_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(15114, 2, "Gahz_OnWipe")

function Gahz_OnDie(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(15114, 4, "Gahz_OnDie")