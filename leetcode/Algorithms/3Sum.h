#pragma once 
#include "utility.h"
using namespace utility;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len =nums.size();
		vector<vector<int>> ret;
		if(len<3) return ret;
		sort(nums.begin(),nums.end());
		for (int a=0;a<len-2;++a)
		{
			if (a>0 && nums[a]==nums[a-1])
			{
				continue;
			}
			int b=a+1;
			int c=len-1;
			while (b<c)
			{
				if(b>a+1 && nums[b]==nums[b-1])
				{
					b++;
					continue;
				}
				if(c< len-1 && nums[c] == nums[c+1])
				{
					c--;
					continue;
				}
				int nSumVal = nums[a]+nums[b]+nums[c];
				if(nSumVal == 0){
					vector<int> vTmp;
					vTmp.reserve(3);
					vTmp.push_back(nums[a]);
					vTmp.push_back(nums[b]);
					vTmp.push_back(nums[c]);
					ret.push_back(vTmp);
					++b;
				}else
				{
					if(nSumVal<0){
						++b;
					}else
					{
						--c;
					}
				}
			}
		}
		return ret;
	}
};