function Ragnaros_WrathOfRag(pUnit, event)
     pUnit:PlaySoundToSet(8047)
     pUnit:SendChatMessage(14, 0, "Taste the flames of Sulfuron!")
     pUnit:FullCastSpellOn(20566)
end

function Ragnaros_HandOfRag(pUnit, event)
     pUnit:PlaySoundToSet(8046)
     pUnit:SendChatMessage(14, 0, "By fire be purged!")
     pUnit:FullCastSpellOnTarget(19780, pUnit:GetRandomPlayer(4))
end

function Ragnaros_ElementalFire(pUnit, event)
     pUnit:FullCastSpellOnTarget(20564, pUnit:GetMainTank())
end

function Ragnaros_MagmaBlast(pUnit, event)
     if pUnit:GetDistance(pUnit:GetClosestPlayer()) > 54 then
     local tbl=pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
     	local players={}
        if v:IsAlive() == true then
           table.insert(players, v)
           local player=math.random(1, table.getn(players))          
           pUnit:FullCastSpellOnTarget(20565, players[player])
        end
     end
     end
end

function Rag_Emerge(pUnit, event)
     pUnit:RemoveEvents()
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, 0)
     pUnit:Root()
     pUnit:RegisterEvent("Ragnaros_WrathOfRag", 30000, 0)
     pUnit:RegisterEvent("Ragnaros_HandOfRag", math.random(20000, 35000), 0)
     pUnit:RegisterEvent("Ragnaros_ElementalFire", 18000, 0)
     pUnit:RegisterEvent("Ragnaros_MagmaBlast", 1100, 0)
     pUnit:RegisterEvent("Ragnaros_SonsOfRag", 180000, 0)
end

function Ragnaros_EmergeAlternate(pUnit, event)
     local args=getvars(pUnit)
     if args.death == 8 then
     	setvars(pUnit, {death=nil})
        pUnit:RemoveEvents()
     	pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, 0)
     	pUnit:Root()
     	pUnit:RegisterEvent("Ragnaros_WrathOfRag", 25000, 0)
     	pUnit:RegisterEvent("Ragnaros_HandOfRag", math.random(20000, 35000), 0)
     	pUnit:RegisterEvent("Ragnaros_ElementalFire", 18000, 0)
     	pUnit:RegisterEvent("Ragnaros_MagmaBlast", 3000, 0)
     	pUnit:RegisterEvent("Ragnaros_SonsOfRag", 180000, 0)
     end
end

function Ragnaros_SonsOfRag(pUnit, event)
     pUnit:RemoveEvents()
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2)
     pUnit:RegisterEvent("Rag_Emerge", 180000, 1)
     pUnit:RegisterEvent("Ragnaros_EmergeAlternate", 1000, 0)
     pUnit:SendChatMessage(14, 0, "Come forth my servants! Defend your master!")
     local tbl=pUnit:GetInRangePlayers()
     for k,v in pairs(tbl) do
	if v:IsAlive() == true then
	local players={}
	table.insert(players, v)
	local player=math.random(1, table.getn(players))
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        pUnit:SpawnCreature(12143, players[player]:GetX(), players[player]:GetY(), players[player]:GetZ(), players[player]:GetO(), 16, 0)
        setvars(pUnit, {death=nil})
        end
    end
end

function Ragnaros_OnEnterCombat(pUnit, event)
     pUnit:Root()
     pUnit:RegisterEvent("Ragnaros_WrathOfRag", 35000, 0)
     pUnit:RegisterEvent("Ragnaros_HandOfRag", math.random(20000, 35000), 0)
     pUnit:RegisterEvent("Ragnaros_ElementalFire", 18000, 0)
     pUnit:RegisterEvent("Ragnaros_MagmaBlast", 3000, 0)
     pUnit:RegisterEvent("Ragnaros_SonsOfRag", 180000, 0)
end

RegisterUnitEvent(11502, 1, "Ragnaros_OnEnterCombat")

function Ragnaros_OnWipe(pUnit, event)
     pUnit:SetUInt32Value(UNIT_FIELD_FLAGS, 0)
     pUnit:RemoveEvents()
     local tbl=pUnit:GetInRangeFriends()
     for k,v in pairs(tbl) do
		if v:GetEntry() == 12143 then
        v:Despawn(1000, 0)
		end
     end
end

RegisterUnitEvent(11502, 2, "Ragnaros_OnWipe")

function SonOfFlame_OnDeath(pUnit, event)
     local args=getvars(pUnit)
     if args.death == nil then
     	setvars(pUnit, {death=1})
     return;
     end
     
     if args.death == 1 then
     	setvars(pUnit, {death=2})
     return;
     end

     if args.death == 2 then
     	setvars(pUnit, {death=3})
     return;
     end

     if args.death == 3 then
     	setvars(pUnit, {death=4})
     return;
     end

     if args.death == 4 then
     	setvars(pUnit, {death=5})
     return;
     end

     if args.death == 5 then
     	setvars(pUnit, {death=6})
     return
     end

     if args.death == 6 then
     	setvars(pUnit, {death=7})
     return
     end

     if args.death == 7 then
     	setvars(pUnit, {death=8})
     return
     end
end

RegisterUnitEvent(12143, 4, "SonOfFlame_OnDeath")
