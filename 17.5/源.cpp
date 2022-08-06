#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	cout << boolalpha << true << " " << noboolalpha << true <<
		showbase << 123 << " " << noshowbase << 123 << endl <<
		showpoint << 1.23 << " " << noshowpoint << 1.23 << endl <<
		showpos << 123 << " " << noshowpos << 123 << endl <<
		uppercase << 0x123 << " " << nouppercase << 0x123 << endl <<
		dec << 123 << " " << hex << 123 << " " << oct << 123 << " " << dec << endl <<
		left << setw(12) << 123 << endl << right << setw(12) << 123 << endl << internal << setw(12) << endl
		<< right << fixed << 1.2344 << " " << scientific << 1.2345 << " " << hexfloat << 1.2345 << " " << defaultfloat << 1.2345 << endl <<
		unitbuf << 12234.3 << " " << nounitbuf << 1.2345 << endl;
	cin >> skipws;
	//char c;
	//cin >> noskipws;
	//while (cin >> c) {
	//	cout << c;
	//}
	cout << flush;
	cout << 122 << ends << 14512 << endl;

	cout << setfill('D');
	cout << setprecision(10);
	cout << setw(12) << setbase(12) << 11221313 << " " << setw(12) << 1.23124 << endl;
	
	cout << uppercase << hexfloat << sqrt(2.0)<<" "<<1.2313<<" "<<3.1415926 << endl;


	ifstream is("test.txt");

	char* c = new char[100];


	while (is)
	{
		is.getline(c, 100);
		cout << c << endl;
	}

	fstream inOut("copyout.txt", fstream::ate | fstream::in | fstream::out);
	if (!inOut) {
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}
	auto end_mark = inOut.tellg();
	inOut.seekg(0, fstream::beg);
	size_t cnt = 0;
	string line;
	while (inOut && inOut.tellg() != end_mark
		&& std::getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0, fstream::end);
		inOut << cnt;
		if (mark != end_mark) {
			inOut << " ";
		}
		inOut.seekg(mark);
	}
	inOut.seekp(0, fstream::end);


	return 0;
}