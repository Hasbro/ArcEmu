function LatencyDisplay_OnLoad()
	LATENCYDISPLAY_LOW_LATENCY = 150;
	LATENCYDISPLAY_MEDIUM_LATENCY = 250;
	LATENCYDISPLAY_UPDATE_INTERVAL = 1;
	this.updateInterval = 0;
end

function LatencyDisplay_OnUpdate()
	if (this.updateInterval > 0) then
		this.updateInterval = this.updateInterval - arg1;
	else
		this.updateInterval = LATENCYDISPLAY_UPDATE_INTERVAL;
		local bandwidthIn, bandwidthOut, latency = GetNetStats();
		if (latency > LATENCYDISPLAY_MEDIUM_LATENCY) then
			LatencyDisplay_Text:SetTextColor(1, 0, 0);									
		elseif (latency > LATENCYDISPLAY_LOW_LATENCY) then
			LatencyDisplay_Text:SetTextColor(1, 1, 0);
		else
			LatencyDisplay_Text:SetTextColor(0, 1, 0);
		end
		if (latency > 9999) then
			LatencyDisplay_Text:SetText("Latency: HIGH");
		else
			LatencyDisplay_Text:SetText("Latency: "..latency.." ms");
		end
	end

end




