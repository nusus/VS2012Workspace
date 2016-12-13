#pragma once
#include <iostream>

class Shape {};
class Rectangle : public Shape {};
class Cycle : public Shape {};
class Triangle : public Shape {};


struct ShapeTest 
{
	void operator()(Shape&, Shape&)
	{
		std::cout << "shape:shape" << std::endl;
	}

	void operator()(Rectangle&, Rectangle&)
	{
		std::cout << "Rectangle:Rectangle" << std::endl;
	}

	void operator()(Cycle&, Cycle&)
	{
		std::cout << "Cycle:Cycle" << std::endl;
	}

	void operator()(Triangle&, Triangle&)
	{
		std::cout << "Triangle:Triangle" << std::endl;

	}

	void operator()(Triangle&, Rectangle&)
	{
		std::cout << "Triangle:Rectangle" << std::endl;
	}
};


template<typename Func, typename T1, typename T2>
void ShapeTestImpl(T1& lhs, T2& rhs)
{
	Func func;
	func(lhs, rhs);
}