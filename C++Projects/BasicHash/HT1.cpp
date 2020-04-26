//Clare Minnerath
//Hashing example

#include <iostream>
#include <iomanip>
#include <vector>
#include "HT1.h"
using namespace std;

int main(void)
{
	HashMap table;
	int keys[] = { 789564, 34623, 564354, 34765, 76567, 1432, 5643, 99999 };
	vector<int> vals;
	int val, temp;
	table.countProbes = 0;	//countProbes is public

	for (auto key : keys)
	{
		temp = key;
		val = 0;
		while (temp > 0)
		{
			val += temp % 10;
			temp /= 10;
		}
		table.put(key, val);
	}

	for (int i = 0; i < 50; i++)
	{
		int key = rand();	//get random key
		temp = key;
		val = 0;
		while (temp > 0)
		{
			val += temp % 10;
			temp /= 10;
		}
		table.put(key, val);
	}

	cout << "Table has been constructed\n";
	cout << "Table construction took " << table.countProbes << " probes\n";

	//TODO: try to evaluate preformance in a sequence of random gets()

	HashEntry *tentry;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		tentry = table[i];
		if (tentry != nullptr)
		{
			cout << setw(6) << i << setw(10) << right << tentry->getKey() << setw(8) << right << tentry->getValue() << endl;
		}
	}
}


