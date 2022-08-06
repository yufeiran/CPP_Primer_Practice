#include<iostream>
#include<regex>
#include<string>

using namespace std;

int main()
{

	regex r8("[^c]ei");

	smatch results;
	string name;

	while (getline(cin,name)) {
		for (sregex_iterator it(name.begin(), name.end(), r8), end_it; it != end_it; it++)
		{
			cout << it->prefix().str() << endl;
			cout << it->str() << endl;
			cout << it->suffix().str() << endl;
		}

	}

	return 0;
}