#include "WaitQueue_t.h"
#include <string>

using namespace std;


/********************************************************/
			//default CTOR
/********************************************************/
WaitQueue_t:: WaitQueue_t()
{
	m_maxSize = 0;
	pthread_mutex_init(&m_mutex, NULL);
	sem_init(&m_sem, 0, 0);
}

/********************************************************/
			//default DTOR
/********************************************************/
WaitQueue_t:: ~WaitQueue_t()
{
	pthread_mutex_destroy(&m_mutex);
}

/********************************************************/
			//copy CTOR
/********************************************************/
WaitQueue_t:: WaitQueue_t(const WaitQueue_t& _queue)
{
	m_queue = _queue.m_queue;
	m_maxSize = _queue.m_maxSize;
	pthread_mutex_init(&m_mutex, NULL);
	sem_init(&m_sem, 0, 0);
}

/********************************************************/
			//asignment operator
/********************************************************/
const WaitQueue_t& WaitQueue_t:: operator=(const WaitQueue_t& _queue)
{
	if (this != &_queue)
	{
		m_queue = _queue.m_queue;
		m_maxSize = _queue.m_maxSize;	
	}
	
	return *this;
}

/********************************************************/
			//Push
/********************************************************/
void WaitQueue_t:: Push(const shared_ptr<Event_t> _value)
{
	exception ex;
	
	if (m_maxSize && m_maxSize == m_queue.size())
	{
		throw ex;
	}
	
	pthread_mutex_lock(&m_mutex);
	m_queue.push(_value);
	pthread_mutex_unlock(&m_mutex);
	sem_post(&m_sem);
}

/********************************************************/
			//Pop
/********************************************************/
const shared_ptr<Event_t> WaitQueue_t:: Pop()
{
	sem_wait(&m_sem);
	pthread_mutex_lock(&m_mutex);
	const shared_ptr<Event_t> value = m_queue.front();
	m_queue.pop();
	pthread_mutex_unlock(&m_mutex);
	
	return value;
}

/********************************************************/
			//Pop
/********************************************************/
size_t WaitQueue_t:: Size()
{
	pthread_mutex_lock(&m_mutex);
	size_t size = m_queue.size();
	pthread_mutex_unlock(&m_mutex);
	
	return size;
}

/********************************************************/
			//SetMaxSize
/********************************************************/
void WaitQueue_t:: SetMaxSize(size_t _size)
{
	m_maxSize = _size;
}

/********************************************************/
			// operator<
/********************************************************/
bool WaitQueue_t:: operator<(const WaitQueue_t& _queue) const
{
	return m_queue < _queue.m_queue ? true : false;
}

/********************************************************/
			// operator==
/********************************************************/
bool WaitQueue_t:: operator==(const WaitQueue_t& _queue) const
{
	if (m_queue == _queue.m_queue)
	{
		return true;
	}
	else
	{
		return false;
	}
}














