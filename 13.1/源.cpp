#include<iostream>
#include<vector>
using namespace std;

struct X {
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X& x) { cout << "X& operator=(const(X &x)" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};


void fun()
{
	X x1, x3;


}


int nowIndex = 0;

class numbered
{
public:
	numbered() { index = nowIndex; nowIndex++; }
	numbered(const numbered& n) { index = nowIndex; nowIndex++; }
	numbered& operator=(const numbered& n) { index = nowIndex; nowIndex++; }
	int index;
};

void f(numbered s) { cout << s.index << endl; }
void f1(const numbered &s) { cout << s.index << endl; }



class Employee
{
public:
	Employee() { id = idNow; addId(); };
	Employee(const string& s) { id = idNow; addId(); name = s; }
	static int employeeInit();
	

private:
	static void addId() { idNow++; }
	string name;
	int id;
	static int  idNow;
};
int Employee::idNow = Employee::employeeInit();
int Employee::employeeInit()
{
	return 0;
}


int main()
{
	//X x1, x3;
	//X X2(x1);
	//x3 = x1;
	//fun();
	//vector<X>xvec;
	//xvec.push_back(x1);

	//numbered a, b = a, c = a;
	////f(a); f(b); f(c);
	//f1(a); f1(b); f1(c);

	Employee::employeeInit();

	Employee e1("yufeiran");
	Employee e2 = e1;
	Employee e3("ddd");





	return 0;
}