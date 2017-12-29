#ifndef __EVENT_FIRE_T_H__
#define __EVENT_FIRE_T_H__

#include <string>
#include "Event_t.h"
 
/*************************************************/

class EventFire_t: public Event_t 
{
public:
	virtual	~EventFire_t(){};										
	EventFire_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time);
	
	double GetTemp() const;
	void SetTemp(double _temp);								
	//const string&			GetTime() const;
	//const string&			GetType() const;
	//const string&			GetFloor() const;
	//const string&			GetRoom() const;
	
protected:
	//void					SetTime(const string& _time);
	//void					SetType(const string& _type);
	//void					SetFloor(const string& _floor);
	//void					SetRoom(const string& _room);
															
private:
	EventFire_t(const EventFire_t& _event_t);			
	const EventFire_t& operator = (const EventFire_t& _event_t);	
	
	//string					m_time;
	//string					m_type;
	//string					m_floor;
	//string					m_room;
	
	// add payload if neccesery			
};

inline EventFire_t:: EventFire_t(const std::string& _type, const std::string& _floor, const std::string& _room, const std::string& _time):
Event_t(_type, _floor, _room, _time)
{	
}




#endif /* __EVENT_TEMP_T_H__ */
