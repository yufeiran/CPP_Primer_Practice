#pragma once
#include<utility>
#include<exception>
#include<stdexcept>
#include<iostream>
#include<initializer_list>

class string
{
	friend bool operator<(const string& lhs, const string& rhs);
	friend bool operator==(const string& lhs, const string& rhs);
public:
	string() :elm_start(nullptr), free_start(nullptr), free_end(nullptr) {};
	string(const string& s);
	string(const char* c);
	string(string&& s)noexcept;
	string& operator=(const string& s);
	string& operator=(string&& s)noexcept;
	char& operator[](size_t n) { return *(elm_start + n); }
	const char& operator[](size_t n)const { return *(elm_start + n); }
	
	size_t size();
	size_t capacity();
	bool empty();
	const char* cbegin()const { return elm_start; };
	const char* cend()const { return free_start; };
	char* begin();
	char* end(); 
	char* at(size_t pos);
	void push_back(const char& c);
	void pop_back();
	char* c_str();
private:

	void check_range(size_t pos);
	void check_size() { if (size() == capacity())reallcoate(); }
	void reallcoate();
	void free();
	std::pair<char*, char*>alloc_n_copy(const char* begin, const char* end);
	std::allocator<char> alloc;
	char* elm_start;
	char* free_start;
	char* free_end;
};

bool operator==(const string& lhs, const string& rhs)
{
	return lhs.elm_start == rhs.elm_start && lhs.free_start == rhs.free_start && lhs.free_end == rhs.free_end;
}

bool operator!=(const string& lhs, const string& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const string& lhs, const string& rhs)
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

std::ostream& operator<<(std::ostream& os, const string& s)
{
	for (auto it = s.cbegin(); it != s.cend(); it++) {
		os << *it;
	}
	return os;
}


string& string::operator=(const string& s)
{
	std::cout << "string& string::operator=(const string& s) call!" << std::endl;
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	free();
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
	return *this;
}

inline string& string::operator=(string&& s) noexcept
{
	if (&s != this) {
		elm_start = s.elm_start;
		free_start = s.free_start;
		free_end = s.free_end;
		s.elm_start = s.free_start = s.free_end = nullptr;
	}
	return *this;
}

void print( string& s)
{
	for (auto it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it;
	}
}

string::string(const string& s)
{
	std::cout << "string::string(const string& s) call!" << std::endl;
	auto new_mem = alloc_n_copy(s.elm_start, s.free_start);
	elm_start = new_mem.first;
	free_start = new_mem.second;
	free_end = new_mem.second;
}

string::string(const char* c)
{
	const char* nowptr = c;
	while (*nowptr != 0) {
		push_back(*nowptr++);
	}

}

inline string::string(string&& s)noexcept :elm_start(s.elm_start),free_start(s.free_start),free_end(s.free_end)
{
	std::cout << "inline string::string(string&& s) noexcept call!" << std::endl;
	s.elm_start = s.free_start = s.free_end = nullptr;
}

void string::push_back(const char& c)
{
	check_size();
	alloc.construct(free_start++, c);
}

void string::pop_back()
{
	if (empty()) {
		throw std::out_of_range("empty string can not pop_back");
	}

}

char* string::begin()
{
	return elm_start;
}

char* string::end()
{
	return free_start;
}

char* string::at(size_t pos)
{
	check_range(pos);
	return elm_start + pos;
}

char* string::c_str()
{
	return elm_start;
}


size_t string::size()
{
	return free_start - elm_start;
}

size_t string::capacity()
{
	return free_end - elm_start;
}

bool string::empty()
{
	if (size() == 0)return true;
	else return false;
}

void string::reallcoate()
{
	size_t new_size = size() ? size() * 2 : 1;

	auto new_mem = alloc.allocate(new_size);

	auto old_size = size();
	auto now_elm = new_mem;
	auto old_now_elm = elm_start;
	for (auto it = elm_start; it != free_start; it++) {
		alloc.construct(now_elm++, std::move(*old_now_elm++));
	}
	elm_start = new_mem;
	free_start = new_mem + old_size;
	free_end = new_mem + new_size;

}

std::pair<char*, char*>string::alloc_n_copy(const char* begin, const char* end)
{
	auto new_mem = alloc.allocate(end - begin);

	return std::pair<char*, char*>(new_mem, std::uninitialized_copy(begin, end, new_mem));
}

void string::free()
{
	auto now_elm = elm_start;

	while (now_elm != free_start) {
		alloc.destroy(now_elm++);
	}
	alloc.deallocate(elm_start, free_end - elm_start);
}

void string::check_range(size_t pos)
{
	if (pos >= size()) {
		throw std::out_of_range("out of string range");
	}
}