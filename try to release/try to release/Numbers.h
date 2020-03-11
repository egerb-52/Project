#pragma once
#include "ZeroArg.h"
class Numbers :
	public ZeroArg
{
protected:
	double value;
public:
	Numbers(double val) :value(val){}
	double Calc();
	~Numbers();
};

