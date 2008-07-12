--[[ UNIT - Western Plaguelands - Generic.lua

********************************
*                                                            *
* The Moon++ Scripting Project        *
*                                                            *
********************************

This software is provided as free and open source by the
staff of The Moon++ Scripting Project, in accordance with 
the GPL license. This means we provide the software we have 
created freely and it has been thoroughly tested to work for 
the developers, but NO GUARANTEE is made it will work for you 
as well. Please give credit where credit is due, if modifying,
redistributing and/or using this software. Thank you.

Staff of The Moon++ Scripting Project, November 2007
~~End of License Agreement

All credits for the files in this folder that are GameMonkey scripts
go to the GMScripts project, for all their hard work for the Ascent 
community.

-- Moon++ Project, November 2007 ]]

function Arajs_Phylactery (pUnit, Event)
	x = pUnit:GetX()
	y = pUnit:GetY()
	z = pUnit:GetZ()
	o = pUnit:GetO()
	pUnit:SpawnGameObject(177241, x, y, z, o, 600000)
end
RegisterUnitEvent(1852, 4, "Arajs_Phylactery")