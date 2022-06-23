#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<memory>
#include<fstream>
#include<sstream>
#include"StrBlob.h" 
#include"StrVec.h"

using namespace std;

class QueryResult;

class TextQuery
{
	friend QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery() :nowfile(nullptr) {};
	TextQuery(ifstream& infile) { loadFile(infile); };
	void loadFile(ifstream& infile);
	QueryResult query(const string& word) const;
private:
	shared_ptr<StrVec>lineData;
	map<string, shared_ptr<set<line_no>>>wordMap;
	map<string, int>wordCount;
	ifstream* nowfile;
};

class QueryResult
{
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult() = default;
	QueryResult(const string& w, const shared_ptr<set<line_no>>& s,const shared_ptr<StrVec>& ld) :word(w), resultSet(s), lineData(ld) {
		count = resultSet->size();
	};

	string word;
	int count;
	shared_ptr<set<line_no>> resultSet;
	shared_ptr<StrVec> lineData;
	set<line_no>::iterator begin();
	set<line_no>::iterator end();
	shared_ptr<StrVec> get_file();
	ifstream* nowfile;
};

ostream& print(ostream& os, const QueryResult& q);
ostream& print(ostream& os, const QueryResult& q, pair<size_t, size_t>range);