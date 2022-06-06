#include<map>
#include<set>
#include<iostream>
#include <string>
#include<unordered_map>

using namespace std;

void cutStr(string& s)
{
	for (auto& c : s) {
		c = tolower(c);
	}

	set<char>exclude = { ',','.' };
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (exclude.find(*it) != exclude.end()) {
			s.erase(it);
		}
		if (it == s.end())break;
	}
}

int main()
{
	string rawStr;
	unordered_map<string, int>strMap;
	while (cin >> rawStr) {
		cutStr(rawStr);
		auto it=strMap.insert({ rawStr,1 });
		if (it.second == false) {
			++it.first->second;
		}

	}

	for (const auto& m : strMap) {
		cout << m.first << " " << m.second << endl;
	}


	return 0;
}