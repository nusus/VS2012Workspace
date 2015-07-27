#pragma once
#include "utility.h"
using namespace utility;
#include <unordered_set>
#include <string>

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.size();
		assert(len>=0);
		vector<bool>  bIsBreaked(len+1,false);
		bIsBreaked[0] = true;
		for (int i= 1; i<len+1 ; ++i)
		{
			for (int j = i-1 ; j>=0 ; --j)
			{
				if(bIsBreaked[j] && wordDict.find(s.substr(j,i-1)) !=wordDict.end()){
					bIsBreaked[i] = true;
					break;
				}
			}
		}

		return bIsBreaked[len];
	}
};
