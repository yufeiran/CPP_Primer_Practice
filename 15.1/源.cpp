#include"Quote.h"
#include<vector>
using namespace std;
Basket basket;

int main()
{
	vector<shared_ptr<Quote>>qVec;
	vector<Quote>qqVec;
	qVec.push_back(make_shared<Bulk_quote>("ddd", 99.99, 20, 0.9));
	qVec.push_back(make_shared<Quote>("yufeiran", 99.99));
	print_total(cout, *(qVec.front()), 20);

	Quote q1("yufeiran", 99.99);
	Bulk_quote q2("ddd", 99.99, 20, 0.9);

	Bulk_quote1 q3("yu", 99.99, 10, 0.9);
	qVec.push_back(make_shared<Bulk_quote1>(q3));
	qqVec.push_back(q1);
	qqVec.push_back(q2);
	qqVec.push_back(q3);
	double qVecNet = 0;
	double qqVecNet = 0;
	int n = 30;
	for (auto& q : qVec) {
		qVecNet += q->net_price(n);
	}
	for (auto& q : qqVec) {
		qqVecNet += q.net_price(n);
	}
	cout << "qNet:" << qVecNet << " qqNet:" << qqVecNet << endl;

	//Dis_quote dq;
	print_total(cout, q1, 20);
	print_total(cout, q2, 20);
	print_total(cout, q3, 20);
	q1.debug(cout);
	cout << endl;
	q2.debug(cout);
	cout << endl;
	q3.debug(cout);
	cout << endl;
	Bulk_quote q21 = q2;
	basket.add(q1);
	basket.add(q2);
	basket.add(q3);
	basket.total_receipt(cout);
	return 0;
}