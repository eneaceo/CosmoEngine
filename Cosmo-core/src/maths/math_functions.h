#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


namespace cosmo { namespace maths {

		inline float to_radians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}

} }