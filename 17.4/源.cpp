#include<iostream>
#include<random>
using namespace std;

unsigned int make_randon_uint(unsigned int min,unsigned int max, unsigned int seed = 0)
{
	default_random_engine e;
	uniform_int_distribution<unsigned int>u(min, max);
	e.seed(seed);
	return u(e);
}

int main()
{

	cout << make_randon_uint(0,12151152,999) << endl;

	return 0;
}