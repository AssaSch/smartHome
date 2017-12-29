#include "AgentFour_t.h"
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
AgentFour_t:: AgentFour_t()
{	
	m_run = true;
}

/********************************************************/
			//DTOR
/********************************************************/
AgentFour_t:: ~AgentFour_t()
{
	
}

/********************************************************/
			//Initialize
/********************************************************/
void AgentFour_t:: Initialize(const ConfigData_t& _confData)
{
	m_deviceId = _confData.GetDeviceId();
	m_type = _confData.GetType();
	m_floor = _confData.GetFloor();
	m_room = _confData.GetRoom();
}

/********************************************************/
			//Connect
/********************************************************/
void AgentFour_t:: Connect(HubApi_t& _hub)
{
	//EventType_t eventType("TestFire", "1", "room_1_a");
	EventType_t eventType("TestFire", "1", "");
	
	_hub.Subscribe(m_deviceId, eventType, *this);
	m_hub = &_hub;
}

/********************************************************/
			//Push
/********************************************************/
void AgentFour_t:: Push(const shared_ptr<Event_t> _event)
{
	cout << "push " << m_deviceId << _event->GetType() << endl;
}

/********************************************************/
			//Connect
/********************************************************/
void AgentFour_t:: Run()
{
	while(m_run)
	{
		sleep(4);
		cout << m_deviceId << " run" << endl;
	}
}

/********************************************************/
			// create - destroy
/********************************************************/
extern "C"
{
	AgentFour_t* create()
	{
	  return new AgentFour_t;
	}

	void destroy(AgentFour_t* p)
	{
	  delete p;  
	}
}

/********************************************************/
			//Stop
/********************************************************/
void AgentFour_t:: Stop()
{
	m_run = false;
}







