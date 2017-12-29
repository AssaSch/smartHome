#ifndef __SMART_HOME_T_H__
#define __SMART_HOME_T_H__

#include "Hub_t.h"
#include "Loader_t.h"
#include "AgentRunner_t.h"
#include <string>
#include <vector>
#include <memory>
#include <pthread.h>

/*************************************************/

class SmartHome_t
{
public:
	virtual	~SmartHome_t();						
	SmartHome_t(const std::string& _pathName);												
	void Run();
	
protected:
	static void* RunSystem(void* _context);
	static void* RunThread(void* _context);
	void ExitProcedure();
															
private:
	SmartHome_t(const SmartHome_t& _hub);		
	const SmartHome_t& 	operator = (const SmartHome_t& _hub);	
	
	std::unique_ptr<Hub_t> m_hub;
	std::unique_ptr<Loader_t> m_loader;
	std::unique_ptr<AgentRunner_t> m_agentRunner;
	pthread_t m_thread;
	pthread_t m_exitThread;
	std::string m_pathName;
};


#endif /* __SMART_HOME_T_H__ */
