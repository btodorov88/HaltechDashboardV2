/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATSVIEWBASE_HPP
#define STATSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/stats_screen/StatsPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class StatsViewBase : public touchgfx::View<StatsPresenter>
{
public:
    StatsViewBase();
    virtual ~StatsViewBase();
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void changeToScreen1();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea1_2;
    touchgfx::TextArea textArea1_2_1;
    touchgfx::TextArea textArea1_2_1_1;
    touchgfx::TextArea textArea1_2_1_1_1;
    touchgfx::TextArea textArea1_2_1_1_1_1;
    touchgfx::TextArea textArea1_2_1_1_1_2;
    touchgfx::TextArea textArea1_2_1_1_1_2_1;
    touchgfx::TextArea textArea1_2_1_1_1_2_1_1;
    touchgfx::TextArea textArea1_2_1_1_1_2_1_1_1;
    touchgfx::TextArea textArea1_2_1_1_1_2_1_1_1_1;
    touchgfx::TextArea textArea1_2_1_1_1_2_1_1_1_1_1;
    touchgfx::TextArea textArea1_1;
    touchgfx::TextArea textArea1_1_2;
    touchgfx::TextArea textArea1_1_2_1;
    touchgfx::TextArea textArea1_1_1;
    touchgfx::TextArea textArea1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_2;
    touchgfx::TextArea textArea1_1_1_1_1_2_1;
    touchgfx::TextArea textArea1_1_1_1_1_2_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_2_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_1_1_1_1;
    touchgfx::TextArea textArea1_1_1_1_1_1_1_1_1_2;
    touchgfx::TextArea textArea1_1_1_1_1_1_1_1_1_1;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Line line1_1_1;
    touchgfx::PainterRGB565 line1_1_1Painter;
    touchgfx::Line line1_1_1_1;
    touchgfx::PainterRGB565 line1_1_1_1Painter;
    touchgfx::Line line1_1_1_1_1;
    touchgfx::PainterRGB565 line1_1_1_1_1Painter;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // STATSVIEWBASE_HPP