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
	bool lowMinFuelPressure;
	int fuelTemp;
	int maxFuelTemp;
} Fuel;

typedef struct {
	float voltage;
	float minVoltage;
	bool lowVoltageIndicator;
	bool lowMinVoltageIndicator;
} Bat;

typedef struct {
	int iat;
	int maxIat;
} IAT;


typedef struct {
	int activeScreen;
	int rpm;
	int maxRpm;

	int speed;
	int maxSpeed;

	float afr;
	int tps;
	bool celIndicator;
	char gear;
	int shiftLampPersentage; // From 0 to 100% - how intense the gear shift lamp should be
	int runTime; // in seconds

	float baro;
	int knockCount;
	double usedFuel;


	Oil oil;
	Coolant coolant;
	Fuel fuel;
	Bat bat;
	IAT iat;
} display_values;

#endif
