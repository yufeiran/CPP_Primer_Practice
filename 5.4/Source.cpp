#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	//string inStr;
	//string nowStr;
	//int nowCnt = 0;
	//string maxStr;
	//int maxCnt = 0;
	//string lastStr;
	//while (cin >> inStr) {
	//	if (lastStr == inStr) {
	//		nowStr = lastStr;
	//		nowCnt++;
	//		if (nowCnt > maxCnt) {
	//			maxCnt = nowCnt;
	//			maxStr = nowStr;
	//		}
	//	}
	//	else {
	//		nowStr = inStr;
	//		nowCnt = 1;
	//	}
	//	lastStr = inStr;
	//}

	//cout << maxStr << " cnt:" << maxCnt << endl;

	
	vector<int>v1 = { 0,1,1,2 };
	vector<int>v2 = { 0,1,1,2,3,5,8 };

	bool sameFlag = true;
	for (int i = 0; i < v1.size() && i < v2.size(); i++) {
		if (v1[i] != v2[i]) {
			cout << "No!" << endl;
			sameFlag = false;
			break;
		}
		
	}
	if (sameFlag == true) {
		cout << "Yes!" << endl;
	}
	string s1, s2;
	cin >> s1 >> s2;
	do {
		if (s1.size() > s2.size()) {
			cout<<"The biger is " << s1 << endl;
		}
		else {
			cout<<"The biger is " << s2 << endl;
		}
		cout << "enter two string:";

	} while (cin >> s1 >> s2);
	return 0;
}