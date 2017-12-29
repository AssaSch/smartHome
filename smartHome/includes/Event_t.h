#ifndef __EVENT_API_T_H__
#define __EVENT_API_T_H__

#include <string>

 
/*************************************************/

class Event_t 
{
public:
	virtual ~Event_t(){};										
	Event_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time);
										
	const std::string& GetTime() const;
	const std::string& GetType() const;
	const std::string& GetFloor() const;
	const std::string& GetRoom() const;
	
	
protected:
	void SetTime(const std::string& _time);
	void SetType(const std::string& _type);
	void SetFloor(const std::string& _floor);
	void SetRoom(const std::string& _room);
															
private:
	Event_t(const Event_t& _event_t);			
	const Event_t& operator = (const Event_t& _event_t);	
	
	std::string m_time;
	std::string	m_type;
	std::string	m_floor;
	std::string	m_room;
	
	// add payload if neccesery			
};

inline Event_t:: Event_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time):
m_time(_time), m_type(_type), m_floor(_floor), m_room(_room)
{	
	
}	

inline const std::string& Event_t::GetTime() const
{
   return m_time;
}

inline const std::string& Event_t::GetType() const
{
   return m_type;
}

inline const std::string& Event_t::GetFloor() const
{
   return m_floor;
}

inline const std::string& Event_t::GetRoom() const
{
   return m_room;
}

inline void Event_t::SetTime(const std::string& _time)
{
   m_time = _time;
}

inline void Event_t::SetType(const std::string& _type)
{
   m_type = _type;
}

inline void Event_t::SetFloor(const std::string& _floor)
{
   m_floor = _floor;
}

inline void Event_t::SetRoom(const std::string& _room)
{
   m_room = _room;
}

#endif /* __EVENT_API_T_H__ */
