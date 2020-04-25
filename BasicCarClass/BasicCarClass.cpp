//Clare Minnerath and Jovana
//Lab 1 Part 1
//Data Table Application


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;
class cars
{
private:
	ifstream input;
	vector<double> data;
	vector <string> carName;
	vector <string> carProp;
	void trim(string& s);
	
	int numC = 0;
public:
	cars();
	void importData();
	void readAll();
	void readSome();
	double avg(string variable);
	double stand(string variable);
	void min(string variable);
	void max(string variable);
	double pr(string variable1, string variable2);
};

cars::cars()
{
	
}


void cars::trim(string& s){
	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);
	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p + 1);
}

void cars::importData()
{

	string filename;
	string title;
	string nextTitle;
	char sent;
	int num;
	int commas = 0;
	int pos = 0;
	double dval;

	cout << "Enter file name:(default - carData) " << endl;
	cin >> filename;

	if (filename.find(".csv") == -1)
	{
		filename += string(".csv");
	}

	input.open(filename);

	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}
	

	getline(input, title);

	while ((pos = title.find(',', pos)) != -1)
	{
		commas++;
		pos++;
	}

	istringstream ins = istringstream(title);

	getline(ins, nextTitle, ',');
	for (int i = 0; i < commas; i++)
	{
		sent = (i == commas ? '\n' : ',');
		getline(ins, nextTitle, sent);
		trim(nextTitle);
		//cout << nextTitle << endl;
		carProp.push_back(nextTitle);
	}

	while (getline(input, title))
	{
		sent = ' ';
		ins = istringstream(title);
		getline(ins, title, ',');
		trim(title);
		//cout << title << endl;
		carName.push_back(title);

		int r = 1;
		int c = 1;

		for (int i = 1; i <= commas; i++)
		{
			if (i == 1)
			{
				r = 1;
				c = 1;
			}

			sent = (i == commas ? '\n' : ',');
			getline(ins, nextTitle, sent);
			trim(nextTitle);
			if (sscanf_s(nextTitle.c_str(), "%If", &dval) != 1)
			{
				cout << "Error reading numeric data value!\n";
				return;
			}

			if (c == i)
			{
				r++;
				c = 1;
			}
			data.push_back(stod(nextTitle));
			//cout << nextTitle << endl;
		}
	}
	numC = commas;
	cout << "\nFile read complete\n\n";
	input.close();
}

void cars::readAll()
{
	int n = 0;
	int count = 0;
	cout << "   ";
	for (int i = 0; i < carProp.size(); i++)
	{
		cout << setw(7) << carProp[i];
	}
	cout << endl;
	for (int i = 0; i < carName.size(); i++)
	{
		cout << setw(7) << carName[i] << endl;
		cout << "-->";
		while (n < carProp.size() + numC*count)
		{
			cout << setw(7) << setprecision(3) << data[n];
			n++;
		}
		count++;
		cout << endl;
	}
}

void cars::readSome()
{
	int r1, r2, c1, c2;
	cout << "Enter the first and last variable number: " << endl;
	cin >> c1 >> c2;
	cout << "Enter the first and last observation number: " << endl;
	cin >> r1 >> r2;
	int count = r1 - 1;
	int n = (c1 - 1) + count*numC;
	cout << "   ";
	for (int i = c1 - 1; i < c2; i++)
	{
		cout << setw(7) << carProp[i];
	}
	cout << endl;
	for (int i = r1 - 1; i < r2; i++)
	{
		cout << setw(7) << carName[i] << endl;
		cout << "-->";
		while (n < (c2 + numC*count))
		{
			cout << setw(7) << setprecision(3) << data[n];
			n++;
		}
		count++;
		n = c1 + numC*count - 1;
		cout << endl;
	}
}

double cars::avg(string variable)
{
	double total = 0;
	int n = 0;
	int count = 0;
	double average;

	for (int i = 0; i < carProp.size(); i++)
	{
		if (variable == carProp[i])
		{
			while (n < data.size())
			{
				total += data[n + i];
				n += numC;
				count++;
			}
		}
	}
	average = total / count;
	return average;
}

double cars::stand(string variable)
{
	double total = 0;
	int count = 0;
	int n = 0;
	double sd;
	double average = avg(variable);

	for (int i = 0; i < carProp.size(); i++)
	{
		if (variable == carProp[i])
		{
			while (n < data.size())
			{
				total += pow((data[n + i] - average),2);
				n += numC;
				count++;
			}
		}
	}
	sd = sqrt(total / (count - 1));
	return sd;
}

void cars::min(string variable)
{
	double min;
	int n = 0;
	vector<int> pos;
	for (int i = 0; i < carProp.size(); i++)
	{
		if (variable == carProp[i])
		{
			min = data[n + i];
			while (n < data.size())
			{
				if (data[n + i] < min)
				{
					min = data[n + i];
					pos.clear();
					pos.push_back(n + i);
				}
				else if (data[n + i] == min)
					pos.push_back(n + i);
				n += numC;
			}
		}
	}
	cout << "The minimum value is: " << min << endl << "Located at observation(s): " << endl;
	for (int k = 0; k < pos.size(); k++)
	{
		cout << carName[pos[k]/numC] << endl;
	}
}

void cars::max(string variable)
{
	double max;
	int n = 0;
	vector<int> pos;
	for (int i = 0; i < carProp.size(); i++)
	{
		if (variable == carProp[i])
		{
			max = data[n + i];
			while (n < data.size())
			{
				if (data[n + i] > max)
				{
					max = data[n + i];
					pos.clear();
					pos.push_back(n + i);
				}
				else if (data[n + i] == max)
					pos.push_back(n + i);
				n += numC;
			}
		}
	}
	cout << "The maximum value is: " << max << endl << "Located at observation(s): " << endl;
	for (int k = 0; k < pos.size(); k++)
	{
		cout << carName[pos[k] / numC] << endl;
	}
}

double cars::pr(string variable1, string variable2)
{
	int n = 0;
	int count = 0;
	double total = 0;
	double squ1 = 0;
	double squ2 = 0;
	int pos1;
	int pos2;

	double pearson;
	for (int i = 0; i < carProp.size(); i++)
	{
		if (variable1 == carProp[i])
		{
			pos1 = i;
		}
		if (variable2 == carProp[i])
		{
			pos2 = i;
		}
		
	}
	while (n < data.size())
	{
		total += data[n + pos1] * data[n + pos2];
		squ1 += data[n + pos1] * data[n + pos1];
		squ2 += data[n + pos2] * data[n + pos2];
		n += numC;
		count++;
	}
	pearson = (total - count*avg(variable1)*avg(variable2)) / ((sqrt(squ1 - count*avg(variable1)*avg(variable1)))*(sqrt(squ2 - count*avg(variable2)*avg(variable2))));
	return pearson;
}

int main(void)
{
	cars car1;
	int choice = 0;
	int morm;
	string variable1;
	string variable2;

	while (choice != 7)
	{
		cout << "Enter Option:" << endl;
		cout << "1 : Read from a .csv file" << endl;
		cout << "2 : Print the data table" << endl;
		cout << "3 : Compute the average of a variable" << endl;
		cout << "4 : Compute the sample standard deviation of a variable" << endl;
		cout << "5 : Find the observation with the max or min value of a variable" << endl;
		cout << "6 : Compute the Pearson's r statistic for two variables" << endl;
		cout << "7 : Quit" << endl;

		cin >> choice;

		if (choice == 1)
			car1.importData();
		else if (choice == 2)
		{
			char n;
			cout << "Would you like to the whole table? (Y/N): " << endl;
			cin >> n;
			if (n == 'Y')
				car1.readAll();
			else if (n == 'N')
				car1.readSome();
			else
				cout << "Incorrect Answer, restart." << endl;
			cout << endl;
		}
		else if (choice == 3)
		{
			cout << "Enter the name of the variable: " << endl;
			cin >> variable1;
			cout << "The average value for " << variable1 << " is: " << car1.avg(variable1) << endl;
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << "Enter the name of the variable: " << endl;
			cin >> variable1;
			cout << "The sample standard deviation for " << variable1 << " is: " << car1.stand(variable1) << endl;
			cout << endl;
		}
		else if (choice == 5)
		{
			bool done = false;
			while (done != true)
			{
				cout << "Enter 1 for min. Enter 2 for max." << endl;
				cin >> morm;
				if (morm == 1)
				{
					cout << "Enter the name of the variable: " << endl;
					cin >> variable1;
					car1.min(variable1);
					done = true;
				}
				else if (morm == 2)
				{
					cout << "Enter the name of the variable: " << endl;
					cin >> variable1;
					car1.max(variable1);
					done = true;
				}
				else
					cout << "Incorrect value, try again." << endl;
			}
			cout << endl;
		}
		else if (choice == 6)
		{
			cout << "Enter the name of the first variable: " << endl;
			cin >> variable1;
			cout << "Enter the name of the second variable: " << endl;
			cin >> variable2;

			cout << "The r value for " << variable1 << " and " << variable2 << " is: " << car1.pr(variable1, variable2) << endl;
			cout << endl;
		}
	}

	return 0;
}

