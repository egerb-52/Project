#pragma once
#include "Includes.h"
#include "Tokens.h"


namespace Parsing {

	Node* Parse(string str, const set<string>& localVars, const set<string>& globalVars);
	void Clean();
	bool Tokenize(string, const set<string>& localVars, const set<string>& globalVars);
	Node* E();
	Node* T();
	Node* F();
	Node* B();
	Node* N();
}