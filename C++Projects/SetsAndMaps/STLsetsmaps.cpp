#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <string>
using namespace std;

int N;
string words[1000] = { "" };
bool readWords(void);
void testSet(void);
void testMultiSet(void);
void testMap(void);
void testMultiMap(void);

int main(void){
	if (readWords()){
		;
	}
	cout << endl;
	return 0;
}


void testSet(void){
	set<string> ts;
	cout << "\nAdd up to 100 words to a set: ";
	for (int i = 0; i < 100; i++){
		ts.insert(words[rand() % 50]);
	}
	cout << "The size of the set is " << ts.size() << endl;
	cout << "The elements of the set:\n";
	int slen = 0;
	for each(auto w in ts){
		cout << w << " "; slen += w.length() + 1;
		if (slen >= 65){ slen = 0; cout << endl; }
	}
	cout << endl;
}

void testMultiSet(void){
	multiset<string> tms;
	cout << "\nAdd 100 words to a multiset: ";
	for (int i = 0; i < 100; i++){
		tms.insert(words[rand() % 50]);
	}
	cout << "The size of the multiset is " << tms.size() << endl;
	cout << "The elements of the multiset:\n";
	int slen = 0;
	for each(auto w in tms){
		cout << w << " "; slen += w.length() + 1;
		if (slen >= 65){ slen = 0; cout << endl; }
	}
	cout << endl;
}

void testMap(void){
	map<char, int> tmap;
	for (char c = 'a'; c <= 'z'; c++){
		tmap[c] = 0;
	}
	for each (string s in words){
		if (s.length()>0)
			tmap[s[0]]++;
	}
	cout << "\nUse the map class:\n";
	cout << "\nFrequencies in the word list by first letter:\n";
	for each(auto pr in tmap)
		cout << pr.first << ":\t" << pr.second << endl;
}

void testMultiMap(void){
	multimap<char, string> tmmap;
	char firstletter;
	for each (string s in words){
		if (s.length() > 0){
			firstletter = s[0];
			tmmap.insert(pair<char, string>(firstletter, s));
		}
	}
	cout << "\nUse the multi-map class\n";
	pair<multimap<char, string>::iterator, multimap<char, string>::iterator> ii;
	multimap<char, string>::iterator it;	//Iterator to be used along with ii
	for (firstletter = 'a'; firstletter <= 'z'; firstletter++){
		ii = tmmap.equal_range(firstletter); //We get the first and up to last entry in ii;
		if (ii.first == ii.second)
			continue;
		int count = 0;
		cout << "'" << firstletter << "' words:\n";
		for (it = ii.first; it != ii.second; ++it){
			cout << setw(15) << it->second;
			if ((++count) % 5 == 0) cout << endl;
		}
		if (count % 5 != 0) cout << endl;
	}
}

bool readWords(void){
	string fname = "words.txt";
	try{
		ifstream fin(fname);
		int n = 0;
		while (n < 1000) {
			fin >> words[n];
			if (fin.good())
				n++;
			else
				break;
		}
		N = n;
		return true;
	}
	catch (...){
		cout << "Error reading from " << fname << endl;
		N = 0;
		return false;
	}
}