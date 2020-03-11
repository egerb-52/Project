#pragma once
#include "Node.h"
class TwoArg :
	public Node
{
protected:
	Node* left;
	Node* right;
public:
	TwoArg(Node* left, Node* right):left(left), right(right)
	{}
	~TwoArg();
};

