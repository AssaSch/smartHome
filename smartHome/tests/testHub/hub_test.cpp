#include "mu_test.h"
#include <stdio.h>
#include <iostream>
#include <map>
//#include "EventType_t.h"



/*****************************************************************************/


UNIT(hub_ok)
	
	multimap<string, string>		m_subscribers;
	string
	
	m_subscribers.insert(pair<EventType_t, string>(eventType1, "1"));
	m_subscribers.insert(pair<EventType_t, string>(eventType2, "2"));
	
	

END_UNIT

/*****************************************************************************/

TEST_SUITE(framework test)

	TEST(hub_ok)
	
END_SUITE

/*****************************************************************************/
	
	

