// CSC 103 Exam 1 Part 2 Fall 2017
// Problem 4
#include <iostream>
#include <vector>
#include "Timer.h"
#include <iomanip>
using namespace std;
void outputV(vector<int> & v);
unsigned long long generate(int n, vector<int> & A, int & s);

int main(void){
	int N, cSwaps = 0;
	cout << "Enter positive integer N: ";
	cin >> N;
	vector<int> els(N);
	int i = 1;
	for (auto &el : els)
		el = i++;
	stopWatch sw;
	startTimer(&sw);
	unsigned long long nperms = generate(N, els, cSwaps);
	stopTimer(&sw);
	cout << "Time: " << fixed << setprecision(5) << getElapsedTime(&sw) << endl;
	cout << "Swaps: " << cSwaps << endl;
	cout << "We generated " << nperms << " permutations\n";
	return 0;
}

void outputV(vector<int> & v){
	cout << "{ ";
	for (auto el : v)
		cout << el << " ";
	cout << "}\n";
}

unsigned long long generate(int n, vector<int> & A, int & s) {

	unsigned long long np;
	vector<int> c(n, 0);
	int i;

	if (n == 1)
	{
		//outputV(A);
		np = 1;
	}
	else
	{
		np = 0;
		for (i = 0; i < n - 1; i++)
		{
			np += generate(n - 1, A, s);
			if (n % 2 == 0)
				swap(A[i], A[n - 1]);
			else
				swap(A[0], A[n - 1]);
			s++;
		}
		np += generate(n - 1, A, s);
	}
	return np;
}