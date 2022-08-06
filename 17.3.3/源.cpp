#include<iostream>
#include<regex>

using namespace std;

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched
		&& (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched
		&& m[4].str() == m[6].str();
}

bool valid1(const smatch& m)
{
	if (m[1].matched == false)
	{
		return !m[2].matched;
	}
	else return true;
}

int main()
{
	//regex r("(\\()?(\\d{3})(\\))?([ .-])*(\\d{3})([-. ])*(\\d{4})");

	//smatch m;
	//string s;
	//while (getline(cin, s)) {
	//	for (sregex_iterator it(s.begin(), s.end(), r), it_end; it != it_end; it++)
	//	{
	//		if (valid(*it))
	//		{
	//			cout << "valid: " << it->str() << endl;
	//			string fmt("$2.$5.$7");
	//			cout << "replace " << regex_replace(it->str(),r, fmt) << endl;
	//		}
	//		else {
	//			cout << "not valid: " << it->str() << endl;
	//		}
	//	}
	//}

	regex r1("(\\d{5})?(-)?(\\d{4})");
	regex r2("(\\d{5})(\\d{4})");

	smatch m1;
	string s1;
	while (getline(cin, s1)) {
		for (sregex_iterator it(s1.begin(), s1.end(), r2), it_end; it != it_end; it++)
		{
			if (valid1(*it))
			{
				cout << "valid: " << it->str() << endl;
				string fmt("$1-$2");
				cout << "replace " << regex_replace(it->str(),r2, fmt) << endl;
			}
			else {
				cout << "not valid: " << it->str() << endl;
			}
		}
	}


	return 0;
}