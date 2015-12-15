#pragma  once
#include "utility.h"

class Solution {
public:
	double myPow(double x, int n) {
		if ( n== 0)
		{
			return 1.0;
		}
		if (n > 0)
		{
			return myPowPositive(x, n);
		}
		return myPowNegative(x, n);
	}

	double myPowNegative(double x, int n) {
		return 1.0 / myPowPositive(x, -n);
	}

	double myPowPositive(double x, unsigned int n) {
		double ret;
		double value = x;
		while (n & 1 ==0)
		{
			value *= value;
			n = n>>1;
		}
		value *= x;
		n = n>>1;
		while (n != 0)
		{
			if (n & 1 == 0)
			{
				value *= value;
			}else
			{
				value *= x;
			}
			n = n>>1;
		}

		return value;
	}

};