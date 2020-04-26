//Clare Minnerath
//Final Exam P3
//Popular Names

#include <set>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int comCount;

class popName
{
//private:
//	popularName Name1;
public:
	set<popularName> theNames;
	friend ostream& operator<<(ostream & o, const popularName & n)
	{
		o << n.name << " (" << n.rank << ") " << endl;
		return o;
	}
	friend bool operator<(const popularName& n1, const popularName& n2)
	{
		comCount++;
		return n1.name < n2.name;
	}
	friend bool operator==(const popularName& n1, const popularName& n2)
	{
		comCount++;
		return n1.name == n2.name;
	}

	bool operator<(popularName& other)
	{
		return < other.name;
	}

	//popName()
	//{
	//	Name1.name = " ";
	//	Name1.gender = ' ';
	//	Name1.rank = 0;
	//}
	//popName(string n, char g, int r)
	//{
	//	Name1.name = n;
	//	Name1.gender = g;
	//	Name1.rank = r;
	//}
	//popName(popularName n1)
	//{
	//	Name1 = n1;
	//}
};

struct popularName
{
	string name;
	char gender;
	int rank;
};

int main(void)
{
	comCount = 0;
	ifstream input("names.txt");
	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}

	string fname;
	popularName n;
	int count = 1;
	char gen = 'M';
	//popName nameClass;
	set<popularName> theNames;

	while (!input.eof())
	{
		input >> fname;
		n.name = fname;
		n.gender = gen;
		n.rank = count;

		if (gen == 'M')
			gen = 'F';
		else
		{
			gen = 'M';
			count++;
		}
			for each(auto p in theNames)
			{
				//if (n == p)
				{
					theNames.insert(n);
				}
			}
			for each(auto p in theNames)
			{
				//if (n == p)
				{
					cout << p << endl;
				}
			}
	}

	return 0;
}