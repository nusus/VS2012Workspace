#pragma once
#include "utility.h"
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum =nums[0] ,tmpSum =nums[0];
		int len = nums.size();
		for (int i=1; i<len; ++i)
		{
			if (tmpSum<=0)
			{
				tmpSum = 0;
			}
			tmpSum+=nums[i];
			maxSum = max(tmpSum, maxSum);
		}

		return maxSum;
	}
};