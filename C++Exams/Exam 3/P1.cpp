//Clare Minnerath
//Final Exam P1
//Starbucks line

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;



int main(void)
{
	int n = 100;
	int seed = 72931;
	srand(1729);
	int customer = 1;
	double probArrival = .46;
	double probDeparture = .33;
	int totalLength = 0;

	queue<int> line;

	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << i + 1;
		if (!line.empty() && rand() % 100 < probDeparture * 100)
		{
			cout << setw(10) << "Customer " << line.front() << " departs.";
			line.pop();
		}
		if (rand() % 100 < probArrival * 100)
		{
			cout << setw(10) << "Customer " << customer << " arrives.";
			line.push(customer);
			customer++;
		}
		totalLength += line.size();
		cout << endl;
	}

	cout << "At the end of the simulation, the line has " << line.size() << " customers." << endl;
	cout << "Customer " << line.front() << " is at the front of the line." << endl;
	cout << "During the simulation, the average length of the line was " << (double)totalLength / n << " customers." << endl;

	return 0;
}