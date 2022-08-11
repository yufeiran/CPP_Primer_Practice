#include"TextQuery.h"

namespace chapter10
{

	void TextQuery::loadFile(ifstream& infile)
	{
		nowfile = &infile;
		wordMap.clear();
		lineData = make_shared<StrVec>();
		lineData->clear();
		string line;
		QueryResult::line_no lineCurr = 0;
		while (getline(infile, line)) {
			lineData->push_back(line);
			istringstream istr(line);
			string word;
			while (istr >> word) {
				if (wordMap.find(word) == wordMap.end()) {
					wordMap[word] = make_shared<set<QueryResult::line_no>>(set<QueryResult::line_no>{ lineCurr });
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
			result.resultSet = make_shared<set<QueryResult::line_no>>();
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
		os << q.word << " occurs " << q.count << ((q.count > 1) ? " times" : " time") << endl;

		for (auto c : *(q.resultSet)) {
			os << "\t" << "(line " << c + 1 << " ) " << *(*q.lineData).at(c) << endl;
		}
		return os;
	}

	ostream& print(ostream& os, const QueryResult& q, pair<size_t, size_t>range)
	{
		os << q.word << " occurs " << q.count << ((q.count > 1) ? " times" : " time") << endl;
		os << "in range :line " << range.first << " to line " << range.second << endl;
		for (auto c : *(q.resultSet)) {
			if (c >= range.first - 1 && c < range.second - 1) {
				os << "\t" << "(line " << c + 1 << " ) " << *(*q.lineData).at(c) << endl;
			}
		}
		return os;
	}

	set<QueryResult::line_no>::iterator QueryResult::begin()
	{
		return (*resultSet).begin();
	}

	set<QueryResult::line_no>::iterator QueryResult::end()
	{
		return (*resultSet).end();
	}

	shared_ptr<StrVec> QueryResult::get_file()
	{
		return make_shared<StrVec>(*lineData);
	}

}
