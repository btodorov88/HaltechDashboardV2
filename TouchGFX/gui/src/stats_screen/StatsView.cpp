#include <gui/stats_screen/StatsView.hpp>
#include <message_types.h>

static display_values current = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'N',0};

StatsView::StatsView()
{

}

void StatsView::setupScreen()
{
    StatsViewBase::setupScreen();
    // Clean cache
    current = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'N',0};
}

void StatsView::tearDownScreen()
{
    StatsViewBase::tearDownScreen();
}

void StatsView::updateVal(uint8_t* newValue)
{
	display_values* values = (display_values*) newValue;

	if(values->activeScreen == 0)
	{
		changeToScreen1();
	}

	// RPM
	if(values->rpm != current.rpm)
	{
		touchgfx::Unicode::snprintf(curRpmBuffer, CURRPM_SIZE, "%d", values->rpm);
		maxRpm.invalidate();
		current.rpm = values->rpm;
	}
	if(values->maxRpm != current.maxRpm)
	{
		touchgfx::Unicode::snprintf(maxRpmBuffer, MAXRPM_SIZE, "%d", values->maxRpm);
		maxRpm.invalidate();
		current.maxRpm = values->maxRpm;
	}

	// SPEED
	if(values->speed != current.speed)
	{
		touchgfx::Unicode::snprintf(curSpeedBuffer, CURSPEED_SIZE, "%d", values->speed);
		curSpeed.invalidate();
		current.speed = values->speed;
	}
	if(values->maxSpeed != current.maxSpeed)
	{
		touchgfx::Unicode::snprintf(maxSpeedBuffer, MAXSPEED_SIZE, "%d", values->maxSpeed);
		maxSpeed.invalidate();
		current.maxSpeed = values->maxSpeed;
	}

	// OIL

	// COOLANT

	// FUEL

	// BAT

	//OTHER

}
