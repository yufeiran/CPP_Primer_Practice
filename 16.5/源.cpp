#include<iostream>
#include"Sales_data.h"
#include<vector>
#include<sstream>
using namespace std;

template<typename T>
size_t count_( vector<T>& vec,  T val)
{
	size_t count = 0;
	for (const auto& u : vec) {
		if (u == val) {
			count++;
		}
	}
	return count;
}
template<>
size_t count_( vector<const char*>& vec,  const char* val)
{
	size_t count = 0;
	for (const auto& u : vec) {
		if (strcmp( u, val)==0) {
			count++;
		}
	}
	return count;
}


template<typename T>
string debug_rep(const T& d)
{
	ostringstream ret;
	ret << d;
	return ret.str();
}

template<typename T>
string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

template<>
string debug_rep(char* p)
{
	return debug_rep(string(p));
}

template<>
string debug_rep(const char* p)
{
	return debug_rep(string(p));
}

int main()
{

	const std::string Sales_data::*pdata = Sales_data::BOOKNO();

	unordered_map<string, Sales_data> umap;
	umap["yu"]= Sales_data("yu", 1, 4);
	umap["dd"] = Sales_data("dd", 122, 34);
	umap["ydu"] = Sales_data("ydu", 13, 40);
	vector<int> ivec = { 1,2,3,4,5,5,6,5,6,1,3 };
	vector<double> dvec = { 1.2,2.3,4.4,3.4,56.33,1.2 };
	vector<string> svec = { "yu","yu","dddd" };
	vector< const char*>cvec = { "yu","yu","dddd" };
	cout << count_(ivec, 5) << endl;
	cout << count_(dvec, 1.2) << endl;
	cout << count_(svec, string("yu")) << endl;
	cout << count_(cvec, "yu") << endl;
	try {
		umap["yu"] + umap["dd"];
	}
	catch (isbn_mismatch e) {
		cout << e.what() << " left:" << e.left << " right:" << e.right << endl;
	}

	return 0;
}