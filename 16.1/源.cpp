#include<iostream>
#include<vector>
#include<list>

#include"DebugDelete.h"
#include<string>
#include"Blob.h"
#include"screen.h"
#include"Vec.h"
#include"MyMemory.h"

using namespace std;
template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)return 1;
	if (rhs < lhs)return -1;
	else return 0;
}

template<typename ITER,typename T>
ITER find(const ITER& begin,const ITER& end, T raw)
{
	ITER now = begin;
	while (now != end)
	{
		if (*now == raw) {
			return now;
		}
		now++;
	}
	return now;
}

template<unsigned T>
void print(int(&arr)[T])
{
	for (auto elm : arr) {
		std::cout << elm << " ";
	}
}

template<typename T,unsigned M>
T* begin(T(&arr)[M])
{
	return &arr[0];
}

template<typename T,unsigned M>
T* end(T(&arr)[M])
{
	return &arr[0] + M;
}

template<typename T,unsigned M>
constexpr unsigned  len(T(&arr)[M])
{
	return M;
}

template<typename T>
void print(vector<T>& vec)
{
	using size_t =typename vector<T>::size_type;
	for (size_t i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}	

template<typename T>
void print1(vector<T>& vec)
{
	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
}

template<typename T>
void Debug1Delete(T* data) {
	cout << "Delete unique_ptr" << std::endl;
	delete data;
}

int main()
{
	std::cout << compare(22, 34) << std::endl;
	std::cout << compare(22.9, 3.3) << std::endl;
	std::cout << compare(std::string("hello"), std::string("wordld")) << std::endl;
	std::vector<int> ivec = { 1,2,3,4,5,6,7 };
	std::list<int>ilist = { 2,3,4,5,6,8 };
	std::cout << *(::find(ivec.begin(), ivec.end(), 6)) << std::endl;
	std::cout << *(::find(ilist.begin(), ilist.end(), 8)) << std::endl;
	int a[] = { 1,4,5656,23112,65546 };
	print(a);
	std::cout << std::endl;

	auto beg = ::begin(a);
	auto end_ = ::end(a);
	while (beg != end_) {
		std::cout << *beg << " ";
		beg++;
	}
	std::cout << std::endl;
	std::cout << len(a) << std::endl;

	Blob<string> b = { "yu","feiran","1999","@","gmail",".com" };
	Blob<int> bb = { 1,2,3,4 };
	cout << "bb size:" << bb.size() << endl;
	//b.show();
	//bb.show();
	//BlobPtr<string> bp(b, 1);
	//cout << endl;
	//cout << bp.deref() << endl;
	//bp.incr();
	//cout << bp.deref() << endl;

	//Screen<double> s1;
	//cin >> s1;
	//cout << s1 << endl;

	Vec<string> v1= { "yu","feiran","1999","@","gmail",".com" };

	cout << "v1 size:" << v1.size() << endl;
	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}

	vector<string>v2 = { "aaaaaaaayu","feiran","1999","@","gmail",".com" };
	print(v2);
	cout << endl;
	print1(v2);
	cout << endl;

	int* p = new int;
	*p = 233;
	DebugDelete d;
	d(p);
	std::shared_ptr<int>aaaa(new int(333), DebugDelete());

	Blob<string> bs(v2.begin(), v2.end());
	bs.show();
	::shared_ptr<int> AA(new int(535));
	for (int i = 0; i < 3; i++) {

		cout << *AA << endl;

		::shared_ptr<int> BB = AA;
		::shared_ptr<int> CC = AA;
		*BB = i;
	}
	::shared_ptr<string>spS(new string("yu"),Debug1Delete);
	cout << *spS << endl;
	cout << spS->size() << endl;
	DebugDelete DD1;
	::unique_ptr<string, DebugDelete>upd(new string("yufeiran"), DD1);
	cout << *upd << endl;

	return 0;
}