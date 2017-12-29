#include "SmartHome_t.h"
#include "Hub_t.h"
#include "Loader_t.h"
#include "Config_t.h"
#include "AgentRunner_t.h"
#include "AgentApi_t.h"
#include "EventType_t.h"
#include "Event_t.h"
#include "ConfigData_t.h"
#include "WaitQueue_t.h"
#include "AgentQueuePair_t.h"
#include <dlfcn.h>
#include <string>
#include <memory>
#include <iostream>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
SmartHome_t:: SmartHome_t(const string& _pathName): 
m_hub(new Hub_t), m_loader(new Loader_t), m_agentRunner(new AgentRunner_t)
,  m_pathName(_pathName)
{	
	
}

/********************************************************/
			//DTOR
/********************************************************/
SmartHome_t:: ~SmartHome_t()
{
    pthread_cancel(m_exitThread);
	pthread_join(m_exitThread, NULL);
}

/********************************************************/
			//Run
/********************************************************/
void SmartHome_t:: Run()
{	
    // create user exit thread
    m_thread = pthread_self();
    pthread_create(&m_exitThread, NULL ,RunSystem, this);
    
	// read from config file and activate shared object files
	m_loader->InitializeSystem(m_pathName, *m_hub);

	// run each agent in different thread
	m_agentRunner->CreateThread(m_loader->GetAgents());
	
	// check for incoming events in queue and publish to subscribers 
	m_hub->CheckForEvents();
}

/********************************************************/
			//ExitProcedure
/********************************************************/
void SmartHome_t:: ExitProcedure()
{
	// exit agent threads
	m_loader->ExitAgents();
	
	// join agent threads
	m_agentRunner->JoinThreads();
	
	// join subscribers threads
	// clean allocated memory of queues and AgentQueuePairs
	m_hub->ExitProcedure();
	
	// clean allocated memory of agents and close handles
	m_loader->DestroyAgents();
}

/********************************************************/
			// RunSystem
/********************************************************/
void* SmartHome_t::RunSystem(void* _context)
{   
	int close;
	cin >> close;
	((SmartHome_t*)_context)->ExitProcedure();
	pthread_cancel(((SmartHome_t*)_context)->m_thread);
	pthread_join(((SmartHome_t*)_context)->m_thread, NULL);
    
	return 0;
}











