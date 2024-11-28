#include <gui/stats_screen/StatsView.hpp>

static display_values current;

StatsView::StatsView()
{
	current = getDefaults();
}

void StatsView::setupScreen()
{
    StatsViewBase::setupScreen();
    // Clean cache
    current = getDefaults();
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
		curRpm.invalidate();
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

display_values StatsView::getDefaults(){
	Oil oil = {0,0,0,0,0,0};
	Coolant coolant = {0,0,0,0};
	Fuel fuel = {0,0,0};
	Bat bat = {0,0};

	display_values vals = {1,0,0,0,0,0,0,0,0,'N',0,oil,coolant,fuel,bat};
	return vals;
}
