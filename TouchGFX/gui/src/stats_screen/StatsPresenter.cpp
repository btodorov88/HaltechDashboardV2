#include <gui/stats_screen/StatsView.hpp>
#include <gui/stats_screen/StatsPresenter.hpp>

StatsPresenter::StatsPresenter(StatsView& v)
    : view(v)
{

}

void StatsPresenter::activate()
{

}

void StatsPresenter::deactivate()
{

}

void StatsPresenter::setNewValue(uint8_t* newValue)
{
	view.updateVal(newValue);
}
