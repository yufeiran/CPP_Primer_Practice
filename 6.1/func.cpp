#include"Chapter6.h"
using namespace std;
long long fact(int n)
{
	if (n < 0)return -1;
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}
void Proc()
{
	cout << "Enter one num:" << endl;
	int n;
	cin >> n;
	cout << "Fact is " << fact(n) << endl;
}


int abs(int a)
{
	if (a > 0)return a;
	else return -a;
}

int fun()
{
	static int count = 0;
	return count++;

}