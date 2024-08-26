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
	float maxOilPressure;
	bool lowOilPressureIndicator;

	float fuelPressure;
	float minFuelPressure;

	int voltage;
	bool lowVoltageIndicator;

	int fuelTemp;
	int iat;
	float afr;
	int tps;
	bool celIndicator;
} display_values;
