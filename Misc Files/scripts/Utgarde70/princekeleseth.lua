--[[Utgarde Keep LUA Script - Made by FaKiE for PridefireGaming (www.wotlk.h0rs.com)]]--

function PrinceKeleseth_EnterCombat(pUnit, Event)
print "Prince Keleseth Encounter: Initiated."
pUnit:SendChatMessage(12,0,"Your blood is mine!")
pUnit:PlaySoundToSet(13221)
pUnit:RegisterEvent("SummonSkeletons",20000,1)
pUnit:FullCastSpellOnTarget(43667,pUnit:GetMainTank())
pUnit:RegisterEvent("Shadowbolt",6500,0)
pUnit:RegisterEvent("IceTomb",24500,0)
end

function Shadowbolt(pUnit, Event)
end

function IceTomb(pUnit, Event)
print "Prince Kelseth Encounter: Casting Ice Tomb."
pUnit:SendChatMessage(12,0,"Not so fast!")
pUnit:PlaySoundToSet(13222)
pUnit:FullCastSpellOnTarget(48400,pUnit:GetRandomPlayer(0))
end

function PrinceKeleseth_KillsTarget(pUnit, Event)
print "Prince Keleseth Encounter: Killed Target."
pUnit:SendChatMessage(12,0,"Darkness waits...")
pUnit:PlaySoundToSet(13223)
end

function PrinceKeleseth_Died(pUnit, Event)
print "Prince Keleseth Encounter: Prince Died."
pUnit:RemoveEvents()
pUnit:SendChatMessage(12,0,"I join the night...")
pUnit:PlaySoundToSet(13225)
Dead=1
end

function PrinceKeleseth_LeavingCombat(pUnit, Event)
print "Prince Keleseth Encounter: Leaving Combat."
pUnit:RemoveEvents()
end

RegisterUnitEvent (23953,1, "PrinceKeleseth_EnterCombat")
RegisterUnitEvent (23953,3, "PrinceKeleseth_KillsTarget")
RegisterUnitEvent (23953,4, "PrinceKeleseth_Died")
RegisterUnitEvent (23953,2, "PrinceKeleseth_LeavingCombat")

--[[Skeleton part]]--

function SummonSkeletons(pUnit, Event)
print "Prince Keleseth Encounter: Summoning Skeletons"
pUnit:SendChatMessage(12,0,"Not so fast!")
pUnit:PlaySoundToSet(13224)
x=pUnit:GetX()
y=pUnit:GetY()
z=pUnit:GetZ()
o=pUnit:GetO()
pUnit:SpawnCreature(23970, 162.855972, 257.979584, 42.871555, 5.539413, 14, 0)
pUnit:SpawnCreature(23970, 160.570862, 255.495850, 42.871555, 5.539413, 14, 0)
pUnit:SpawnCreature(23970, 158.031860, 252.736145, 42.871555, 5.539413, 14, 0)
pUnit:SpawnCreature(23970, 157.287201, 255.78795, 42.871555, 5.539413, 14, 0)
pUnit:SpawnCreature(23970, 159.260864, 257.934998, 42.871555, 5.539413, 14, 0)
end

function Skeletons_Spawning(pUnit,Event)
print "Prince Keleseth Encounter: Zombies Spawning"
pUnit:MoveTo(x, y, z, o)
pUnit:RegisterEvent("Decrepify",6500,1)
end

function Decrepify(pUnit, Event)
print "Prince Keleseth Encounter: Skeleton Casting Decrepify" 
pUnit:FullCastSpellOnTarget(42702,pUnit:GetMainTank())
end

function Skeletons_EnterCombat(pUnit, Event)
SkeletonDead=0
pUnit:RegisterEvent("Decrepify",6500,1)
if Ress==1 then
pUnit:FullCastSpell(21074)
end
end

function SkeletonsDied(pUnit, Event)
print "Prince Keleseth Encounter: Skeleton Died"
pUnit:RemoveEvents()
if Dead==1 then
print "Prince Keleseth Encounter: Skeleton will not be respawned since Prince is dead."
pUnit:Despawn(500,0)
elseif SkeletonDead==0 then
SkeletonDead=1
x2=pUnit:GetX()
y2=pUnit:GetY()
z2=pUnit:GetZ()
o2=pUnit:GetO()
elseif SkeletonDead==1 then
SkeletonDead=2
x3=pUnit:GetX()
y3=pUnit:GetY()
z3=pUnit:GetZ()
o3=pUnit:GetO()
elseif SkeletonDead==2 then
SkeletonDead=3
x4=pUnit:GetX()
y4=pUnit:GetY()
z4=pUnit:GetZ()
o4=pUnit:GetO()
elseif SkeletonDead==3 then
SkeletonDead=4
x5=pUnit:GetX()
y5=pUnit:GetY()
z5=pUnit:GetZ()
o5=pUnit:GetO()
elseif SkeletonDead==4 then
x6=pUnit:GetX()
y6=pUnit:GetY()
z6=pUnit:GetZ()
o6=pUnit:GetO()
pUnit:RegisterEvent("ZombiesRespawn",4000,1)
Ress=1
SkeletonDead=0
print "Prince Keleseth Encounter: Reviving Skeletons in 4000ms."
end
end

function ZombiesRespawn(pUnit, Event)
pUnit:SpawnCreature(23970, x2, y2, z2, o2, 14, 0)
pUnit:SpawnCreature(23970, x3, y3, z3, o3, 14, 0)
pUnit:SpawnCreature(23970, x4, y4, z4, o4, 14, 0)
pUnit:SpawnCreature(23970, x5, y5, z5, o5, 14, 0)
pUnit:SpawnCreature(23970, x6, y6, z6, o6, 14, 0)
end

function Skeletons_LeavingCombat(pUnit, Event)
if Dead==1 then
pUnit:RemoveEvents()
pUnit:Despawn(500,0)
elseif SkeletonDead==0 and Dead==0 then
pUnit:Despawn(500,0)
end
end

RegisterUnitEvent (23970,6, "Skeletons_Spawning")
RegisterUnitEvent (23970,1, "Skeletons_EnterCombat")
RegisterUnitEvent (23970,4, "Skeletons_Died")
RegisterUnitEvent (23970,2, "Skeletons_LeavingCombat")