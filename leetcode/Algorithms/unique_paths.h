#pragma  once

#include "utility.h"
#include <iostream>
using namespace utility;

class Solution {
public:
	int uniquePaths(int m, int n) {
		assert( m>=0 && n>=0);
		return uniquePathsImpl(m,n);
	}

	int uniquePathsImpl(int m, int n)
	{
		vector<int> pp(m*n);
		for (int i=0;i<m;++i)
		{
			for (int j=0;j<n;++j)
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
		return pp[m*n-1];
	}
};