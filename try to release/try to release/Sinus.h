#pragma once
#include "OneArg.h"
#include <cmath>

class Sinus :
	public OneArg
{
public:
	Sinus(Node* sub) :OneArg(sub){}
	double Calc();
	~Sinus();
};

