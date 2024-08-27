#include <stdbool.h>

typedef struct {
	int rpm;
	int maxRpm;

	int coolantTemp;
	bool coolantTempWarning;
	int maxCoolantTemp;
	bool maxCoolentTempWarning;

	int oilTemp;
	int maxOilTemp;

	int speed;
	int maxSpeed;

	float oilPressure;
	float minOilPressure;
	bool minOilPressureWarning;
	bool lowOilPressureIndicator;

	float fuelPressure;
	float minFuelPressure;

	float voltage;
	bool lowVoltageIndicator;

	int fuelTemp;
	int iat;
	float afr;
	int tps;
	bool celIndicator;
	char gear;
} display_values;
