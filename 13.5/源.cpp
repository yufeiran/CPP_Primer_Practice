//#include"StrVec.h"
//#include<string>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	StrVec sVec,sVec1({"yu","feiran"});
//
//	for (int i = 0; i < 100; i++)
//	{
//		sVec.push_back("hello world");
//		sVec.push_back("yu");
//		sVec.push_back("fei");
//		sVec.push_back("ran");
//	}
//
//
//	for (auto it = sVec.begin(); it != sVec.end(); it++) {
//		cout << *it << endl;
//	}
//
//	cout << sVec.size() << endl;
//
//	for (int i = 0; i < 100; i++)
//	{
//		sVec.pop_back();
//		sVec.pop_back();
//		sVec.pop_back();
//		sVec.pop_back();
//	}
//	cout << sVec.size() << endl;
//
//	for (auto it = sVec1.begin(); it != sVec1.end(); it++) {
//		cout << *it << endl;
//	}
//	return 0;
//}

#include"string.h"
#include<iostream>
#include<vector> 

int main()
{
	string a("yufeiran");
	string b = "yu",c="ddd",d="eee",e="ffajksdf",f="dddszz";
	b.push_back('c');
	
	print(a);
	std::cout << std::endl;
	print(b);
	std::cout << std::endl;

	std::vector<string> vec;
	vec.push_back(a);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(b);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(c);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(d);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(e);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(f);
	std::cout << vec.capacity() << std::endl;
	return 0;
}