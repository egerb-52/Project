#include "Parsing.h"

namespace Parsing {
	queue<Tokens> tokens;
	queue<double> numbers;
	queue<string> names;
	
	Node* Parse(string str, const set<string>& localVars, const set<string>& globalVars) {
		if (Tokenize(str, localVars, globalVars)) {
			auto res = E();
			Clean();
			return res;
		}
		Clean();
		return nullptr;
	}

	void Clean() {
		while (!tokens.empty())
			tokens.pop();
		while (!numbers.empty())
			numbers.pop();
		while (!names.empty())
			names.pop();
	}

	bool Tokenize(string str, const set<string>& localVars, const set<string>& globalVars) {
		str += "     ";
		for (auto p = str.begin(); p < str.end()-5; ) {
			switch (*p) {
			case ' ':case '\t':
				p++;
				break;
			case '+':case '-':
			case '*':case '/':
			case '^':case '(':case ')':
				tokens.push(static_cast<Tokens>(*p));
				p++;
				break;
			case 's':
				if (string(p, p + 4) == "sin(") {
					tokens.push(SIN);
					p += 4;
				}
				else
					goto tokenize_endcase;
				break;
			case 'c':
				if (string(p, p + 4) == "cos(") {
					tokens.push(COS);
					p += 4;
				}
				else
					goto tokenize_endcase;
				break;
			case 't':
				if (string(p, p + 4) == "tan(") {
					tokens.push(TAN);
					p += 4;
				}
				else
					goto tokenize_endcase;
				break;
			case 'a':
				if (string(p, p + 5) == "asin(") {
					tokens.push(ASIN);
					p += 5;
				}
				else if (string(p, p + 5) == "acos(") {
					tokens.push(ACOS);
					p += 5;
				}
				else if (string(p, p + 5) == "atan(") {
					tokens.push(ATAN);
					p += 5;
				}
				else
					goto tokenize_endcase;
				break;
			case 'l':
				if (string(p, p + 3) == "ln(") {
					tokens.push(LN);
					p += 3;
				}
				else
					goto tokenize_endcase;
				break;
			tokenize_endcase:default:
				auto t = p;
				if (isalpha(*p) || *p == '_') {
					while (isalpha(*t) || *t == '_')
						t++;
					tokens.push(NAME);
					names.push(string(p, t));
					if (!globalVars.count(names.front())
						&& !localVars.count(names.front())) {
						Clean();
						return false;
					}
					p = t;
					break;
				}
				if (isalnum(*p)) {
					while (isalnum(*t)||*t == '.')
						t++;
					tokens.push(NUMBER);
					numbers.push(atof(string(p, t).c_str()));
					p = t;
					break;
				}
				Clean();
				return false;
			}
		}
		return true;
	}

	Node* E() {
		Node* left, *right = nullptr;
		if (tokens.empty())
			return nullptr;
		if (tokens.front() == PLUS)
			tokens.pop();
		if (tokens.front() == MINUS) {
			tokens.pop();
			auto res = T();
			if (res == nullptr)
				return nullptr;
			left = new UnMinus(res);
		}
		else {
			left = T();
		}
		if (left == nullptr)
			return nullptr;
		if (tokens.empty()||tokens.front() == RP)
			return left;
		if (tokens.front() == PLUS) {
			tokens.pop();
			right = E();
		}
		else if (tokens.front() == MINUS) {
			tokens.pop();
			auto res = E();
			if (res == nullptr)
				return nullptr;
			right = new UnMinus(res);
		}
		
		if (right == nullptr) {
			delete left;
			return nullptr;
		}
				
		return new Plus(left, right);
	}

	Node* T() {
		auto left = F();
		if (left == nullptr)
			return nullptr;
		if (tokens.empty() || (tokens.front() != MUL && tokens.front() != DIV))
			return left;
		auto oper = tokens.front();
		tokens.pop();
		auto right = T();
		if (right == nullptr) {
			delete left;
			return nullptr;
		}
		switch (oper)
		{
		case MUL:
			return new Multiply(left, right);
		case DIV:
			return new Divide(left, right);
		}
	}

	Node* F() {
		auto left = B();
		if (left == nullptr)
			return nullptr;
		if (tokens.empty() || tokens.front() != POW)
			return left;
		tokens.pop();
		auto right = F();
		if (right == nullptr) {
			delete left;
			return nullptr;
		}
		return new Power(left, right);
	}

	Node* B() {
		if (tokens.empty())
			return nullptr;
		const set<Tokens> t({ LP, SIN, COS, TAN, ASIN, ACOS, ATAN, LN });
		auto tok = tokens.front();
		if(t.count(tok)){
			tokens.pop();
			auto sub = E();
			if (sub == nullptr)
				return nullptr;
			if (tokens.empty() || tokens.front() != RP) {
				delete sub;
				return nullptr;
			}
			tokens.pop();

			switch (tok) {
			case LP:
				return sub;
			case SIN:
				return new Sinus(sub);
			case COS:
				return new Cosinus(sub);
			case TAN:
				return new Tangens(sub);
			case ASIN:
				return new ASinus(sub);
			case ACOS:
				return new ACosinus(sub);
			case ATAN:
				return new ATangens(sub);
			case LN:
				return new Ln(sub);
			}
		}
		else {
			return N();
		}
	}

	Node* N() {
		if (tokens.empty())
			return nullptr;
		Node* res;
		switch (tokens.front()) {
		case NUMBER:
			tokens.pop();
			res = new Numbers(numbers.front());
			numbers.pop();
			return res;
		case NAME:
			tokens.pop();
			res = new Variables(names.front());
			names.pop();
			return res;
		}
		return nullptr;
	}
}