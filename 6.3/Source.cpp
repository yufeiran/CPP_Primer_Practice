#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size)i = 0; i != size; i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

int& get(int* arry, int index) { return arry[index]; }


void Show(const vector<int>::iterator it,const vector<int>::iterator end)
{
	cout << *it << " ";
	if (it+1 != end) {
		Show(it+1, end);
	}
}

//string(&fun())[10]{
//
//}
//
//using string_10= string[10];
//string_10 &fun1() {
//
//}
//
//auto fun2()->string(&)[10]{
//
//}
//
//string str[10];
//decltype(str)& fun3() {
//
//}

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

decltype(odd)& arrPtr(int i)
{
	return (i % 2) ? odd : even;
}

int main()
{
	cout << str_subrange("yu", "yuf") << endl;
	int ia[10];

	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
	}
	vector<int>d = { 9,8,7,6,5,4,3,2,1 };
	Show(d.begin(), d.end());

	return 0;
}