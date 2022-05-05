#include<iostream>

using namespace std;

int main()
{
	int arr[10][20][30] = { 0 };

	int(&a)[20][30] = arr[1];

	for (auto& s1 : arr) {
		for (auto& s2 : s1) {
			for (const auto s3 : s2) {
				cout << s3 << " ";
			}
			cout << endl;
		}
		cout << "____________" << endl;
	}

	//3.43
	int ia[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			ia[i][j] = i * 4 + j;
		}
	}

	for (int (&s)[4] : ia) {
		for (int c : s) {
			cout << c << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}

	for (int(*a)[4] = begin(ia); a < end(ia); a++) {
		for (int* b = begin(*a); b < end(*a); b++) {
			cout << *b << " ";
		}
		cout << endl;
	}

	cout << "=====================" << endl;

	//3.34
	using int_arry = int[4];

	for (int_arry&s : ia) {
		for (int c : s) {
			cout << c << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}

	for (int_arry*a = begin(ia); a < end(ia); a++) {
		for (int* b = begin(*a); b < end(*a); b++) {
			cout << *b << " ";
		}
		cout << endl;
	}

	cout << "=====================" << endl;

	//3.35

	for (auto &s : ia) {
		for (auto c : s) {
			cout << c << " ";
		}
		cout << endl;
	}

	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 4; j++) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}

	for (auto a = begin(ia); a < end(ia); a++) {
		for (auto b = begin(*a); b < end(*a); b++) {
			cout << *b << " ";
		}
		cout << endl;
	}

	return 0;
}