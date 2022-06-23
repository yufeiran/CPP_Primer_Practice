#pragma once
#include<memory>
#include<string>
#include<iostream>
#include<algorithm>
#include"TextQuery.h"
class Query;
class Query_base
{
	friend Query;
public:
	using line_no = TextQuery::line_no;
protected:
	virtual ~Query_base() = default;
private:


	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual  std::string rep() const = 0;

};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:

	Query(const std::string&);
	QueryResult eval(const TextQuery& t)const {

		return q->eval(t); 
	}
	
	std::string rep() const { 
		//std::cout << "std::string Query::rep() call" << std::endl;
		return q->rep();
	}
private:
	Query(Query_base*query) :q(query) {
		//std::cout << "Query(std::shared_ptr<Query_base>query) call" << std::endl; 
	}
	Query_base *q;
};

class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const std::string& s) :query_word(s) {
		//std::cout << "WordQuery(const std::string& s) call" << std::endl;  
	};
	QueryResult eval(const TextQuery&t)const
	{
		return t.query(query_word);
	}
	std::string rep() const{ 
		//std::cout << "WordQuery::rep() call" << std::endl;
		return query_word; 
	}

	std::string query_word;
};

inline Query::Query(const std::string& s) :q(new WordQuery(s)) {};

class NotQuery :public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) {
		//std::cout << "NotQuery(const Query& q) call" << std::endl;
	};

	std::string rep()const { 
		//std::cout << "NotQuery::rep() call" << std::endl;
		return "~(" + query.rep() + ")"; 
	}
	QueryResult eval(const TextQuery& t)const;
	Query query;
};

QueryResult
NotQuery::eval(const TextQuery& text)const
{
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();

	auto  beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; n++) {
		if (beg == end || *beg != n) {
			ret_lines->insert(n);
		}
		else if (beg != end) {
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query&operand)
{
	return (Query_base*)(new NotQuery(operand));
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) :
		lhs(l), rhs(r), opSym(s) {
		//std::cout << "BinaryQuery(const Query& l, const Query& r, std::string s) call" << std::endl;
	};
	std::string rep()const { 
		//std::cout << "BinaryQuery::rep() call" << std::endl; 
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "&") {
		//std::cout << "AndQuery(const Query& left, const Query& right) call" << std::endl;
	};
	QueryResult eval(const TextQuery&)const;
};

QueryResult AndQuery::eval(const TextQuery& Text)const {
	auto right = rhs.eval(Text), left = lhs.eval(Text);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
	
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	return (Query_base*)(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "|") {
		//std::cout << "OrQuery(const Query& left, const Query& right) call" << std::endl;
	};
	QueryResult eval(const TextQuery&)const;
};

QueryResult OrQuery::eval(const TextQuery& Text)const {
	auto right = rhs.eval(Text), left = lhs.eval(Text);
	auto ret_lines =
		make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
	return (Query_base*)(new OrQuery(lhs, rhs));
}