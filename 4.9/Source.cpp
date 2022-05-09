#include<iostream>
#include<vector>
using namespace std;


int f() {
	cout << 233 << endl;
	return 1;
}
struct P {
	int mem[10];
};

int main()
{
	//4.28
	cout << "int:" << sizeof(int) << " char:" << sizeof(char) << " float:" << sizeof(float) << " double:" << sizeof(double)<<" bool:"<<sizeof(bool) << endl;

	//4.29
	int x[10]; int* p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	P t;

	P* ptr = &t;

	cout << sizeof f() << endl;
	cout << sizeof & f << endl;
	cout << sizeof ptr->mem[0] << endl;

	int a = 5, b = 10;
	cout << sizeof (a < b) << endl;

	//4.30
	vector<int>ivec(10, 1);
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;



	//int x = 0, y = 0;
	//a ? ++x, ++y : --x, --y;
	int i = 2;
	double d = 3.5;
	i *= static_cast<int>(d);
	i *= static_cast<int>(d);
	i *= static_cast<int>(d);
	//i *= d;
	//i *= d;
	//i *= d;
	cout << i << endl;

	return 0;
}
