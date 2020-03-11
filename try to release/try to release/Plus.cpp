#include "Plus.h"


//Plus::Plus(Node * left, Node * right):TwoArg(left, right)
//{
//}

double Plus::Calc()
{
	return left->Calc() + right->Calc();
}


Plus::~Plus()
{
}
