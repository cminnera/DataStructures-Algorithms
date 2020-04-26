//Clare Minnerath
//Lab 6 Part 0 Q1

#include "dateClass.h"

int main(void)
{
	cDate todaysDate;
	cout << "Today is " << todaysDate << endl;

	cDate newDate = todaysDate;

	for (int i = 10; i < 140; i++)
	{
		++newDate;
		cout << "The date: " << newDate << endl;
	}

	return 0;
}