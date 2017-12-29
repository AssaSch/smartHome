#ifndef __AGENT_API_T_H__
#define __AGENT_API_T_H__

#include <string>
#include <memory>

class ConfigData_t;
class Event_t;
class HubApi_t;
 
/*************************************************/

class AgentApi_t 
{
public:
	virtual	~AgentApi_t() {};										
	// AgentApi_t() {};   using default CTOR											
	virtual void Initialize(const ConfigData_t& _confData) = 0;
	virtual void Connect(HubApi_t& _hub) = 0;
	virtual void Push(const std::shared_ptr<Event_t> _event) = 0;
	virtual void Run() = 0;
	virtual void Stop() = 0;
	//create and destroy in cpp.
	
protected:
	AgentApi_t(const AgentApi_t& _agent);
	const AgentApi_t& operator = (const AgentApi_t& _agent);
															
private:
	
};

#endif /* __AGENT_API_T_H__ */
