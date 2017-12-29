#include "AgentThree_t.h"
#include "HubApi_t.h"
#include "EventType_t.h"
#include "Event_t.h"
#include "EventFire_t.h"
#include "ConfigData_t.h"
#include <string.h>
#include <stddef.h>	// size_t 
#include <iostream>
#include <memory>
#include <unistd.h>
#include <signal.h>
#include <csignal>

using namespace std;

namespace
{
  volatile std::sig_atomic_t gSignalStatus = 0;
}
 
void signal_handler(int signal)
{
  gSignalStatus = signal;
}

/********************************************************/
			// default CTOR
/********************************************************/
AgentThree_t:: AgentThree_t()
{	
	m_run = true;
}

/********************************************************/
			//DTOR
/********************************************************/
AgentThree_t:: ~AgentThree_t()
{
	
}

/********************************************************/
			//Initialize
/********************************************************/
void AgentThree_t:: Initialize(const ConfigData_t& _confData)
{
	m_deviceId = _confData.GetDeviceId();
	m_type = _confData.GetType();
	m_floor = _confData.GetFloor();
	m_room = _confData.GetRoom();
}

/********************************************************/
			//Connect
/********************************************************/
void AgentThree_t:: Connect(HubApi_t& _hub)
{
	m_hub = &_hub;
}

/********************************************************/
			//Push
/********************************************************/
void AgentThree_t:: Push(const shared_ptr<Event_t> _event)
{
	cout << "push " << m_deviceId << _event->GetType() << endl;
}

/********************************************************/
			//Connect
/********************************************************/
void AgentThree_t:: Run()
{
    signal(SIGUSR2, signal_handler);
    
	while(m_run)
	{
	    if (gSignalStatus)
	    {
		    sleep(3);
		    shared_ptr<EventFire_t> event(new EventFire_t(m_type, m_floor, m_room, "ddd"));
		    cout << m_deviceId << " run" << endl;
		    m_hub->Publish(event);
		    gSignalStatus = 0;    
	    }
	}
}

/********************************************************/
			// create - destroy
/********************************************************/
extern "C"
{
	AgentThree_t* create()
	{
	  return new AgentThree_t;
	}

	void destroy(AgentThree_t* p)
	{
	  delete p;  
	}
}

/********************************************************/
			//Connect
/********************************************************/
void AgentThree_t:: Stop()
{
	m_run = false;
}







