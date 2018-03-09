#pragma once

#include <iostream>

#define DEBUG 1
	// DEBUG 1 -> DEBUG active
	// DEBUG 0 -> DEBUG desactive

#if (DEBUG)
	#define LOG(x) std::cout << x;
#else
	#define LOG(x)
#endif
