#include<iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reset(int& a) {
	a = 0;
}

bool isAllUpper(const string& s)
{
	for (auto c : s) {
		if (!isupper(c))
			return false;
	}
	return true;
}


void Upper(string& s)
{
	for (auto& c : s) {
		c = toupper(c);
	}
}

int cmp(int a, const int* b)
{
	if (a > *b)return a;
	else return *b;
}

void swap(int** a, int** b)
{
	int* temp = *a;
	*a = *b;
	*b = temp;
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int cal(initializer_list<int>l)
{
	int ans = 0;
	for (auto s : l) {
		ans += s;
	}
	return ans;
}

int main()
{

	int a = 2, b = 4;
	swap(&a, &b);

	cout << "a " << a << " b " << b << endl;

	swap1(a, b);
	cout << "a " << a << " b " << b << endl;

	int c = 5;
	reset(c);
	cout << "c " << c << endl;

	string s1;
	cin >> s1;
	if (isAllUpper(s1)) {
		cout << "is all upper";
	}
	else {
		cout << "not all upper";
	}
	cout << endl;

	Upper(s1);
	cout << "Upper " << s1 << endl;

	cout << "cmp " << cmp(a, &b) << endl;

	int d = 5, e = 6;
	int* p1 = &d, * p2 = &e;
	cout << "p1 " << p1 << " p2 " << p2 << endl;
	swap(&p1, &p2);
	cout << "p1 " << p1 << " p2 " << p2 << endl;
	cout << *p1 << " " << *p2 << endl;

	int i = 0, j[2] = { 0,1 };
	print(&i, 1);
	print(j, 2);

	cout << cal({ 1,2,3,4,5 }) << endl;

	return 0;
}