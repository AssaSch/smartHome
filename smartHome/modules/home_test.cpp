#include "Hub_t.h"
#include "SmartHome_t.h"

int main()
{
	SmartHome_t smartHome("configFile/config.txt");
	smartHome.Run();
	
	return 0;
}

