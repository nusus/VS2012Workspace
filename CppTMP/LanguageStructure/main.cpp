#include "DoubleDispatch.h"
#include<iostream>

int main()
{
	ShapeTestImpl<ShapeTest>(Rectangle(), Triangle());
	std::cin.get();
	return 0;
}