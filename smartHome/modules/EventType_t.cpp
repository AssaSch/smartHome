#include "EventType_t.h"
#include <string>

using namespace std;


/********************************************************/
			// default CTOR
/********************************************************/
EventType_t:: EventType_t()
{	

}

/********************************************************/
			//DTOR
/********************************************************/
EventType_t:: ~EventType_t()
{
	
}

/********************************************************/
			// copy CTOR
/********************************************************/
EventType_t:: EventType_t(const EventType_t& _eventType): m_type(_eventType.m_type), m_floor(_eventType.m_floor), m_room(_eventType.m_room)	
{
	
}

/********************************************************/
			// operator=
/********************************************************/
EventType_t& EventType_t:: operator=(const EventType_t& _eventType)
{
	if (this != &_eventType)
	{
		m_type = _eventType.m_type;
		m_floor = _eventType.m_floor;
		m_room = _eventType.m_room;	
	}
	
	return *this;
}

/********************************************************/
			// operator<
/********************************************************/
bool EventType_t:: operator<(const EventType_t& _eventType) const
{
	return !(!(m_type < _eventType.m_type) && !(m_floor < _eventType.m_floor) && !(m_room < _eventType.m_room));
}

/********************************************************/
			// operator==
/********************************************************/
bool EventType_t:: operator==(const EventType_t& _eventType) const
{
	if ((m_type == _eventType.m_type) && (m_floor == _eventType.m_floor) && (m_room == _eventType.m_room))
	{
		return true;
	}
	else
	{
		return false;
	}
}
 			

















