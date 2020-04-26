//Clare Minnerath
//Final Exam P4

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ifstream input("citiesInAustralia.txt");
	vector<string> places;
	vector<string> tour;
	string place;
	int dis;
	int count1 = 1;
	int count2 = 0;
	int total = 0;

	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}

	map<pair<string, string>, int> placesToDis;

	input >> place;
	while (place != "0")
	{
		places.push_back(place);
		input >> place;
	}

	for (auto p : places)
	{
		placesToDis.insert(pair<pair<string, string>, int>(pair<string, string>(p, p), 0));
	}

	input >> dis;
	while (!input.eof())
	{
		if (dis == 0)
		{
			count1++;
			count2 = 0;
		}
		else
		{
			placesToDis.insert(pair<pair<string, string>, int>(pair<string, string>(places[count1], places[count2]), dis));
			count2++;
		}
		input >> dis;
	}

	/*for (auto pd : placesToDis)
	{
		cout << pd.first.first << " to " << pd.first.second << " is " << pd.second << endl;
	}*/

	cout << "Enter the cities of the tour, line by line: " << endl;
	cin >> place;
	tour.push_back(place);
	cin >> place;
	while (place != tour[0])
	{
		tour.push_back(place);
		cin >> place;
	}
	tour.push_back(tour[0]);

	cout << tour[0];
	for (int i = 0; i < tour.size() - 1; i++)
	{
		cout << " -> " << tour[i + 1] << " (";

		for each(auto pd in placesToDis)
		{
			if (tour[i] == pd.first.first&&tour[i + 1] == pd.first.second)
			{
				cout << pd.second << ")";
				total += pd.second;
			}
			if (tour[i] == pd.first.second&&tour[i + 1] == pd.first.first)
			{
				cout << pd.second << ")";
				total += pd.second;
			}
		}
	}
	cout << endl;
	cout << "Total cost = " << total << endl;

	return 0;
}