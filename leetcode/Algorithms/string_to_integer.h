#pragma once

#include "utility.h"
using namespace utility;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		bool sign = true;
		int index = 0;
		while (str[index] == ' ')
		{
			++index;
		}
		if(str[index] == '-'){
			sign = false;
			++index;
		}else if(str[index] == '+')
		{
			++index;
		}
		long long ret =0;
		while (str[index] >='0' && str[index] <='9' && str[index]!='\0')
		{
			ret = ret*10 + (str[index] - '0');
			if(ret> INT_MAX) return sign?INT_MAX:INT_MIN;
			++index;
		}
		return sign?ret:(-ret);
	}
};