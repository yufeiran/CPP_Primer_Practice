#include"StrBlob.h"



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

void StrBlob::push_back(const string& s)
{
	data->push_back(s);
}

void StrBlob::pop_back()
{
	check(0, "empty vector can not pop");
	data->pop_back();
}

void StrBlob::clear()
{
	data->clear();

}



void StrBlob::show()
{
	for (const auto& c : *data) {
		cout << c << " ";
	}

}

string StrBlob::getByPos(vector<string>::size_type pos)
{
	check(pos, "out of vec range");

	return ( * data)[pos];
}



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
	return (*p)[curr];
}

void StrBlobPtr::incr()
{
	check(curr + 1, "out of vec range");
	++curr;
}

string StrBlobPtr::getByPos(vector<string>::size_type pos)
{
	
	return (*check(pos, "out of vec range"))[pos];
}

