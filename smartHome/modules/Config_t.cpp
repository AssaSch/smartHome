#include "Config_t.h"
#include "ConfigData_t.h"
#include <string>
#include <exception>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
Config_t:: Config_t(const string& _pathName)
{	
	exception ex;
	
	m_file.open(_pathName.c_str());
	if (!m_file.good())
	{
		throw ex;
	}
	
	m_first = 7;
	m_second = 7;
	m_third = 8;
	m_fourth = 6;
	m_fifth = 9;
}

/********************************************************/
			//DTOR
/********************************************************/
Config_t:: ~Config_t()
{
	m_file.close();
}

/********************************************************/
			//CreateAgent
/********************************************************/
bool Config_t:: GetConfigData(ConfigData_t& _configData)
{
	string line;
	string token;
	
	while(1)
	{
		if (!getline(m_file, line))
		{
			return false;
		}
		if (line =="")
		{
			getline(m_file, line);
		}
	
		token = line;
		_configData.SetDeviceId(token);
	
		getline(m_file, line);
		token = line.substr(m_first); 	
		_configData.SetType(token);
	
		getline(m_file, line);
		token = line.substr(m_second); 	
		_configData.SetRoom(token);
	
		getline(m_file, line);
		token = line.substr(m_third); 	
		_configData.SetFloor(token);
	
		getline(m_file, line);
		token = line.substr(m_fourth); 	
		_configData.SetLog(token);
	
		getline(m_file, line);
		token = line.substr(m_fifth); 	
		_configData.SetConfig(token);
		
		return true;
	}
}



















