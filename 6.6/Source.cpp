#include<iostream>
#include<string>
#include<vector>

using namespace std;

void f()
{
	cout << __func__ << endl;
}

void f(int a)
{
	cout << "int" << endl;
}

void f(int a, int b)
{
	cout << "int int" << endl;
}

void f(double a, double b = 3.14)
{
	cout << "double double" << endl;
}

int calc(char* a, char* b) {
	return 0;
}

int calc(char* const a, char* const b) {
	return 0;
}
int main()
{
	//f(2.56, 42);
	f(42);
	f(42,0);
	f(2.56, 3.14);
	

	return 0;
}