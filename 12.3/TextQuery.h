#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<memory>
#include<fstream>
#include<sstream>
#include<tuple>
#include"StrBlob.h" 
#include"StrVec.h"
#include"DebugDelete.h"
using namespace std;


class TextQuery
{


public:
	class QueryResult;
	friend QueryResult;

	TextQuery():nowfile(nullptr) {};
	TextQuery(ifstream& infile) {  loadFile(infile); };
	void loadFile(ifstream& infile);
	QueryResult query(const string& word) const;
	tuple<string,int, shared_ptr<set<int>>, shared_ptr<StrVec>, ifstream*>query1(const string& word) const;
private:
	shared_ptr<StrVec>lineData;
	map<string, shared_ptr<set<int>>>wordMap;
	map<string, int>wordCount;
	ifstream* nowfile;
};

class TextQuery::QueryResult
{
public:
	string word;
	int count;
	shared_ptr<set<int>> resultSet;
	shared_ptr<StrVec> lineData;
	set<int>::iterator begin();
	set<int>::iterator end();
	ifstream* get_file();
	ifstream* nowfile;
};
ostream& print(ostream& os, const TextQuery::QueryResult& q);