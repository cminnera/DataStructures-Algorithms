//Clare Minnerath
//Exam p5

#include <iostream>
#include <vector>
#include "genSLListMODIFIED.h"

using namespace std;

int main(void)
{
	vector<int> one = { 3, 5, 6, 1 };
	vector<int> two = { 3, 2 };
	vector <int> three = { 3, 5, 6, 1 };
	vector <int> four = { 8, 5, 2, 0 };

	SLList<int> singleOne;
	SLList<int> singleTwo;
	SLList<int> singleThree;
	SLList<int> singleFour;

	for (auto num : one)
	{
		singleOne.addToHead(num);
	}

	for (auto num : two)
	{
		singleTwo.addToHead(num);
	}

	for (auto num : three)
	{
		singleThree.addToHead(num);
	}

	for (auto num : four)
	{
		singleFour.addToHead(num);
	}

	if (singleOne == singleTwo)
		cout << "One and Two are the same.\n";
	else
		cout << "One and Two are not equal.\n";
	if (singleOne == singleThree)
		cout << "One and Three are the same.\n";
	else
		cout << "One and Three are not equal.\n";
	if (singleOne == singleFour)
		cout << "One and Four are the same.\n";
	else
		cout << "One and Four are not equal.\n";


	return 0;
}