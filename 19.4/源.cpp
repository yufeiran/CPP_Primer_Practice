#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
typedef std::string::size_type pos;
class Screen {
public:
	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd)const;
	static const std::string Screen::* data() {
		return &Screen::contents;
	}
	static const pos Screen::* cur() {
		return &Screen::cursor;
	}
	Screen(std::string s,pos n) :contents(s),cursor(n) {};
private:
	std::string contents;
	pos cursor;
	pos height, width;

};

using namespace std;

using GET =
char (Screen::*)() const;

bool isEmpty(const string& s) {
	if (s == "")return true;
	return false;
}

int main()
{
	Screen s("yu",3);
	const string Screen::* pdata = Screen::data();
	const pos Screen::* pcur = Screen::cur();
	auto S = s.*pdata;
	auto c = s.*pcur;
	cout << S << endl;
	cout << c << endl;

	vector<string>svec = { "yu","","dwad","","dw","",""};
	cout << count_if(svec.begin(), svec.end(), isEmpty) << endl;


	return 0;
}