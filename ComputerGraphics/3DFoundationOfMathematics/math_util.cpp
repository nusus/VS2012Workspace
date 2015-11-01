#include <math.h>

#include "math_util.h"
#include "Vector3.h"

const tdfom::Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

extern float tdfom::WrapPI( float theta )
{
	theta += tdfom::g_kPI;
	theta -= floor(theta * tdfom::g_k1Over2PI) * tdfom::g_k2PI;
	theta -= tdfom::g_kPI;
	return theta;
}

extern float tdfom::SafeAcos( float x )
{
	if(x <= -1.0f) 
		return tdfom::g_kPI;
	if (x >= 1.0f){
		return 0.0f;
	}
	return acos(x);
}
