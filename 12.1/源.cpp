#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
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
	StrBlob(initializer_list<string>s):data(make_shared<vector<string>>(s)) {
	}
	const string back();
	const string front();
	void push(const string &s);
	void pop();

	void show();

private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string& msg) const;
};



void StrBlob::check(size_t i, const string& msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

const string StrBlob::back()
{
	check(0, "empty vector have not back");
	return data->back();
}

const string StrBlob::front()
{
	check(0, "empty vector have not front");
	return data->front();
}

void StrBlob::push(const string& s)
{
	data->push_back(s);
}

void StrBlob::pop()
{
	check(0, "empty vector can not pop");
	data->pop_back();
}



void StrBlob::show()
{
	for (const auto &c : *data) {
		cout << c << " ";
	}
	
}


class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() :ptr(), curr(0) {};
	ConstStrBlobPtr(const StrBlob& b, vector<string>::size_type sz) :ptr(b.data), curr(sz) {};
	const string deref() const;
	void incr() ;

private:
	const shared_ptr<vector<string>> check(vector<string>::size_type sz, const string& msg) const;
	vector<string>::size_type curr;
	weak_ptr<vector<string>>ptr;
};

const shared_ptr<vector<string>> ConstStrBlobPtr::check(vector<string>::size_type sz, const string& msg)const
{
	auto ret = ptr.lock();
	if (!ret) {
		throw runtime_error("no vec in this ptr");
	}
	else if (sz >= ret->size())
	{
		throw out_of_range(msg);
	}
	else {
		return ret;
	}
}

const string ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "out of vec range");
	return (*p)[curr];
}

void ConstStrBlobPtr::incr() 
{
	check(curr + 1, "out of vec range");
	++curr;
}

class StrBlobPtr
{
public:
	StrBlobPtr() :ptr(), curr(0) {};
	StrBlobPtr(StrBlob& b, vector<string>::size_type sz) :ptr(b.data), curr(sz) {};
	string deref();
	void incr();

private:
	shared_ptr<vector<string>> check(vector<string>::size_type sz, const string& msg);
	vector<string>::size_type curr;
	weak_ptr<vector<string>>ptr;
};


shared_ptr<vector<string>> StrBlobPtr::check(vector<string>::size_type sz, const string& msg)
{
	auto ret = ptr.lock();
	if (!ret) {
		throw runtime_error("no vec in this ptr");
	}
	else if (sz >= ret->size())
	{
		throw out_of_range(msg);
	}
	else {
		return ret;
	}
}

string StrBlobPtr::deref()
{
	auto p = check(curr, "out of vec range");
	return ( * p)[curr];
}

void StrBlobPtr::incr()
{
	check(curr + 1, "out of vec range");
	++curr;
}


shared_ptr<vector<int>> make_int_vec()
{
	return make_shared<vector<int>>();
}

void add_int_vec(shared_ptr<vector<int>> ivec)
{
	int temp;
	while (cin >> temp) {
		ivec->push_back(temp);
	}
	cin.clear();
}

void show_int_vec(shared_ptr<vector<int>> ivec)
{
	for (auto c : *ivec) {
		cout << c << " ";
	}
	cout << endl;
}

bool b()
{
	int* p = new int;

	return p;
}

void process(shared_ptr<int>p)
{
	cout <<"in process:" << p.use_count() << endl;
}

struct destination { int a; };
struct connection { int b; };
connection connect(destination*) { connection a; a.b = 1; return a; };
void disconnect(connection) {};

void deleteConnection(connection* c)
{
	disconnect(*c);
}

void f(destination& d)
{
	connection c = connect(&d);
	//shared_ptr<connection> p(&c, deleteConnection);
	shared_ptr<connection>p(&c, [](connection* c) {disconnect(*c); });

}


int main()
{
	//StrBlob b1= { "yu", "fei", "ran" }, b2,b3;
	//b2 = b1;
	//b3 = { "yu", "fei", "ran" ,"1999"}; 

	//b2.push("ddd");
	//cout << "b1:";
	//b1.show();
	//cout << endl;
	//cout << "b2:";
	//b2.show();
	//cout << endl;
	//b3.show();       
	//cout << endl;

	//StrBlobPtr pb(b1,0);

	//cout << pb.deref() << endl;
	//pb.incr();
	//cout << pb.deref() << endl;

	//auto now_vec = make_int_vec();
	//add_int_vec(now_vec);
	//show_int_vec(now_vec);

	/*cout << b() << endl;

	auto p = new int();
	auto sp = make_shared<int>();
	cout << *p << endl;
	cout << "sp count:" << sp.use_count() << endl;
	process(sp);
	cout << "sp count:" << sp.use_count() << endl;
	process(shared_ptr<int>(sp));
	cout << "sp count:" << sp.use_count() << endl;
	process(shared_ptr<int>(p));
	cout << *p << endl;*/

	//auto sp1 = make_shared<int>();
	//auto p1 = sp1.get();
	//delete p1;


	//unique_ptr<int> a = make_unique<int>(3);
	//decltype(a) b = a;

	//unique_ptr<int>a(10);

	StrBlob b;
	ifstream ifs("raw.txt");
	string str;
	int count = 0;
	while (ifs >> str) {
		b.push(str);
		count++;
	}
	StrBlobPtr pb(b,0);
	for (int i = 0; i < count; i++) {
		cout << pb.deref() << endl;
		if (i != count - 1)pb.incr();
	}
	const StrBlob b1(b);
	ConstStrBlobPtr pb1(b1,0);
	for (int i = 0; i < count; i++) {
		cout << pb1.deref() << endl;
		if (i != count - 1)pb1.incr();
	}

	return 0;
}