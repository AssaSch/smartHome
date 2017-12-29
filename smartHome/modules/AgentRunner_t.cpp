#include "AgentRunner_t.h"
#include "AgentApi_t.h"
#include "AgentHandlePair_t.h"
#include <pthread.h>
#include <string.h>


using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
AgentRunner_t:: AgentRunner_t()
{	
	
}

/********************************************************/
			// DTOR
/********************************************************/
AgentRunner_t:: ~AgentRunner_t()
{
	
}

/********************************************************/
			//CreateAgent
/********************************************************/
void AgentRunner_t::CreateThread(vector<AgentHandlePair_t>& _agents)
{
	// run each agent in different thread
	for (vector<AgentHandlePair_t>:: iterator it = _agents.begin(); it != _agents.end(); ++it)
	{
	    pthread_t thread;
	    pthread_create(&thread, NULL ,Run, (void*)&(*((*it).m_agent)));
	    m_threads.insert(m_threads.end(), thread);
	}
}

/********************************************************/
			//Run
/********************************************************/
void* AgentRunner_t::Run(void* _context)
{
	((AgentApi_t*)_context)->Run();
	return 0;
}

/********************************************************/
			//JoinThreads
/********************************************************/
void AgentRunner_t::JoinThreads()
{
	for (vector<pthread_t>::iterator it = m_threads.begin(); it != m_threads.end(); ++it)
	{
		pthread_join(*it, NULL);	
	}
}

			






























