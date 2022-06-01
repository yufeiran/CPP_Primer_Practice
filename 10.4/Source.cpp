#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<fstream>
#include<numeric>
#include<iterator>
#include<functional>

#include"Sales_data.h"

using namespace std;

void vecout(const list<int>& vec)
{
	for (auto& c : vec) {
		cout << c << " ";
	}
}

void elimDups(list<string>& words)
{
	words.sort();
	words.unique();
	
}

int main(int argc,char *argv[])
{
	vector<int>vec = { 1,3,4,5,5,1,3 };
	list<int>ivec;

	sort(vec.begin(), vec.end());
	auto it= unique_copy(vec.begin(), vec.end(),back_inserter(ivec));
	auto tempit = ivec.begin();
	while (tempit!= ivec.end()) {
		cout << *tempit << " ";
		tempit++;
	}
	cout << endl;

	vector<int>vec1 = { 1,2,3,4,5,6,7,8,9 };
	list<int>tvec;
	copy(vec1.begin(), vec1.end(), inserter(tvec,tvec.begin()));
	vecout(tvec);
	cout << endl;
	tvec.clear();
	copy(vec1.begin(), vec1.end(), back_inserter(tvec));
	vecout(tvec);
	cout << endl;
	tvec.clear();
	copy(vec1.begin(), vec1.end(), front_inserter(tvec));
	vecout(tvec);
	cout << endl;

	//10.29
	ifstream is("1.txt");
	istream_iterator<string> ist(is);
	istream_iterator<string> eof;
	vector<string>svec(ist, eof);

	for (auto s : svec) {
		cout << s << " ";
	}
	cout << endl;

	//10.30/31
	//istream_iterator<int> intis(cin);
	//istream_iterator<int> ieof;
	//ostream_iterator<int> intos(cout,"\n");
	//
	//vector<int>inData;
	//while (intis != ieof) {
	//	inData.push_back(*intis++);
	//}
	//sort(inData.begin(), inData.end());
	//unique_copy(inData.begin(), inData.end(), intos);


	//10.32
	//vector<Sales_item>sivec;
	//Sales_item now_item;
	//while (cin >> now_item) {
	//	sivec.push_back(now_item);
	//}
	//sort(sivec.begin(), sivec.end(), [](const Sales_item& s1, const Sales_item& s2) {return s1.isbn() < s2.isbn(); });

	//cin.clear();

	//while (true) {
	//	cout << "Enter Search isbn:";
	//	string isbn;
	//	cin >> isbn;
	//	auto cmpStrIsbn = [isbn](const Sales_item& s) ->bool{return s.isbn() == isbn; };
	//	auto start = find_if(sivec.begin(), sivec.end(), cmpStrIsbn);
	//	auto end = find_if_not(start + 1, sivec.end(), cmpStrIsbn);

	//	cout << accumulate(start, end,Sales_item(isbn)) << endl;
	//}
	//if (argc < 3) {
	//	return -1;
	//}
	//ifstream in(argv[1]);
	//ofstream out1(argv[2]);
	//ofstream out2(argv[3]);
	//istream_iterator<int> init(in);
	//istream_iterator<int> ieof;
	//ostream_iterator<int>oit1(out1, " ");
	//ostream_iterator<int>oit2(out2, "\n");

	//while (init != ieof) {
	//	if (*init % 2 != 0) {
	//		*oit1++ = *init;
	//	}
	//	else {
	//		*oit2++ = *init;
	//	}
	//	init++;
	//}
	//cout << "work ok!" << endl;

	//vector<int>ivec1 = { 0,1,2,3,4,5,6,7,8,9,0 };
	//for (auto it = ivec1.rbegin(); it != ivec1.rend(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	//for (auto it = ivec1.end() - 1; it >= ivec1.begin() ; it--) {
	//	cout << *it << " ";
	//	if (it == ivec1.begin())break;
	//}
	//cout << endl;

	//auto ans = find(ivec1.rbegin(), ivec1.rend(), 0);
	//cout << (ans.base()-ivec1.begin()-1) << endl;
	//vector<int>ivec2 = { 0,1,2,3,4,5,6,7,8,9 };
	//vector<int>ivec3;
	//vector<int>ivec4;
	//copy(ivec2.begin() + 2, ivec2.begin() + 6,back_inserter( ivec3));
	//copy(ivec3.rbegin(), ivec3.rend(), back_inserter(ivec4));
	//for (auto s : ivec4) {
	//	cout << s << " ";
	//}
	//cout << endl;

	list<string>svec1 = { "apple","apple","ape","banana","color","color","yufeiran","size","dsadsawssa" };
	elimDups(svec1);

	for (auto s : svec1) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}