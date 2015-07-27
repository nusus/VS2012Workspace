#pragma once
#include "utility.h"
using namespace utility;
#include <unordered_set>
#include <string>
#include <list>

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.size();
		assert(len>=0);
		vector<bool>  bIsBreaked(len+1,false);
		bIsBreaked[0] = true;
		for (int i= 1; i<len+1 ; ++i)
		{
			for (int j = i-1 ; j>=0 ; --j)
			{
				if(bIsBreaked[j] && wordDict.count(s.substr(j,i-j))>0){
					bIsBreaked[i] = true;
					break;
				}
			}
		}
		if(bIsBreaked[len])
			return breakWord(s,bIsBreaked,wordDict);
		return vector<string>();
	}

	void breakWordImpl(const string& s , const vector<bool>& bIsBreaked, const unordered_set<string>& wordDict , string tmp, int index, vector<string>& ret){
		string strTmp;
		for (int len = 1 ; index + len <=s.size(); ++len)
		{
			if(bIsBreaked[index+len] && wordDict.count(s.substr(index,len))>0){
				string tStr = s.substr(index, len);
				strTmp = tmp + (tStr + " ");
				if( index +len <s.size() )
					breakWordImpl(s, bIsBreaked, wordDict, strTmp, index + len,ret);
				else{
					ret.push_back(strTmp);
					return;
				}
			}

		}
	}
	
	vector<string> breakWord(const string& s , const vector<bool>& bIsBreaked , const unordered_set<string>& wordDict){
		vector<string> ret;
		string tmp;
		int index =0;
		breakWordImpl(s, bIsBreaked, wordDict, tmp, index, ret);
		return ret;
	}
};