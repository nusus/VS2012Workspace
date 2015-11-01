#pragma once

#include <stdio.h>

namespace utility{
	void PrintNnumberImpl(int n){
		if(n<=0) return;
		for (int i=0;i<10;++i)
		{
			PrintNnumberImpl(n-1);
			printf("%d",i);
			if (n==1)
			{
				printf("\n");
				break;
			}
		}
		
	}

	void PrintNnumberRecursively(int n){

	}

	void PrintNnumber(int n){
			
	}
};