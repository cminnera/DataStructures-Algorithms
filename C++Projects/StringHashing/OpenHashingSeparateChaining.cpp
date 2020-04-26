// File OpenHashingSeparateChaining.cpp
// CSC 225
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int h(string s,int m);
bool insert(vector<list<string>> &table, string);
void print(const vector<list<string>> table);
int main(void){
	const int HTSIZE = 13;
	vector<list<string>> HT(HTSIZE);
	string words[] = {"A", "FOOL", "AND", "HIS", "MONEY","ARE", "SOON", "PARTED"};
	int i,nwords = sizeof(words)/sizeof(string);
	cout << "The number of words is " << nwords << endl;
	for (i = 0; i < nwords; i++){
		if (!insert(HT,words[i]))
			cout << "Could not insert " << words[i] << endl;
	}
	cout << "An Open Hashing (Separate Chaining) Hash Table:\n";
	print(HT);

	string word;
	do
	{
		cout << "Enter next word to insert: ";
		cin >> word;
		for (i = 0; i < word.length(); i++)
			word[i] == toupper(word[i]);
		if (word != "END")
		{
			if (!insert(HT, word))
				cout << "Could not insert " << word << endl;
		}
	} while (word != "END");
	print(HT);

	return 0;
}

// a simple hash function for strings, in which you add the
// position of a word's letters in the alphabet, and compute the sum
// mod m, where m is the number of entries in the table.
int h(string s,int m){
	int offset = int('A')-1;
	int i,sum = 0,n = s.length();
	for (i = 0; i < n; i++)
		sum += int(s[i] - offset);
	return sum%m;
}
bool insert(vector<list<string>> &table, string word){
	int index,n = table.size();
	bool found = false;
	list<string>::iterator listit;

	index = h(word,n);
	for (list<string>::iterator listit = table[index].begin();
							    listit != table[index].end(); listit++)
		if (*listit == word)
			return false;
	table[index].push_back(word);
	return true;
}

void print(const vector<list<string>> table){
	int i,n = table.size();
	for (i = 0; i < n; i++){
		cout << setw(5) << i << " -> ";
		for (list<string>::const_iterator lit = table[i].begin(); lit != table[i].end(); lit++)
			cout << *lit << " -> ";
		cout << endl;
	}
}
