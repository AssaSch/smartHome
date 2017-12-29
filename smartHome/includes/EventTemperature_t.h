#ifndef __EVENT_TEMP_T_H__
#define __EVENT_TEMP_T_H__

#include <string>
#include "Event_t.h"
 
/*************************************************/

class EventTemperature_t: public Event_t 
{
public:
	virtual	~EventTemperature_t(){};										
	EventTemperature_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time);
	
	double GetTemp() const;
	void SetTemp(double _temp);								
	//const std::string&			GetTime() const;
	//const std::string&			GetType() const;
	//const std::string&			GetFloor() const;
	//const std::string&			GetRoom() const;
	
protected:
	//void					SetTime(const std::string& _time);
	//void					SetType(const std::string& _type);
	//void					SetFloor(const std::string& _floor);
	//void					SetRoom(const std::string& _room);
															
private:
	EventTemperature_t(const EventTemperature_t& _event_t);			
	const EventTemperature_t& operator = (const EventTemperature_t& _event_t);	
	
	double m_temperature;
	//std::string					m_time;
	//std::string					m_type;
	//std::string					m_floor;
	//std::string					m_room;
	
	// add payload if neccesery			
};

inline EventTemperature_t:: EventTemperature_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time):
Event_t(_type, _floor, _room,_time)
{	
	m_temperature = 25;
}

inline double EventTemperature_t:: GetTemp() const
{	
	return m_temperature;
}

inline void EventTemperature_t:: SetTemp(double _temp)
{	
	m_temperature = _temp;
}	


#endif /* __EVENT_TEMP_T_H__ */
