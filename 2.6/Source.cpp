#include<iostream>
#include<string>
#include"Header.h"

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

int main()
{
	Sales_data data1, data2;
	double price = 0;
	//in data1
	cin >> data1.ISBN >> data1.sum >> price;
	data1.totalPrice += data1.sum * price;
	//in data2
	cin >> data2.ISBN >> data2.sum >> price;
	data2.totalPrice += data2.sum * price;

	if (data1.ISBN == data2.ISBN) {
		int totalSum = data1.sum + data2.sum;
		double totalPrice = data1.totalPrice + data2.totalPrice;
		cout << data1.ISBN << " " << totalSum
			<< " " << totalPrice<<" ";
		if (totalSum != 0)
			cout << totalPrice / totalSum << endl;
		return 0;
	}
	else {
		cerr << "Data must refer to the same ISBN"
			<< endl;
		return -1;
	}


}