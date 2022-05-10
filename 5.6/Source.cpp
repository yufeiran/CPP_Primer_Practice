#include<iostream>
#include<exception>
#include<stdexcept>
#include<string>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		try {

			if (b == 0) {
				throw runtime_error("div by 0");
			}
			cout << a / b << endl;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
			cout << "whether enter new num?[y/n]";
			char ans;
			cin >> ans;
			if (ans == 'n')break;
		}
	}
	


	return 0;
}