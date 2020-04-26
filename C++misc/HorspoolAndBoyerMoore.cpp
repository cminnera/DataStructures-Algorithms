#include <iostream>
#include <string>
#include <vector>    // used in Boyer Moore
#include <algorithm> // for max() function
using namespace std;

string Sonnet15 =
"  When I consider every thing that grows\n"
"Holds in perfection but a little moment.\n"
"That this huge stage presenteth nought but shows\n"
"Whereon the stars in secret influence comment.\n"
"When I perceive that men as plants increase,\n"
"Cheered and checked even by the self - same sky :\n"
"Vaunt in their youthful sap, at height decrease,\n"
"And wear their brave state out of memory.\n"
"Then the conceit of this inconstant stay,\n"
"Sets you most rich in youth before my sight,\n"
"Where wasteful time debateth with decay\n"
"To change your day of youth to sullied night,\n"
"And all in war with Time for love of you,\n"
"As he takes from you, I engraft you new.";
string Sonnet18 =  // Poetry Foundation 
"Shall I compare thee to a summer's day?\n"
"Thou art more lovely and more temperate :\n"
"Rough winds do shake the darling buds of May,\n"
"And summer's lease hath all too short a date;\n"
"Sometime too hot the eye of heaven shines,\n"
"And often is his gold complexion dimm'd;\n"
"And every fair from fair sometime declines,\n"
"By chance or nature's changing course untrimm'd;\n"
"But thy eternal summer shall not fade,\n"
"Nor lose possession of that fair thou ow'st;\n"
"Nor shall death brag thou wander'st in his shade,\n"
"When in eternal lines to time thou grow'st :\n"
"So long as men can breathe or eyes can see,\n"
"So long lives this, and this gives life to thee.";

const int NC = 256;
class Horspool{	
private:
	int table[NC];
	string pattern;
	int m;  // pattern length
	void initTable(){
		int i, index, shftAmt;
		for (i = 0; i < NC; i++)
			table[i] = m;
		for (i = 0; i <= m - 2; i++){
			index = int(pattern[i]);
			shftAmt = m - 1 - i;
			table[index] = shftAmt;
		}
	}
	int ccount;
public:
	Horspool(string pat) : pattern(pat){
		m = pat.size();
		initTable();
	}
	// Horspools Matching algorithm - tries to find one match
	// Return the index of the left end of the first matching substring
	// starting at position pos, or -1 if there are no matches
	int match(const string& text, int textlength, int pos){
		
		int i, k, n = textlength;
		i = pos + m - 1; // position of pattern's right end;
		while (i <= n-1){
			//cout << "i = " << i << endl;
			k = 0;
			while ((k <= m-1) && (++ccount) && (pattern[m - 1 - k] == text[i - k])) k++;
			if (k == m)
				return i - m + 1;
			else{
				int increment = table[int(text[i])];
				i += increment;
			}
		}
		return -1;
	}
	// Use the Horspool algorithm to find all matches
	vector<int> SearchString(const string& text){
		vector<int> result;
		ccount = 0;
		int i, k, n = text.length();
		i = m - 1; // position of pattern's right end;
		while (i <= n - 1){
			//cout << "i = " << i << endl;
			k = 0;
			while ((k <= m - 1) && (++ccount) && (pattern[m - 1 - k] == text[i - k])) k++;
			if (k == m){
				result.push_back(i - m + 1);
				i += m;
			}
			else{
				int increment = table[int(text[i])];
				i += increment;
			}
		}
		return result;
	}
	int count(){ return ccount; }
};

class BoyerMoore{
	int table[NC];
	string pattern;
	int m;  // pattern length
	int ccount; // count comparisons
	void initTable( ) {
		int i;
		for (i = 0; i < 256; i++)
			table[i] = -1;
		for (i = 0; i < m; i++)
			table[(int)pattern[i]] = i;
	}
public:
	BoyerMoore(string pat) : pattern(pat){
		m = pat.size();
		initTable();
	}
	vector<int> SearchString(const string & str) {
		ccount = 0;
		vector<int> retVal;
		int n = str.length(), s = 0, j;
		while (s <= (n - m)){
			j = m - 1;
			while ((j >= 0) && (++ccount) && (pattern[j] == str[s + j]))
				--j;
			if (j < 0){
				retVal.push_back(s);
				s += (s + m < n) ? m - table[str[s + m]] : 1;
			}
			else
			{
				s += max(1, j - table[str[s + j]]);
			}
		}
		return retVal;
	}
	int count(){ return ccount; }
};

int main(void){
	//string thePattern = "you"; // Horspool and BoyerMoore ~ the same
	string thePattern = "and";  // Horspool is a wee bit better
	Horspool matcher1(thePattern);
	BoyerMoore matcher2(thePattern);
	vector<int> matchPositions;
	int nmatches;
	// Use Horspool 
	matchPositions = matcher1.SearchString(Sonnet18);
	nmatches = matchPositions.size();
	if (nmatches == 0)
		cout << "Horspool found no matches\n";
	else {
		cout << "Horspool found \"" << thePattern << "\" at positions ";
		for (auto p : matchPositions)
			cout << p << " ";
		cout << endl;
	}
	cout << "Count of character comparisons = " << matcher1.count() << "\n\n";
	
	// Use BoyerMoore
	matchPositions = matcher2.SearchString(Sonnet15);
	nmatches = matchPositions.size();
	if (nmatches == 0)
		cout << "BoyerMoore found no matches\n";
	else {
		cout << "BoyerMoore found \"" << thePattern << "\" at positions ";
		for (auto p : matchPositions)
			cout << p << " ";
		cout << endl;
	}
	cout << "Count of character comparisons = " << matcher2.count() << "\n\n";
	return 0;
}