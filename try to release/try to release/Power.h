#pragma once
#include "TwoArg.h"
#include <cmath>
class Power :
	public TwoArg
{
public:
	Power(Node* left, Node* right) :TwoArg(left, right){}
	double Calc();
	~Power();
};
//left - число
