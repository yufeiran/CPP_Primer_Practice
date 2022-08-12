#include"Query.h"
#include<fstream>
#include<iostream>
#include<typeinfo>
using namespace std;
using namespace chapter15;
int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q.rep() << endl;
	ifstream in("story.txt");
	TextQuery text(in);
	print(cout, q.eval(text));

	Query* Q1 = new Query("wind");
	
	if (typeid(Q1) == typeid(Query*)) {
		cout << "equal" << endl;
	}


	print(cout, Query("Daddy").eval(text));
	Query q1 = ~Query("Alice");
	print(cout, q1.eval(text));
	Query q2 = Query("Alice")|Query("hair");
	print(cout, q2.eval(text));
	Query q3 = Query("Alice") & Query("hair");
	print(cout, q3.eval(text));
	//BinaryQuery a = Query("fiery") & Query("bird");
	//AndQuery b = Query("fiery") & Query("bird");
	//OrQuery c = Query("fiery") & Query("bird");
	Query q4("_"), q5("+++");
	print(cout, (q1 | q4).eval(text),{5,20});
	//print(cout, (q4 | q1).eval(text));
	Query q6 = q4 | q5;
	//print(cout, q6.eval(text));

	return 0;
}