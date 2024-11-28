#ifndef MESSAGETYPES_H
#define MESSAGETYPES_H

#include <stdbool.h>

typedef struct {
	int oilTemp;
	int maxOilTemp;
	float oilPressure;
	float minOilPressure;
	bool minOilPressureWarning;
	bool lowOilPressureIndicator;
} Oil;

typedef struct {
	int coolantTemp;
	bool coolantTempWarning;
	int maxCoolantTemp;
	bool maxCoolentTempWarning;
} Coolant;

typedef struct {
	float fuelPressure;
	float minFuelPressure;
	int fuelTemp;
} Fuel;

typedef struct {
	float voltage;
	bool lowVoltageIndicator;
} Bat;


typedef struct {
	int activeScreen;
	int rpm;
	int maxRpm;

	int speed;
	int maxSpeed;

	int iat;
	float afr;
	int tps;
	bool celIndicator;
	char gear;
	int shiftLampPersentage; // From 0 to 100% - how intense the gear shift lamp should be

	Oil oil;
	Coolant coolant;
	Fuel fuel;
	Bat bat;
} display_values;

#endif
