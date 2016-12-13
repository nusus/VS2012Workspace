#pragma once


template<bool c, typename Then, typename Else > 
class IF_ {};

template<typename Then, typename Else>
class IF_<true, Then, Else> 
{ 
public: 
	typedef Then retType; 
};

template<typename Then, typename Else>
class IF_<false, Then, Else> 
{ 
public: 
	typedef Else retType; 
};

template<template<typename> class Condition, typename Statement >
class WHILE_
{
	template<typename Statement>
	class STOP
	{
	public:
		typedef Statement retType;
	};
public:
	typedef typename
		IF_<Condition<Statement>::retType,
		WHILE_<Condition, typename Statement::Next>,
		STOP<Statement>>::retType::retType
		retType;
};

template<int n, int e>
class SumPow
{
	template<int i, int e>
	class pow_e
	{
	public:
		enum 
		{
			ret = i * pow_e<i, e - 1>::ret
		};
	};

	template<int i>
	class pow_e<i, 0>
	{
	public:
		enum 
		{
			ret = 1
		};
	};

	template<int i >
	class pow
	{
	public:
		enum
		{
			ret = pow_e<i, e>::ret
		};
	};

	template<typename state>
	class cond
	{
	public:
		enum
		{
			ret = (state::ri <= n)
		};
	};

	template<int i, int sum>
	class state
	{
	public:
		typedef state<i + 1, sum + pow<i>::ret> Next;
		enum 
		{
			ri = i, 
			ret = sum
		};
	};

public:
	enum 
	{
		ret = WHILE_<cond, stat<1, 0> >::retType::ret
	};
};


