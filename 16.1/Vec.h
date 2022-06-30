#pragma once
#include<string>
#include<utility>
#include<exception>
#include<stdexcept>
#include<initializer_list>


template<typename T>
class Vec
{
public:
	Vec() :elm_start(nullptr), free_start(nullptr), free_end(nullptr) {};
	Vec(const Vec& s);
	Vec(std::initializer_list<T> slist);
	Vec& operator=(const Vec& s);
	~Vec() { free(); };
	void push_back(const T& s);
	void pop_back();
	T* at(size_t index);
	T* begin();
	T* end();
	void reserve(size_t new_size);
	size_t capacity();
	size_t size();
	void resize(size_t new_size);
	bool empty();
	void clear();
private:
	void check_range(size_t index, const T& msg);
	void check_size() { if (size() == capacity())reallocate(); };
	void reallocate();
	std::pair<T*, T*> alloc_n_copy(const T* begin, const T* end);
	void free();
	std::allocator<T> alloc;
	T* elm_start;
	T* free_start;
	T* free_end;
};

using namespace std;

//分配新的空间
template<typename T>
void Vec<T>::reallocate()
{
	size_t newSize = (size() ? 2 * size() : 1);

	auto new_data = alloc.allocate(newSize);
	auto new_elm = new_data;
	auto old_elm = elm_start;


	auto old_size = size();
	for (size_t nowSize = 0; nowSize < old_size; nowSize++) {
		alloc.construct(new_elm++, move(*old_elm++));
	}
	elm_start = new_data;
	free_start = new_data + old_size;
	free_end = new_data + newSize;
}



//获得一块string的拷贝
template<typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* begin, const T* end)
{

	auto new_data = alloc.allocate(end - begin);


	return pair<T*, T*>(new_data, uninitialized_copy(begin, end, new_data));
}

template<typename T>
void Vec<T>::free()
{
	auto now_elm = elm_start;
	while (now_elm != free_start) {
		alloc.destroy(now_elm++);
	}
	alloc.deallocate(elm_start, free_end - elm_start);

}

template<typename T>
Vec<T>::Vec(const Vec& s)
{
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec& s)
{
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	free();
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
	return *this;
}

template<typename T>
void Vec<T>::push_back(const T& s)
{
	check_size();
	alloc.construct(free_start++, s);
}
template<typename T>
void Vec<T>::pop_back()
{
	if (empty() == true) {
		throw out_of_range("pop_back empty StrVec!");
	}
	alloc.destroy(--free_start);
}

template<typename T>
T* Vec<T>::at(size_t index)
{
	check_range(index, "out of StrVec range");
	return elm_start + index;
}

template<typename T>
T* Vec<T>::begin()
{
	return elm_start;
}

template<typename T>
T* Vec<T>::end()
{
	if (free_start == nullptr)return nullptr;
	else return free_start;
}

template<typename T>
void Vec<T>::reserve(size_t new_size)
{
	if (new_size <= capacity())return;
	size_t newSize = new_size;
	auto new_data = alloc.allocate(newSize);
	auto new_elm = new_data;
	auto old_elm = elm_start;

	for (size_t nowSize = 0; nowSize < newSize; nowSize++) {
		alloc.construct(new_elm++, move(*old_elm++));
	}
	free();
	elm_start = new_data;
	free_start = new_data + new_size;
	free_end = new_data + new_size;
}

template<typename T>
size_t Vec<T>::capacity()
{
	return free_end - elm_start;
}

template<typename T>
size_t Vec<T>::size()
{
	return free_start - elm_start;
}

template<typename T>
void Vec<T>::resize(size_t new_size)
{
	if (new_size < size()) {
		while (free_start != elm_start + new_size) {
			alloc.destroy(--free_start);
		}
	}
	else if (new_size > size()) {
		while (free_start != elm_start + new_size) {
			alloc.construct(free_start++);
		}
	}
}

template<typename T>
bool Vec<T>::empty()
{
	if (elm_start == nullptr) {
		return true;
	}
	else if (elm_start == free_start) {
		return true;
	}
	return false;
}

template<typename T>
void Vec<T>::check_range(size_t index, const T& msg)
{
	if (empty()) {
		throw out_of_range(msg);
	}
	else {
		if (elm_start + index >= free_start) {
			throw out_of_range(msg);
		}
	}
}

template<typename T>
Vec<T>::Vec(initializer_list<T> slist)
{
	for (auto& it : slist) {
		push_back(it);
	}
}

template<typename T>
void Vec<T>::clear()
{
	while (free_start != elm_start)
	{
		alloc.destroy(--free_start);
	}
}