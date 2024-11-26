#ifndef STATSPRESENTER_HPP
#define STATSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class StatsView;

class StatsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    StatsPresenter(StatsView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~StatsPresenter() {}

    void setNewValue(uint8_t* newValue);

private:
    StatsPresenter();

    StatsView& view;
};

#endif // STATSPRESENTER_HPP
