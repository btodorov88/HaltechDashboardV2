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

	touchgfx::Unicode::snprintf(rpmValueBuffer, RPMVALUE_SIZE, "%d", values->rpm);
	rpmValue.invalidate();

	touchgfx::Unicode::snprintf(txtMaxRpmBuffer, TXTMAXRPM_SIZE, "%d", values->maxRpm);
	txtMaxRpm.invalidate();

	touchgfx::Unicode::snprintf(txtCoolantTempBuffer, TXTCOOLANTTEMP_SIZE, "%d", values->coolantTemp);
	txtCoolantTemp.invalidate();

	touchgfx::Unicode::snprintf(speedValueBuffer, SPEEDVALUE_SIZE, "%d", values->speed);
	speedValue.invalidate();
	touchgfx::Unicode::snprintf(txtMaxSpeedBuffer, TXTMAXSPEED_SIZE, "%d", values->maxSpeed);
	txtMaxSpeed.invalidate();

	touchgfx::Unicode::snprintf(txtOilTempBuffer, TXTOILTEMP_SIZE, "%d", values->oilTemp);
	txtOilTemp.invalidate();
	touchgfx::Unicode::snprintfFloat(txtOilPressBuffer, TXTOILPRESS_SIZE, "%.1f", values->oilPressure);
	txtOilPress.invalidate();
	touchgfx::Unicode::snprintfFloat(txtMinOilPressureBuffer, TXTMINOILPRESSURE_SIZE, "%.1f", values->minOilPressure);
	txtMinOilPressure.invalidate();

	touchgfx::Unicode::snprintfFloat(txtFuelPressBuffer, TXTFUELPRESS_SIZE, "%.1f", values->fuelPressure);
	txtFuelPress.invalidate();
	touchgfx::Unicode::snprintfFloat(txtMinFuelPressureBuffer, TXTMINFUELPRESSURE_SIZE, "%.1f", values->minFuelPressure);
	txtMinFuelPressure.invalidate();

	touchgfx::Unicode::snprintfFloat(txtVoltageBuffer, TXTVOLTAGE_SIZE, "%.1f", values->voltage);
	txtVoltage.invalidate();

	touchgfx::Unicode::snprintfFloat(txtWidebandBuffer, TXTWIDEBAND_SIZE, "%.2f", values->afr);
	txtWideband.invalidate();

	touchgfx::Unicode::snprintf(txtIatBuffer, TXTIAT_SIZE, "%d", values->iat);
	txtIat.invalidate();

}
