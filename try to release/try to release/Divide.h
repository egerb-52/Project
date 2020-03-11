#pragma once
#include "TwoArg.h"
class Divide :
	public TwoArg
{
public:
	Divide(Node* left, Node* right) :TwoArg(left, right) {}
	double Calc();
	~Divide();
};
