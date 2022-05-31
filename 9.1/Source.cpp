#include<list>
#include<deque>
#include<vector>
#include<iostream>
using namespace std;

vector<int>::iterator findInt(vector<int>::iterator begin, vector<int>::iterator end, int raw)
{
	while (begin != end)
	{
		if (*begin == raw)return begin;
		begin++;
	}
	return end;
}

bool judgeEqual(vector<int>& v1, vector<int>& v2)
{
	return v1 == v2;
}

bool judgeEqual(list<int>& v1, vector<int>& v2)
{
	vector<int>v3(v1.begin(), v1.end());
	return v3 == v2;
}

int main()
{
	vector<int>ivec{ 1,2,3,4,5,6,7,8,9 };
	cout << &*findInt(ivec.begin(), ivec.end(), 5) << endl;
	//list<int>lst1;
	//list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();

	//while (iter1 != iter2) {

	//}

	vector<int>v1;
	vector<int>v2(v1);
	vector<int>v3{ 1,2,3 };
	vector<int>v4(v3.begin(), v3.end());
	vector<int>v5(10);
	vector<int>v6(10, 4);

	list<int>l1 = { 1,2,3,4,5 };
	vector<double>v7(l1.begin(), l1.end());

	vector<int>v8 = { 1,2,3,4,5,6 };
	vector<double>v9(v8.begin(), v8.end());

	list< const char*>l2 = { "yufeiran","dd" };
	vector<string>v10;
	v10.assign(l2.begin(), l2.end());
	vector<int>ivec1{ 1,2,3,4,5,6,7,8,9 };

	cout << judgeEqual(ivec1, ivec) << endl;
	return 0;
}