#pragma once
#include "TwoArg.h"
class Multiply :
	public TwoArg
{
public:
	Multiply(Node* left, Node* right) :TwoArg(left, right) {}
	double Calc();
	Node* Clone() {
		auto l = left->Clone();
		auto r = right->Clone();
		return new Multiply(l, r);
	}
	~Multiply();
};

