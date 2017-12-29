#include "AgentTwo_t.h"
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
AgentTwo_t:: AgentTwo_t()
{	
	m_run = true;
}

/********************************************************/
			//DTOR
/********************************************************/
AgentTwo_t:: ~AgentTwo_t()
{
	
}

/********************************************************/
			//Initialize
/********************************************************/
void AgentTwo_t:: Initialize(const ConfigData_t& _confData)
{
	m_deviceId = _confData.GetDeviceId();
	m_type = _confData.GetType();
	m_floor = _confData.GetFloor();
	m_room = _confData.GetRoom();
}

/********************************************************/
			//Connect
/********************************************************/
void AgentTwo_t:: Connect(HubApi_t& _hub)
{
	m_hub = &_hub;
	
	EventType_t eventType1("ambient_temp", "1", "room_1_a");
	_hub.Subscribe(m_deviceId, eventType1, *this);
	
	EventType_t eventType2("TestFire", "1", "room_1_a");
	_hub.Subscribe(m_deviceId, eventType2, *this);
}

/********************************************************/
			//Push
/********************************************************/
void AgentTwo_t:: Push(const shared_ptr<Event_t> _event)
{
	cout << "push " << m_deviceId << _event->GetType() << endl;
}

/********************************************************/
			//Connect
/********************************************************/
void AgentTwo_t:: Run()
{
	while(m_run)
	{
		sleep(2);
		cout << m_deviceId << " run" << endl;
	}
}

/********************************************************/
			// create - destroy
/********************************************************/
extern "C"
{
	AgentTwo_t* create()
	{
	  return new AgentTwo_t;
	}

	void destroy(AgentTwo_t* p)
	{
	  delete p;  
	}
}

/********************************************************/
			//Connect
/********************************************************/
void AgentTwo_t:: Stop()
{
	m_run = false;
}






