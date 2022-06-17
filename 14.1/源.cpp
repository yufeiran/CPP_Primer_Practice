#include"Sales_data.h"
#include<iostream>
using namespace std;

int main()
{
	Sales_data s1("yu", 10, 20);
	Sales_data s2("yu", 20, 1);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1 + s2 << endl;
	Sales_data s3;
	cin >> s3;
	cout << s3 << endl;

	return 0;
}