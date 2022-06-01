#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<numeric>
#include<iterator>
#include"Sales_data.h"
using namespace std;

void elimDups(vector<string>& vec)
{
	auto uni_end= unique(vec.begin(), vec.end());
	vec.erase(uni_end,vec.end());
}


bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

bool compateIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}

bool biggerThen4(const string& s)
{
	return s.size() > 4;
}

int main()
{
	vector<int>vec{ 1,2,3,4,5,1,1,3 };
	cout << count(vec.begin(), vec.end(), 1) << endl;
	list<int>l{ 1,2,3,4,5,1,1,3 };
	cout << count(l.begin(), l.end(), 1) << endl;
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;
	vector<double>vec1{ 1,2.5,3,4,5,1,1,3 };
	cout << accumulate(vec1.begin(), vec1.end(), 0) << endl;

	vector<int>ivec;
	fill_n(back_inserter(ivec), 10, 0);
	vector<string>svec = { "apple","apple","ape","banana","color","color"};
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (auto c : svec) {
		cout << c << " ";
	}
	cout << endl;

	vector<Sales_data>sdvec = { {"yu"},{"fei"},{"yu"} };
	sort(sdvec.begin(), sdvec.end(), compateIsbn);

	for (auto c : sdvec) {
		print(cout, c);
	}
	cout << endl;
	vector<string>svec1 = { "apple","apple","ape","banana","color","color","yufeiran","size"};
	auto it= partition(svec1.begin(), svec1.end(), biggerThen4);
	auto nowit = svec1.begin();
	while (nowit != it) {
		cout << *nowit << " ";
		nowit++;
	}
	cout << endl;
	return 0;
}