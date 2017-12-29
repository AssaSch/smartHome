#ifndef __HUB_API_T_H__
#define __HUB_API_T_H__

#include <string>
#include <memory>

class Event_t;
class EventType_t;
class AgentApi_t;
 
/*************************************************/

class HubApi_t 
{
public:
	virtual	~HubApi_t() {};										
	HubApi_t() {};											
	virtual void Publish(const std::shared_ptr<Event_t> _event) const = 0;
	virtual void Subscribe(std::string _deviceId, const EventType_t& _eventType, const AgentApi_t& _agent) = 0;
	
protected:
															
private:
	HubApi_t(const HubApi_t& _hub);		
	const HubApi_t& operator = (const HubApi_t& _hub);
	
};


#endif /* __HUB_API_T_H__ */
