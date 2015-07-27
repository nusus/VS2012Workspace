#pragma  once


#include "utility.h"
#include <set>

using namespace utility;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if(nums.size()<4) return vector<vector<int>>();
		sort(nums.begin(),nums.end());
		set<vector<int>> tSet;
		vector<int> tmp;
		tmp.reserve(4);
		ksumImpl(nums, 0, 4, target, tSet, tmp);
		vector<vector<int>> ret(tSet.begin(),tSet.end());
		return ret;
	}
	void ksumImpl ( vector<int>& nums, int begin, int k, int target, std::set<vector<int>>& ret, vector<int> tmp)
	{
		size_t len = nums.size();
		if( k==2 ){
			size_t nLeftCursor = begin;
			size_t nRightCursor = len-1;
			while( nLeftCursor < nRightCursor ){
				int sum = nums[nLeftCursor]+nums[nRightCursor];
				if(sum == target){
					vector<int> vTmp(tmp.begin(),tmp.end());
					vTmp.push_back(nums[nLeftCursor]);
					vTmp.push_back(nums[nRightCursor]);
					ret.insert(ret.end(),vTmp);
					nLeftCursor ++;
				}
				if(sum<target){
					nLeftCursor++;
				}
				if(sum>target){
					nRightCursor--;
				}
			}
			return ;
		}
		for ( int i=begin; i < len-k; i++){
			vector<int> vTmp(tmp.begin(),tmp.end());
			vTmp.push_back(nums[begin]);
			ksumImpl(nums, begin+1, k-1, target - nums[begin], ret, vTmp);
		}
	}
};