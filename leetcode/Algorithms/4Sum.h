#pragma once
#include "utility.h"
#include <unordered_map>

using namespace utility;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		size_t len = nums.size();
		vector<vector<int>> ret;
		if(len<4) return ret;
		sort(nums.begin(),nums.end());
		for(int a = 0; a<=len-4; a++){
			for (int b=a+1; b<=len-3; b++)
			{
				int c=b+1;
				int d=len-1;
				while (c<d)
				{
					int sum = nums[a]+nums[b]+nums[c]+nums[d];
					if(sum == target){
						vector<int> vTmp;
						vTmp.reserve(4);
						vTmp.push_back(nums[a]);
						vTmp.push_back(nums[b]);
						vTmp.push_back(nums[c]);
						vTmp.push_back(nums[d]);
						ret.push_back(vTmp);
						c++;
					}
					if(sum<target){
						c++;
					}
					if(sum>target){
						d--;
					}
					
				}
			}
		}
		sort(ret.begin(),ret.end());
		ret.erase(unique(ret.begin(),ret.end()),ret.end());
		return ret;
	}


	vector<vector<int>> twoSum(vector<int>::const_iterator begin,vector<int>::const_iterator end, int target){
		size_t len = distance(begin,end);
		if(len<2) return vector<vector<int>>();
		vector<vector<int>> ret;
		while (begin<end)
		{
			if(*begin + *end == target){
				vector<int> vTmp;
				vTmp.reserve(2);
				vTmp.push_back(*begin);
				vTmp.push_back(*end);
				ret.push_back(vTmp);
				begin ++;
			}
			if(*begin + *end <target){
				begin++;
			}
			if(*begin + *end >target)
			{
				end--;
			}
		}
		return ret;
	}

};
