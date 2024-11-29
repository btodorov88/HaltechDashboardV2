#include <gui/stats_screen/StatsView.hpp>
#include <gui/common/DataUtils.hpp>
#include <touchgfx/Color.hpp>

static display_values current;

static colortype RED = touchgfx::Color::getColorFromRGB(255, 0, 0);
static colortype YELLOW = touchgfx::Color::getColorFromRGB(255, 255, 0);
static colortype WHITE = touchgfx::Color::getColorFromRGB(255, 255, 255);

StatsView::StatsView()
{
	current = dataUtils::getDefaults(1);
}

void StatsView::setupScreen()
{
    StatsViewBase::setupScreen();
    // Clean cache
    current = dataUtils::getDefaults(1);
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
	if(!dataUtils::compare_float(values->bat.voltage, current.bat.voltage)){
		touchgfx::Unicode::snprintfFloat(curVoltageBuffer, CURVOLTAGE_SIZE, "%.1f", values->bat.voltage);
		curVoltage.invalidate();
		current.bat.voltage = values->bat.voltage;
	}
	if(values->bat.lowVoltageIndicator != current.bat.lowVoltageIndicator){
		if(values->bat.lowVoltageIndicator){
			curVoltage.setColor(RED);
		} else {
			curVoltage.setColor(WHITE);
		}
		curVoltage.invalidate();
		current.bat.lowVoltageIndicator = values->bat.lowVoltageIndicator;
	}

	//OTHER

}
