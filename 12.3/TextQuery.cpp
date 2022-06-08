#include"TextQuery.h"



void TextQuery::loadFile(ifstream& infile)
{
	nowfile = &infile;
	wordMap.clear();
	lineData = make_shared<StrBlob>();
	lineData->clear();
	string line;
	int lineCurr = 0;
	while (getline(infile, line)) {
		lineData->push_back(line);
		istringstream istr(line);
		string word;
		while (istr >> word) {
			if (wordMap.find(word) == wordMap.end()) {
				wordMap[word] =make_shared<set<int>>( set<int>{ lineCurr });
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
		result.resultSet = make_shared<set<int>>();
		return result;
	}
	result.count = wordCount.find(word)->second;
	result.resultSet = wordMap.find(word)->second;
	result.lineData = lineData;
	result.nowfile = nowfile;

	return result;
}



ostream& print(ostream& os, const QueryResult& q)
{
	os << q.word << " occurs " << q.count <<((q.count>1)? " times":" time" )<< endl;

	for (auto c : *(q.resultSet) ){
		os << "\t" << "(line " << c << " ) " <<(*q.lineData).getByPos(c) << endl;
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
