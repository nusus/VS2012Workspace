#pragma once 

#include "utility.h"

using namespace utility;

class Solution {
public:
	enum class DirectionEnum : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		UNKOWN
	};

	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<DirectionEnum> lDirections;
		lDirections.reserve(row+col);

		vector<vector<int>> dp(row, (vector<int>(col)));
		for (int i=0; i<row ; ++i)
		{
			for (int j=0; j<col ;++j)
			{
				if(i==0 && j==0){
					dp[i][j] = grid[i][j];
				}else if ( j==0)
				{
					dp[i][j] = dp[i-1][j] + grid[i][j];
					lDirections.push_back(DirectionEnum::RIGHT);
				}else if ( i==0)
				{
					dp[i][j] = dp[i][j-1] + grid[i][j];
					lDirections.push_back(DirectionEnum::DOWN);
				}else{
					int minVal = (dp[i-1][j]>dp[i][j-1]?dp[i][j-1]:dp[i-1][j]);
					dp[i][j] = minVal + grid[i][j];
					if(minVal == dp[i-1][j])
						lDirections.push_back(DirectionEnum::RIGHT);
					else
						lDirections.push_back(DirectionEnum::DOWN);
				}
			}
		}

		return dp[row-1][col-1];
	}
};
