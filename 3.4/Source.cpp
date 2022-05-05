#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	//3.21
	vector<int>v1;
	cout << "v1 size:" << v1.size() << endl;
	vector<int>v2(10);
	for (auto s = v2.begin(); s != v2.end(); s++) {
		cout << *s << " ";
	}

	cout << endl;
	cout << "v2 size:" << v2.size() << endl;

	vector<int>v3(10, 42);
	for (auto s = v3.begin(); s != v3.end(); s++) {
		cout << *s << " ";
	}
	cout << endl;
	cout << "v3 size:" << v3.size() << endl;
	vector<int>v4{ 10 };
	for (auto s = v4.begin(); s != v4.end(); s++) {
		cout << *s << " ";
	}
	cout << endl << "v4 size:" << v4.size() << endl;
	vector<int>v5{ 10,42 };
	for (auto s = v5.begin(); s != v5.end(); s++) {
		cout << *s << " ";
	}
	cout << endl << "v5 size:" << v5.size() << endl;
	vector<string>v6{ 10 };
	for (auto s = v6.begin(); s != v6.end(); s++) {
		cout << *s << " ";
	}
	cout << endl << "v6 size:" << v6.size() << endl;
	vector<string>v7{ 10,"hi" };
	for (auto s = v7.begin(); s != v7.end(); s++) {
		cout << *s << " ";
	}
	cout << endl << "v7 size:" << v7.size() << endl;


	//3.22
	//vector<string>text;
	//string temp;
	//while (getline(cin, temp)) {
	//	text.push_back(temp);
	//}

	//if (text.begin() != text.end()) {
	//	for (auto &s : *text.begin()) {
	//		s = toupper(s);
	//	}
	//}
	//for (auto it = text.begin(); it != text.end(); it++) {
	//	cout << *it << endl;
	//}

	//3.23
	//vector<int>ivec;
	//for (int i = 0; i < 10; i++) {
	//	ivec.push_back(i);
	//}

	//for (auto s = ivec.begin(); s != ivec.end(); s++) {
	//	*s *= 2;
	//}
	//for (auto it = ivec.begin(); it != ivec.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	//3.24
	//vector<int>ivec;
	//int temp;
	//while (cin >> temp) {
	//	ivec.push_back(temp);
	//}
	//for (auto it = ivec.begin(); it != ivec.begin()+ivec.size()/2; it++) {
	//	int ans = *it + *(ivec.begin()+(ivec.end() - 1 - it));
	//	cout << ans << endl;
	//}

	//3.25
	vector<unsigned> scores(11, 0);


	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100) {
			(* (scores.begin() + (grade / 10)))++;
		}
	}

	for (auto s : scores) {
		cout << s << " ";
	}
	cout << endl;

	return 0;
} 