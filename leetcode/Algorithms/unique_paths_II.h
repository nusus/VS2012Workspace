#pragma once

#include "utility.h"

using namespace utility;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> pp(m*n);
		for (int i=0;i<m;++i)
		{
			for (int j=0;j<n;++j)
			{
				if (!obstacleGrid[i][j])
				{
					if( i==0&& j==0){
						pp[0] =1;
					}else if( i==0 ){
						pp[i*m+j] = pp[i*n+j-1];
					}else if (j==0 ){
						pp[i*n+j]  =pp[(i-1)*n+j];
					}
					else
					{
						pp[i*n+j] = pp[(i-1)*n+j]+pp[i*n+j-1];
					}	
				}				
			}
		}
		return pp[m*n-1];
	}
};