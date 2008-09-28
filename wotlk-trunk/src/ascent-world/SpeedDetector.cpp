#include "StdAfx.h"

#ifdef EXPERIMENTAL_SPEED_DETECTOR

SpeedDetector::SpeedDetector(int p_window_size)
{
	window_size = p_window_size;
	Init();
}

SpeedDetector::SpeedDetector()
{
	window_size = SPDT_WINDOW_SIZE;
	Init();
}

SpeedDetector::~SpeedDetector()
{
	if( s_samples )
		delete s_samples;
}

void SpeedDetector::Init()
{
	s_samples = new SpeedDetectorEventHolder[window_size];
	EventSpeedChange();
}

void SpeedDetector::EventSpeedChange()
{
#ifdef _DEBUG
	printf("Speedchange Event occured prevspeed=%f\n",GetSpeed());
#endif
	next_slot = 0;
	last_x = last_y = 0;
	last_stamp = 0;
	tot_speed = 0;
	grouped_dif_x = grouped_dif_y = 0;
	values_since_reset = 0;
	memset( s_samples, 0, sizeof( SpeedDetectorEventHolder ) * window_size );
}

void SpeedDetector::AddSample(float x, float y, int stamp)
{
	if( last_stamp != 0 )
	{
		//get current speed
		float dif_x = x - last_x;
		float dif_y = y - last_y;
		grouped_dif_x += dif_x;
		grouped_dif_y += dif_y;

		int time_dif = stamp - last_stamp;
		if( time_dif <= SPDT_SAMPLINGRATE )
			return; //don't flood with calculations. Small values might get lost in calculations

		//new speed
		float dist = sqrt( grouped_dif_x*grouped_dif_x + grouped_dif_y * grouped_dif_y );
		float cur_speed = dist / (float)time_dif;

#ifdef	SPDT_DUMPPEAKVALUES
		if( cur_speed > SPDT_PEAK_SPEED )
		{
#ifdef _DEBUG
			printf("Dumping speed sample since we probably teleported curspeed=%f, timedif %d\n",cur_speed,time_dif);
#endif
			goto UPDATE_CLIENT_POS;
		}
#endif

		//check if this value is a peak value. and if we should use peak values at all
#ifdef	DUMPPEAKVALUES
		if( values_since_reset > window_size 
			&& cur_speed < tot_speed * PEAK_VALUE_PCT / window_size )
		{
#ifdef _DEBUG
			printf("Dumping speed sample since we were not moving most of the time of registration curspeed=%f, peakspped=%f, timedif %d\n",cur_speed,tot_speed * PEAK_VALUE_PCT / window_size,time_dif);
#endif
			goto UPDATE_CLIENT_POS;
		}
#endif 
		//reset grouping value
		grouped_dif_x = grouped_dif_y = 0;

		//update cached avg values
		tot_speed = tot_speed - s_samples[ next_slot ].speed + cur_speed;

		//save our values 
		s_samples[ next_slot ].speed = cur_speed;

		//cycle our index
		next_slot = ( next_slot + 1 ) % window_size;
	}
	values_since_reset++;
UPDATE_CLIENT_POS:
	last_stamp = stamp;
	last_x = x;
	last_y = y;
}

float SpeedDetector::GetSpeed()
{
	return tot_speed / (float)window_size;
}

#endif