#pragma once
#include <algorithm>

/************************************************************************/
/* 
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
/************************************************************************/
class Solution {
public:
	bool isPalindrome(int x) {
		if( x < 0) return false;
		
		if( x == 0) return true;
		
		size_t bits = numberOfDigits(x);
		
		if (bits == 1) return true;

		if (bits == 2){
			if ( x / 10 == x % 10){
				return true;
			}
			return false;
		}
		int highBit = x / std::pow(10, bits -1 ) ;
		int lowBit = x % 10;
		if( highBit != lowBit){
			return false;
		}
		return isPalindrome(x - highBit * std::pow(10, bits -1 ) - lowBit);
	}
	
	size_t numberOfDigits(int x){
		size_t ret = 1;
		int remain = x / 10;
		while (remain)
		{
			ret++;
			remain /= 10;
		}
		return ret;
	}

};