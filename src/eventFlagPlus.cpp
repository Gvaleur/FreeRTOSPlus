#include "eventFlagPlus.h"


EventFlag::EventFlag()
{
	mEventGroup = xEventGroupCreate();
}

void EventFlag::clear(const uint32_t flags)
{
	xEventGroupClearBits(mEventGroup, flags);
}

uint32_t EventFlag::wait(const uint32_t flags, const wait_t waitFor, const clear_t clearOnExit, const uint32_t timeOutMs)
{
	return xEventGroupWaitBits(mEventGroup, flags, clearOnExit, waitFor, timeOutMs / portTICK_PERIOD_MS);
}

uint32_t EventFlag::get()
{
	return xEventGroupGetBits(mEventGroup);
}

void EventFlag::set(const uint32_t flags)
{
	xEventGroupSetBits(mEventGroup, flags);
}