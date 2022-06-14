#include"Message.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
	Folder f1("work"), f2("pic"), f3("doc");
	Message m1("c++"), m2("happy new year!"),m3("Nothing Is Gonna Stop Us");

	m1.addFolder(f1);
	m1.addFolder(f3);

	m2.addFolder(f2);

	m3.addFolder(f1);
	m3.addFolder(f2);
	m3.addFolder(f3);

	f1.show();
	f2.show();
	f3.show();

	swap(m1, m2);
	f1.show();
	f2.show();
	f3.show();

	return 0;
}