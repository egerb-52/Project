#include "Power.h"



//Power::Power()
//{
//}

double Power::Calc()
{
	return pow(left -> Calc(), right -> Calc());
}


Power::~Power()
{
}
