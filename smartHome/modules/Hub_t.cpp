#include "Hub_t.h"
#include "AgentApi_t.h"
#include "EventType_t.h"
#include "Event_t.h"
#include "WaitQueue_t.h"
#include "AgentQueuePair_t.h"
#include <string>
#include <memory>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
Hub_t:: Hub_t(): m_systemEvents(new WaitQueue_t)
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
	m_systemEvents->Push(_event);
}

/********************************************************/
			//Subscribe
/********************************************************/
void Hub_t:: Subscribe(string _deviceId, const EventType_t& _eventType, const AgentApi_t& _agent)
{	
	// subscribe device on requested event type
	m_subscribers.insert(pair<EventType_t, string>(_eventType, _deviceId));
	
	// create new thread only if new device id
	map<string,AgentQueuePair_t*>::iterator it = m_agentsQueues.find(_deviceId);
	if (it == m_agentsQueues.end())
	{
		shared_ptr<WaitQueue_t> queue(new WaitQueue_t); 
		AgentQueuePair_t* agentQueuePair = new AgentQueuePair_t((AgentApi_t*)&_agent, queue);
		m_agentsQueues.insert(pair<string, AgentQueuePair_t* >(_deviceId, agentQueuePair));
		
		pthread_t thread;
		pthread_create(&thread, NULL ,RunThread, (void*)agentQueuePair);
		m_queueThreads.insert(m_queueThreads.end(), thread);
	}
}

/********************************************************/
			//CheckForEvents
/********************************************************/
void Hub_t:: CheckForEvents()
{
	while(1)
	{
	    shared_ptr<Event_t> event;
	
	    event = m_systemEvents->Pop();
	    PublishToAgents(event);	
	}
}

/********************************************************/
			//PublishToAgents
/********************************************************/
void Hub_t:: PublishToAgents(shared_ptr<Event_t> _event)
{
	// create event type from event
	EventType_t eventTypeOne(_event->GetType(), _event->GetFloor(), _event->GetRoom());
	EventType_t eventTypeTwo(_event->GetType(), _event->GetFloor(), "");
	EventType_t eventTypeThree(_event->GetType(), "", "");
	
	// find event type in container
	SendEvent(_event, eventTypeOne);
	SendEvent(_event, eventTypeTwo);
	SendEvent(_event, eventTypeThree);
}

/********************************************************/
			//SendEvent
/********************************************************/
void Hub_t:: SendEvent(shared_ptr<Event_t> _event, const EventType_t& _eventType)
{
	// find event type in container
	multimap<EventType_t, string>::iterator iter = m_subscribers.find(_eventType);
	
	// send event to all queues subscribed for this Type
	if (iter != m_subscribers.end())
	{
		while (iter != m_subscribers.end() && iter->first == _eventType)
		{
			((m_agentsQueues.find(iter->second))->second->m_queue)->Push(_event);
			++iter;
		}
	}
}

/********************************************************/
			//RunThread
/********************************************************/
void* Hub_t:: RunThread(void* _context)
{
	AgentQueuePair_t* pair = (AgentQueuePair_t*)_context;
	shared_ptr<Event_t> event;
	
	while (1)
	{
		event = (pair->m_queue)->Pop();
		pair->m_agent->Push(event);	
	}
	
	return 0;
}

/********************************************************/
			//ExitProcedure
/********************************************************/
void Hub_t:: ExitProcedure()
{
	// join subscribers threads
	for (vector<pthread_t>::iterator it = m_queueThreads.begin(); it != m_queueThreads.end(); ++it)
	{
		pthread_cancel(*it);
		pthread_join(*it, NULL);	
	}
	
	// clean allocated memory of queues and AgentQueuePairs
	for (map<string, AgentQueuePair_t*>::iterator it = m_agentsQueues.begin(); it != m_agentsQueues.end(); ++it)
	{
		delete (it->second);
	}
}













