#pragma once
#include "OneArg.h"
class ATangens :
	public OneArg
{
public:
	ATangens(Node* sub) :OneArg(sub) {}
	double Calc();
	~ATangens();
};

