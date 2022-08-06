#include"TextQuery.h"



void TextQuery::loadFile(ifstream& infile)
{
	nowfile = &infile;
	wordMap.clear();
	shared_ptr<StrVec>temp(new StrVec, DebugDelete());
	lineData = temp;
	lineData->clear();
	string line;
	int lineCurr = 0;
	while (getline(infile, line)) {
		lineData->push_back(line);
		istringstream istr(line);
		string word;
		while (istr >> word) {
			if (wordMap.find(word) == wordMap.end()) {
				wordMap[word] = shared_ptr<set<int>>(new set<int>{ lineCurr }, DebugDelete());
				wordCount[word] = 1;
			}
			else {
				wordMap[word]->insert(lineCurr);
				wordCount[word]++;
			}
		}
		lineCurr++;
	}
	return;
}

QueryResult TextQuery::query(const string& word) const
{
	QueryResult result;
	result.word = word;

	if (wordMap.find(word) == wordMap.end()) {
		result.resultSet = shared_ptr<set<int>>(new set<int>, DebugDelete());
		return result;
	}
	result.count = wordCount.find(word)->second;
	result.resultSet = wordMap.find(word)->second;
	result.lineData = lineData;
	result.nowfile = nowfile;

	return result;
}

tuple<string, int, shared_ptr<set<int>>, shared_ptr<StrVec>, ifstream*> TextQuery::query1(const string& word) const
{

	QueryResult result;
	result.word = word;

	if (wordMap.find(word) == wordMap.end()) {
		result.resultSet = shared_ptr<set<int>>(new set<int>, DebugDelete());
		return tuple<string, int, shared_ptr<set<int>>, shared_ptr<StrVec>, ifstream*>(result.word, result.count, result.resultSet, result.lineData, result.nowfile);
	}
	result.count = wordCount.find(word)->second;
	result.resultSet = wordMap.find(word)->second;
	result.lineData = lineData;
	result.nowfile = nowfile;

	

	return tuple<string, int, shared_ptr<set<int>>, shared_ptr<StrVec>, ifstream*>(result.word, result.count, result.resultSet, result.lineData, result.nowfile);

}



ostream& print(ostream& os, const QueryResult& q)
{
	os << q.word << " occurs " << q.count <<((q.count>1)? " times":" time" )<< endl;

	for (auto c : *(q.resultSet) ){
		os << "\t" << "(line " << c << " ) " <<*(*q.lineData).at(c) << endl;
	}
	return os;
}

set<int>::iterator QueryResult::begin()
{
	return (*resultSet).begin();
}

set<int>::iterator QueryResult::end()
{
	return (*resultSet).end();
}

ifstream* QueryResult::get_file()
{
	return nowfile;
}
