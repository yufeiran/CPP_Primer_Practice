#pragma once

#include<fstream>
#include<iostream>



template<typename T>
class Screen
{
	template<typename T> friend  std::ostream& operator<<(std::ostream& os, const Screen<T>& s);
	template<typename T> friend  std::istream& operator>>(std::istream& is, Screen<T>& s);
public:
	Screen(T h, T w) :height(h), width(w) {};
	Screen():height(0),width(0) {};
private:
	T height, width;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Screen<T>& s)
{
	os << "Height:" << s.height << " Width:" << s.width;
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Screen<T>& s)
{
	is >> s.height >> s.width;
	return is;
}