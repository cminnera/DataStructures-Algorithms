// CSC 103 Exam 1 Part 2 Fall 2017
// Problem 2

//Clare Minnerath

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class sgrade
{
private:
	string name;
	double average;
	string letter;
	void computeLetterGrade();
public:
	sgrade(string nm = "",
		double av = 0.0,
		string lg = "") :name(nm), average(av), letter(lg){
		if (letter == "")computeLetterGrade();
	}
	double avg(){ return average; }
	void display();
	void sort(sgrade* &s1, sgrade* &s2);

	friend bool operator<(const sgrade& s1, const sgrade& s2)
	{
		return s1.average < s2.average;
	}
	friend bool operator==(const sgrade& s1, const sgrade& s2)
	{
		return s1.average == s2.average;
	}


};

void sgrade::display()
{
	cout << fixed << setw(10) << name << setw(10) << setprecision(1) << average << setw(10) << letter << endl;
}


void sgrade::sort(sgrade* &s1, sgrade* &s2)
{
	vector<sgrade> sorted;
	sgrade* iterator;
	sgrade* lowspot;
	double low;
	while (iterator != NULL)
	{
		iterator = s1;
		low = DBL_MAX;
		for (iterator; iterator != s2; iterator++)
		{
			if (iterator->average < low)
			{
				low = iterator->average;
				lowspot = iterator;
			}
		}
		sorted.push_back(*lowspot);
	}
	//for (auto k : sorted)
	//	cout << k.average << endl;
}

void sgrade::computeLetterGrade()
{
	if (average >= 90)
		letter = "A";
	else if (average >= 80)
		letter = "B";
	else if (average >= 70)
		letter = "C";
	else if (average >= 60)
		letter = "D";
	else
		letter = "F";
}

int main(void){
	string names[] = { "Susan", "Jamie", "George", 
		               "John", "Lucia", "Sorensen", "Austin" };
	vector<sgrade> CSC179;
	double randAve;
	srand(225669);
	for (auto s : names){
		randAve = (rand() % 400 + 600) / 10.0;
		CSC179.push_back(sgrade(s, randAve));
	}
	sort(CSC179.begin(), CSC179.end());
	cout << "Sorted into descending order:\n";
	for (auto entry : CSC179)
		entry.display();	
	
	sort(CSC179.begin(), CSC179.end(),
	   [](sgrade s1, sgrade s2)->bool {return s1.avg() > s2.avg(); });
	cout << "\nSorted into ascending order:\n";
	for (auto entry : CSC179)
		entry.display();
	return 0;
}