#pragma once

#include "utility.h"
using namespace utility;

struct PalindromeProbe 
{
	size_t len;
	int begin;
	int end;
	int mid;
};

class Solution {
public:
	string longestPalindrome(string s) {
		size_t len = s.size();
		if(len<=2) return s;
		PalindromeProbe maxPalindrome;
		maxPalindrome.begin = maxPalindrome.end =maxPalindrome.mid = 1;
		maxPalindrome.len =1;

		PalindromeProbe curPalindrome = maxPalindrome;

		for(int i=1; i< len-1; ++i)
		{
			curPalindrome.begin = curPalindrome.end = curPalindrome.mid = i;
			curPalindrome.len =1;
			for ( ; (--curPalindrome.begin) >=0 && (++curPalindrome.end) < len;)
			{
				if(s[curPalindrome.begin] == s[curPalindrome.end]){
					curPalindrome.len+=2;
				}else
				{
					break;
				}
			}
			++curPalindrome.begin;
			--curPalindrome.end;
			if (curPalindrome.len>maxPalindrome.len)
			{
				maxPalindrome = curPalindrome;
			}
		}
		for(int i=1; i< len; ++i)
		{
			curPalindrome.begin =  i;
			curPalindrome.end   = i-1;
			curPalindrome.len =0;
			for ( ; (--curPalindrome.begin) >=0 && (++curPalindrome.end) < len;)
			{
				if(s[curPalindrome.begin] == s[curPalindrome.end]){
					curPalindrome.len+=2;
				}else
				{
					break;
				}
			}
			++curPalindrome.begin;
			--curPalindrome.end;
			if (curPalindrome.len>maxPalindrome.len)
			{
				maxPalindrome = curPalindrome;
			}
		}

		return s.substr(maxPalindrome.begin, maxPalindrome.len);
	}
};