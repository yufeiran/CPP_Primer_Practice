#include<iostream>
#include<string>
#include<memory>
using namespace std;


int main()
{
	char* raw = new char[20];
	memset(raw, 0, sizeof(raw));
	//strcpy_s(raw, 3,"yu");
	//strcpy_s(raw + 2, 4, "fei");
	//cout << raw << endl;
	strcpy_s(raw, 7, (string("yu") + string("fei")).c_str());
	cout << raw << endl;


	//char* raw1 = new char[20];
	//cin >> raw1;
	//cout << raw1;

	allocator<string> alloc;
	auto p = alloc.allocate(10);
	string s;
	string* q = p;
	while (cin >> s && q != p + 10) {
		alloc.construct(q, s);
		++q;
	}
	const size_t size = q - p;
	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 10);

	return 0;
}
