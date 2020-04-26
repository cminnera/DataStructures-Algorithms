//Clare Minnerath

// Passing functions example
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename Func>

vector<string> find_if(vector<string> words, Func func){
	vector<string> results;
	for (auto w : words){
		if (func(w))
			results.push_back(w);
	}
	return results;
}

//Example 1

int example1(vector<string> wds)
{
	vector<string> shortWords = find_if(wds, [](string s)->bool{return (s.length() <= 3); });
	cout << "Example 1: short words: \n";
	for (auto s : shortWords)
		cout << s << " ";
	cout << endl;
	return 0;
}

//Example 2
struct shortWord
{
	bool operator()(string s)
	{
		return(s.length() <= 3);
	}
};

int example2(vector<string> wds)
{
	vector<string> shortWords = find_if(wds, shortWord());
	cout << "Example 2: short words: \n";
	for (auto s : shortWords)
		cout << s << " ";
	cout << endl;
	return 0;
}

//Example 3
bool wordIsShort(string s)
{
	return(s.length() <= 3);
}

int example3(vector<string> wds)
{
	vector<string> shortWords = find_if(wds, wordIsShort);	//words because our find_if is templetized
	cout << "Example 2: short words: \n";
	for (auto s : shortWords)
		cout << s << " ";
	cout << endl;
	return 0;
}

string nurseryRhyme =
"Mary Mary quite contrary How does your garden grow "
"With silver bells and cockleshells And pretty maids all in a row ";
vector<string> nurseryWords;

int main(void){
	int pos1 = 0, pos2;
	while ((pos2 = nurseryRhyme.find_first_of(" \t\n", pos1)) != -1){
		nurseryWords.push_back(nurseryRhyme.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
	}
	cout << "All words:\n";
	for (auto s : nurseryWords)
		cout << s << endl;
	// Choose either example1, 2, or 3
	example3(nurseryWords);
	return 0;
}