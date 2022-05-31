#include<vector>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

const string mStr[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
const string mmStr[] = { "Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec" };

class Date {
public:
	Date(const string& s) {
		int nowPos = 0;
		for (int i = 0; i < 12; i++) {
			if ((nowPos=s.find(mStr[i])) != string::npos) {
				month = i + 1;
				string  temp = s.substr(mStr[i].size(), s.find(',') - mStr[i].size());
				day = stoi(temp);
				temp = s.substr(s.find(',')+1);
				year = stoi(temp);
				return;
			}
			if ((nowPos = s.find(mmStr[i])) != string::npos) {
				month = i + 1;
				string  temp = s.substr(s.find_first_of(' '),s.find_last_of(' '));
				day = stoi(temp);
				temp = s.substr(s.find_last_of(' '));
				year = stoi(temp);
				return;
			}
		}
		string temp;
		temp = s.substr(0, s.find_first_of('/'));
		day = stoi(temp);
		temp = s.substr(s.find_first_of('/') + 1, s.find_last_of('/')- s.find_first_of('/')-1);
		month = stoi(temp);
		temp = s.substr(s.find_last_of('/') + 1);
		year = stoi(temp);

	}
private:
	unsigned year, month, day;
};

void showInfo(const vector<int>&vec)
{
	cout << "size: " << vec.size() << " cap: " << vec.capacity() << " size(Bytes):" << sizeof(vec) << endl;

}

void replaceStr(string& str, const string& val1, const string& val2)
{
	int size = val1.size();
	for (auto it = str.begin(); it != str.end(); it++){
		string sub = str.substr(it-str.begin(),size);
		if (sub == val1) {
			//str.erase(it, it + size);
			//str.insert(it-str.begin(),val2 );
			str.replace(it-str.begin(), size, val2);
		}
	}
}

string AddName(const string& name, const string& first, const string& end)
{
	//string s(first);
	//s.append(name);
	//s.append(end);
	//return s;
	string s(name);
	s.insert(0, first);
	s.insert(s.size(), end);
	return s;
}

int findMax(const string& s)
{
	int maxLen = 0;
	int lastPos = -1;
	int nowPos = -1;
	int pos = 0;
	string notS("qtypdfghjlb");
	if (s.find_first_of(notS, pos) == string::npos) {
		return s.size();
	}
	while ((pos = s.find_first_of(notS, pos)) != string::npos) {
		lastPos = nowPos;
		nowPos = pos;
		int nowLen = nowPos - lastPos-1;
		if (nowLen > maxLen)maxLen = nowLen;
		pos++;
	}
	return maxLen;
}

int main()
{
	vector<int>vec;
	showInfo(vec);
	for (int i = 1; i < 20; i++)
	{
		int count = pow(2, i);
		for (int j = 0; j < count; j++) {
			vec.push_back(0);

		}
		showInfo(vec);

	}

	vector<char> cvec = {'y','f','r'};
	//string s(cvec.begin(),cvec.end());
	//cout << s << endl;

	string test = "Yufeiran1999";
	replaceStr(test, "1999", "2022");
	cout << test << endl;

	cout << AddName("yufeiran", "Mr.", "Jr.") << endl;

	string s("ab2c3d7R4E6");
	string findS = "abcdRE";
	int pos = 0;
	while ((pos = s.find_first_of(findS, pos)) != string::npos) {
		cout << pos << " ";
		pos++;
	}
	cout << endl;
	pos = 0;
	while ((pos = s.find_first_not_of(findS,pos)) != string::npos) {
		cout << pos << " ";
		pos++;
	}
	cout << endl;

	cout << findMax("aczxdmn") << endl;

	vector<string>svec = { "123","456","789" };

	int ans = 0;
	for (const auto& s : svec) {
		ans += stoi(s);
	}
	cout << "ans:" << ans << endl;
	double ans1 = 0;
	for (const auto& s : svec) {
		ans1 += stod(s);
	}
	cout << "ans:" << ans1 << endl;

	//Date("January 1,1900");
	Date("Jan 1 1900");
	Date("1/1/1990");
	return 0;
}