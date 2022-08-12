#include<iostream>
#include<typeinfo>
using namespace std;

class A {};
class B :public A {};
class C :public B {};

int main()
{
	int arr[10];
	cout << typeid(arr).name() << endl
		<< typeid(123).name() << endl
		<< typeid(1.2).name() << endl
		<< typeid("yu").name() << endl;
	A* pa = new C;
	cout << typeid(pa).name() << endl;

	C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;

	B* px = new B;
	A& ra1 = *px;
	cout << typeid(ra1).name() << endl;
	return 0;
}