#pragma  once
#include "utility.h"
#include <unordered_set>

using namespace utility;

class Solution {
public:
	void findAllPathImpl(const vector<vector<int>>& mat,int start, int target,vector<int> tmp,vector<vector<int>>& ret)
	{
		if(mat[start][target]){
			tmp.push_back(target);
			tmp.push_back(start);
			reverse(tmp.begin(),tmp.end());
			ret.push_back(tmp);
			return;
		}
		for (int i=target-1; i>start ;--i)
		{
			vector<int> vTmp = tmp;
			if(mat[i][target]){	
				vTmp.push_back(target);
				findAllPathImpl(mat,start, i ,vTmp, ret);
			}
		}
	} 
	vector<vector<int>> findAllPath(const vector<vector<int>>& mat , int start, int target){
		vector<int> tmp;
		tmp.reserve(mat[0].size());
		vector<vector<int>> ret;
		findAllPathImpl(mat,start,target,tmp,ret);

		return ret;
	}
};