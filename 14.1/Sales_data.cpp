#include"Sales_data.h"
using namespace std;
Sales_data& Sales_data::combine(const Sales_data& other)
{
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
