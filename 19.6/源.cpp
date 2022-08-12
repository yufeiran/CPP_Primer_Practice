#include<iostream>
#include<string>
#include"Sales_data.h"

using namespace std;

class Token {
public:
	Token() :tok(INT), ival(0) {};
	Token(const Token& t) :tok(t.tok) { copyUnion(t); }
	Token& operator=(const Token&);
	~Token() { if (tok == STR)sval.~string(); }

	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const Sales_data&);
private:
	enum { INT, CHAR, DBL, STR,SAL }tok;
	union {
		char cval;
		int  ival;
		double dval;
		std::string sval;
		Sales_data salval;
	};
	void copyUnion(const Token&);
};

Token& Token::operator=(int i)
{
	if (tok == STR)sval.~string();
	tok = INT;
	ival = i;  
	return *this;
}

Token& Token::operator=(char i)
{
	if (tok == STR)sval.~string();
	tok = CHAR;
	cval = i;
	return *this;
}

Token& Token::operator=(double i)
{
	if (tok == STR)sval.~string();
	tok = DBL;
	dval = i;
	return *this;
}


Token& Token::operator=(const std::string& s)
{
	if (tok == STR) {
		sval = s;
	}
	else {
		new(&sval) string(s);
		tok = STR;
	}
	return *this;
}

Token& Token::operator=(const Sales_data& s)
{
	if (tok == STR)sval.~string();
	tok = SAL;
	salval = s;
	return *this;
}



Token& Token::operator=(const Token&t)
{
	if (tok == STR && t.tok != STR) {
		sval.~basic_string();
	}
	if (tok == STR && t.tok == STR) {
		sval = t.sval;
	}
	else {
		copyUnion(t);
	}
	return *this;
}


void Token::copyUnion(const Token&t)
{
	switch (t.tok)
	{
	INT:ival = t.ival; break;
	CHAR:cval = t.cval; break;
	DBL:dval = t.dval; break;
	STR:sval = t.sval; break;
	SAL:salval = t.salval; break;
	default:
		break;
	}

}

int main()
{
	Token t;
	t = 2;
	t = t;
	t = "yuufei";


	return 0;
}