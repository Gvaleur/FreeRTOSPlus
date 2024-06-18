#include "threadPlus.h"

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"

Thread::Thread(const char* name, const uint16_t stackSize, const thread_priority priority)
{
	xTaskCreate(taskAdapter, name, stackSize, this, priority, &mTaskHandle);
}

#if INCLUDE_vTaskDelete == 1
Thread::~Thread()
{
	vTaskDelete(mTaskHandle);
}
#endif

void Thread::sleep(const uint32_t ms)
{
	vTaskDelay(ms / portTICK_PERIOD_MS);
}

void Thread::taskAdapter(void *params)
{
	Thread* thread = static_cast<Thread*>(params);
	thread->vRun();
}

void Thread::startThreads()
{
	vTaskStartScheduler();
}