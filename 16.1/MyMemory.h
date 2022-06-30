#pragma once
#include<iostream>

template<typename T>
class shared_ptr
{
public:
	shared_ptr(T* data, void(*delFun)(T*) = nullptr) :_data(data), delF(delFun), count(new size_t(1)) {};
	shared_ptr(const shared_ptr<T>& sp) :_data(sp._data), delF(sp.delF), count(sp.count) {
		std::cout << "shared_ptr(const shared_ptr<T>& sp)  call!" << std::endl;
		(* count)++;
	}
	T& operator*() const {
		return *_data;
	}
	T* operator->()const {
		return _data;
	}
	void reset(T* data, void(*delFun)(T*) = nullptr) {
		(*count)--;
		_data = data;
		delF = delFun;
		count = new int(1);
	}
	shared_ptr<T> operator=(const shared_ptr<T>& sp) {
		std::cout << "shared_ptr<T> operator=(const shared_ptr<T>& sp) call" << std::endl;
		(*count)--;
		(* sp.count)++;
		return shared_ptr(_data, delF, count);
	}
	
	shared_ptr<T> operator=(shared_ptr<T>&& sp) {
		if (this == sp) {
			return this;
		}
		return shared_ptr(_data, delF, count);
	}
	~shared_ptr() {
		(*count)--;
		std::cout << "shared_ptr now count " << *count << std::endl;
		if (*count == 0) {
			std::cout << "shared_ptr start del" << std::endl;
			if (delF != nullptr) {
				delF(_data);
			}
			else {
				delete _data;
				delete count;
			}
		}
	}

private:
	shared_ptr(T* data, void(*delFun)(T*), size_t* new_count) :_data(data), delF(delFun), count(new_count) {};
	void (*delF)(T*);
	size_t *count;
	T* _data;
};

template<typename T,typename DELT>
class unique_ptr
{
public:
	unique_ptr(T* data, DELT del) :_data(data), delF(del) {};
	~unique_ptr() {
		delF(_data);
	}
	T& operator*() {
		return *_data;
	}
	T* operator->() {
		return _data;
	}

private:
	T* _data;
	DELT delF;
};