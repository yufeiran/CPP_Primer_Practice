#include<iostream>
#include<string>

using namespace std;

string markStr[] = { "F","D","C","B","A","A++","unknown"};


int main()
{
	int ival1 = 10, ival2 = 10;
	if (ival1 != ival2)
		ival1 = ival2;
	else ival1 = ival2 = 0;



	//int mark = 0;
	//while (cin >> mark) {
	//	string nowMark;
	//	//if (mark < 60) {
	//	//	nowMark = markStr[0];
	//	//}
	//	//else if(mark<70) {
	//	//	nowMark = markStr[1];
	//	//}
	//	//else if (mark < 80) {
	//	//	nowMark = markStr[2];
	//	//}
	//	//else if (mark < 90) {
	//	//	nowMark = markStr[3];
	//	//}
	//	//else if (mark < 100) {
	//	//	nowMark = markStr[4];
	//	//}
	//	//else if (mark == 100) {
	//	//	nowMark = markStr[5];
	//	//}
	//	//else {
	//	//	nowMark = "Unkown";
	//	//}
	//	nowMark = markStr[(mark < 60) ? 0 : (mark < 70) ? 1 : (mark < 80) ? 2 : (mark < 90) ? 3 : (mark < 100) ? 4 : (mark == 100) ? 5 : 6];
	//	cout << nowMark << endl;

	//}

	//5.9
	string str;
	getline(cin, str);
	int vowelCnt = 0;
	int spaceCnt = 0;
	int tableCnt = 0;
	int entCnt = 0;
	for (auto c : str) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			vowelCnt++;
		}else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			vowelCnt++;
		}
		else if (c == ' ') {
			spaceCnt++;
		}
		else if (c == '\t') {
			tableCnt++;
		}
		else if (c == '\n') {
			entCnt++;
		}
	}
	int twoCnt = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == 'f' || str[i] == 'i' || str[i] == 'l') {
			twoCnt++;
		}
	}
	cout << str << " has " << vowelCnt << " vowels " << spaceCnt << " spaces " << tableCnt << " tables " << entCnt << " enters " << twoCnt << " ff fl fi " << endl;
	
	//5.13

	//unsigned evenCnt = 0, oddCnt = 0;
	//int digit = 8;
	//switch (digit) {
	//case 1,3,5,7,9:
	//	oddCnt++;
	//	break;
	//case 2,4,6,7,8:
	//	evenCnt++;
	//	break;
	//}

	//unsigned ival = 512, javl = 1024, kval = 4096;
	//unsigned bufsize;
	//unsigned swt = 1024;
	//switch (swt) {
	//case ival:

	//}
	
	return 0;
}