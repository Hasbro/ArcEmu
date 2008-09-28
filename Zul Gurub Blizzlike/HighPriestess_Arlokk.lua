function Gong_OnActivate(pMisc, event)
     if clicked == nil then
     clicked=1;
     print "Gong_OnActivate initiated..."
     pMisc:SpawnGameObject(177371, -11501.605, -1614.630005, 41.299400, 0, 180000)
     pMisc:SpawnCreature(14515, -11506.171875, -1627.715088, 41.29725, 3.173003, 14, 0)
--     pMisc:SetUInt32Value(GAMEOBJECT_UNCLICKABLE, 1)
     end
end

RegisterGameObjectEvent(180526, 4, "Gong_OnActivate")

function Arlokk_SpawnPanther(pUnit, event)
     pUnit:SpawnCreature(15101, -11527.047852, -1646.880737, 41.299145, 3, 14, 0)
     pUnit:SpawnCreature(15101, -11527.299805, -1609.370850, 41.299145, 3, 14, 0)
end

function Arlokk_ShadowWordPain(pUnit, event)
     pUnit:FullCastSpellOnTarget(24212, pUnit:GetRandomPlayer(0))
end

function Arlokk_Gouge(pUnit, event)
     pUnit:FullCastSpellOnTarget(36862, pUnit:GetMainTank())
     pUnit:ChangeTarget(pUnit:GetAddTank())
end

function Arlokk_Ravage(pUnit, event)
     pUnit:FullCastSpellOnTarget(14515, pUnit:GetMainTank())
end

function Arlokk_Thrash(pUnit, event)
     pUnit:FullCastSpellOnTarget(3391, pUnit:GetMainTank())
end

function Arlokk_ReappearTwo(pUnit, event)
     print "Arlokk_ReappearTwo initiated..."
     pUnit:SetModel(15218)
     pUnit:SetCombatCapable(0)
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, 0)
     pUnit:FullCastSpellOnTarget(41390, pUnit:GetClosestPlayer())
     pUnit:RegisterEvent("Arlokk_ShadowWordPain", math.random(15000, 18000), 0)
     pUnit:RegisterEvent("Arlokk_Vanish", 60000, 1)
end

function Arlokk_Reappear(pUnit, event)
     print "Arlokk_Reappear initiated..."
     pUnit:SetModel(15218)
     pUnit:SetCombatCapable(0)
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, 0)
     pUnit:FullCastSpellOnTarget(41390, pUnit:GetClosestPlayer())
     pUnit:RegisterEvent("Arlokk_Gouge", math.random(16000, 20000), 0)
     pUnit:RegisterEvent("Arlokk_VanishTwo", 60000, 1)
     pUnit:RegisterEvent("Arlokk_Ravage", math.random(12000, 15000), 0)
     pUnit:RegisterEvent("Arlokk_Thrash", math.random(22000, 25000), 0)
end

function Arlokk_VanishTwo(pUnit, event)
     print "Arlokk_VanishTwo initiated..."
     pUnit:RemoveEvents()
     pUnit:SetModel(15294)
     pUnit:SetCombatCapable(1)
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE)
     pUnit:RegisterEvent("Arlokk_SpawnPanther", 5000, 0)
     pUnit:RegisterEvent("Arlokk_ReappearTwo", 30000, 1)
end

function Arlokk_Vanish(pUnit, event)
     print "Arlokk_Vanish initiated..."
     pUnit:RemoveEvents()
     pUnit:SetModel(15294)
     pUnit:SetCombatCapable(1)
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE)
     pUnit:RegisterEvent("Arlokk_SpawnPanther", 5000, 0)
     pUnit:RegisterEvent("Arlokk_Reappear", 30000, 1)
end

function Arlokk_OnEnterCombat(pUnit, event)
     pUnit:SendChatMessage(14, 0, "Bethekk, your priestess calls upon your might!")
     pUnit:SpawnCreature(15101, -11527.047852, -1646.880737, 41.299145, 3, 14, 0)
     pUnit:SpawnCreature(15101, -11527.047852, -1646.880737, 41.299145, 3, 14, 0)
     pUnit:SpawnCreature(15101, -11527.299805, 1609.370850, 41.299145, 3, 14, 0)
     pUnit:SpawnCreature(15101, -11527.299805, 1609.370850, 41.299145, 3, 14, 0)
     pUnit:RegisterEvent("Arlokk_SpawnPanther", 5000, 0)
     pUnit:RegisterEvent("Arlokk_ShadowWordPain", math.random(15000, 18000), 0)
     pUnit:RegisterEvent("Arlokk_Vanish", 60000, 1)
end

RegisterUnitEvent(14515, 1, "Arlokk_OnEnterCombat")

function Arlokk_Clickable(pUnit, event)
     clicked=nil;
end

function Arlokk_OnWipe(pUnit, event)
     if pUnit:IsAlive() == true then
     local tbl=pUnit:GetInRangeFriends()
     for k,v in pairs(tbl) do
     	if v:GetEntry() == 15101 then
        v:RemoveEvents()
        v:Despawn(1000, 0)
--      gobject:SetFloatValue(GAMEOBJECT_CLICKABLE, 1)
        end
     pUnit:RemoveEvents()
     pUnit:Despawn(1000, 0)
     pUnit:RegisterEvent("Arlokk_Clickable", 900, 1)
     end
     else
     pUnit:RemoveEvents()
     end
end

RegisterUnitEvent(14515, 2, "Arlokk_OnWipe")

function Panther_OnSpawn(pUnit, event)
     print "Panther_Spawn initiated..."
     local player=pUnit:GetClosestPlayer()
     pUnit:MoveTo(player:GetX(), player:GetY(), player:GetZ(), player:GetO())
end

RegisterUnitEvent(15101, 18, "Panther_OnSpawn")