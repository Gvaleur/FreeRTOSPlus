#include "mutexPlus.h"
#include "FreeRTOS/task.h"

Mutex::Mutex()
{
	mMutex = xSemaphoreCreateMutex();
}

bool Mutex::lock(const uint32_t timeOutMs)
{
	if (xTaskGetSchedulerState() == taskSCHEDULER_NOT_STARTED)
	{
		return true;
	}
	else
	{
		return xSemaphoreTake(mMutex, timeOutMs / portTICK_PERIOD_MS);
	}
}

void Mutex::unlock()
{
	if (xTaskGetSchedulerState() == taskSCHEDULER_NOT_STARTED)
	{
		return;
	}
	else
	{
		xSemaphoreGive(mMutex);
	}
}

EnterMutex::EnterMutex(Mutex& mutex) : mMutex(mutex)
{
	mMutex.lock(portMAX_DELAY);
}

EnterMutex::~EnterMutex()
{
	mMutex.unlock();
}