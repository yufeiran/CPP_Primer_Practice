#pragma once
#include<string>
#include<iostream>
using namespace std;
class HasPtr
{
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr() :ps(new string()), i(0), count(new unsigned(0)) {};
	HasPtr(const string& s) :ps(new string(s)), i(0), count(new unsigned(0)) {};
	HasPtr(const HasPtr& h) :ps(h.ps), i(h.i), count(h.count) { ++* count; }
	HasPtr(HasPtr&& p)noexcept :ps(p.ps), i(p.i),count(p.count) { p.ps = 0; }

	HasPtr& operator=(const HasPtr& h);
	//HasPtr& operator=(HasPtr h);
	HasPtr& operator=(HasPtr&& h)noexcept;
	const string& getString() { return *ps; }
	bool operator<(const HasPtr& h)const {
		return (*ps) < (*h.ps);
	}
	~HasPtr() {
		if (-- * count == 0) {
			delete ps;
			delete count;
		}
	}

private:
	string* ps;
	int i;
	unsigned* count;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	swap(lhs.count, rhs.count);
	//cout << "void swap(HasPtr& lhs, HasPtr& rhs)" << *rhs.ps << " " << *lhs.ps << endl;
}

HasPtr& HasPtr::operator=(const HasPtr& h)
{
	++* h.count;
	if (-- * count == 0) {
		delete ps;
		delete count;
	}
	ps = h.ps;
	count = h.count;
	return *this;
}

//HasPtr& HasPtr::operator=(HasPtr h)
//{
//	swap(*this, h);
//	return *this;
//}

inline HasPtr& HasPtr::operator=(HasPtr&& h) noexcept
{
	if (&h != this) {
		ps = h.ps;
		i = h.i;
		count = h.count;
		h.ps = 0;
	}
	return *this;
}
