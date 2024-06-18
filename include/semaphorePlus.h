#pragma once
#include <stdint.h>
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/semphr.h"

class Semaphore
{
public:
	Semaphore(const uint32_t size, const uint32_t initalCount);

	bool take(const uint32_t timeOutMs);
	bool takeInt();
	bool release();
	bool releaseInt();

private:
	SemaphoreHandle_t mSemaphore;
};