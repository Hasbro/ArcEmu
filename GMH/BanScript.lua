function BanPlayer()
result=".ban char "..CharName:GetText().." "..BanReason:GetText();   
outSAY(result);
end

function UnBanPlayer()
result=".unban char "..CharName:GetText();    
outSAY(result);
end

function AddIPBan()
result=".ban ip "..IPAddress1:GetText().." "..Duration1:GetText();    
outSAY(result);
end

function DelIPBan()
result=".unban ip "..IPAddress1:GetText();
outSAY(result);
end

function KickPlayer()
result=".kickplayer "..CharName:GetText().." "..BanReason:GetText();    
outSAY(result);
end

function ParPlayer()
result=".paralyze "..CharName:GetText();    
outSAY(result);
end

function UnParPlayer()
result=".unparalyze "..CharName:GetText();    
outSAY(result);
end

function PInfo()
result=".playerinfo "..CharName:GetText();    
outSAY(result);
end

