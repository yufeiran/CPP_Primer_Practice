#include<iostream> 
using namespace std;

int main()
{
	//5.3
	int val = 1;
	int sum = 0;
	while (val <= 10)
		sum += val, val++;
	cout << "Sum of 1 to 10 inclusive is "
		<< sum << endl;


	return 0;
}