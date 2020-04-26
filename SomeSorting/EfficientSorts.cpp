// Efficient Sorts for Lab 9
// Uses a modified version of Drozdek's code from Chapter 9
#include <iostream>
#include <iomanip>
#include <iomanip>
#include <string>
#include <random>
using namespace std;
#include "sortsInstrumented.h"

// For observing the steps in a sort, as in Figure 9. page 506
bool beloud = true;
bool useArtificialSequence = true;
// For recording and accessing performance measures 
unsigned long long countDataComps, countDataAssigns;
void initCounts(void){ countDataComps = countDataAssigns = 0; }
void outputCounts(void){
	cout << "Count data comparisons = " << countDataComps
		<< "\tCount data assignments = " << countDataAssigns << endl;
}
template<class T>
bool issorted(T data[], int n){
	for (int i = 1; i < n; i++)
		if (data[i] < data[i - 1])
			return false;
	return true;
}
void runWithSampleData(void){
	int fig9_7Data[] = { // Drozdek page 506
		10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16 };
	int i, dataSize = sizeof(fig9_7Data) / sizeof(int);
	
	
	cout << "Sorting " << dataSize << " integers using Shell sort\n";
	initCounts();
	Shellsort<int>(fig9_7Data, dataSize);
	for (i = 0; i < dataSize; i++)
		cout << fig9_7Data[i] << " ";
	cout << endl;
	if (issorted(fig9_7Data, dataSize))
		outputCounts();
	else
		cout << "Error in Shell sort\n";

	// Investigate heap sort
	int fig9_9Data[] = { // Drozdek page 510
		2, 8, 6, 1, 10, 15, 3, 12, 11 };
	dataSize = sizeof(fig9_9Data) / sizeof(int);
	cout << "\nSorting " << dataSize << " integers using heap sort\n";
	initCounts();
	heapsort<int>(fig9_9Data, dataSize);
	for (i = 0; i < dataSize; i++)
		cout << fig9_9Data[i] << " ";
	cout << endl;
	if (issorted(fig9_9Data, dataSize))
		outputCounts();
	else
		cout << "Error in heap sort\n";


	// Investigate quick sort
	int fig9_12Data[] = { // Drozdek page 515
		8, 5, 4, 7, 6, 1, 6, 3, 8, 12, 10 };
	dataSize = sizeof(fig9_12Data) / sizeof(int);
	cout << "\nSorting " << dataSize << " integers using quick sort\n";
	initCounts();
	quicksort<int>(fig9_12Data, dataSize);
	for (i = 0; i < dataSize; i++)
		cout << fig9_12Data[i] << " ";
	cout << endl;
	if (issorted(fig9_12Data, dataSize))
		outputCounts();
	else
		cout << "Error in quick sort\n";

	// TODO:  compare quicksort2 to quicksort

	// Investigate merge sort
	int fig9_14Data[] = { // Drozdek page 520
		1, 8, 6, 4, 10, 5, 3, 2, 22};
	dataSize = sizeof(fig9_14Data) / sizeof(int);
	cout << "\nSorting " << dataSize << " integers using merge sort\n";
	initCounts();
	mergesort<int>(fig9_14Data, dataSize);
	for (i = 0; i < dataSize; i++)
		cout << fig9_14Data[i] << " ";
	cout << endl;
	if (issorted(fig9_14Data, dataSize))
		outputCounts();
	else
		cout << "Error in merge sort\n";


	// Investigate radix sort
	int fig9_15Data[] = { // Drozdek page 523
		10, 1234, 9, 7234, 67, 9181,733, 197, 7, 3 };
	dataSize = sizeof(fig9_15Data) / sizeof(int);
	cout << "\nSorting " << dataSize << " integers using radix sort\n";
	// This is not a comparison sort
	radixsort<int>(fig9_15Data, dataSize);
	for (i = 0; i < dataSize; i++)
		cout << fig9_15Data[i] << " ";
	cout << endl;
	if (issorted(fig9_15Data, dataSize))
		cout << "Sorted okay\n";
	else
		cout << "Error in radix sort\n";
	
	// Bit radix sort does not seem very promising, except for quite small sized elements, perhaps bytes 
	// instead of 32-bit integers.

	// Test counting sort for the data given in Figure 9.17
	// 
	long fig9_17Data[] = { // Drozdek page 526
		7,1,1,3,0,7,5,5,7,3};
	long dataSizeL = sizeof(fig9_17Data) / sizeof(long);
	cout << "\nSorting " << dataSizeL << " long integers using counting sort\n";

	// This is not a comparison sort, nor is it templatized
	countingsort(fig9_17Data, dataSizeL);
	for (i = 0; i < dataSizeL; i++)
		cout << fig9_17Data[i] << " ";
	cout << endl;
	if (issorted(fig9_17Data, dataSize))
		cout << "Sorted okay\n";
	else
		cout << "Error in counting sort\n";

}

void runWithLargeData(void){
	int dsi, i, j, k, dataSize;
	int nvals[] = { 100000, 200000, 300000, 400000 };
	random_device rd;   // non-deterministic generator
	
	mt19937 gen(212121);
	cout << "This random number generator will return values between "
		<< gen.min() << " and " << gen.max() << endl;  // 0 to 4294967295

	unsigned long *data, *copy;
	string sortNames[] = { "Shellsort", "Quicksort", "Merge Sort", "Heap Sort" };
	unsigned long long table[4][4];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			table[i][j] = 0;


	// Do these in a loop, and average the results
	const int nTrials = 1;
	for (k = 0; k < nTrials; k++){

		for (dsi = 0; dsi < 4; dsi++){
			dataSize = nvals[dsi];
			cout << "data size = " << dataSize << endl;
			data = new unsigned long[dataSize];
			copy = new unsigned long[dataSize];

			for (i = 0; i < dataSize; i++)
				copy[i] = data[i] = gen();

			initCounts();
			Shellsort<unsigned long>(data, dataSize);

			if (issorted(data, dataSize))
				table[0][dsi] += countDataComps; //or countDataComps;
			else
				cout << "Error occurred with Shellsort\n";


			initCounts();
			for (i = 0; i < dataSize; i++)
				data[i] = copy[i];
			quicksort<unsigned long>(data, dataSize);
			if (issorted(data, dataSize))
				table[1][dsi] += countDataComps; //or countDataComps;
			else
				cout << "Error occurred with quicksort\n";

			initCounts();
			for (i = 0; i < dataSize; i++)
				data[i] = copy[i];
			mergesort<unsigned long>(data, dataSize);
			if (issorted(data, dataSize))
				table[2][dsi] += countDataComps; //or countDataComps;
			else
				cout << "Error occurred with merge sort\n";


			initCounts();
			for (i = 0; i < dataSize; i++)
				data[i] = copy[i];
			heapsort<unsigned long>(data, dataSize);
			if (issorted(data, dataSize))
				table[3][dsi] += countDataComps; // or countDataComps;
			else
				cout << "Error occurred with heap sort\n";

			delete[] data;
			delete[] copy;
		}
	}// end of for-k loop on the number of trials

	// print the table here
	
	cout << endl;
	cout << "             Number of Data Assignments\n           ";
	for (j = 0; j < 4; j++)
		cout << setw(16) << nvals[j];
	cout << "\n";
	cout << "           ==================================================================\n";

	// Question...how many assignments are expected for each sort, based on n - the data size?
	//            how many comparisons are expected for each sort, based on n - the data size?
	for (i = 0; i < 4; i++){
		cout << setw(10) << sortNames[i] << "|";
		for (j = 0; j < 4; j++)
			cout << setw(16) << table[i][j]/nTrials;
		cout << endl;
	}
	cout << endl;

}
int main(void){
	//runWithSampleData();
	beloud = false;
	runWithLargeData();
	return 0;
}