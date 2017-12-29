#ifndef __EVENT_TYPE_T_H__
#define __EVENT_TYPE_T_H__

#include <string>
 
/*************************************************/

class EventType_t 
{
public:
	virtual	~EventType_t();							
	EventType_t();				
	EventType_t(const std::string& _type, const std::string& _floor, const std::string& _room);			
	const std::string& GetType() const;
	const std::string& GetFloor() const;
	const std::string& GetRoom() const;
	
	EventType_t(const EventType_t& _eventType);				
	EventType_t& operator=(const EventType_t& _eventType);			
	bool operator<(const EventType_t& _eventType) const;			
	bool operator==(const EventType_t& _eventType) const;	
protected:
															
private:
	std::string	m_type;
	std::string	m_floor;
	std::string	m_room;
				
};	

inline EventType_t::EventType_t(const std::string& _type, const std::string& _floor, const std::string& _room): 
m_type(_type)
, m_floor(_floor)
, m_room(_room)	
{
	
}

inline const std::string& EventType_t::GetType() const
{
   return m_type;
}

inline const std::string& EventType_t::GetRoom() const
{
   return m_room;
}

inline const std::string& EventType_t::GetFloor() const
{
   return m_floor;
}

#endif /* __EVENT_TYPE_T_H__ */
