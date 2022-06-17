#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include"Sales_data.h"
using namespace std;
using namespace std::placeholders;

void elimDups(vector<string>& vec)
{
	auto uni_end = unique(vec.begin(), vec.end());
	vec.erase(uni_end, vec.end());
}

void biggies(vector<string>& words,
	vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2) {return s1.size() < s2.size(); });
	//auto ws = find_if(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	auto ws=stable_partition(words.begin(),words.end(), [sz](const string& s) {return s.size() < sz; });
	cout << "sum:" << words.end() - ws << endl;
	for_each(ws, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;

}

bool cmpStr(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

bool cmpStrLen(const string& s1, int sz)
{
	return s1.size() < sz;
}

void strOut(const string& s)
{
	cout << s << " ";
}

bool check_size(const string& s, string::size_type sz)
{
	return s.size() >= sz;
}


class cmp_size
{
public:
	bool operator()(const string& s, size_t size) {
		return s.size() >= size;
	}
};

void biggies1(vector<string>& words,
	vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), cmpStr);
	//auto ws = find_if(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	//auto ws = stable_partition(words.begin(), words.end(), bind(check_size,_1,sz));
	auto ws = stable_partition(words.begin(), words.end(), bind(cmp_size(), _1, sz));
	cout << "sum:" <<  ws-words.begin() << endl;
	for_each(words.begin(), ws, strOut);
	cout << endl;

}

int main()
{
	auto f = [](int a, int b) {return a + b; };
	cout << f(1, 2) << endl;

	int a = 22;
	auto fa = [a](int b) {return a + b; };
	cout << fa(33) << endl;

	vector<string>vec = { "apple","apple","ape","banana","color","color","yufeiran","size" };
	biggies1(vec, 4);
	biggies1(vec, 3);

	vector<Sales_data>sdvec = { {"yu"},{"fei"},{"yu"} };
	sort(sdvec.begin(), sdvec.end(), [](const Sales_data& s1, const Sales_data& s2) {return  s1.isbn() < s2.isbn(); });


	vector<string>svec1 = { "apple","apple","ape","banana","color","color","yufeiran","size","dsadsawssa"};
	auto it = partition(svec1.begin(), svec1.end(), [](const string& s) {return s.size() > 4; });
	auto nowit = svec1.begin();
	while (nowit != it) {
		cout << *nowit << " ";
		nowit++;
	}
	cout << endl;

	cout << count_if(svec1.begin(), svec1.end(), [](const string& s) {return s.size() > 6; }) << endl;

	int aa = 5;

	auto fun = [&aa]()->bool {
		if (aa > 0) {
			--aa;
			return true;
		}
		else {
			return false;
		}
	};

	while (fun()) {
		cout << aa << endl;
	}

	vector<int>ivec = { 1,2,3,5,6,102,3214,3 };
	string str1 = "yufeiran";
	auto pit= find_if_not(ivec.begin(), ivec.end(), bind(check_size, str1, _1));
	cout << *pit << endl;
	return 0;
}