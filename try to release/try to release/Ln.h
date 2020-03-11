#pragma once
#include "OneArg.h"
#include <cmath>
class Ln :
	public OneArg
{
public:
	Ln(Node* sub) :OneArg(sub) {}
	double Calc();
	~Ln();
};

