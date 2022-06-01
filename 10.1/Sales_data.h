
#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>



class Sales_data
{
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

#endif // !SALES_DATA_H
