#include"TextQuery.h"

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);


	do {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	} while (true);

}

int main()
{
	ifstream infile("GONE WITH THE WIND.txt");
	runQueries(infile);

	return 0;
}