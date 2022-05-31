#include<iostream>
#include<deque>
#include<string>
#include<list>
#include<vector>
#include<forward_list>

using namespace std;

void insertStr(forward_list<string>& fl, const string& str1, const string& str2)
{
	auto it = fl.begin();
	auto before = fl.before_begin();
	while (it != fl.end()) {
		if (*it == str1) {
			fl.insert_after(it,str2);
			return;
		}
		before = it;
		++it;
	}
	fl.insert_after(before, str2);
}

int main()
{
	//deque<string>strd;
	//string str;
	//while (cin >> str) {
	//	strd.push_back(str);
	//}
	//
	//for (deque<string>::iterator it = strd.begin(); it != strd.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	//list<string>strd;
	//string str;
	//while (cin >> str) {
	//	strd.push_back(str);
	//}

	//for (list<string>::iterator it = strd.begin(); it != strd.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	list<int> lista = { 1,2,3,4,5,6,7,8,9 };
	list<int> list1, list2;

	for (const auto& c : lista) {
		if (c % 2 == 0) {
			list1.push_back(c);
		}
		else {
			list2.push_back(c);
		}
	}

	cout << "list1:";
	for (auto c : list1) {
		cout << c << " ";
	}
	cout << endl;
	cout << "list2:";
	for (auto c : list2) {
		cout << c << " ";
	}
	cout << endl;

	//vector<string> vec;
	//auto iter = vec.begin();
	//string word;
	//while (cin >> word) {
	//	iter = vec.insert(iter, word);
	//}

	//for (auto s : vec) {
	//	cout << s << " ";
	//}
	//cout << endl;
	vector<int>a;

	//auto now = a.at(0);
	//auto now1 = a[0];
	//auto now2 = a.front();
	auto now3 = a.begin();

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int>ivec;
	list<int>ilist;
	for (auto it = begin(ia); it != end(ia); it++) {
		ivec.push_back(*it);
		ilist.push_back(*it);
	}

	auto it = ivec.begin();
	while (it != ivec.end()) {
		if (( * it % 2) == 0) {
			it = ivec.erase(it);
		}
		else {
			it++;
		}
	}

	auto it1 = ilist.begin();
	while (it1 != ilist.end()) {
		if (( * it1 % 2) != 0) {
			it1 = ilist.erase(it1);
		}
		else {
			it1++;
		}
	}

	cout << "ilist:";
	for (auto c : ilist) { cout << c << " "; }
	cout << endl;
	cout << "ivec:";
	for (auto c : ivec) { cout << c << " "; }
	cout << endl;

	forward_list<int> flist;
	for (auto it = rbegin(ia); it != rend(ia); it++) {
		flist.push_front(*it);
	}

	auto it2 = flist.begin();
	auto beforeit2 = flist.before_begin();
	while (it2 != flist.end()) {
		if ((*it2) % 2 != 0) {
			it2 = flist.erase_after(beforeit2);
		}
		else {
			beforeit2 = it2;
			++it2;
		}

	}

	forward_list<string>fl = { "yu","fei","ran" };
	insertStr(fl, "yu", "1999");
	for (auto s : fl) {
		cout << s << " ";
	}
	cout << endl;
	insertStr(fl, "223", "six");
	for (auto s : fl) {
		cout << s << " ";
	}
	cout << endl;

	forward_list<int>vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	auto beforeIter = vi.before_begin();
	while (iter != vi.end()) {
		if (( *iter % 2)==0) {
			iter = vi.insert_after(beforeIter, *iter);
			++iter;
			beforeIter = iter;
			++iter;
		}
		else {
			iter=vi.erase_after(beforeIter);

		}
	}

	vector<int>v={1};
	auto begin = v.begin();
	while (begin != v.end()) {
		++begin;
		begin = v.insert(begin, 42);
		++begin;
	}

	vector<int>v2 = { 1,2,3 };
	auto iter1 = v2.begin();
	while (iter1 != v2.end()) {
		if (*iter1 % 2)
		{
			iter1 = v2.insert(iter1, *iter1);
			++iter1;

		}
		++iter1;

	}
	
	return 0;
}