#ifndef STATSVIEW_HPP
#define STATSVIEW_HPP

#include <gui_generated/stats_screen/StatsViewBase.hpp>
#include <gui/stats_screen/StatsPresenter.hpp>

class StatsView : public StatsViewBase
{
public:
    StatsView();
    virtual ~StatsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateVal(uint8_t* newValue);
protected:
};

#endif // STATSVIEW_HPP
