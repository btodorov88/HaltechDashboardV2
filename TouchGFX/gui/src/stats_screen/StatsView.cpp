#include <gui/stats_screen/StatsView.hpp>
#include <gui/common/DataUtils.hpp>
#include <touchgfx/Color.hpp>

static display_values current;

static colortype RED = touchgfx::Color::getColorFromRGB(255, 0, 0);
//static colortype YELLOW = touchgfx::Color::getColorFromRGB(255, 255, 0);
static colortype WHITE = touchgfx::Color::getColorFromRGB(255, 255, 255);

StatsView::StatsView()
{
	current = dataUtils::getDefaults(1);
}

void StatsView::setupScreen()
{
    StatsViewBase::setupScreen();
    // Clean cache
    current = dataUtils::getDefaults(1);
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

	// RPM
	if(values->rpm != current.rpm)
	{
		touchgfx::Unicode::snprintf(curRpmBuffer, CURRPM_SIZE, "%d", values->rpm);
		curRpm.invalidate();
		current.rpm = values->rpm;
	}
	if(values->maxRpm != current.maxRpm)
	{
		touchgfx::Unicode::snprintf(maxRpmBuffer, MAXRPM_SIZE, "%d", values->maxRpm);
		maxRpm.invalidate();
		current.maxRpm = values->maxRpm;
	}

	// SPEED
	if(values->speed != current.speed)
	{
		touchgfx::Unicode::snprintf(curSpeedBuffer, CURSPEED_SIZE, "%d", values->speed);
		curSpeed.invalidate();
		current.speed = values->speed;
	}
	if(values->maxSpeed != current.maxSpeed)
	{
		touchgfx::Unicode::snprintf(maxSpeedBuffer, MAXSPEED_SIZE, "%d", values->maxSpeed);
		maxSpeed.invalidate();
		current.maxSpeed = values->maxSpeed;
	}

	// OIL
	if(values->oil.oilTemp != current.oil.oilTemp)
	{
		touchgfx::Unicode::snprintf(curOilTempBuffer, CUROILTEMP_SIZE, "%d", values->oil.oilTemp);
		curOilTemp.invalidate();
		current.oil.oilTemp = values->oil.oilTemp;
	}
	if(values->oil.maxOilTemp != current.oil.maxOilTemp)
	{
		touchgfx::Unicode::snprintf(maxOilTempBuffer, MAXOILTEMP_SIZE, "%d", values->oil.maxOilTemp);
		maxOilTemp.invalidate();
		current.oil.maxOilTemp = values->oil.maxOilTemp;
	}

	if(!dataUtils::compare_float(values->oil.oilPressure, current.oil.oilPressure)){
		touchgfx::Unicode::snprintfFloat(curOilPressureBuffer, CUROILPRESSURE_SIZE, "%.1f", values->oil.oilPressure);
		curOilPressure.invalidate();
		current.oil.oilPressure = values->oil.oilPressure;
	}
	if(!dataUtils::compare_float(values->oil.minOilPressure, current.oil.minOilPressure)){
		touchgfx::Unicode::snprintfFloat(minOilPressureBuffer, MINOILPRESSURE_SIZE, "%.1f", values->oil.minOilPressure);
		if(values->oil.minOilPressure < 0){
			minOilPressure.setVisible(false);
		} else {
			minOilPressure.setVisible(true);
		}

		if(values->oil.minOilPressureWarning){
			minOilPressure.setColor(RED);
		} else {
			minOilPressure.setColor(WHITE);
		}
		minOilPressure.invalidate();
		current.oil.minOilPressure = values->oil.minOilPressure;
	}

	// COOLANT
	if(values->coolant.coolantTemp != current.coolant.coolantTemp)
	{
		touchgfx::Unicode::snprintf(curCoolantTempBuffer, CURCOOLANTTEMP_SIZE, "%d", values->coolant.coolantTemp);
		if(values->coolant.coolantTempWarning){
			curCoolantTemp.setColor(RED);
		} else {
			curCoolantTemp.setColor(WHITE);
		}
		curCoolantTemp.invalidate();
		current.coolant.coolantTemp = values->coolant.coolantTemp;
	}

	if(values->coolant.maxCoolantTemp != current.coolant.maxCoolantTemp)
	{
		touchgfx::Unicode::snprintf(maxCoolantTempBuffer, MAXCOOLANTTEMP_SIZE, "%d", values->coolant.maxCoolantTemp);
		if(values->coolant.maxCoolentTempWarning){
			maxCoolantTemp.setColor(RED);
		} else {
			maxCoolantTemp.setColor(WHITE);
		}
		maxCoolantTemp.invalidate();
		current.coolant.maxCoolantTemp = values->coolant.maxCoolantTemp;
	}


	// FUEL
	if(values->fuel.fuelTemp != current.fuel.fuelTemp)
	{
		touchgfx::Unicode::snprintf(curFuelTempBuffer, CURFUELTEMP_SIZE, "%d", values->fuel.fuelTemp);
		curFuelTemp.invalidate();
		current.fuel.fuelTemp = values->fuel.fuelTemp;
	}
	if(values->fuel.maxFuelTemp != current.fuel.maxFuelTemp)
	{
		touchgfx::Unicode::snprintf(maxFuelTempBuffer, MAXFUELTEMP_SIZE, "%d", values->fuel.maxFuelTemp);
		maxFuelTemp.invalidate();
		current.fuel.maxFuelTemp = values->fuel.maxFuelTemp;
	}

	if(!dataUtils::compare_float(values->fuel.fuelPressure, current.fuel.fuelPressure)){
		touchgfx::Unicode::snprintfFloat(curFuelPressureBuffer, CURFUELPRESSURE_SIZE, "%.1f", values->fuel.fuelPressure);
		curFuelPressure.invalidate();
		current.fuel.fuelPressure = values->fuel.fuelPressure;
	}
	if(!dataUtils::compare_float(values->fuel.minFuelPressure, current.fuel.minFuelPressure)){
		touchgfx::Unicode::snprintfFloat(minFuelPressureBuffer, MINFUELPRESSURE_SIZE, "%.1f", values->fuel.minFuelPressure);
		if(values->fuel.lowMinFuelPressure){
			minFuelPressure.setColor(RED);
		} else {
			minFuelPressure.setColor(WHITE);
		}
		if(values->fuel.minFuelPressure < 0){
			minFuelPressure.setVisible(false);
		} else {
			minFuelPressure.setVisible(true);
		}
		minFuelPressure.invalidate();
		current.fuel.minFuelPressure = values->fuel.minFuelPressure;
	}

	// BAT
	if(!dataUtils::compare_float(values->bat.voltage, current.bat.voltage)){
		touchgfx::Unicode::snprintfFloat(curVoltageBuffer, CURVOLTAGE_SIZE, "%.1f", values->bat.voltage);
		if(values->bat.lowVoltageIndicator){
			curVoltage.setColor(RED);
		} else {
			curVoltage.setColor(WHITE);
		}
		curVoltage.invalidate();
		current.bat.voltage = values->bat.voltage;
		current.bat.lowVoltageIndicator = values->bat.lowVoltageIndicator;
	}

	if(!dataUtils::compare_float(values->bat.minVoltage, current.bat.minVoltage)){
		touchgfx::Unicode::snprintfFloat(minVoltageBuffer, MINVOLTAGE_SIZE, "%.1f", values->bat.minVoltage);
		if(values->bat.minVoltage < 0){
			minVoltage.setVisible(false);
		} else {
			minVoltage.setVisible(true);
		}
		if(values->bat.lowMinVoltageIndicator){
			minVoltage.setColor(RED);
		} else {
			minVoltage.setColor(WHITE);
		}
		minVoltage.invalidate();
		current.bat.minVoltage = values->bat.minVoltage;
		current.bat.lowMinVoltageIndicator = values->bat.lowMinVoltageIndicator;
	}

	//IAT
	if(values->iat.iat != current.iat.iat)
	{
		touchgfx::Unicode::snprintf(curIatBuffer, CURIAT_SIZE, "%d", values->iat.iat);
		curIat.invalidate();
		current.iat.iat = values->iat.iat;
	}
	if(values->iat.maxIat != current.iat.maxIat)
	{
		touchgfx::Unicode::snprintf(maxIatBuffer, MAXIAT_SIZE, "%d", values->iat.maxIat);
		if(values->iat.maxIat < -60){
			maxIat.setVisible(false);
		} else {
			maxIat.setVisible(true);
		}
		maxIat.invalidate();
		current.iat.maxIat = values->iat.maxIat;
	}

	//OTHER
	if(values->tps != current.tps)
	{
		touchgfx::Unicode::snprintf(tpsBuffer, TPS_SIZE, "%d", values->tps);
		tps.invalidate();
		current.tps = values->tps;
	}

	if(values->runTime != current.runTime)
	{
		touchgfx::Unicode::snprintf(runTimeBuffer, RUNTIME_SIZE, "%02d:%02d", values->runTime / 60, values->runTime % 60);
		runTime.invalidate();
		current.runTime = values->runTime;
	}

	if(values->celIndicator != current.celIndicator){
		cel.setVisible(values->celIndicator);
		cel.invalidate();
		current.celIndicator = values->celIndicator;
	}

	if(!dataUtils::compare_float(values->baro, current.baro)){
		touchgfx::Unicode::snprintfFloat(baroBuffer, BARO_SIZE, "%.2f", values->baro);
		baro.invalidate();
		current.baro = values->baro;
	}

	if(!dataUtils::compare_float(values->usedFuel, current.usedFuel, 0.1f)){
		touchgfx::Unicode::snprintfFloat(fuelUsedBuffer, FUELUSED_SIZE, "%.1f", values->usedFuel);
		fuelUsed.invalidate();
		current.usedFuel = values->usedFuel;
	}
}
