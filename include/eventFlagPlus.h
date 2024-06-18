#pragma once

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/event_groups.h"

#include "stdint.h"

class EventFlag
{
public:
	enum wait_t
	{
		ALL = 1,
		ANY = 0
	};

	enum clear_t
	{
		CLEAR = 1,
		DONT_CLEAR = 0
	};

	EventFlag();

	void set(const uint32_t flags);
	void clear(const uint32_t flags);
	uint32_t wait(const uint32_t flags, const wait_t waitFor, const clear_t clearOnExit, const uint32_t timeOutMs);
	uint32_t get();

private:
	EventGroupHandle_t mEventGroup;
};