#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<sstream>
#include<fstream>
#include<unordered_map>

using namespace std;

multimap<string, vector<pair<string, string>>>familys;

multimap<string, string>workbook;

unordered_map<string, string> build_translate_map(ifstream& rule)
{
	unordered_map<string, string> nowMap;
	string key, value;
	while (rule >> key && getline(rule, value)) {
		if (value.size() > 0) {
			nowMap.insert( { key, value.substr(1)});
			//nowMap[key] = value.substr(1);
		}
	}
	return nowMap;
}

string translate(const string& raw, const unordered_map<string, string>& rule_map)
{
	if (rule_map.find(raw) != rule_map.end()) {
		return rule_map.find(raw)->second;
	}
	else {
		return raw;
	}
}

void transform_text(ifstream& rule, ifstream& raw)
{
	auto rule_map = build_translate_map(rule);
	string text;
	while(getline(raw,text))
	{
		stringstream ss(text);
		bool isFirst = true;
		string nowStr;
		while (ss >> nowStr) {
			if (isFirst) {
				isFirst = false;
			}
			else {
				cout << " ";
			}
			cout << translate(nowStr, rule_map);
		}
		cout << endl;
	}
}

int main()
{
	map<string, int>smap;
	smap["yu"] = 3;
	auto m_it = smap.begin();
	++m_it->second;
	cout << m_it->second << endl;
	multiset<string>c = { "yu","fei","ran" };
	vector<string>v = { "wang","da" };
	copy(v.begin(), v.end(), inserter(c, c.end()));
	//copy(v.begin(), v.end(), back_inserter(c));
	copy(c.begin(), c.end(), inserter(v, v.end()));
	copy(c.begin(), c.end(), back_inserter(v));

	vector<pair<string, string>>family = { {"yufeiran","19990519"},{"yuyong","20000101"} };
	familys.insert({ "yu",family });

	workbook.insert({ "yu", "mips" });
	workbook.insert({ "li", "c++" });
	workbook.emplace("yu", "unix");
	workbook.emplace("ali", "taobao");
	workbook.emplace("tencent", "wzry");

	string str;
	cin >> str;
	auto it = workbook.find(str);
	if (it != workbook.end()) {
		workbook.erase(it);
	}
	for (auto c : workbook) {
		cout << c.first << " " << c.second << endl;
	}

	ifstream rule("rule.txt");
	ifstream raw("raw.txt");
	transform_text(rule, raw);

	return 0;
}