#pragma once
#include "OneArg.h"
class ASinus :
	public OneArg
{
public:
	ASinus(Node* sub) :OneArg(sub) {}
	double Calc();
	~ASinus();
};

