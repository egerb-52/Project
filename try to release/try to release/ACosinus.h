#pragma once
#include "OneArg.h"
class ACosinus :
	public OneArg
{
public:
	ACosinus(Node* sub) :OneArg(sub) {}
	double Calc();
	~ACosinus();
};

