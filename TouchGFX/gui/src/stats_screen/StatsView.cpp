#include <gui/stats_screen/StatsView.hpp>
#include <message_types.h>

StatsView::StatsView()
{

}

void StatsView::setupScreen()
{
    StatsViewBase::setupScreen();
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

}
