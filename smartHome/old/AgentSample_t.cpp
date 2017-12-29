#include "AgentSample_t.h"
#include "HubApi_t.h"
#include "EventType_t.h"
#include "Event_t.h"
#include "ConfigData_t.h"
#include <string.h>
#include <stddef.h>	// size_t 
#include <iostream>
#include <memory>
#include <unistd.h>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
AgentSample_t:: AgentSample_t()
{	

}

/********************************************************/
			//DTOR
/********************************************************/
AgentSample_t:: ~AgentSample_t()
{
	
}

/********************************************************/
			//Initialize
/********************************************************/
void AgentSample_t:: Initialize(const ConfigData_t& _confData)
{
	m_deviceId = _confData.GetDeviceId();
	m_type = _confData.GetType();
	m_floor = _confData.GetFloor();
	m_room = _confData.GetRoom();
}

/********************************************************/
			//Connect
/********************************************************/
void AgentSample_t:: Connect(HubApi_t& _hub)
{
	EventType_t eventType(m_type, m_floor, m_room);
	
	_hub.Subscribe(m_deviceId, eventType, *this);
	m_hub = &_hub;
}

/********************************************************/
			//Push
/********************************************************/
void AgentSample_t:: Push(const shared_ptr<Event_t> _event)
{
	cout << "push agent" << endl;
}

/********************************************************/
			//Connect
/********************************************************/
void AgentSample_t:: Run()
{
	shared_ptr<Event_t> event(new Event_t(m_type, m_floor, m_room, "ddd"));
	while(1)
	{
		cout << "agent run" << endl;
		m_hub->Publish(event);
		sleep(5);
	}
}

/********************************************************/
			//create
/********************************************************/
AgentSample_t* AgentSample_t:: create()
{
	return new AgentSample_t;
}


/*extern "C"
{
	AgentSample_t* create()
	{
	  return new AgentSample_t;
	}

	void destroy(AgentSample_t* p)
	{
	  delete p;  
	}
}
*/







