
#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
#include<unordered_map>
#include<exception>

class out_of_stock :public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s):
		std::runtime_error(s) {}
};

class isbn_mismatch :public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s):
		std::logic_error(s) {}
	isbn_mismatch(const std::string& s,
		const std::string& lhs, const std::string& rhs) :
		std::logic_error(s), left(lhs), right(rhs) {}
	const std::string left, right;
};

template<class T>class std::hash;
class Sales_data
{
	friend class  std::hash<Sales_data>;
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);

public:
	Sales_data() :Sales_data("", 0, 0) { std::cout << "()" << std::endl; }
	Sales_data(const std::string& s) :Sales_data(s, 0, 0) { std::cout << "(string)" << std::endl; }
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p) {
		std::cout << "(string,uint,double)" << std::endl;
	}
	Sales_data(std::istream& is) :Sales_data() {
		read(is, *this); std::cout << "(istream)" << std::endl;
	}
	Sales_data& operator+=(const Sales_data& s);
	Sales_data& operator=(const std::string& str);
	operator std::string() { return bookNo; }
	operator double() { return revenue; }
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
private:
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

Sales_data operator+(const Sales_data& a, const Sales_data& b);
std::ostream& operator<<(std::ostream& os, const Sales_data& s);

std::istream& operator>>(std::istream& is, Sales_data& s);

#ifndef HEADER
#define HEADER
namespace std {
template<>
struct hash<Sales_data>
{
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator()(const Sales_data& s) const;
};
size_t hash<Sales_data>::operator()(const Sales_data& s)const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
}
}
#endif //HEADER

#endif // !SALES_DATA_H
using namespace std;
Sales_data& Sales_data::combine(const Sales_data& other)
{
	if (this->isbn() != other.isbn()) {
		throw isbn_mismatch("wrong isbns", isbn(), other.isbn());
	}
	units_sold += other.units_sold;
	revenue += other.revenue;

	return *this;
}

inline double Sales_data::avg_price() const
{
	if (units_sold == 0)return 0;
	return revenue / units_sold;
}



std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is) {
		item.revenue = price * item.units_sold;
	}
	else {
		item = Sales_data();
	}
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{

	Sales_data ans = lhs;
	ans.combine(rhs);

	return ans;
}



Sales_data operator+(const Sales_data& a, const Sales_data& b)
{
	return add(a, b);
}

std::ostream& operator<<(std::ostream& os, const Sales_data& s)
{
	return print(os, s);
}

std::istream& operator>>(std::istream& is, Sales_data& s)
{
	double price = 0;
	return read(is, s);
}

Sales_data& Sales_data::operator+=(const Sales_data& s)
{

	*this = *this + s;
	return *this;
}

Sales_data& Sales_data::operator=(const std::string& str)
{
	bookNo = str;
	return *this;
}
