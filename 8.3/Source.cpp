#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
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

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched
		&& (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched
		&& m[4].str() == m[6].str();
}

bool vaild(string s)
{
	regex r("(\\()?(\\d{3})(\\))?([ .-])*(\\d{3})([-. ])*(\\d{4})");

	smatch m;
	while (getline(cin, s)) {
		for (sregex_iterator it(s.begin(), s.end(), r), it_end; it != it_end; it++)
		{
			if (valid(*it))
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
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
		bool firstFlag = true;
		for (const auto& nums : entry.phones) {
			if (!vaild(nums)) {
				badNums << " " << nums;
			}
			else
			{
				//if (firstFlag == false) {
				//	formatted << " " << format(nums);
				//	break;
				//}
				firstFlag = false;
				formatted << " " << format(nums);
				//break;
			}

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