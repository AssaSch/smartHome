#ifndef __AGENT_RUNNER_T_H__
#define __AGENT_RUNNER_T_H__

#include <string>
#include <vector>
#include <pthread.h>
 
class AgentApi_t;
class AgentHandlePair_t;

/*************************************************/

class AgentRunner_t 
{
public:
	virtual	~AgentRunner_t();								
	AgentRunner_t();								
	void CreateThread(std::vector<AgentHandlePair_t>& _agents);
	void JoinThreads();
	static void* Run(void* _context);
	
protected:
															
private:
	AgentRunner_t(const AgentRunner_t& _agentRunner);		
	const AgentRunner_t& operator = (const AgentRunner_t& _agentRunner);			
	
	std::vector<pthread_t> m_threads;
				
};	


#endif /* __AGENT_RUNNER_T_H__ */
