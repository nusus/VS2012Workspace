#pragma once
#include "utility.h"
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		assert(!nums.empty());
		int nMajorityElement = nums[0];
		int nAppearCount = 0;

		for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
		{
			if(*itr != nMajorityElement){
				if (nAppearCount == 0)
				{
					nAppearCount++;
					nMajorityElement = *itr;
				}
				else
				{
					nAppearCount--;
				}
			}
			else
			{
				nAppearCount++;
			}
		}

		return nMajorityElement;
	}
};