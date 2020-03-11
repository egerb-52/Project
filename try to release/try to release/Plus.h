#pragma once
#include "TwoArg.h"
class Plus :
	public TwoArg
{
public:
	Plus(Node* left, Node* right) :TwoArg(left, right) {}
	double Calc();
	~Plus();
};

