#include"Account.h"
double Account::interestRate = Account::initRate();
void Account::rate(double d)
{
	interestRate = d;
}

double Account::initRate()
{
	return 0;
}