#ifndef __AGENT_SAMPLE_T_H__
#define __AGENT_SAMPLE_T_H__

#include "AgentApi_t.h"
#include <string>
#include <memory>

using namespace std;

class ConfigData_t;
class Event_t;
class HubApi_t;
 
/*************************************************/

class AgentSample_t: public AgentApi_t
{
public:
	virtual				~AgentSample_t();									// DTOR			
						AgentSample_t();									// default CTOR				
	virtual void		Initialize(const ConfigData_t& _confData);
	virtual void		Connect(HubApi_t& _hub);
	virtual void		Push(const shared_ptr<Event_t> _event);
	virtual void		Run();
	static AgentSample_t* create();
	//create and destroy in cpp.
	
protected:
							AgentSample_t(const AgentSample_t& _agent);		// copy CTOR
	const AgentSample_t&	operator = (const AgentSample_t& _agent);		// asignment operator
															
private:
	HubApi_t* 	m_hub;
	string 		m_deviceId;
	string 		m_type;
	string		m_floor;
	string 		m_room;
};


#endif /* __AGENT_API_T_H__ */
