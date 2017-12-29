#ifndef __WAIT_QUEUE_T_H__
#define __WAIT_QUEUE_T_H__

#include <string>
#include <memory>
#include <queue>
#include <exception>
#include <pthread.h>
#include <semaphore.h>
#include "Event_t.h"


/*************************************************/
class WaitQueue_t 
{
public:
	~WaitQueue_t();											
	WaitQueue_t();										
	void Push(const std::shared_ptr<Event_t> _value);	
	const std::shared_ptr<Event_t> Pop();
	size_t Size();
	void SetMaxSize(size_t _size);
	
	WaitQueue_t(const WaitQueue_t& _queue);								
	const WaitQueue_t& operator = (const WaitQueue_t& _queue);								
	bool operator<(const WaitQueue_t& _queue) const;			
	bool operator==(const WaitQueue_t& _queue) const;			
	
protected:
															
private:
	
	std::queue<std::shared_ptr<Event_t> > m_queue;
	pthread_mutex_t m_mutex;
	sem_t m_sem;
	size_t m_maxSize;
	
};


		

#endif /* __WAIT_QUEUE_T_H__ */
