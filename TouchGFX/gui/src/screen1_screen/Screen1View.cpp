#include <gui/screen1_screen/Screen1View.hpp>
#include <message_types.h>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateVal(uint8_t* newValue)
{
	display_values* values = (display_values*) newValue;

	rpmGauge.setValue(values->rpm);
	rpmGauge.invalidate();
}
