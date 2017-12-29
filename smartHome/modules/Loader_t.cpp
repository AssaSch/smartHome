#include "Loader_t.h"
#include "Hub_t.h"
#include "AgentApi_t.h"
#include "ConfigData_t.h"
#include "Config_t.h"
#include "AgentHandlePair_t.h"
#include <string.h>
#include <dlfcn.h>
#include <iostream>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
Loader_t:: Loader_t()
{	

}

/********************************************************/
			//DTOR
/********************************************************/
Loader_t:: ~Loader_t()
{
	
}

/********************************************************/
			//CreateAgent
/********************************************************/
AgentHandlePair_t Loader_t:: CreateAgent(const ConfigData_t& _confData, Hub_t& _hub) const
{
    exception ex;
	void* lib_handle;
	AgentApi_t* (*fn)(void);
	string soPath = "libc" + _confData.GetType() + ".so";
	
	lib_handle = dlopen(soPath.c_str(), RTLD_LAZY);
	if (!lib_handle)
	{
		throw ex;
	}

	fn = (AgentApi_t*(*)())dlsym(lib_handle, "create");
	if (dlerror())
	{
		throw ex;
	}	
	
	AgentApi_t* agent = fn();
	agent->Initialize(_confData);
	agent->Connect(_hub);
	
	AgentHandlePair_t pair(agent, lib_handle);
	
	return pair;
}

/********************************************************/
			//InitializeSystem
/********************************************************/
void Loader_t:: InitializeSystem(const string& _pathName, Hub_t& _hub)
{
	Config_t config(_pathName);
	ConfigData_t configData;
	
	// create agent and insert pointer to container
	while (config.GetConfigData(configData))
	{
		m_agents.insert(m_agents.end(), CreateAgent(configData, _hub));
	}
}

/********************************************************/
			//Destroy
/********************************************************/
void Loader_t:: DestroyAgents()
{
	for (vector<AgentHandlePair_t>::iterator it = m_agents.begin(); it != m_agents.end(); ++it)
	{
		delete (it->m_agent);	
		dlclose(it->m_handle);
	}
}

/********************************************************/
			//Destroy
/********************************************************/
void Loader_t:: ExitAgents()
{
	for (vector<AgentHandlePair_t>::iterator it = m_agents.begin(); it != m_agents.end(); ++it)
	{
		(it->m_agent)->Stop();
	}
}
					
/********************************************************/
			//GetAgents
/********************************************************/
vector<AgentHandlePair_t>& Loader_t:: GetAgents()
{
	return m_agents;
}





























