#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <message_types.h>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateVal(uint8_t* newValue);
protected:
    bool compare_float(float x, float y, float epsilon = 0.1f);
    display_values getDefaults();
};

#endif // SCREEN1VIEW_HPP
