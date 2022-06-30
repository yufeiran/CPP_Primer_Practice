#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<fstream>
#include<initializer_list>
#include"MyMemory.h"

template<typename> class BlobPtr;

template<typename T>class Blob
{
	friend BlobPtr<T>;

public:
	using size_t = std::vector<int>::size_type;
	Blob();
	Blob(std::initializer_list<T> li);
	template<typename IT>
	Blob(IT begin, IT end);
	const T back();
	const T front();
	T& operator[](size_t i);
	void push_back(const T& d) {
		data->push_back(d);
	}
	void push_back(T&& d) {
		data->push_back(std::move(d));
	}
	void pop_back() {
		check(0, "empty Blob");
		data->pop_back();
	}
	void clear() { 
		data->clear(); }
	void show() const;
	size_t size()const { return data->size(); }

	T& getByPos(size_t pos);


private:
	::shared_ptr<std::vector<T>>data;
	void check(size_t i, const std::string& msg)const;
};


template<typename T>
Blob<T>::Blob() :data(std::make_shared<std::vector<T>>())
{

}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(new std::vector<T>(il))
{

}

template<typename T>
template<typename IT>
Blob<T>::Blob(IT begin, IT end):
	data(new std::vector<T>(begin,end))
{

}

template<typename T>
const T Blob<T>::back()
{
	return data->back();
}

template<typename T>
void Blob<T>::check(size_t i, const std::string& msg)const
{
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

template<typename T>
const T Blob<T>::front()
{
	return data->front();
}

template<typename T>
T& Blob<T>::operator[](size_t i)
{
	return getByPos(i);

}

template<typename T>
T& Blob<T>::getByPos(size_t pos)
{
	check(pos, "out of Blob range");
	return (*data)[pos];

}

template<typename T>
void  Blob<T>::show() const
{
	for (auto it = (*data).begin(); it != (*data).end(); it++)
	{
		std::cout << *it << " ";
	}

	//for (const auto& c : *data) {
	//	std::cout << c << " ";
	//}
}
//
//template<typename T>
//class BlobPtr
//{
//	friend bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
//	friend bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
//public:
//	using size_t = std::vector<int>::size_type;
//	BlobPtr() :ptr(), curr(0) {};
//	BlobPtr(Blob<T>& b, size_t sz) :ptr(b.data), curr(sz) {};
//	T deref();
//	void incr() {
//		curr++;
//	}
//	T getByPos(size_t pos);
//	
//private:
//	std::shared_ptr<std::vector<T>> check(size_t sz, const std::string& msg);
//	size_t curr;
//	std::weak_ptr<std::vector<T>>ptr;
//};
//template<typename T>
//bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
//{
//	if (lhs.ptr.lock() == rhs.ptr.lock())
//	{
//		if (lhs.curr == rhs.curr) {
//			return true;
//		}
//	}
//	return false;
//}
//template<typename T>
//bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
//{
//	if (lhs.curr < rhs.curr)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//template<typename T>
//T BlobPtr<T>::deref() 
//{
//	check(curr, "out of range");
//	return (*ptr.lock())[curr];
//}
//
//template<typename T>
//T BlobPtr<T>::getByPos(size_t pos)
//{
//	check(pos, "out of range");
//	return (*ptr.lock())[pos];
//}
//
//template<typename T>
//std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t sz, const std::string& msg)
//{
//	auto ret = ptr.lock();
//	if (!ret) {
//		throw std::runtime_error("no vec in this ptr");
//	}
//	else if (sz >= ret->size())
//	{
//		throw std::out_of_range(msg);
//	}
//	else {
//		return ret;
//	}
//}