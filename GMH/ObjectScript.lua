function TargetObject()
result=".go select ";    
outSAY(result);
end

function ObjectInfo()
result=".go info "; 
outSAY(result);
end

function DeleteObject()
result=".go delete ";    
outSAY(result);
end

function PlaceObject()
if ObjectNumber:GetText() == "" then
UIErrorsFrame:AddMessage("Specify an Object Number!", 1.0, 0.0, 0.0, 53, 2);
else
PlaceObjectTrue();
end
end

function PlaceObjectTrue()
if NoSaveCheck:GetChecked() then
        result=".go spawn "..ObjectNumber:GetText();
        outSAY(result)
    else
        result=".go spawn "..ObjectNumber:GetText().." 1";
        outSAY(result)
end
end
