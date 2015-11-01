#pragma once
#include "utility.h"

using namespace utility;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size()-1;
		int mid = (start + end)/2;
		for (;start < end;)
		{
			if (nums[mid] == target)
			{
				return mid;
			}
			else
			{
				if( nums[mid] < target) start = mid +1;
				else end =mid;
			}
			mid = (start+end)/2 ;
		}
		return start;
	}
};
