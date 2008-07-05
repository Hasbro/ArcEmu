<<<<<<< .working
<<<<<<< .working
/*
 * ArcEmu Failure Server
 * Copyright (C) 2008 <http://www.AscentEmu.com/>
 *
 * This program is stolen software. Please visit www.ascentemu.com
 * for the real owners of this emulator.
 * 
 * ArcEmu is a pathetic piece of software which crashes even more
 * than vanilla Ascent. And don't even put it up against Summit.
 * There's no comparison there.
 *
 * SO, why use a project run by an idiot who can't even code?
 * You don't! :D
 *
 */

//
// WorldRunnable.cpp
//

#include "StdAfx.h"
#define WORLD_UPDATE_DELAY 50

WorldRunnable::WorldRunnable() : CThread()
{

}

bool WorldRunnable::run()
{
	SetThreadName("WorldRunnable (non-instance/logon)");
	uint32 LastWorldUpdate=getMSTime();
	uint32 LastSessionsUpdate=getMSTime();

	THREAD_TRY_EXECUTION2

	while(ThreadState != THREADSTATE_TERMINATE)
	{
		// Provision for pausing this thread.
		if(ThreadState == THREADSTATE_PAUSED)
		{
			while(ThreadState == THREADSTATE_PAUSED)
			{
				Sleep(200);
			}
		}
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_BUSY;

		uint32 diff;
		//calce time passed
		uint32 now,execution_start;
		now=getMSTime();
		execution_start=now;

		if( now < LastWorldUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastWorldUpdate;
		
		LastWorldUpdate=now;
		sWorld.Update( diff );
		
		now=getMSTime();
		
		if( now < LastSessionsUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastSessionsUpdate;
		
		LastSessionsUpdate=now;
		sWorld.UpdateSessions( diff );
		
		now=getMSTime();
		//we have to wait now 
		
		if(execution_start > now)//overrun
			diff=WORLD_UPDATE_DELAY-now;
		else
			diff=now-execution_start;//time used for updating 
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_SLEEPING;

		/*This is execution time compensating system
			if execution took more than default delay 
			no need to make this sleep*/
		if(diff<WORLD_UPDATE_DELAY)
		Sleep(WORLD_UPDATE_DELAY-diff);
	}

	THREAD_HANDLE_CRASH2
	return true;
}
=======
/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2008 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//
// WorldRunnable.cpp
//

#include "StdAfx.h"
#define WORLD_UPDATE_DELAY 50

WorldRunnable::WorldRunnable() : CThread()
{

}

bool WorldRunnable::run()
{
	SetThreadName("WorldRunnable (non-instance/logon)");
	uint32 LastWorldUpdate=getMSTime();
	uint32 LastSessionsUpdate=getMSTime();

	THREAD_TRY_EXECUTION2

	while(ThreadState != THREADSTATE_TERMINATE)
	{
		// Provision for pausing this thread.
		if(ThreadState == THREADSTATE_PAUSED)
		{
			while(ThreadState == THREADSTATE_PAUSED)
			{
				Sleep(200);
			}
		}
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_BUSY;

		uint32 diff;
		//calce time passed
		uint32 now,execution_start;
		now=getMSTime();
		execution_start=now;

		if( now < LastWorldUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastWorldUpdate;
		
		LastWorldUpdate=now;
		sWorld.Update( diff );
		
		now=getMSTime();
		
		if( now < LastSessionsUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastSessionsUpdate;
		
		LastSessionsUpdate=now;
		sWorld.UpdateSessions( diff );
		
		now=getMSTime();
		//we have to wait now 
		
		if(execution_start > now)//overrun
			diff=WORLD_UPDATE_DELAY-now;
		else
			diff=now-execution_start;//time used for updating 
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_SLEEPING;

		/*This is execution time compensating system
			if execution took more than default delay 
			no need to make this sleep*/
		if(diff<WORLD_UPDATE_DELAY)
		Sleep(WORLD_UPDATE_DELAY-diff);
	}

	THREAD_HANDLE_CRASH2
	return true;
}
>>>>>>> .merge-right.r249
=======
/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2008 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//
// WorldRunnable.cpp
//

#include "StdAfx.h"
#define WORLD_UPDATE_DELAY 50

WorldRunnable::WorldRunnable() : CThread()
{

}

bool WorldRunnable::run()
{
	SetThreadName("WorldRunnable (non-instance/logon)");
	uint32 LastWorldUpdate=getMSTime();
	uint32 LastSessionsUpdate=getMSTime();

	THREAD_TRY_EXECUTION2

	while(ThreadState != THREADSTATE_TERMINATE)
	{
		// Provision for pausing this thread.
		if(ThreadState == THREADSTATE_PAUSED)
		{
			while(ThreadState == THREADSTATE_PAUSED)
			{
				Sleep(200);
			}
		}
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_BUSY;

		uint32 diff;
		//calce time passed
		uint32 now,execution_start;
		now=getMSTime();
		execution_start=now;

		if( now < LastWorldUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastWorldUpdate;
		
		LastWorldUpdate=now;
		sWorld.Update( diff );
		
		now=getMSTime();
		
		if( now < LastSessionsUpdate)//overrun
			diff=WORLD_UPDATE_DELAY;
		else
			diff=now-LastSessionsUpdate;
		
		LastSessionsUpdate=now;
		sWorld.UpdateSessions( diff );
		
		now=getMSTime();
		//we have to wait now 
		
		if(execution_start > now)//overrun
			diff=WORLD_UPDATE_DELAY-now;
		else
			diff=now-execution_start;//time used for updating 
		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		ThreadState = THREADSTATE_SLEEPING;

		/*This is execution time compensating system
			if execution took more than default delay 
			no need to make this sleep*/
		if(diff<WORLD_UPDATE_DELAY)
		Sleep(WORLD_UPDATE_DELAY-diff);
	}

	THREAD_HANDLE_CRASH2
	return true;
}
>>>>>>> .merge-right.r249
