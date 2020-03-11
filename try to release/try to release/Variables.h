#pragma once
#include "ZeroArg.h"
class Variables :
	public ZeroArg
{
protected: 
	string name;
public:
	Variables(string name) :name(name){}
	double Calc();
	~Variables();
};

