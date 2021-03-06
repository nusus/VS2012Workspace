#ifndef math_util_h__
#define math_util_h__

#include <math.h>

namespace tdfom{

	const float g_kPI = 3.141592654f;
	const float g_k2PI = g_kPI * 2.0f;
	const float g_kPIOver2 = g_kPI / 2.0f;
	const float g_k1OverPI = 1.0f / g_kPI;
	const float g_k1Over2PI = 1.0f / g_k2PI;

	//************************************
	// Description:通过加适当的2pi倍数将角度限制在-pi到pi的区间内
	// Method:    WrapPI
	// FullName:  tdfom::WrapPI
	// Access:    public 
	// Returns:   extern float
	// Qualifier:
	// Parameter: float theta
	//************************************
	extern float WrapPI(float theta);


	//************************************
	// Description:安全的反三角函数
	// Method:    SafeAcos
	// FullName:  tdfom::SafeAcos
	// Access:    public 
	// Returns:   extern float
	// Qualifier:
	// Parameter: float x
	//************************************
	extern float SafeAcos(float x);

	inline void SinCos(float theta, float* return_sin, float* return_cos) {
		*return_sin = sin(theta);
		*return_cos = cos(theta);
	}

}

#endif // math_util_h__


