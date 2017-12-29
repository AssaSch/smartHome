#include "AgentOne_t.h"
#include "HubApi_t.h"
#include "EventType_t.h"
#include "Event_t.h"
#include "EventTemperature_t.h"
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
AgentOne_t:: AgentOne_t()
{	
	m_run = true;
}

/********************************************************/
			//DTOR
/********************************************************/
AgentOne_t:: ~AgentOne_t()
{
	//LogClose(m_logger);
}

/********************************************************/
			//Initialize
/********************************************************/
void AgentOne_t:: Initialize(const ConfigData_t& _confData)
{
	m_deviceId = _confData.GetDeviceId();
	m_type = _confData.GetType();
	m_floor = _confData.GetFloor();
	m_room = _confData.GetRoom();
	m_log = _confData.GetLog();
	//m_logger = LogOpen("loggerOne", m_log.c_str());
}

/********************************************************/
			//Connect
/********************************************************/
void AgentOne_t:: Connect(HubApi_t& _hub)
{
	m_hub = &_hub;
}

/********************************************************/
			//Push
/********************************************************/
void AgentOne_t:: Push(const shared_ptr<Event_t> _event)
{
	cout << "push " << m_deviceId << _event->GetType() << (static_pointer_cast<EventTemperature_t>(_event))->GetTemp() << endl;
}

/********************************************************/
			//Connect
/********************************************************/
void AgentOne_t:: Run()
{
	//LOG_WRITE(m_logger, F, "run thread");
	while(m_run)
	{
	    sleep(1);
		shared_ptr<EventTemperature_t> event(new EventTemperature_t(m_type, m_floor, m_room, "ddd"));
		cout << m_deviceId << " run" << endl;
		m_hub->Publish(event);
	}
}

/********************************************************/
			//Connect
/********************************************************/
void AgentOne_t:: Stop()
{
	m_run = false;
}

/********************************************************/
			// create - destroy
/********************************************************/
extern "C"
{
	AgentOne_t* create()
	{
	  return new AgentOne_t;
	}

	void destroy(AgentOne_t* p)
	{
	  delete p;  
	}
}








