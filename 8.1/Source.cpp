#include<iostream>
#include<string>
using namespace std;
 

istream& output(istream& is)
{
	string temp;
	while (is >> temp) {
		cout << temp << " ";
	}
	is.clear();
	return is;
}

int main()
{
	cout << "hi!" << endl;
	cout << "hi!" << flush;
	cout << "hi!" << ends;
	cout << unitbuf;
	cout << "yufe";
	cout << nounitbuf;
	if (output(cin).good()) {
		cout << "666" << endl;
	}

	return 0;
}