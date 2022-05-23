#pragma once
#include<string>
#include<iostream>

class Person
{
	friend std::istream& read(std::istream& is, Person& p);
	friend std::ostream& print(std::ostream& os, const Person& p);

public:
	Person() = default;
	Person(std::string Name, std::string Address) :name(Name), address(Address) {}


	const std::string getName()const { return name; }
	const std::string getAddress()const { return address; }
private:
	std::string name;
	std::string address;
};


std::istream& read(std::istream& is, Person& p);
std::ostream& print(std::ostream& os, const Person& p);