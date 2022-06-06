#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<algorithm>
#include"Sales_data.h"
using namespace std;

map<string, vector<pair<string,string>>>familys;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	vector<pair<string, string>>family = { {"yufeiran","19990519"},{"yuyong","20000101"}};
	familys["yu"] = family;

	vector<string>setVec;

	//string str;
	//while (cin >> str) {
	//	if (find(setVec.begin(), setVec.end(), str) == setVec.end()) {
	//		setVec.push_back(str);
	//	}
	//}
	//sort(setVec.begin(), setVec.end());
	//for (const auto c : setVec) {
	//	cout << c << " ";
	//}
	//cout << endl;

	map<string, list<int>>slit;

	map<vector<int>::iterator, int>itmap;
	map<list<int>::iterator, int>iitmap;

	
	set<Sales_data, bool>bookstore(compareIsbn);

	vector<pair<string, int>>pvec;
	pair<string, int> p;
	pair<string, int> p1("yu",1);
	pair<string, int> p2={"yuf",2};
	while (cin>>p.first>>p.second){
		pvec.push_back(p);
	}

	return 0;
}