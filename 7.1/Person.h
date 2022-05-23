#pragma once
#include<string>
#include<iostream>

struct Person
{
	Person() = default;
	Person(std::string Name, std::string Address) :name(Name), address(Address) {}

	std::string name;
	std::string address;
	const std::string getName()const { return name; }
	const std::string getAddress()const { return address; }
};


std::istream& read(std::istream& is, Person& p);
std::ostream& print(std::ostream& os, const Person& p);