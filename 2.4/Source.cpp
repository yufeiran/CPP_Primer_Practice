#include<iostream>

 int abc()
{

	return 111;
}

int main()
{
	int a = 444;
	const int max = a;
	const int aaa = 3333;
	const int* p = &max;
	p = &aaa;

	const int& r = 1;
	int i = 111;
	const int i2 = i, & r = i;

	//const int  ic ,&r = ic;
	int* p1 , * const p2 = nullptr;

	//constexpr int MAX = abc();
	const int  MMM = abc();
	const int aaa = 333;

	//int a[aaa];

	 int null = 0, *  p = &null;

	return 0;
}