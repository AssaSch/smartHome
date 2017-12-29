#include "SafeQueue_t.h"

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
Hub_t:: Hub_t(): m_events(new SafeQueue_t), m_agentRunner(new AgentRunner_t)
{	

}

/********************************************************/
			//DTOR
/********************************************************/
Hub_t:: ~Hub_t()
{
	
}


/********************************************************/
			//Publish
/********************************************************/
void Hub_t:: Publish(const shared_ptr<Event_t> _event) const
{
	m_events->Push(_event);
}

/********************************************************/
			//Publish
/********************************************************/
void Hub_t:: Subscribe(AgentApi_t& _agent, EventType_t& _eventType)
{
	m_subscribers.insert(pair<EventType_t, AgentApi_t*>(_eventType, &_agent));
}















