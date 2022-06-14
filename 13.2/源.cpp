#include"StrBlob.h"

class HasPtr
{
public:
	HasPtr() :ps(new string()), i(0), count(new unsigned(0)) {};
	HasPtr(const string& s) :ps(new string(s)), i(0), count(new unsigned(0)) {};
	HasPtr(const HasPtr& h) :ps(h.ps), i(h.i), count(h.count) { ++* count; }
	HasPtr& operator=(const HasPtr& h);
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

int main()
{


	return 0;
}