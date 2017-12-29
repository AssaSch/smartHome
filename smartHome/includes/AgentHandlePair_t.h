#ifndef __AGENT_HANDLE_PAIR_T_H__
#define __AGENT_HANDLE_PAIR_T_H__

#include <string>
 
/*************************************************/

class AgentHandlePair_t
{
public:
	~AgentHandlePair_t(){};												
	AgentHandlePair_t(AgentApi_t* _agent, void* _handle);
	AgentHandlePair_t(const AgentHandlePair_t& _agent);												
	AgentHandlePair_t& operator = (const AgentHandlePair_t& _agent);
	bool operator<(const AgentHandlePair_t& _agent) const;
	bool operator==(const AgentHandlePair_t& _agent) const;
			
	AgentApi_t* m_agent;
	void* m_handle;
	
protected:
															
private:
	
};

inline AgentHandlePair_t:: AgentHandlePair_t(AgentApi_t* _agent, void* _handle)
{	
	 m_agent = _agent;
	 m_handle = _handle;				
}

inline AgentHandlePair_t:: AgentHandlePair_t(const AgentHandlePair_t& _agent)
{	
	 m_agent = _agent.m_agent;
	 m_handle = _agent.m_handle;				
}

/********************************************************/
			// operator=
/********************************************************/
inline AgentHandlePair_t& AgentHandlePair_t:: operator=(const AgentHandlePair_t& _agent)
{
	if (this != &_agent)
	{
		 m_agent = _agent.m_agent;
	 	m_handle = _agent.m_handle;
	}
	
	return *this;
}

/********************************************************/
			// operator<
/********************************************************/
inline bool AgentHandlePair_t:: operator<(const AgentHandlePair_t& _agent) const
{
	return m_agent < _agent.m_agent ? true : false;
}

/********************************************************/
			// operator==
/********************************************************/
inline bool AgentHandlePair_t:: operator==(const AgentHandlePair_t& _agent) const
{
	if ( m_agent == _agent.m_agent &&  m_handle == _agent.m_handle)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 	

#endif /* __AGENT_HANDLE_PAIR_T_H__ */
