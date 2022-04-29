#include<iostream>

int main()
{
	int i = 0, & r1 = i;
	double d = 0, & r2 = d;

	r2 = 3.1415926;
	r2 = r1;
	i = r2;
	r1 = d;
	//2.17
	i = 5; r1 = 10;
	std::cout << i << " " << r1 << std::endl;


	//2.18
	int a = 233;
	int b = 666;
	int* p = &a;
	p = &b;
	*p = a;
	 int ii = 0;
	//int* ip = ii;


	return 0;
}