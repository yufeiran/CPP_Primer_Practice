#pragma once
#include<string>
#include<utility>
#include<exception>
#include<stdexcept>
#include<initializer_list>

class StrVec
{
public:
	StrVec() :elm_start(nullptr), free_start(nullptr), free_end(nullptr) {};
	StrVec(const StrVec& s);
	StrVec(std::initializer_list<std::string> slist);
	StrVec& operator=(const StrVec& s);
	~StrVec() { free(); };
	void push_back(const std::string& s);
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
private:
	void check_range(size_t index, const std::string& msg);
	void check_size() { if (size() == capacity())reallocate(); };
	void reallocate();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string* begin, const std::string* end);
	void free();
	std::allocator<std::string> alloc;
	std::string* elm_start;
	std::string* free_start;
	std::string* free_end;
};