#include<stack>
#include<iostream>
#include<string>
using namespace std;

stack<char>s;



int main()
{
	string str="(yu fei(ran))";
	//cin >> str;
	for (auto c : str) {
		if (c == ')') {
			while (s.top() != '(') {
				cout << s.top() << " ";
				s.pop();
			}
			s.pop();
		}
		else {
			s.push(c);
		}
	}
	cout << endl;





	return 0;
}