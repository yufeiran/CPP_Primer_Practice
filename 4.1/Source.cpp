#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

	const char* cp = "Hello World";
	if (cp && *cp) {

	}
	cout << *cp << endl;

	//int now;
	//vector<int>ivec;
	//while (cin >> now && now != 42) {
	//	ivec.push_back(now);
	//}

	double dval; int val; int* pi;

	dval = val =int(pi = 0);

	vector<int>ivec;

	for (int i = 0; i < 100; i++) {
		ivec.push_back(i);
	}

	for (auto& c : ivec) {
		if (c % 2 != 0) {
			c *= 2;
		}
	}
	
	for (auto c : ivec) {
		cout << c << " ";
	}
	cout << endl;

	int grade = 71;
	string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "lowpass";

	string finalgrade1;
	if (grade > 90) {
		finalgrade1 = string("high pass");
	}
	else if (grade > 75) {
		finalgrade1 = string("pass");
	}
	else if (grade > 60) {
		finalgrade1 = string("low pass");
	}
	else {
		finalgrade1 = string("fail");
	}

	unsigned long u11 = 3, u12 = 7;

	std::cout << (u11 && u12) << " " << (u11 || u12) << endl;



	return 0;
}
