#include<iostream>

using namespace std;

class Base
{
public:
	Base() = default;
	Base(const Base& b) {
		a = b.a;
	}
	Base(int A) :a(A) {};
	int  a;
};

class P1 :public Base {
public:
	P1() :Base() {};
	P1(const P1& p) {
		a = p.a;
	}
	P1(int A) :Base(A) {};
};

int main()
{


	return 0;
}