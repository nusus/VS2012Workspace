#pragma once
#include <cstdlib>

void processProfit(int* prices, int* left, int* right, int pricesSize);

int maxProfit(int* prices, int pricesSize) {
	if( pricesSize == 0) return 0;
	int max = 0;
	int* left = (int*)malloc(sizeof(int) * pricesSize);
	int* right = (int*)malloc(sizeof(int) * pricesSize);

	processProfit(prices, left, right, pricesSize);

	for (int i =0 ; i<pricesSize ; ++i)
	{
		if(left[i] + right[i] >max)
			max = left[i] + right[i];
	}
	return max;
}

void processProfit( int* prices, int* left, int* right ,int pricesSize)
{
	left[0] = 0;
	int min = prices[0];
	for(int i = 1; i < pricesSize ; ++i){
		if(prices[i] - min > left[i-1]){
			left[i] = prices[i] -min;
		}else
		{
			left[i] = left[i-1];
		}
		if(prices[i] < min){
			min = prices[i];
		}
	}

	right[pricesSize - 1] = 0;
	int max = prices[pricesSize - 1];
	for (int i = pricesSize -2; i>=0 ;--i)
	{
		if(max - prices[i] > right[i +1]){
			right[i] = max - prices[i];
		}
		else
		{
			right[i] = right[i+1];
		}
		if(prices[i] > max){
			max = prices[i];
		}
	}
}

