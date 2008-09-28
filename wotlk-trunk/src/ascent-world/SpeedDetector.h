#ifndef _SPEED_DETECTOR_H_
#define _SPEED_DETECTOR_H_

#define SPDT_WINDOW_SIZE			5		// x seconds to define a speed. Use at least a few seconds
//#define SPDT_EVENTS_PER_SECOND		2		// we get Y movement packets in 1 second
#define SPDT_SAMPLINGRATE			1000	// there is no point flooding calculations	
#define SPDT_DUMPPEAKVALUES			1		// No need to store values when player wasa standing for a while	
#define SPDT_PEAK_VALUE_PCT			0.75f	// if values is smaller then 75% of avg value then dump it as not relevant value	
#define SPDT_PEAK_SPEED				100		// do not register speed like this there was probably a teleport event

struct SpeedDetectorEventHolder
{
	SpeedDetectorEventHolder() { speed = 0; }
	float		speed;		
};

//uses a sliding window over X seconds to get avarege movement speed. 
//this can be fooled if you turn on / off speed hacking every WINDOW_SIZE interval. It's not worth alt tabbing that frequently
//This return maximum used speed client side and not actual speed ! ex : char stands still = 0 speed
class SpeedDetector
{
	public:

		SpeedDetector(int p_window_size);	//monitor speed over X sec interval
		SpeedDetector();					//default window size
		~SpeedDetector();					//not much to say about this :)
		void	EventSpeedChange();			//reset statistical values on speed change
		float	GetSpeed();					//if speed is detected then it is returned. Else 0 is returned
		void	AddSample(float x, float y, int stamp);

	private:

		void						Init();

		SpeedDetectorEventHolder	*s_samples;
		int							window_size;
		int							next_slot;
		float						last_x,last_y;
		int							last_stamp;
		float						grouped_dif_x,grouped_dif_y;
		int							values_since_reset;

		float						tot_speed;		//for speedup we keep this calculated all the time
};

#endif