// Lab10P0RegularExpressionTester.cpp
// CSC 225
// Clare
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;



//William Shakespeare Sonnet 10
string sonnet[] = {
	"For shame deny that thou bear'st love to any,",
	"Who for thyself art so unprovident.",
	"Grant, if thou wilt, thou art beloved of many,",
	"But that thou none lovest is most evident;",
	"For thou art so possess'd with murderous hate",
	"That 'gainst thyself thou stick'st not to conspire.",
	"Seeking that beauteous roof to ruinate",
	"Which to repair should be thy chief desire.",
	"O, change thy thought, that I may change my mind!",
	"Shall hate be fairer lodged than gentle love?",
	"Be, as thy presence is, gracious and kind,",
	"Or to thyself at least kind-hearted prove:",
	"Make thee another self, for love of me,",
	"That beauty still may live in thine or thee." };

int parseLine(string & line, vector<string>& words);


int main(void)
{
	vector<string> wordsOnALine;
	int i, nwords, nlines = sizeof(sonnet) / sizeof(string);

	for (i = 0; i < nlines; i++)
	{
		nwords = parseLine(sonnet[i], wordsOnALine);
		cout << nwords << '\t';
		for (auto w : wordsOnALine)
			cout << w << " ";
		cout << endl;
	}
	return 0;
}

//http://stackoverflow.com/questions/2159026/regex-how-to-get-words-from-a-string-c
// Note: modified by adding the ' after \\d and changing {1,2} to {1} LMW
static char *pattern = "[^\\W\\d'](\\w|[-']{1}(?=\\w))*";
regex word_regex(pattern);
int parseLine(string &line, vector<string> & words){
	words.clear();
	sregex_iterator words_begin =
		sregex_iterator(line.begin(), line.end(), word_regex);
	sregex_iterator words_end = sregex_iterator();

	int nwords = distance(words_begin, words_end);

	for (sregex_iterator i = words_begin; i != words_end; ++i) {
		smatch match = *i;
		words.push_back(match.str());
	}
	return nwords;
}
