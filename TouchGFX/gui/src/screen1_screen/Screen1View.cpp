#include <gui/screen1_screen/Screen1View.hpp>
#include <message_types.h>
#include <touchgfx/Color.hpp>

static display_values current = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'N',0};
static int shiftLightSwitch = 0;

static colortype RED = touchgfx::Color::getColorFromRGB(255, 0, 0);
static colortype YELLOW = touchgfx::Color::getColorFromRGB(255, 255, 0);
static colortype WHITE = touchgfx::Color::getColorFromRGB(255, 255, 255);
static int SHIFT_LIGHT_ALPHA = 132;
static int SHIFT_LIGHT_BLINK_ALPHA = 255;


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

	if(values->rpm != current.rpm)
	{
		rpmGauge.setValue(values->rpm);
		rpmGauge.invalidate();

		touchgfx::Unicode::snprintf(rpmValueBuffer, RPMVALUE_SIZE, "%d", values->rpm);
		rpmValue.invalidate();

		current.rpm = values->rpm;
	}

	if(values->maxRpm != current.maxRpm)
	{
		touchgfx::Unicode::snprintf(txtMaxRpmBuffer, TXTMAXRPM_SIZE, "%d", values->maxRpm);
		txtMaxRpm.invalidate();
		current.maxRpm = values->maxRpm;
	}

	if(values->coolantTemp != current.coolantTemp)
	{
		touchgfx::Unicode::snprintf(txtCoolantTempBuffer, TXTCOOLANTTEMP_SIZE, "%d", values->coolantTemp);
		if(values->coolantTempWarning){
			txtCoolantTemp.setColor(RED);
		} else {
			txtCoolantTemp.setColor(YELLOW);
		}
		txtCoolantTemp.invalidate();
		current.coolantTemp = values->coolantTemp;
	}

	if(values->speed != current.speed)
	{
		touchgfx::Unicode::snprintf(speedValueBuffer, SPEEDVALUE_SIZE, "%d", values->speed);
		speedValue.invalidate();
		current.speed = values->speed;
	}

	if(values->maxSpeed != current.maxSpeed)
	{
		touchgfx::Unicode::snprintf(txtMaxSpeedBuffer, TXTMAXSPEED_SIZE, "%d", values->maxSpeed);
		txtMaxSpeed.invalidate();
		current.maxSpeed = values->maxSpeed;
	}

	if(values->oilTemp != current.oilTemp)
	{
		touchgfx::Unicode::snprintf(txtOilTempBuffer, TXTOILTEMP_SIZE, "%d", values->oilTemp);
		txtOilTemp.invalidate();
		current.oilTemp = values->oilTemp;
	}

	if(!compare_float(values->oilPressure, current.oilPressure)){
		touchgfx::Unicode::snprintfFloat(txtOilPressBuffer, TXTOILPRESS_SIZE, "%.1f", values->oilPressure);
		txtOilPress.invalidate();
		current.oilPressure = values->oilPressure;
	}
	if(!compare_float(values->minOilPressure, current.minOilPressure)){
		touchgfx::Unicode::snprintfFloat(txtMinOilPressureBuffer, TXTMINOILPRESSURE_SIZE, "%.1f", values->minOilPressure);
		if(values->minOilPressure < 0){
			txtMinOilPressure.setVisible(false);
		} else {
			txtMinOilPressure.setVisible(true);
		}

		if(values->minOilPressureWarning){
			txtMinOilPressure.setColor(RED);
		} else {
			txtMinOilPressure.setColor(WHITE);
		}
		txtMinOilPressure.invalidate();
		current.minOilPressure = values->minOilPressure;
	}

	if(!compare_float(values->fuelPressure, current.fuelPressure)){
		touchgfx::Unicode::snprintfFloat(txtFuelPressBuffer, TXTFUELPRESS_SIZE, "%.1f", values->fuelPressure);
		txtFuelPress.invalidate();
		current.fuelPressure = values->fuelPressure;
	}
	if(!compare_float(values->minFuelPressure, current.minFuelPressure)){
		touchgfx::Unicode::snprintfFloat(txtMinFuelPressureBuffer, TXTMINFUELPRESSURE_SIZE, "%.1f", values->minFuelPressure);
		if(values->minFuelPressure < 0){
			txtMinFuelPressure.setVisible(false);
		} else {
			txtMinFuelPressure.setVisible(true);
		}
		txtMinFuelPressure.invalidate();
		current.minFuelPressure = values->minFuelPressure;
	}

	if(!compare_float(values->voltage, current.voltage)){
		touchgfx::Unicode::snprintfFloat(txtVoltageBuffer, TXTVOLTAGE_SIZE, "%.1f", values->voltage);
		txtVoltage.invalidate();
		current.voltage = values->voltage;
	}

	if(!compare_float(values->afr, current.afr, 0.01f)){
		touchgfx::Unicode::snprintfFloat(txtWidebandBuffer, TXTWIDEBAND_SIZE, "%.2f", values->afr);
		txtWideband.invalidate();
		current.afr = values->afr;
	}

	if(values->iat != current.iat)
	{
		touchgfx::Unicode::snprintf(txtIatBuffer, TXTIAT_SIZE, "%d", values->iat);
		txtIat.invalidate();
		current.iat = values->iat;
	}

	if(values->gear != current.gear)
	{
		touchgfx::Unicode::snprintf(gearValueBuffer, GEARVALUE_SIZE, "%c", values->gear);
		gearValue.invalidate();
		current.gear = values->gear;
	}

	if(values->lowVoltageIndicator != current.lowVoltageIndicator){
		if(values->lowVoltageIndicator){
			txtVoltage.setColor(RED);
		} else {
			txtVoltage.setColor(WHITE);
		}
		txtVoltage.invalidate();
		current.lowVoltageIndicator = values->lowVoltageIndicator;
	}

	if(values->celIndicator != current.celIndicator){
		celLight.setVisible(values->celIndicator);
		celLight.invalidate();
		current.celIndicator = values->celIndicator;
	}

	if(values->lowOilPressureIndicator != current.lowOilPressureIndicator){
		if(values->lowOilPressureIndicator){
			txtOilPress.setColor(RED);
		} else {
			txtOilPress.setColor(YELLOW);
		}
		txtOilPress.invalidate();
		oilPressureLight.setVisible(values->lowOilPressureIndicator);
		oilPressureLight.invalidate();
		current.lowOilPressureIndicator = values->lowOilPressureIndicator;
	}

	int shiftLampPersentage = values->shiftLampPersentage;
	if(shiftLampPersentage >= 100){
		// 280 radius covers the whole screen
		shiftIndicator.setRadius(280);
		shiftIndicator.setAlpha(SHIFT_LIGHT_BLINK_ALPHA);
		shiftIndicator.setVisible(shiftLightSwitch<2);
		shiftLightSwitch = (shiftLightSwitch < 3 ) ? shiftLightSwitch + 1: 0;
		shiftIndicator.invalidate();
	} else if(shiftLampPersentage == current.shiftLampPersentage) {
		// nothing changes in the UI
	}else if(shiftLampPersentage > 0){
		shiftIndicator.setRadius(280*shiftLampPersentage/100);
		shiftIndicator.setAlpha(SHIFT_LIGHT_ALPHA);
		shiftIndicator.setVisible(true);
		shiftIndicator.invalidate();
	} else {
		shiftIndicator.setVisible(false);
		shiftIndicator.invalidate();
	}
	current.shiftLampPersentage = shiftLampPersentage;
}

bool Screen1View::compare_float(float x, float y, float epsilon){
	if(abs(x - y) < epsilon)
		return true; //they are same
	return false; //they are not same
}
