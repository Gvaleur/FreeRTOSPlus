#pragma once
#include <stdint.h>
#include "FreeRTOSConfig.h"

class Thread
{
public:
	enum thread_priority
	{
		PRIORITY_HIGH = 5,
		PRIORITY_MEDIUM_HIGH = 4,
		PRIORITY_MEDIUM = 3,
		PRIORITY_MEDIUM_LOW = 2,
		PRIORITY_LOW = 1
	};

	Thread(const char* name, const uint16_t stackSize, const thread_priority priority);
#if INCLUDE_vTaskDelete == 1
	~Thread();
#endif

	static void sleep(const uint32_t ms);
	static void startThreads();

protected:
	virtual void vRun() = 0;

private:
	static void taskAdapter(void *params);

	void* mTaskHandle;
};