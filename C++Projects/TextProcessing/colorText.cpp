// File colorText.cpp
#include<iostream>
#include <string>
using namespace std;

string colorstr[] = {
	"0 = Black       8 = Gray\n",
	"1 = Blue        9 = Light Blue\n",
	"2 = Green       A = Light Green\n",
	"3 = Aqua        B = Light Aqua\n",
	"4 = Red         C = Light Red\n",
	"5 = Purple      D = Light Purple\n",
	"6 = Yellow      E = Light Yellow\n",
	"7 = White       F = Bright White\n" };

int main(void){
	string hexcolors = "0123456789ABCDEF";
	char sbuff[32];
	char tcolor, bcolor;
	cout << "Colors:\n";
	for (int i = 0; i < 8; i++)
		cout << colorstr[i];
	cout << endl;
	do {
		cout << "Enter a character {0,1,2,.., 9,A,B,C,D,E,F} for the background: ";
		cin >> bcolor;
	} while (hexcolors.find(bcolor) == -1);
	do {
		cout << "Enter a character {0,1,2,.., 9,A,B,C,D,E,F} for the text color: ";
		cin >> tcolor;
	} while (hexcolors.find(tcolor) == -1);
	sprintf_s<32>(sbuff,"\"COLOR %c%c\"", bcolor, tcolor);
	cout << "sbuff = " << sbuff << endl;
	system(sbuff);
	cout << "December 7, 1941 - a date which will live in infamy " << endl;
	return 0;
}