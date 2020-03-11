#pragma once
#include "OneArg.h"
class UnMinus :
	public OneArg
{
public:
	UnMinus(Node* sub) :OneArg(sub){}
	double Calc();
	~UnMinus();
};

