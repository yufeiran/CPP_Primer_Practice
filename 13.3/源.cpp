#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class HasPtr
{
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr() :ps(new string()), i(0), count(new unsigned(0)) {};
	HasPtr(const string& s) :ps(new string(s)), i(0), count(new unsigned(0)) {};
	HasPtr(const HasPtr& h) :ps(h.ps), i(h.i), count(h.count) { ++* count; }
	//HasPtr& operator=(const HasPtr& h);
	HasPtr& operator=(HasPtr h);
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
	cout << "void swap(HasPtr& lhs, HasPtr& rhs)"<<*rhs.ps<<" " << *lhs.ps << endl;
}

//HasPtr& HasPtr::operator=(const HasPtr& h)
//{
//	++* h.count;
//	if (-- * count == 0) {
//		delete ps;
//		delete count;
//	}
//	ps = h.ps;
//	count = h.count;
//	return *this;
//}

HasPtr& HasPtr::operator=(HasPtr h)
{
	swap(*this, h);
	return *this;
}

int main()
{
	vector<HasPtr>hpVec;
	HasPtr hs("yufiran");
	HasPtr hs1("HHH");
	HasPtr hs2("AAA");
	HasPtr hs3("aaa");
	HasPtr hs4("bbb");
	swap(hs, hs1);
	hpVec.push_back(hs);
	hpVec.push_back(hs1);
	hpVec.push_back(hs2);
	hpVec.push_back(hs3);
	hpVec.push_back(hs4);
	sort(hpVec.begin(), hpVec.end());
	for (auto c : hpVec)
	{
		cout << c.getString() << endl;
	}


	return 0;
}