/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Gauge.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void changeToStatsScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Gauge rpmGauge;
    touchgfx::TextAreaWithOneWildcard gearValue;
    touchgfx::TextAreaWithOneWildcard rpmValue;
    touchgfx::TextAreaWithOneWildcard speedValue;
    touchgfx::TextArea lblSpeed;
    touchgfx::TextAreaWithOneWildcard txtIat;
    touchgfx::TextAreaWithOneWildcard txtVoltage;
    touchgfx::TextAreaWithOneWildcard txtOilTemp;
    touchgfx::TextAreaWithOneWildcard txtMaxRpm;
    touchgfx::TextAreaWithOneWildcard txtMaxSpeed;
    touchgfx::TextAreaWithOneWildcard txtFuelPress;
    touchgfx::TextAreaWithOneWildcard txtCoolantTemp;
    touchgfx::TextAreaWithOneWildcard txtOilPress;
    touchgfx::TextAreaWithOneWildcard txtWideband;
    touchgfx::TextArea lblAirTemp;
    touchgfx::TextArea lblVoltage;
    touchgfx::TextArea lblMaxRpm;
    touchgfx::TextArea lblMaxSpeed;
    touchgfx::TextArea lblOilTemp;
    touchgfx::TextArea lblFuelPress;
    touchgfx::TextAreaWithOneWildcard txtMinFuelPressure;
    touchgfx::TextAreaWithOneWildcard txtMinOilPressure;
    touchgfx::TextArea lblCoolTemp;
    touchgfx::TextArea lblOilPress;
    touchgfx::TextArea lblWB;
    touchgfx::Image oilPressureLight;
    touchgfx::Image celLight;
    touchgfx::Circle shiftIndicator;
    touchgfx::PainterRGB565 shiftIndicatorPainter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t GEARVALUE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar gearValueBuffer[GEARVALUE_SIZE];
    static const uint16_t RPMVALUE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar rpmValueBuffer[RPMVALUE_SIZE];
    static const uint16_t SPEEDVALUE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar speedValueBuffer[SPEEDVALUE_SIZE];
    static const uint16_t TXTIAT_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtIatBuffer[TXTIAT_SIZE];
    static const uint16_t TXTVOLTAGE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtVoltageBuffer[TXTVOLTAGE_SIZE];
    static const uint16_t TXTOILTEMP_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtOilTempBuffer[TXTOILTEMP_SIZE];
    static const uint16_t TXTMAXRPM_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtMaxRpmBuffer[TXTMAXRPM_SIZE];
    static const uint16_t TXTMAXSPEED_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtMaxSpeedBuffer[TXTMAXSPEED_SIZE];
    static const uint16_t TXTFUELPRESS_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtFuelPressBuffer[TXTFUELPRESS_SIZE];
    static const uint16_t TXTCOOLANTTEMP_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtCoolantTempBuffer[TXTCOOLANTTEMP_SIZE];
    static const uint16_t TXTOILPRESS_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtOilPressBuffer[TXTOILPRESS_SIZE];
    static const uint16_t TXTWIDEBAND_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtWidebandBuffer[TXTWIDEBAND_SIZE];
    static const uint16_t TXTMINFUELPRESSURE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtMinFuelPressureBuffer[TXTMINFUELPRESSURE_SIZE];
    static const uint16_t TXTMINOILPRESSURE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtMinOilPressureBuffer[TXTMINOILPRESSURE_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // SCREEN1VIEWBASE_HPP
