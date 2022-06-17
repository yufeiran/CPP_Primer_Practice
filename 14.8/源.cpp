#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<fstream>
#include<map>
using namespace std;
using namespace std::placeholders;

class IFELSE
{
public:
	int operator()(bool a, int b, int c) {
		if (a) {
			return b;
		}
		else {
			return c;
		}
	}
};

class ScanString
{
public:
	string operator()(istream& is) {
		string temp;
		is >> temp;
		if (is) {
			return temp;
		}
		else {
			return string();
		}
	}
};

class IsEqual
{
public:
	bool operator()(const string &a,const string &b) {
		return a == b;
	}
};

class JudgeLength
{
public :
	bool operator()(const string& str, size_t length) {
		return str.size() == length;
	}
};

class GreaterThen9
{
public:
	bool operator()(const string& str) {
		return str.size() >= 10;
	}
};

bool fullModulus(int n, vector<int>& ivec)
{
	auto m = modulus<int>();
	for (auto i : ivec) {
		if (m(i, n) != 0) {
			return false;
		}
	}
	return true;
};

int ADD(int a, int b)
{
	return a + b;
}

int SUB(int a, int b)
{
	return a - b;
}

int MUL(int a, int b)
{
	return a * b;
}

int DIV(int a, int b)
{
	return a / b;
}

int MOD(int a, int b)
{
	return a % b;
}

int main()
{
	//IFELSE ie;
	//cout << ie(true, 10, 100) << endl;
	//cout << ie(false, 10, 100) << endl;
	//ScanString ss;
	//string str = ss(cin);
	//cout << str << endl;
	//vector<string> svec;

	//while (true)
	//{
	//	string str;
	//	str = ss(cin);
	//	if (str == string())break;
	//	svec.push_back(str);
	//}
	//IsEqual ieq;
	//auto yu_ieq=bind(ieq, "yufeiran", _1);
	//replace_if(svec.begin(), svec.end(), yu_ieq, "1999");
	//for (auto& s : svec) {
	//	cout << s << endl;
	//}
	ifstream is("raw.txt");
	vector<string>raw_vec;
	string str;
	while (is >> str) {
		raw_vec.push_back(str);
	}
	for (int i = 1; i <= 9; i++) {
		int count = 0;
		JudgeLength jl;
		for (auto& s : raw_vec) {
			if (jl(s, i)) {
				count++;
			}
		}
		cout << i << " : " << count << endl;
	}
	int count = 0;
	GreaterThen9 g9;
	for (auto& s : raw_vec) {
		if (g9(s)) {
			count++;
		}
	}
	cout << "10+ : " << count << endl;

	vector<int> ivec = { 111111,231321,423,21,13,4543,23,55,132,3445,333,55 };
	sort(ivec.begin(), ivec.end(), greater<int>());
	int count1 = 0;
	for (auto i : ivec) {
		if (i > 1024)count1++;
	}
	cout << "greater than 1024 has " << count1 << endl;
	vector<string>ssvec = { "pooh","pooh","sdaadsa" };
	string qstr = "pooh";
	auto it = find_if(ssvec.begin(), ssvec.end(), bind( not_equal_to<string>(),"pooh",_1));
	cout << *it << endl;

	for_each(ivec.begin(), ivec.end(), [](int& a) {
		auto m =multiplies<int>();
		a = m(a, 2);});
	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;

	cout << fullModulus(1, ivec) << endl;
	cout << fullModulus(3, ivec) << endl;

	map<string, function< int(int, int) >> calfun;
	calfun["+"] = ADD;
	calfun["-"] = SUB;
	calfun["*"] = MUL;
	calfun["/"] = DIV;
	calfun["%"] = MOD;
	while (true) {
		int a, b;
		string op;
		cin >> a >> op >> b;
		cout << "=" << calfun[op](a, b) << endl;
	}



	return 0;
}