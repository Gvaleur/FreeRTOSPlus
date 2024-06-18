#pragma once
#include <stdint.h>
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/semphr.h"

class Mutex
{
public:
	Mutex();

	bool lock(const uint32_t timeOutMs);
	void unlock();
	
private:
	SemaphoreHandle_t mMutex;
};

class EnterMutex
{
public:
	EnterMutex(Mutex& mutex);
	~EnterMutex();

private:
	Mutex& mMutex;
};
