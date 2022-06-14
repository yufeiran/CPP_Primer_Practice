#include"HasPtr.h"
#include"Foo.h"
int main()
{
	HasPtr hp("yufeiran");
	HasPtr hp1;
	int count = 100000000;
	//for (int i = 0; i < count; i++)
	//{
	//	hp1 = hp;
	//	hp = hp1;
	//}
	//cout << "copy ok!"<<endl;

	//for (int i = 0; i < count; i++)
	//{
	//	hp1 =std::move(hp);
	//	hp = std::move(hp1);
	//}
	//cout << "move ok!" << endl;

	Foo f1;
	f1.push_back(1);
	f1.push_back(30);
	f1.push_back(199);
	f1.push_back(9);
	f1.push_back(2);
	f1.push_back(3);
	f1.push_back(2);
	f1.push_back(1);
	Foo f= f1.sorted();

	for (int i = 0; i < f.size(); i++) {
		cout << f.at(i) << endl;
	}
	return 0;
}