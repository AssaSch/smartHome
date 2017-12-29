#ifndef __LOADER_T_H__
#define __LOADER_T_H__

#include <string>
#include <vector>

class Hub_t;
class ConfigData_t;
class AgentHandlePair_t;

/*************************************************/

class Loader_t 
{
public:
	virtual	~Loader_t();												
	Loader_t();
	void InitializeSystem(const std::string& _pathName, Hub_t& _hub);														
	std::vector<AgentHandlePair_t>& GetAgents();
	void ExitAgents();
	void DestroyAgents();
	
protected:
	AgentHandlePair_t CreateAgent(const ConfigData_t& _confData, Hub_t& _hub) const;
															
private:
	Loader_t(const Loader_t& _loader);			
	const Loader_t& operator = (const Loader_t& _loader);
	
	std::vector<AgentHandlePair_t> m_agents;
	
};	


#endif /* __LOADER_T_H__ */
