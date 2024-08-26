#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <message_types.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

uint8_t values[sizeof(display_values)];

extern "C"
{
	xQueueHandle messageQ;
}

Model::Model() : modelListener(0)
{
	messageQ = xQueueGenericCreate(1, sizeof(display_values), 0);
}

void Model::tick()
{
	if(xQueueReceive(messageQ, &values, 0) == pdTRUE)
	{
		modelListener->setNewValue(values);
	}
}
