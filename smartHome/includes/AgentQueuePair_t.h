#ifndef __AGENT_QUEUE_PAIR_T_H__
#define __AGENT_QUEUE_PAIR_T_H__

#include <string>
#include <memory>
 
/*************************************************/

class AgentQueuePair_t
{
public:
	~AgentQueuePair_t(){};												
	AgentQueuePair_t(AgentApi_t* _agent, std::shared_ptr<WaitQueue_t> _queue);
																			
	AgentApi_t* m_agent;
	std::shared_ptr<WaitQueue_t> m_queue;
	
protected:
	AgentQueuePair_t(const AgentQueuePair_t& _agent);	
	const AgentQueuePair_t&	operator = (const AgentQueuePair_t& _agent);		
															
private:
	
};

inline AgentQueuePair_t:: AgentQueuePair_t(AgentApi_t* _agent, std::shared_ptr<WaitQueue_t> _queue)
{	
	 m_agent = _agent;
	 m_queue = _queue;				
}


#endif /* __AGENT_QUEUE_PAIR_T_H__ */
