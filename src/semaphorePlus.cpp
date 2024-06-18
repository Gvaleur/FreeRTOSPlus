#include "semaphorePlus.h"

Semaphore::Semaphore(const uint32_t size, const uint32_t initalCount)
{
	mSemaphore = xSemaphoreCreateCounting(size , initalCount);
}

bool Semaphore::take(const uint32_t timeOutMs)
{
	return xSemaphoreTake(mSemaphore, timeOutMs / portTICK_PERIOD_MS);
}

bool Semaphore::takeInt()
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	bool taken = xSemaphoreTakeFromISR(mSemaphore, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	return taken;
}

bool Semaphore::release()
{
	return xSemaphoreGive(mSemaphore);
}

bool Semaphore::releaseInt()
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	bool released = xSemaphoreGiveFromISR(mSemaphore, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	return released;
}