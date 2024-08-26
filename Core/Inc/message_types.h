#include <stdbool.h>

typedef struct {
	int rpm;
	int maxRpm;

	int coolantTemp;
	int maxCoolantTemp;

	int oilTemp;
	int maxOilTemp;

	int speed;
	int maxSpeed;

	float oilPressure;
	float minOilPressure;
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
} display_values;
