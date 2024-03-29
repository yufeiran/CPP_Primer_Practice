
#include <algorithm>
#include<iostream>
#include"StrVec.h"
using namespace std;

void* operator new(size_t size) {
	std::cout << "void* operator new(size_t size) call!" << std::endl;
	if (void* mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void* mem) {
	std::cout << "void operator delete(void* mem) call!" << std::endl;
	free(mem);
}

//分配新的空间
void StrVec::reallocate()
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
	free_start = new_data+ old_size;
	free_end = new_data + newSize;
}



//获得一块string的拷贝
pair<string*, string*> StrVec::alloc_n_copy(const string* begin, const string* end)
{

	auto new_data = alloc.allocate(end - begin);


	return pair<string*, string*>(new_data,uninitialized_copy(begin,end,new_data));
}


void StrVec::free()
{
	auto now_elm = elm_start;
	//while (now_elm != free_start) {
	//	alloc.destroy(now_elm++);
	//}

	for_each(elm_start, free_start, [this](string& new_elm) {alloc.destroy(&new_elm); });
	alloc.deallocate(elm_start, free_end - elm_start);

}

StrVec::StrVec(const StrVec& s)
{
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
}


StrVec::StrVec(StrVec&& s)noexcept :elm_start(s.elm_start), free_start(s.free_start), free_end(s.free_end)
{
	s.elm_start = nullptr;
	s.free_start = nullptr;
	s.free_end = nullptr;

}

StrVec& StrVec::operator=(const StrVec& s)
{
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	free();
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec&& s) noexcept
{
	if (&s != this) {
		elm_start = s.elm_start;
		free_start = s.free_start;
		free_end = s.free_end;
		s.elm_start = s.free_start = s.free_end = nullptr;
	}
	return *this;
}

void StrVec::push_back(const string& s)
{
	check_size();
	alloc.construct(free_start++, s);
}
void StrVec::pop_back()
{
	if (empty() == true) {
		throw out_of_range("pop_back empty StrVec!");
	}
	alloc.destroy(--free_start);
}

string* StrVec::at(size_t index)
{
	check_range(index,"out of StrVec range");
	return elm_start + index;
}

std::string* StrVec::begin()
{
	return elm_start;
}
std::string* StrVec::end()
{
	if (free_start == nullptr)return nullptr;
	else return free_start;
}
void StrVec::reserve(size_t new_size)
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
	free_start = new_data+ new_size;
	free_end = new_data+ new_size;
}

size_t StrVec::capacity()
{
	return free_end - elm_start;
}

size_t StrVec::size()
{
	return free_start - elm_start;
}

void StrVec::resize(size_t new_size)
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

bool StrVec::empty()
{
	if (elm_start == nullptr) {
		return true;
	}
	else if (elm_start == free_start) {
		return true;
	}
	return false;
}


void StrVec::check_range(size_t index,const string &msg)
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

StrVec::StrVec(initializer_list<string> slist)
{
	for (auto &it : slist) {
		push_back(it);
	}
}

void StrVec::clear()
{
	while (free_start != elm_start)
	{
		alloc.destroy(--free_start);
	}
}


bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	return lhs.elm_start == rhs.elm_start && lhs.free_start == rhs.free_start && lhs.free_end == rhs.free_end;

}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);

}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
	auto lhs_elm = lhs.elm_start;
	auto rhs_elm = rhs.elm_start;
	while (lhs_elm != lhs.free_start && rhs_elm != rhs.free_start) {
		if (*lhs_elm > *rhs_elm) {
			return false;
		}
		if (lhs_elm != lhs.free_start)lhs_elm++;
		if (rhs_elm != rhs.free_start)rhs_elm++;
	}
	return true;
}