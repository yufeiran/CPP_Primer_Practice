#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//3.31
	int A[10];
	for (int i = 0; i < 10; i++) {
		A[i] = i;
	}
	//3.32
	vector<int>B;
	for (auto s : A) {
		B.push_back(s);
	}
	//3.33
	//unsigned scores[11] = {};
	//unsigned grade;
	//while (cin >> grade) {
	//	if (grade <= 100)
	//		++scores[grade / 10];
	//}
	//unsigned* b = begin(scores);
	//unsigned* e = end(scores);
	//for (unsigned* it = b; it != e; it++) {
	//	cout << *it << " ";
	//}

	//3.35
	int C[] = { 1,2,3,4,5,6 };
	int* b = begin(C);
	int* e = end(C);
	while (b != e) {
		*b = 0;
		b++;
	}
	for (auto s : C) {
		cout << s << " ";
	}
	b = begin(C);
	//3.36
	int D[] = { 1,2,3,4,5,6 };
	int* b1 = begin(D);
	int* e1 = end(D);
	int E[] = { 1,2,3,4,5,6,7 };
	int* b2 = begin(E);
	int* e2 = end(E);
	while (b2 != e2 && b1 != e1) {
		if (( *b2) != ( *b1)) {
			cout << "NO" << endl;
			break;
		}
		b2++;
		b1++;
		if ((b2 == e2 && b1 != e1) || (b2 != e2 && b1 == e1)) {
			cout << "NO" << endl;
			break;
		}
		else if (b2 == e2 && b1 == e1) {
			cout << "YES" << endl;
			break;
		}
	}

	vector<int>D1= { 1,2,3,4,5,6 };
	vector<int>E1= { 1,2,3,4,5,6};
	auto it1 = D1.begin();
	auto it2 = E1.begin();
	while (it1 != D1.end() && it2 != E1.end()) {
		if (*it1 != *it2) {
			cout << "NO" << endl;
			break; 
		}
		it1++;
		it2++;
		if ((it1 == D1.end() && it2 != E1.end()) || (it1 != D1.end() && it2 == E1.end())) {
			cout << "NO" << endl;
			break;
		}
		else if (it1 == D1.end() && it2 == E1.end()) {
			cout << "YES" << endl;
			break;
		}
	}

	//3.41
	int F[] = { 1,2,3,4,5,6,7 };
	vector<int>Fvec(begin(F), end(F));

	//3.42
	int G[7];
	for (int i = 0; i < Fvec.size(); i++) {
		G[i] = Fvec[i];
	}

	while (1);

	return 0;
}