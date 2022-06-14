#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Foo
{
public:
	void push_back(int a);
	void pop_back();
	int at(size_t index);
	Foo sorted()&&;
	Foo sorted() const&;
	size_t size() { return data.size(); }

private:
	vector<int> data;
};

void Foo::pop_back()
{
	data.pop_back();
}

void Foo::push_back(int a)
{
	data.push_back(a);
}

int Foo::at(size_t index)
{
	return data[index];
}

Foo Foo::sorted()&&
{
	cout << "Foo Foo::sorted()&& call!" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const&
{
	cout << "Foo Foo::sorted() const& call!" << endl;
	//Foo ret(*this);
	//return ret.sorted();
	return Foo(*this).sorted();
}
