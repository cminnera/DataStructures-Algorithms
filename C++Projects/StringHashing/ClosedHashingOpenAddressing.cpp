//File ClosedHashingOpenAddressing.cpp
//CSC 225
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
int h(string s,int m);
bool insert(vector<string> &table, string);
void print(const vector<string> table);

int main(void){
	const int HTSIZE = 13;
	vector<string> HT(HTSIZE,"");
	string words[] = {"A", "FOOL", "AND", "HIS", "MONEY","ARE", "SOON", "PARTED",};
	
	int i,nwords = sizeof(words)/sizeof(string);
	
	for (i = 0; i < nwords; i++){
		if (!insert(HT,words[i]))
			cout << "Could not insert " << words[i] << endl;
	}
	cout << "A Closed Hashing (Open Addressing) Hash Table:\n";
	print(HT);
	insert(HT, "TEST");
	insert(HT, "SITE");
	print(HT);
	return 0;
}

// A simple hash function for strings: add the
// position of a word's letters in the alphabet, and compute the sum
// mod m, where m is the number of entries in the table.
int h(string s,int m){
	int offset = int('A')-1;
	int i,sum = 0,n = s.length();
	for (i = 0; i < n; i++)
		sum += int(s[i] - offset);
	cout << sum%m << endl;
	return sum%m;
}

// Insert using linear probing
bool insert(vector<string> &table, string word){
	int i,count=0,n = table.size();
	i = h(word,n);
	do{
		if (table[i] == word)
		{
			
			cout << "U" << count << endl;
			return false;
		}
		else if (table[i] == ""){
			table[i] = word;
			cout << "S" << count << endl;
			return true;
		}
		if (++i == n)
			i = 0;
	}while (++count < n);
	cout << "ERROR in insert, the hash table is full\n";
	return true;
}
void print(const vector<string> table){
	int i,n = table.size();
	for (i = 0; i < n; i++){
		cout << setw(4) << i << "\t";
		if (table[i] != "")
			cout << table[i];
		cout << endl;
	}
}