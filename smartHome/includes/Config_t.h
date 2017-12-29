#ifndef __CONFIG_T_H__
#define __CONFIG_T_H__

#include <string>
#include <fstream>

class ConfigData_t;
 
/*************************************************/

class Config_t 
{
public:
	virtual	~Config_t();									
	Config_t(const std::string& _pathName);
	bool GetConfigData(ConfigData_t& _configData);
	
protected:
															
private:
	Config_t(const Config_t& _config);
	const Config_t& operator = (const Config_t& _config);
	
	std::ifstream m_file;
	size_t m_first;
	size_t m_second;
	size_t m_third;
	size_t m_fourth;
	size_t m_fifth;
	
};	


#endif /* __CONFIG_T_H__ */
