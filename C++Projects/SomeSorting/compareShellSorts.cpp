//Clare 

//Comparing different shell sorts

#include <iostream>
#include <iomanip>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;
#include "sortsInstrumented.h"

// updated stopWatch
struct stopWatch{
	clock_t start;
	clock_t stop;
};
void startTimer(stopWatch *timer) {
	timer->start = clock();
}
void stopTimer(stopWatch *timer) {
	timer->stop = clock();
}
double getElapsedTime(stopWatch *timer) {
	clock_t elapsedInClocks = timer->stop - timer->start;
	// This returns the time in seconds
	return (double(elapsedInClocks) / double(CLK_TCK));
}
// For observing the steps in a sort, as in Figure 9. page 506
bool beloud = true;

bool useArtificialSequence = false;
bool useAhsort = false;
bool useBhsort = false;
bool useChsort = false;
bool useDhsort = false;
bool useEhsort = false;

// For recording and accessing performance measures 
unsigned long long countDataComps, countDataAssigns;
void initCounts(void){ countDataComps = countDataAssigns = 0; }
void outputCounts(void){
	cout << setw(14) << countDataComps << setw(18) << countDataAssigns << endl;
}
template<class T>
bool issorted(T data[], int n){
	for (int i = 1; i < n; i++)
		if (data[i] < data[i - 1])
			return false;
	return true;
}

void runWithLargeData(void){
	int dsi, i, j, k, dataSize;
	//int nvals[] = { 100000, 200000, 300000, 400000 };
	//int nvals[] = { 800000, 900000, 1000000, 1100000 };
	int nvals[] = { 1000, 5000, 10000, 50000, 100000 };
	random_device rd;   // non-deterministic generator
	stopWatch mytimer;
	mt19937 gen(212121);

	unsigned long *data, *copy;
	string sortNames[] = { "Knuth", "Hibbard", "Papernov..", "Fibonacci", "Dobosiewcz" };
	double table[5][5];
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			table[i][j] = 0;


	cout << "Counts for each Shell sort version: " << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << setw(28) << "Data Size:" << setw(20) << "Data Comparisons:" << setw(20) << "Data Assignments:" << endl;

	// Do these in a loop, and average the results
	useAhsort = true;
	for (int m = 0; m < 5; m++)
	{
		const int nTrials = 1;
		for (k = 0; k < nTrials; k++){

			for (dsi = 0; dsi < 5; dsi++){
				dataSize = nvals[dsi];
				//cout << "data size = " << dataSize << endl;
				data = new unsigned long[dataSize];
				copy = new unsigned long[dataSize];

				for (i = 0; i < dataSize; i++)
					copy[i] = data[i] = gen();

				initCounts();
				startTimer(&mytimer);
				Shellsort<unsigned long>(data, dataSize);
				stopTimer(&mytimer);
				if (issorted(data, dataSize))
					table[m][dsi] += getElapsedTime(&mytimer);
				else
					cout << "Error occurred with Shellsort\n";


				for (i = 0; i < dataSize; i++)
					data[i] = copy[i];
				delete[] data;
				delete[] copy;

				cout << setw(12) << sortNames[m] << ": " << setw(14) << nvals[dsi] << "\t";
				outputCounts();
				initCounts();
			}
		}// end of for-k loop on the number of trials

	/*	cout << sortNames[m] << ": " << endl;
		cout << "->\t";
		outputCounts();
		initCounts();*/

		if (useAhsort)
		{
			useAhsort = false;
			useBhsort = true;
		}
		else if (useBhsort)
		{
			useBhsort = false;
			useChsort = true;
		}
		else if (useChsort)
		{
			useChsort = false;
			useDhsort = true;
		}
		else
		{
			useDhsort = false;
			useEhsort = true;
		}
	}

	// print the table here

	cout << endl;
	cout << "             Time in seconds\n           ";
	for (j = 0; j < 5; j++)
		cout << setw(12) << nvals[j];
	cout << "\n";
	cout << "           ==================================================================\n";


	for (i = 0; i < 5; i++){
		cout << setw(10) << sortNames[i] << "|";
		for (j = 0; j < 5; j++)
			cout << setw(12) << fixed << setprecision(3) << table[i][j];
		cout << endl;
	}
	cout << endl;

}
int main(void){
	stopWatch timer;
	beloud = false;
	runWithLargeData();


	return 0;
}