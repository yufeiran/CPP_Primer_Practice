#ifndef STR_BLOB_H
#define STR_BLOB_H
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
#include<initializer_list>
using namespace std;
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
	friend StrBlobPtr;
	friend ConstStrBlobPtr;
public:
	using size_t = vector<string>::size_type;
	StrBlob() :data(make_shared<vector<string>>()) {  };
	StrBlob(initializer_list<string>s) :data(make_shared<vector<string>>(s)) {
	}
	StrBlob(const StrBlob& s) {
		auto newP = make_shared<vector<string>>();
		newP = s.data;
		data = newP;
	}
	StrBlob& operator=(const StrBlob& s) {
		auto newP = make_shared<vector<string>>();
		newP = s.data;
		data = newP;
	}
	const string back();
	const string front();
	void push_back(const string& s);
	void pop_back();
	void clear();
	void show();
	string getByPos(vector<string>::size_type pos);

private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string& msg) const;
};




class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() :ptr(), curr(0) {};
	ConstStrBlobPtr(const StrBlob& b, vector<string>::size_type sz) :ptr(b.data), curr(sz) {};
	const string deref() const;
	void incr();

private:
	const shared_ptr<vector<string>> check(vector<string>::size_type sz, const string& msg) const;
	vector<string>::size_type curr;
	weak_ptr<vector<string>>ptr;
};


class StrBlobPtr
{
public:
	StrBlobPtr() :ptr(), curr(0) {};
	StrBlobPtr(StrBlob& b, vector<string>::size_type sz) :ptr(b.data), curr(sz) {};
	string deref();
	void incr();
	string getByPos(vector<string>::size_type pos);

private:
	shared_ptr<vector<string>> check(vector<string>::size_type sz, const string& msg);
	vector<string>::size_type curr;
	weak_ptr<vector<string>>ptr;
};

#endif