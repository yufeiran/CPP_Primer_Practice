#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
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

struct PersonInfo
{
	string name;
	vector<string> phones;
};

bool vaild(string s)
{
	for (auto c : s) {
		if (!isdigit(c))return false;
	}
	return true;
}

string format(string s)
{
	return "[" + s + "] ";
}

int main(int argc,char *argv[])
{
	//string s= "yu\nfei \nran\n1999\n@\ngmail . com";
	//istringstream S(s);


	//output(S);

	//if (argc < 2)return 1;
	//vector<string>sVec;
	//ifstream in(argv[1]);
	//string temp;
	//while (getline(in,temp)) {
	//	sVec.push_back(temp);
	//}
	//
	//for (auto c : sVec) {
	//	istringstream is(c);
	//	string nowS;
	//	while (is >> nowS) {
	//		cout << nowS << endl;
	//	}
	//}

	if (argc < 3)return 1;

	ifstream in(argv[1]);
	ofstream os(argv[2]);

	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(in, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
		record.clear();
	}
	
	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			if (!vaild(nums)) {
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty()) {
			os << entry.name << " "
				<< formatted.str() << endl;
		}
		else
			cerr << "input error: " << entry.name
			<< " invalid number(s) " << badNums.str() << endl;
	}

	return 0;
}