#ifndef __SAFE_QUEUE_T_H__
#define __SAFE_QUEUE_T_H__

#include <string>
#include <queue>
#include <exception>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

/*************************************************/
template <class T> 
class SafeQueue_t 
{
public:
							~SafeQueue_t();									// DTOR			
							SafeQueue_t();									// default CTOR		
	void					Push(const T& _value);	
	const T					Pop();
	size_t					Size() const;
	void					SetMaxSize(size_t _size);
	
							SafeQueue_t(const SafeQueue_t& _queue);		// copy CTOR
	const SafeQueue_t& 		operator = (const SafeQueue_t& _queue);		// asignment operator
	bool			 		operator<(const SafeQueue_t& _queue) const;			// asignment operator
	bool					operator==(const SafeQueue_t& _queue) const;			// asignment operator
	
protected:
															
private:
	
	queue<T> 				m_queue;
	pthread_mutex_t 		m_mutex;
	sem_t 					m_sem;
	size_t					m_maxSize;
	
};

/********************************************************/
			//default CTOR
/********************************************************/
template <class T>
SafeQueue_t<T>:: SafeQueue_t()
{
	m_maxSize = 0;
	pthread_mutex_init(&m_mutex, NULL);
	sem_init(&m_sem, 0, 0);
}

/********************************************************/
			//default DTOR
/********************************************************/
template <class T>
SafeQueue_t<T>:: ~SafeQueue_t()
{
	pthread_mutex_destroy(&m_mutex);
}

/********************************************************/
			//copy CTOR
/********************************************************/
template <class T>
SafeQueue_t<T>:: SafeQueue_t(const SafeQueue_t<T>& _queue)
{
	m_queue = _queue.m_queue;
	m_maxSize = _queue.m_maxSize;
	pthread_mutex_init(&m_mutex, NULL);
	sem_init(&m_sem, 0, 0);
}

/********************************************************/
			//asignment operator
/********************************************************/
template <class T>
const SafeQueue_t<T>& SafeQueue_t<T>:: operator=(const SafeQueue_t<T>& _queue)
{
	if (this != &_queue)
	{
		m_queue = _queue.m_queue;
		m_maxSize = _queue.m_maxSize;	
	}
	
	return *this;
}

/********************************************************/
			// operator<
/********************************************************/
template <class T>
bool SafeQueue_t<T>:: operator<(const SafeQueue_t<T>& _queue) const
{
	return m_queue < _queue.m_queue ? true : false;
}

/********************************************************/
			// operator==
/********************************************************/
template <class T>
bool SafeQueue_t<T>:: operator==(const SafeQueue_t<T>& _queue) const
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

/********************************************************/
			//Push
/********************************************************/
template <class T>
void SafeQueue_t<T>:: Push(const T& _value)
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
template <class T>
const T SafeQueue_t<T>:: Pop()
{
	sem_wait(&m_sem);
	pthread_mutex_lock(&m_mutex);
	const T value = m_queue.front();
	m_queue.pop();
	pthread_mutex_unlock(&m_mutex);
	
	return value;
}

/********************************************************/
			//Pop
/********************************************************/
template <class T>
size_t SafeQueue_t<T>:: Size() const
{
	pthread_mutex_lock(&m_mutex);
	size_t size = m_queue.size();
	pthread_mutex_unlock(&m_mutex);
	
	return size;
}

/********************************************************/
			//SetMaxSize
/********************************************************/
template <class T>
void SafeQueue_t<T>:: SetMaxSize(size_t _size)
{
	m_maxSize = _size;
}

		

#endif /* __SAFE_QUEUE_T_H__ */
