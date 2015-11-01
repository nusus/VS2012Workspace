#pragma once
#include <set>
#include "utility.h"
using namespace utility;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//version 1.0 time limited
		/*int array_length = nums.size();
		for (int i = 0; i < array_length; ++i)
		{
			for (int j = 1; j <= k, i + j <array_length; ++j)
			{
				if ( nums[i] == nums[i + j]) return true;
			}
		}
		return false;*/
		int arrayLength = nums.size();
		if (arrayLength == 0 || arrayLength == 1) return false;
		vector<int>::iterator start = nums.begin();
		vector<int>::iterator end = start;
		set<int> window;
		for ( ; end != nums.end(); ++end)
		{
			if(end - start >k) 
			{
				window.erase(*start);
				++start;
			}
			if (!(window.insert(*end).second))
			{
				return true;
			}
		}
		return false;
	}
};