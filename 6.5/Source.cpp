#include<iostream>
#include<string>
#include<vector>

#include<cassert>
using namespace std;
//#define NDEBUG

inline bool  isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void Show(const vector<int>::iterator it, const vector<int>::iterator end)
{
	cout << *it << " ";
#ifndef NDEBUG
	cout << " [" << sizeof(*it) << " byte] ";
#endif // !NDEBUG

	if (it + 1 != end) {
		Show(it + 1, end);
	}
}


int main()
{
	string s1 = "yufeiran", s2 = "yu";
	//assert(s1.size() < s2.size());
	
	cout << isShorter(s1, s2) << endl;
	vector<int>d = { 9,8,7,6,5,4,3,2,1 };
	Show(d.begin(), d.end());
	assert(cin);

	return 0;
}