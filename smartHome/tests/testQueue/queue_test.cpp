#include "SafeQueue_t.h"
#include "mu_test.h"
#include <stdio.h>
#include <iostream>



/*****************************************************************************/


UNIT(queue_ok)
	
	SafeQueue_t<string> queue;
	
	queue.SetMaxSize(2);
	queue.Push("aaa");
	string value = queue.Pop();
	cout << value << endl;
	ASSERT_THAT(value == "aaa");
	

END_UNIT

/*****************************************************************************/

TEST_SUITE(framework test)

	TEST(queue_ok)
	
END_SUITE

/*****************************************************************************/
	
	

