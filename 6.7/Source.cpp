#include<iostream>
#include<vector>
#include<string>

using namespace std;

int cal(int a, int b) 
{
	return a + b;
}

int ADD(int a, int b)
{
	return a + b;
}

int SUB(int a, int b)
{
	return a - b;
}

int MUL(int a, int b)
{
	return a * b;
}

int DIV(int a, int b)
{
	return a / b;
}

vector<int (*)(int, int)>fvec;

int main()
{
	fvec.push_back(&ADD);
	fvec.push_back(&SUB);
	fvec.push_back(&MUL);
	fvec.push_back(&DIV);

	int a = 5, b = 9;
	cout << fvec[0](a, b) << endl;
	cout << fvec[1](a, b) << endl;
	cout << fvec[2](a, b) << endl;
	cout << fvec[3](a, b) << endl;



	return 0;
}