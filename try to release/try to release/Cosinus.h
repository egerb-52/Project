#pragma once
#include "OneArg.h"
#include <cmath>
class Cosinus :
	public OneArg
{
public:
	Cosinus(Node* sub) :OneArg(sub){}
	double Calc();
	~Cosinus();
};

