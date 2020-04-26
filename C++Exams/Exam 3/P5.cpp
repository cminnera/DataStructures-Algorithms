//Clare Minnerath
//Final Exam P5


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
	ifstream input("Christmas.txt");

	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}
	string temp;
	ifstream fin("Thanksgiving.txt");

	if (fin.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}

	ofstream output("Holidays.txt");

	string Ctemp;
	string Ttemp;

	input >> Ctemp;
	fin >> Ttemp;


	while (!fin.eof() && !input.eof())
	{
		while (Ttemp <= Ctemp)
		{
			output << Ttemp << endl;
			fin >> Ttemp;
			if (fin.eof())
				break;
		}

		while (Ctemp <= Ttemp)
		{
			output << Ctemp << endl;
			input >> Ctemp;
			if (input.eof())
				break;
		}
	}

	/*In Case one of the input files still has data in it*/
	while (!fin.eof())
	{
		output << Ttemp << endl;
		fin >> Ttemp;
	}

	while (!input.eof())
	{
		output << Ctemp << endl;
		input >> Ctemp;
	}

	input.close();
	fin.close();
	output.close();

	return 0;
}