#pragma once
#include<string>
#include<iostream>
#include<set>
#include<memory>
class Quote
{
public:
	Quote() = default;
	Quote(const std::string& s, double p) :bookNo(s), price(p) {};
	std::string getIsbn() const{ return bookNo; }
	Quote(const Quote& q) :price(q.price), bookNo(q.bookNo) {
		std::cout << "Quote(const Quote& q) call!" << std::endl;
	}
	Quote(const Quote* q) :price(q->price), bookNo(q->bookNo) {
		std::cout << "Quote(const Quote* q) call!" << std::endl;
	}


	virtual Quote* clone() const &
	{
		return new Quote(*this);

	}
	virtual Quote* clone()&&
	{
		return new Quote(std::move(*this));

	}

	virtual double net_price(int n)const {
		return n * price;
	}
	virtual void debug(std::ostream& os)const {
		os << "bookNo: " << bookNo << " price: " << price;
	}
	virtual ~Quote() = default;
protected:
	double price;
private:
	std::string bookNo;
};

class Dis_quote :public Quote
{
public:
	Dis_quote() = default;
	Dis_quote(const std::string s, double p, int dsc, double des) :Quote(s, p), descount_start_count(dsc), descount(des) {};
	Dis_quote(const Dis_quote& dq) :Quote(dq), descount(dq.descount), descount_start_count(dq.descount_start_count) {
		std::cout << "Dis_quote(const Dis_quote& dq) call!" << std::endl;
	};
	virtual double net_price(int n)const = 0;
	virtual void debug(std::ostream& os)const override {
		Quote::debug(os);
		os << " descount_start_count: " << descount_start_count << " descount: " << descount;
	}
protected:
	int descount_start_count;
	double descount;
private:

};

class Bulk_quote:public Dis_quote
{
public:
	Bulk_quote() = default;
	//Bulk_quote(const std::string s, double p, int dsc, double des) :Dis_quote(s, p, dsc, des) {};
	using Dis_quote::Dis_quote;
	Bulk_quote(const Bulk_quote& bq) :Dis_quote(bq) {
		std::cout << "Bulk_quote(const Bulk_quote& bq) call!" << std::endl;
	}
	double net_price(int n)const override {
		if (n >= descount_start_count) {
			return n * (1 - descount) * price;
		}
		return n * price;
	}
	virtual void debug(std::ostream& os)const override {
		Quote::debug(os);
		os << " descount_start_count: " << descount_start_count << " descount: " << descount;
	}
	Bulk_quote* clone() const& {
		return new Bulk_quote(*this);

	}
	Bulk_quote* clone()&& {
		return new Bulk_quote(std::move(*this));
	}
protected:

private:

};

class Bulk_quote1 :public Dis_quote
{
public:
	Bulk_quote1() = default;
	Bulk_quote1(const std::string s, double p, int dec, double des) :Dis_quote(s, p, dec, des) {};
	double net_price(int n)const override {
		if (n < descount_start_count) {
			return n * (1 - descount) * price;
		}
		else {
			return (n- descount_start_count) * price+ descount_start_count *(1-descount)*price;
		}

	}
	virtual void debug(std::ostream& os)const override {
		Quote::debug(os);
		os << " descount_start_count: " << descount_start_count << " descount: " << descount;
	}
protected:

private:
};


double print_total(std::ostream& os, const Quote& q, int n)
{
	os << q.getIsbn() << " x " << n << " cost: " << q.net_price(n) << std::endl;
	return q.net_price(n);
}

class Basket
{
public:
	void add(std::shared_ptr<Quote>& q_ptr) {
		qset.insert(q_ptr);
	}
	void add(const Quote& q) {
		qset.insert(std::make_shared<Quote>(q.clone()));
	}
	void add(Quote&& q) {
		qset.insert(std::make_shared<Quote> (std::move(q).clone()));
	}
	double total_receipt(std::ostream& os)const {
		double total = 0;
		for (auto q = qset.begin(); q != qset.end(); q = qset.upper_bound(*q))
		{
			total += print_total(os, **q, qset.count(*q));
		}
		os << "Total receipt:" << total << std::endl;
		return total;
	}
private:
	static bool cmp(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
		return lhs->getIsbn() < rhs->getIsbn();
	}
	std::multiset<std::shared_ptr<Quote>,decltype(cmp)*>qset{cmp};
};

