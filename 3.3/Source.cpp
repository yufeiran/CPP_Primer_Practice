#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	//3.14
	//vector<int>iVec;
	//int temp;
	//while (cin >> temp) {
	//	iVec.push_back(temp);
	//}
	//3.15
	//vector<string>sVec;
	//string temp;
	//while (cin >> temp) {
	//	sVec.push_back(temp);
	//}

	//3.16
	vector<int>v1;
	cout << "v1 size:" << v1.size() << endl;
	vector<int>v2(10);
	for (auto s : v2) {
		cout << s << " ";
	}
	cout << endl;
	cout << "v2 size:" << v2.size() << endl;

	vector<int>v3(10, 42);
	for (auto s : v3) {
		cout << s << " ";
	}
	cout << endl;
	cout << "v3 size:" << v3.size() << endl;
	vector<int>v4{ 10 };
	for (auto s : v4) {
		cout << s << " ";
	}
	cout << endl << "v4 size:" << v4.size() << endl;
	vector<int>v5{ 10,42 };
	for (auto s : v5) {
		cout << s << " ";
	}
	cout << endl << "v5 size:" << v5.size() << endl;
	vector<string>v6{ 10 };
	for (auto s : v6) {
		cout << s << " ";
	}
	cout << endl << "v6 size:" << v6.size() << endl;
	vector<string>v7{ 10,"hi" };
	for (auto s : v7) {
		cout << s << " ";
	}
	cout << endl << "v7 size:" << v7.size() << endl;

	//3.17
	//vector<string>ivec;
	//string temp;
	//while (getline(cin, temp)) {
	//	for (auto& c : temp) {
	//		c = toupper(c);
	//	}
	//	ivec.push_back(temp);

	//}

	//for (auto s : ivec) {
	//	cout << s << endl;
	//}

	//3.20
	vector<int>ivec;
	int temp;
	while (cin >> temp) {
		ivec.push_back(temp);
	}
	//for (int i = 0; i < ivec.size()-1; i+=2) {
	//	int ans = ivec[i] + ivec[i + 1];
	//	cout << ans << endl;
	//}
	for (int i = 0; i < ivec.size() / 2; i++) {
		int ans = ivec[i] + ivec[ivec.size() - 1 - i];
		cout << ans << endl;
	}

	return 0;
}