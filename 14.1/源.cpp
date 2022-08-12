#include"Sales_data.h"
#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<vector<Sales_data>> file;

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
typedef pair<vector<Sales_data>::size_type, pair< vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches1;

struct matches2
{
	vector<Sales_data>::size_type index;
	
	vector<Sales_data>::const_iterator begin;
	vector<Sales_data>::const_iterator end;
};

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}

vector<matches> findBook(const vector<vector<Sales_data>>& file, const string& name)
{
	vector<matches>ret;

	unsigned nowIndex = 0;
	for (const auto& nowVec : file)
	{
		auto nowAns = equal_range(nowVec.cbegin(), nowVec.cend(), name, compareIsbn);
		if (nowAns.first != nowAns.second) {
			auto nowRet= make_tuple(nowIndex, nowAns.first, nowAns.second);
			ret.push_back(nowRet);
		}
	    nowIndex++;
	}
	return ret;

}


vector<matches1> findBook1(const vector<vector<Sales_data>>& file, const string& name)
{
	vector<matches1>ret;

	unsigned nowIndex = 0;
	for (const auto& nowVec : file)
	{
		auto nowAns = equal_range(nowVec.cbegin(), nowVec.cend(), name, compareIsbn);
		if (nowAns.first != nowAns.second) {

			auto nowRet = make_pair(nowIndex,make_pair( nowAns.first, nowAns.second));
			ret.push_back(nowRet);
		}
		nowIndex++;
	}
	return ret;

}

vector<matches2> findBook2(const vector<vector<Sales_data>>& file, const string& name)
{
	vector<matches2>ret;

	unsigned nowIndex = 0;
	for (const auto& nowVec : file)
	{
		auto nowAns = equal_range(nowVec.cbegin(), nowVec.cend(), name, compareIsbn);
		if (nowAns.first != nowAns.second) {

			matches2 nowRet{ nowIndex, nowAns.first, nowAns.second };
			ret.push_back(nowRet);
		}
		nowIndex++;
	}
	return ret;

}

bool isGreaterThan( Sales_data s ,double price)
{
	if (s.avg_price() > price)return true;
	return false;
}

int main()
{
	
	Sales_data s1("yu", 10, 20);
	Sales_data s2("yu", 20, 1);
	Sales_data s3("11", 10, 20);
	vector<Sales_data>ss1{ s1,s2,s3 };
	Sales_data s4("ydu", 20, 1);
	Sales_data s5("yu", 10, 20);
	Sales_data s6("ydu", 20, 1);
	vector<Sales_data>ss2{ s4,s5,s6 };

	file.push_back(ss1);
	file.push_back(ss2);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1 + s2 << endl;
	auto it = find_if(ss2.begin(), ss2.end(), bind(&isGreaterThan, placeholders::_1, 1));
	cout <<"ans " << *it << endl;
	//Sales_data s3;
	//cin >> s3;
	//cout << s3 << endl;

	string s;
	cin >> s;
	auto ret = findBook(file, s);
	auto ret1 = findBook1(file, s);
	auto ret2 = findBook2(file, s);

	while (1);

	return 0;
}