#pragma once
#include<string>
#include<utility>
#include<exception>
#include<stdexcept>
#include<initializer_list>
#include<cstdlib>
#include<iostream>

class StrVec
{
	friend bool operator==(const StrVec& lhs, const StrVec& rhs);
	friend bool operator<(const StrVec& lhs, const StrVec& rhs);
public:
	StrVec() :elm_start(nullptr), free_start(nullptr), free_end(nullptr) {};
	StrVec(const StrVec& s);
	StrVec(StrVec&& s)noexcept;
	StrVec(std::initializer_list<std::string> slist);
	StrVec& operator=(const StrVec& s);
	StrVec& operator=(StrVec&& s) noexcept;
	std::string& operator[](size_t n) { return *(elm_start+n); }
	const std::string& operator[](size_t n)const { return *(elm_start + n); }
	~StrVec() { free(); };
	void push_back(const std::string&s);
	void pop_back();
	std::string* at(size_t index);
	std::string* begin();
	std::string* end();
	void reserve(size_t new_size);
	size_t capacity();
	size_t size();
	void resize(size_t new_size);
	bool empty();
	void clear();
	template<class ...Args>void emplace_back(Args&&...);
private:
	void check_range(size_t index,const std::string &msg);
	void check_size() { if (size() == capacity())reallocate(); };
	void reallocate();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string* begin, const std::string* end);
	void free();
	std::allocator<std::string> alloc;
	std::string* elm_start;
	std::string* free_start;
	std::string* free_end;
};

bool operator==(const StrVec& lhs, const StrVec& rhs);
bool operator!=(const StrVec& lhs, const StrVec& rhs);
bool operator<(const StrVec& lhs, const StrVec& rhs);

template<class ...Args>
inline 
void StrVec::emplace_back(Args&&...args)
{
	check_size();
	alloc.construct(free_start++, std::forward<Args>(args)...);
}