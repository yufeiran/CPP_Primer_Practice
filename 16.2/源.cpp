#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<utility>
#include<memory>
#include<type_traits>
using namespace std;

template<typename F,typename T1,typename T2>
void filp(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
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



string debug_rep(const string& s)
{
	return '"' + s + '"';
}

string debug_rep(char* p)
{
	return debug_rep(string(p));
}

template<typename T,typename... Args>
void foo(const T& t, const Args& ... rest)
{
	cout << "sizeof... Args " << sizeof...(Args) << endl;
	cout << "sizeof... rest " << sizeof...(rest) << endl;
}

class A
{
public:
	int aa = 0;
};

template<typename T>
const T& fun1(const T& t)
{
	return t;
}

template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T,typename... Args>
ostream& print(ostream& os, const T& t, const Args& ...rest)
{
	os << t << ",";
	return print(os,  rest...);
}

template<typename ...Args>
ostream& errorMsg(ostream& os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}

template<typename T, typename ...Args>
shared_ptr<T> make_shared_(Args&&... args)
{
	std::allocator<T> alloc;
	auto p=alloc.allocate(1);
	alloc.construct(p, std::forward<Args>( args)...);
	return shared_ptr<T>(p);
}


int main()
{
	cout << max<int>(1, 2.3) << endl;

	int i = 0; double d = 3.14; string s = "how now brown cow";
	foo(i, i, i, i);
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	A a;
	print(cout, 1, 1.2, 'c', "yufeiran", true);
	cout << endl;
	errorMsg(cout, 1, 1.2, 'c', "yufeiran", true);

	auto c = make_shared_<string>(10, 'c');
	cout << *c << endl;
	return 0;
}