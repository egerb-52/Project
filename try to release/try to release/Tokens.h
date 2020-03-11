#pragma once

namespace Parsing {
	enum Tokens : char {
		NAME, NUMBER,SIN, COS, TAN, ASIN, ACOS, ATAN, LN,
		PLUS = '+', MINUS = '-', MUL = '*', DIV = '/', POW = '^',
		LP = '(', RP = ')'
	};
}