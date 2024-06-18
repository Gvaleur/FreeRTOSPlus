#pragma once
#include <stdint.h>

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/queue.h"

template <class T>
class Queue
{
public:
	Queue(const uint32_t size)
	{
		mQueue = xQueueCreate(size, sizeof(T));
	}

	bool send(const T& data, const uint32_t timeOutMs = 0)
	{
		return xQueueSend(mQueue, &data, timeOutMs / portTICK_PERIOD_MS);
	}

	bool sendInt(const T& data)
	{
		bool sent;
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		sent = xQueueSendFromISR(mQueue, &data, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		return sent;
	}

	bool receive(T* data, const uint32_t timeOutMs)
	{
		return xQueueReceive(mQueue, data, timeOutMs / portTICK_PERIOD_MS);
	}

	uint32_t messages()
	{
		return uxQueueMessagesWaiting(mQueue);
	}
private:
	QueueHandle_t mQueue;
};