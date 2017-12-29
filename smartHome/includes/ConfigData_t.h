#ifndef __CONFIG_DATA_T_H__
#define __CONFIG_DATA_T_H__

#include <string>
 
/*************************************************/

class ConfigData_t 
{
public:
	virtual	~ConfigData_t(){};									
	ConfigData_t(){};			
							
	const std::string& GetDeviceId() const;
	const std::string& GetLog() const;
	const std::string& GetConfig() const;
	const std::string& GetType() const;
	const std::string& GetFloor() const;
	const std::string& GetRoom() const;
	
	void SetDeviceId(const std::string& _deviceId);
	void SetLog(const std::string& _log);
	void SetConfig(const std::string& _config);
	void SetType(const std::string& _type);
	void SetFloor(const std::string& _floor);
	void SetRoom(const std::string& _room);
			
	
protected:
															
private:
	ConfigData_t(const ConfigData_t& _configData);
	const ConfigData_t& operator = (const ConfigData_t& _configData);
	
	std::string	m_deviceId;
	std::string	m_type;	
	std::string	m_room;	
	std::string	m_floor;	
	std::string	m_log;	
	std::string	m_config;					
};	

inline const std::string& ConfigData_t::GetDeviceId() const
{
   return m_deviceId;
}

inline const std::string& ConfigData_t::GetType() const
{
   return m_type;
}

inline const std::string& ConfigData_t::GetRoom() const
{
   return m_room;
}

inline const std::string& ConfigData_t::GetFloor() const
{
   return m_floor;
}

inline const std::string& ConfigData_t::GetLog() const
{
   return m_log;
}

inline const std::string& ConfigData_t::GetConfig() const
{
   return m_config;
}

inline void ConfigData_t::SetDeviceId(const std::string& _deviceId)
{
   m_deviceId = _deviceId;
}

inline void ConfigData_t::SetType(const std::string& _type)
{
   m_type = _type;
}

inline void ConfigData_t::SetRoom(const std::string& _room)
{
   m_room = _room;
}

inline void ConfigData_t::SetFloor(const std::string& _floor)
{
   m_floor = _floor;
}

inline void ConfigData_t::SetLog(const std::string& _log)
{
   m_log = _log;
}

inline void ConfigData_t::SetConfig(const std::string& _config)
{
   m_config = _config;
}





#endif /* __CONFIG_DATA_T_H__ */
