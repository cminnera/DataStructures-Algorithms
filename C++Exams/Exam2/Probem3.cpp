// Exam 2 Part 2 Problem 3
#include "bTreeOrderM.h"

void initData(vector<int> & datavals, int range=1000){
	int n = datavals.size(), d, index = 0, j;
	bool duplicate;
	while (index < n){
		d = rand() % range + 1;
		duplicate = false;
		for (j = 0; j < index; j++)
			if (datavals[j] == d){
				duplicate = true;
				break;
			}
		if (!duplicate)
			datavals[index++] = d;
	}
}
void printData(const vector<int> & datavals){
	for (auto dv : datavals)
		cout << dv << " ";
	cout << endl;
}

int main(void){
	int order;
	int ND = 25; // Number of data items
	vector<int> data(ND);
	srand(967531);
	initData(data, 100);
	cout << "The data:\n";
	printData(data);



	cout << endl;
	cout << "Enter the desired order >= 3 (0 to stop): ";
	cin >> order;
	cout << endl;

	while (order != 0)
	{
		//btree t(order);
		improvedBtree t(order);
		for (auto d : data)
		{
			t.insert(d);
		}
		t.show();

		cout << endl;
		cout << "Enter the desired order >= 3 (0 to stop): ";
		cin >> order;
		cout << endl;
	}

	return 0;
}