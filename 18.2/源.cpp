#include<iostream>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
using namespace Exercise;
int ivar = 0;



void main()
{
	using Exercise::ivar;
	double dvar = 3.1416;
	int iobj = _Mtx_internal_imp_alignment + 1;
	++ivar;
	++::ivar;
}