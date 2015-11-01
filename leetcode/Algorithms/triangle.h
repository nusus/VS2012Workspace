#pragma once

#include "utility.h"
#include <algorithm>
using namespace utility;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int rows = triangle.size();
		if(rows<1) return 0;
		if(rows==1) return triangle[0][0];
		vector<vector<int>> dp(rows,(vector<int>(rows,0)));
		dp[0][0] = triangle[0][0];
		for (int rowIndex =1; rowIndex<rows ;++rowIndex)
		{
			for (int colIndex=0; colIndex<=rowIndex; ++colIndex)
			{
				if (colIndex ==0)
				{
					dp[rowIndex][colIndex] =triangle[rowIndex][colIndex]+dp[rowIndex-1][colIndex];
				}else if(colIndex == rowIndex)
				{
					dp[rowIndex][colIndex]=triangle[rowIndex][colIndex]+ dp[rowIndex-1][colIndex-1];
				}
				else
				{
					int min = dp[rowIndex-1][colIndex-1] < dp[rowIndex-1][colIndex] ? dp[rowIndex-1][colIndex-1]:dp[rowIndex-1][colIndex];
					dp[rowIndex][colIndex] = min +triangle[rowIndex][colIndex];
				}
			}
		}

		return *(min_element(dp[rows-1].begin(), dp[rows-1].end()));
	}
};