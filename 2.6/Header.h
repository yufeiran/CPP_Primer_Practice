#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>


struct Sales_data
{
	std::string ISBN;
	int sum = 0;
	double totalPrice = 0;
};

#endif // !SALES_DATA_H
