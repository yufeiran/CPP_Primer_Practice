#include"Sales_data.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>


using namespace std;

int main(int argc,char**argv)
{
	//ifstream in("hello.txt");
	//vector<string>raw;
	//string temp;
	//while (in>>temp)
	//{
	//	raw.push_back(temp);
	//}
	//for (auto s : raw)
	//{
	//	cout << s << endl;
	//}
	if (argc < 2)return 1;
	ifstream in(argv[1]);
	ofstream out(argv[2],ofstream::app);
	Sales_data total;


	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);

			}
			else {
				print(out, total);

				total = trans;
			}
		}
		print(out, total);
	}
	else {
		out << "No data?!" << endl;
		return -1;
	}

	return 0;
}