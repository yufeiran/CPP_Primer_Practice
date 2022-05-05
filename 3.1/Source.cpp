#include<iostream>

using std::cin;
using std::cout; using std::endl;

int main()
{
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << endl;

	int index = 50; int sum = 0;
	while (index <= 100) {
		sum += index;
		index++;
	}
	cout << "The sum is " << sum << endl;

	index = 10;
	while (index >= 0) {
		cout << index << endl;
		index--;
	}

	int a, b;
	cout << "Enter two numbers:" << endl;
	cin >> a >> b;
	if (a < b) {
		for (int index = a; index <= b; index++) {
			cout << index << endl;
		}
	}
	else {
		for (int index = a; index >= b; index--) {
			cout << index << endl;
		}
	}


	return 0;
}