#pragma once
#include "Node.h"
class OneArg :
	public Node
{
protected:
	Node* sub;
public:
	OneArg(Node* sub) :sub(sub)
	{}

	~OneArg();
};

