#ifndef __AGENT_ONE_H__
#define __AGENT_ONE_H__

#include "AgentApi_t.h"
#include <string>
#include <memory>
#include "logger.h"

using namespace std;

class ConfigData_t;
class Event_t;
class HubApi_t;
 
/*************************************************/

class AgentOne_t: public AgentApi_t
{
public:
	virtual				~AgentOne_t();									// DTOR			
						AgentOne_t();									// default CTOR				
	virtual void		Initialize(const ConfigData_t& _confData);
	virtual void		Connect(HubApi_t& _hub);
	virtual void		Push(const shared_ptr<Event_t> _event);
	virtual void		Run();
	virtual void		Stop();

	//create and destroy in cpp.
	
protected:
							AgentOne_t(const AgentOne_t& _agent);		// copy CTOR
	const AgentOne_t&		operator = (const AgentOne_t& _agent);		// asignment operator
															
private:
	HubApi_t* 	m_hub;
	string 		m_deviceId;
	string 		m_type;
	string		m_floor;
	string 		m_room;
	string 		m_log;
	Logger*		m_logger;
	bool 		m_run;
};


#endif /* __AGENT_ONE_H__ */
