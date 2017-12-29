#ifndef __AGENT_TWO_H__
#define __AGENT_TWO_H__

#include "AgentApi_t.h"
#include <string>
#include <memory>

using namespace std;

class ConfigData_t;
class Event_t;
class HubApi_t;
 
/*************************************************/

class AgentTwo_t: public AgentApi_t
{
public:
	virtual				~AgentTwo_t();									// DTOR			
						AgentTwo_t();									// default CTOR				
	virtual void		Initialize(const ConfigData_t& _confData);
	virtual void		Connect(HubApi_t& _hub);
	virtual void		Push(const shared_ptr<Event_t> _event);
	virtual void		Run();
	virtual void		Stop();

	//create and destroy in cpp.
	
protected:
							AgentTwo_t(const AgentTwo_t& _agent);		// copy CTOR
	const AgentTwo_t&		operator = (const AgentTwo_t& _agent);		// asignment operator
															
private:
	HubApi_t* 	m_hub;
	string 		m_deviceId;
	string 		m_type;
	string		m_floor;
	string 		m_room;
	bool		m_run;
};


#endif /* __AGENT_ONE_H__ */
