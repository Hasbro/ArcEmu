--Molten Giant AI
function MoltenGiant_Smash(pUnit, event)
     pUnit:FullCastSpell(18944)
     pUnit:RegisterEvent("MoltenGiant_Smash", math.random(9000, 14000), 1)
end

function MoltenGiant_KnockBack(pUnit, event)
     pUnit:FullCastSpellOnTarget(18944, pUnit:GetMainTank())
     pUnit:RegisterEvent("MoltenGiant_KnockBack", math.random(12000, 18000), 1)
end

function MoltenGiant_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("MoltenGiant_Smash", math.random(9000, 14000), 1)
     pUnit:RegisterEvent("MoltenGiant_KnockBack", math.random(12000, 18000), 1)
end

RegisterUnitEvent(11658, 1, "MoltenGiant_OnEnterCombat")

function MoltenGiant_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11658, 2, "MoltenGiant_OnWipe")


--Molten Destroyer AI
function MoltenDestroyer_Tremor(pUnit, event)
     pUnit:FullCastSpell(19129)
     pUnit:RegisterEvent("MoltenDestroyer_Tremor", math.random(12000, 17000), 1)
end

function MoltenDestroyer_Knockdown(pUnit, event)
     pUnit:FullCastSpellOnTarget(20276, pUnit:GetMainTank())
     pUnit:RegisterEvent("MoltenDestroyer_Knockdown", math.random(9000, 14000), 1)
end

function MoltenDestroyer_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("MoltenDestroyer_Tremor", math.random(12000, 17000), 1)
     pUnit:RegisterEvent("MoltenDestroyer_Knockdown", math.random(9000, 14000), 1)
end

RegisterUnitEvent(11659, 1, "MoltenDestroyer_OnEnterCombat")

function MoltenDestroyer_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11659, 2, "MoltenDestroyer_OnWipe")


--Firelord
function Firelord_LavaSpawn(pUnit, event)
     local player=pUnit:GetClosestPlayer()
     pUnit:SpawnCreature(12265, player:GetX(), player:GetY(), player:GetZ(), player:GetO(), 14, 0)
end

function Firelord_Incinerate(pUnit, event)
     pUnit:FullCastSpellOnTarget(19397, pUnit:GetMainTank())
end

function Firelord_SoulBurn(pUnit, event)
     pUnit:FullCastSpellOnTarget(33913, pUnit:GetRandomPlayer(0))
     pUnit:RegisterEvent("Firelord_SoulBurn", math.random(13000, 18000), 1)
end

function Firelord_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Firelord_LavaSpawn", 20000, 0)
     pUnit:RegisterEvent("Firelord_Incinerate", 10000, 0)
     pUnit:RegisterEvent("Firelord_SoulBurn", math.random(13000, 18000), 1)
end

RegisterUnitEvent(11668, 1, "Firelord_OnEnterCombat")

function Firelord_OnWipe(pUnit, event)
    pUnit:RemoveEvents()
end

RegisterUnitEvent(11668, 2, "Firelord_OnWipe")

--Lava Spawn
function LavaSpawn_Fireball(pUnit, event)
     pUnit:FullCastSpellOnTarget(19391, pUnit:GetRandomPlayer(0))
end

function LavaSpawn_Split(pUnit, event)
     local player=pUnit:GetClosestPlayer()
     pUnit:SpawnCreature(12265, player:GetX(), player:GetY(), player:GetZ(), player:GetO(), 14, 0)
end

function LavaSpawn_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("LavaSpawn_Fireball", math.random(4000, 7000), 0)
     pUnit:RegisterEvent("LavaSpawn_Split", 20000, 0)
end

RegisterUnitEvent(12265, 1, "LavaSpawn_OnEnterCombat")

function LavaSpawn_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
     pUnit:Despawn(100, 0)
end

RegisterUnitEvent(12265, 2, "LavaSpawn_OnWipe")


--Lava Annihilator
function Annihilator_ChangeTarget(pUnit, event)
     pUnit:WipeThreatList()
     local player=pUnit:GetRandomPlayer(0)
     if player ~= nil then
     pUnit:ModThreat(player, 10000)
     end
end

function Annihilator_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Annihilator_ChangeTarget", 3000, 0)
end

RegisterUnitEvent(11665, 1, "Annihilator_OnEnterCombat")

function Annihilator_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11665, 2, "Annihilator_OnWipe")


--Ancient Core Hound
function AncientCoreHound_LavaBreath(pUnit, event)
     pUnit:FullCastSpell(19272)
     pUnit:RegisterEvent("AncientCoreHound_LavaBreath", math.random(8000, 12000), 1)
end

function AncientCoreHound_RandomSpell(pUnit, event)
     local randomspell=math.random(1, 6);
     if randomspell == 1 then
     pUnit:FullCastSpell(19369)
     return
     end

     if randomspell == 2 then
     local tbl = pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     pUnit:FullCastSpellOnTarget(19365, v)
     return
     end
     end

     if randomspell == 3 then
     pUnit:FullCastSpell(19372)
     return
     end

     if randomspell == 4 then
     pUnit:FullCastSpell(19366)
     return
     end

     if randomspell == 5 then
     pUnit:FullCastSpell(19364)
     return
     end

     if randomspell == 6 then
     local tbl = pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     pUnit:FullCastSpellOnTarget(19367, v)
     return
     end
     end
end


function AncientCoreHound_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("AncientCoreHound_LavaBreath", math.random(8000, 12000), 1)
     pUnit:RegisterEvent("AncientCoreHound_RandomSpell", math.random(13000, 18000), 0)
end

RegisterUnitEvent(11673, 1, "AncientCoreHound_OnEnterCombat")

function AncientCoreHound_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11673, 2, "AncientCoreHound_OnWipe")


--Lava Surger
function LavaSurger_MoveCheck(pUnit, event)
     pUnit:ModifyRunSpeed(8)
     pUnit:ModifyWalkSpeed(8)
     pUnit:SetCombatTargetingCapable(0)
end

function LavaSurger_Surge(pUnit, event)
     local tbl = pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     	if pUnit:GetDistance(v) > 8 then
        local players={}
        table.insert(players, v)
        local player=math.random(1, table.getn(players))
        pUnit:FullCastSpellOnTarget(19196, players[player])
        pUnit:SetCombatTargetingCapable(1)
        pUnit:ModifyRunSpeed(300)
		pUnit:ModifyWalkSpeed(300)
        pUnit:MoveTo(players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO())
        pUnit:RegisterEvent("LavaSurger_MoveCheck", 500, 1)
        end
     end
end



function LavaSurger_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("LavaSurger_Surge", math.random(14000, 18000), 0)
end

RegisterUnitEvent(12101, 1, "LavaSurger_OnEnterCombat")

function LavaSurger_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(12101, 2, "LavaSurger_OnWipe")


--Flame Imp
function FlameImp_FireNova(pUnit, event)
     pUnit:FullCastSpell(20602)
end

function FlameImp_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("FlameImp_FireNova", math.random(1500, 3500), 0)
end

RegisterUnitEvent(11669, 1, "FlameImp_OnEnterCombat")

function FlameImp_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11669, 2, "FlameImp_OnWipe")


--[[Core Hound
function CoreHound_DeathCheck(pUnit, event)
     local tbl = pUnit:GetInRangeFriends()
     for k,v in pairs(tbl) do
     	if pUnit:GetDistance(v) <= 30 then
        	if v:IsAlive() == true then
                pUnit:SetDeathState(0)
                end
        end
     end
end
     	

function CoreHound_OnDeath(pUnit, event)
     pUnit:RegisterEvent("CoreHound_DeathCheck", 10000, 1)
end

RegisterUnitEvent(11671, 4, "CoreHound_OnDeath")]]


--Lava Reaver
function LavaReaver_Cleave(pUnit, event)
     pUnit:FullCastSpellOnTarget(31043, pUnit:GetMainTank())
end

function LavaReaver_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("LavaReaver_Cleave", math.random(9000, 14000), 0)
end

RegisterUnitEvent(12100, 1, "LavaReaver_OnEnterCombat")

function LavaReaver_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(12100, 2, "LavaReaver_OnWipe")


--Lava Elemental
function LavaElemental_Pyroclast(pUnit, event)
     pUnit:FullCastSpell(19641)
     pUnit:RegisterEvent("LavaElemental_Pyroclast", math.random(14000, 19000), 1)
end

function LavaElemental_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("LavaElemental_Pyroclast", math.random(14000, 19000), 1)
end

RegisterUnitEvent(12076, 1, "LavaElemental_OnEnterCombat")

function LavaElemental_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(12076, 2, "LavaElemental_OnWipe")


--Flameguard
function Flameguard_ConeOfFire(pUnit, event)
     pUnit:FullCastSpell(19630)
     pUnit:RegisterEvent("Flameguard_ConeOfFire", math.random(13000, 17000), 1)
end

function Flameguard_MeltArmor(pUnit, event)
     pUnit:FullCastSpell(19631)
end

function Flameguard_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Flameguard_ConeOfFire", math.random(13000, 17000), 1)
     pUnit:RegisterEvent("Flameguard_MeltArmor", 12000, 0)
end

RegisterUnitEvent(11667, 1, "Flameguard_OnEnterCombat")

function Flameguard_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11667, 2, "Flameguard_OnWipe")


--[[Firewalker
function Firewalker_MeleeEnable(pUnit, event)
       pUnit:SetCombatMeleeCapable(0)
  end

function Firewalker_FireBlossum(pUnit, event)
     pUnit:SetCombatMeleeCapable(1)
     pUnit:FullCastSpell(19636)
     pUnit:RegisterEvent("Firewalker_MeleeEnable", 6000, 1)
end

function Firewalker_OnEnterCombat(pUnit, event)
     pUnit:RegisterEvent("Firewalker_FireBlossum", math.random(13000, 18000), 0)
end

RegisterUnitEvent(11666, 1, "Firewalker_OnEnterCombat")

function Firewalker_OnWipe(pUnit, event)
     pUnit:RemoveEvents()
end

RegisterUnitEvent(11667, 2, "Firewalker_OnWipe")]]