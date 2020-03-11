#pragma once
#include <string>

using std::string;

class Node
{
public:
	Node();
	virtual double Calc() = 0;
	virtual Node* Clone() = 0;
	~Node();
};

