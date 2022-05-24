
#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>

struct Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
struct Sales_data
{
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p) {}
	Sales_data(std::istream& is) { read(is, *this); }

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};




#endif // !SALES_DATA_H
