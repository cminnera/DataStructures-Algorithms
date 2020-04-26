// StringMatchingQ2
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;


char *Sonnet15 =
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


const char* textColor(int color = 7, const char* Message = ""){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return Message;
}

void displayTextWithHighlights(vector<int> & positions, string pattern, string text, int normalcolor, int hilitecolor);

int main(void){	
	cout << Sonnet15 << endl;

	string pattern;
	string text(Sonnet15);
	vector<int> foundPositions;
	int pos = 0;
	int regularTextColor = 7, highlightingColor = 10;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), highlightingColor);
	cout << "\nEnter string to find: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), regularTextColor);
	getline(cin, pattern);
	
	// TODO:  Add the code here to find all occurrences of the pattern in the text
	while ((pos = text.find(pattern, pos)) != -1)
	{
		foundPositions.push_back(pos);
		pos += pattern.length();
	}
	
	int nfound = foundPositions.size();
	cout << textColor();
	if (!nfound)
		cout << "No instances of " << pattern << " were found\n";
	else {
		cout << "Found " << nfound << " instance of " << pattern << "\n\n";
		displayTextWithHighlights(foundPositions, pattern, text, regularTextColor, highlightingColor);
		cout << endl;
	}
	return 0;
}

void displayTextWithHighlights(vector<int> & positions, string pattern, string text, int normalcolor, int hilitecolor){
	int nfound = positions.size();
	if (nfound == 0)
		return;
	int pos1 = 0, plen = pattern.length(), tlen = text.length();
	string outpart, inpart;
	int part = 0;
	if (positions[0] != 0){
		outpart = text.substr(0, positions[0]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), normalcolor);
		cout << outpart;
	}
	for (; part < nfound; part++){
		pos1 = positions[part];
		inpart = text.substr(pos1, plen);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), hilitecolor);
		cout << inpart;
		pos1 += plen;
		if (pos1 < tlen){
			if (part < nfound - 1){
				outpart = text.substr(pos1, positions[part + 1] - positions[part] - plen);
			}
			else
				outpart = text.substr(pos1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), normalcolor);
			cout << outpart;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), normalcolor);
	cout << endl;
}



