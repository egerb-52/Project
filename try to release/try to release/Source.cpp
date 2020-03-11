#include "Includes.h"
#include <iostream>
using std::cout;
using std::cin;

int main() {
	
	char s[256];
	cin.getline(s, 256);
	string str(s);
	set<string> emp;
	Node* A = Parsing::Parse(str, emp, emp);
	cout << A->Calc() << '\n';
	system("pause");
	return 0;
}