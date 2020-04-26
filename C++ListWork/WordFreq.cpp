//Clare Minnerath

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include <iomanip>
#include "genSkipLMODIFIED.h"
#include "genSLListMODIFIED.h"
#include "timer.h"

using namespace std;

class cword
{
public:
	string word;
	int frequency;
	cword();
	cword(string w1);
	void incFreq();
	friend ostream& operator<<(ostream & o, const cword & aWord)
	{
		o << aWord.word << "," << aWord.frequency << endl;
		return o;
	}
	friend bool operator<(const cword& w1, const cword& w2)
	{
		return w1.word < w2.word;
	}
	friend bool operator==(const cword& w1, const cword& w2)
	{
		return w1.word == w2.word;
	}
};

cword::cword()
{
	word = "";
	frequency = 0;
}

cword::cword(string w1)
{
	word = w1;
	frequency = 1;
}

void cword::incFreq()
{
	frequency++;
}

	void readPoem(string filename, vector<string>& fileWords);
	int vectorToSkipList(vector<string>& fileWords, SkipList<cword>& skip);
	int vectorToSLList(vector<string>& fileWords, SLList<cword>& single);
	int vectorToSTList(vector<string>& fileWords, list<cword>& wlist);







void readPoem(string filename, vector<string>& fileWords)
{
	ifstream input;
	string theWord;

	if (filename.find(".txt") == -1)
	{
		filename += string(".txt");
	}

	input.open(filename);

	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}

	while (getline(input, theWord))
	{
		fileWords.push_back(theWord);
	}
}

int vectorToSkipList(vector<string>& fileWords, SkipList<cword>& skip)
{

	stopWatch sw;
	stopWatch *p = &sw;

	startTimer(p);
	for (auto w : fileWords)
	{
		cword nextWord(w);
		if (skip.skipListSearch(nextWord) != NULL)
		{
			skip.skipListSearch(nextWord)->frequency++;
		}
		else skip.skipListInsert(nextWord);
	}
	stopTimer(p);
	cout << "Building the Skip list took " << fixed << setprecision(2) << getElapsedTime(p) << " seconds\n";
	return skip.skipListSize();

}

int vectorToSLList(vector<string>& fileWords, SLList<cword>& single)
{
	stopWatch sw;
	stopWatch *p = &sw;

	startTimer(p);
	for (auto w : fileWords)
	{
		cword nextWord(w);
		if (single.isInList(nextWord) != NULL)
		{
			single.isInList(nextWord)->frequency++;
		}
		else single.addToHead(nextWord);
	}
	stopTimer(p);
	cout << "Building the SLL list took " << fixed << setprecision(2) << getElapsedTime(p) << " seconds\n";
	return single.size();
}




int vectorToSTList(vector<string>& fileWords, list<cword>& wlist)
{
	stopWatch sw;
	stopWatch *p = &sw;
	list <cword> :: iterator wit;
	wlist.clear();
	startTimer(p);
	for (auto w : fileWords)
	{
		cword nextWord(w);
		if ((wit = find(wlist.begin(), wlist.end(), nextWord)) != wlist.end())
		{
			wit->incFreq();
		}
		else wlist.push_back(nextWord);
	}
	stopTimer(p);
	cout << "Building the STL list took " << fixed << setprecision(2) << getElapsedTime(p) << " seconds\n";
	return wlist.size();
}

int main(void)
{
	int v = 1;
	vector <string> fileWords;
	SkipList<cword> Skip1;
	SLList<cword> single1;
	list<cword> list1;


	readPoem("TomSawyerAllWordsA.txt",fileWords);

	while (v != 0)
	{
	cout << "Enter 1 for singly linked list varient, 2 for skip list varient, 3 for STL list varient, and 0 to exit: \n";
	cin >> v;
	if (v == 1)
		cout << "Number of Unique Words: " << vectorToSLList(fileWords, single1) << endl;
	else if (v == 2)
		cout << "Number of Unique Words: " << vectorToSkipList(fileWords, Skip1) << endl;
	else if (v == 3)
		cout << "Number of Unique Words: " << vectorToSTList(fileWords, list1) << endl;
	else if (v == 0)
		exit(1);
	else
		cout << "Try again\n";
	cout << endl;
	}

	return 0;
}