#ifndef __HUB_T_H__
#define __HUB_T_H__

#include "HubApi_t.h"
#include "WaitQueue_t.h"
#include "AgentHandlePair_t.h"
#include "EventType_t.h"
#include <string>
#include <map>
#include <vector>
#include <memory>

/*************************************************/

class Event_t;
class AgentApi_t;
class AgentRunner_t;
class AgentQueuePair_t;
 
/*************************************************/

class Hub_t: public HubApi_t 
{
public:
	virtual	~Hub_t();						
	Hub_t();												
	virtual void Publish(const std::shared_ptr<Event_t> _event) const;
	virtual void Subscribe(std::string _deviceId, const EventType_t& _eventType, const AgentApi_t& _agent);
	void ExitProcedure();
	void CheckForEvents();
	
protected:
	void PublishToAgents(std::shared_ptr<Event_t> _event);
	void SendEvent(std::shared_ptr<Event_t> _event, const EventType_t& _eventType);
	static void* RunThread(void* _context);
															
private:
	Hub_t(const Hub_t& _hub);		
	const Hub_t& operator = (const Hub_t& _hub);	
	
	std::multimap<EventType_t, std::string> m_subscribers;
	std::map<std::string, AgentQueuePair_t*> m_agentsQueues;
	std::vector<pthread_t> m_queueThreads;
	std::unique_ptr<WaitQueue_t> m_systemEvents;
};


#endif /* __HUB_T_H__ */
