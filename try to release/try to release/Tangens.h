#pragma once
#include "OneArg.h"
#include <cmath>
class Tangens :
	public OneArg
{
public:
	Tangens(Node* sub) :OneArg(sub){}
	double Calc();
	~Tangens();
};

