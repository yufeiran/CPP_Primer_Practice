#pragma once
#include<iostream>

class DebugDelete
{
public:
	DebugDelete(std::ostream& OS = std::cerr) :os(OS) {};
	template<typename T>
	void operator()(T* data)const {
		os << "Delete unique_ptr" << std::endl;
		delete data;
	}
private:
	std::ostream& os;
};
