#include <message_types.h>
#include <gui/common/DataUtils.hpp>
#include <touchgfx/Utils.hpp>

using namespace dataUtils;

display_values dataUtils::getDefaults(int pageIndex){
	Oil oil = {0,0,0,0,0,1};
	Coolant coolant = {0,0,0,0};
	Fuel fuel = {0,0,0,0,0};
	Bat bat = {0,0,0,0};
	IAT iat = {0,0};

	display_values vals = {pageIndex,0,0,0,0,0,0,1,'N',0,0,0,0,0, oil, coolant, fuel, bat, iat};
	return vals;
}

bool dataUtils::compare_float(float x, float y, float epsilon){
	if(touchgfx::abs(x - y) < epsilon)
		return true; //they are same
	return false; //they are not same
}

