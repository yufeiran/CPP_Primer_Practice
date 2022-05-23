#include"Sales_data.h"
#include"Debug.h"
#include"Account.h"
#include<vector>
#include"Example.h"

class NoDefault
{
public:
	NoDefault(int a) {};
};

class C
{
public:
	C() :no(0) {};
	NoDefault no;
};


int main()
{
	Sales_data s;

	Sales_data s1("hi");

	Sales_data s2("HI", 1, 2);

	//Sales_data s3(std::cin);
	std::vector<C>vec(10);
	bool b = false;
	constexpr Debug d(false);

	Debug d1(false);
	d1.set_hw(b);

	Account a;
	a.rate(2.3);


	return 0;
}