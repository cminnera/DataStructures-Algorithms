// CSC 103 Exam 1 Part 2 Fall 2017
// Problem 3

#include <iostream>
#include <vector>
#include <iomanip>
#include "Timer.h";
using namespace std;
void outputV(vector<int> & v);
unsigned long long generate(int n, vector<int> A);
int main(void){
	int N;
	cout << "Enter positive integer N: ";
	cin >> N;
	vector<int> els(N);
	int i = 1;
	for (auto &el : els)
		el = i++;
	unsigned long long nperms = generate(N, els);
	cout << "We generated " << nperms << " permutations\n";
	return 0;
}

void outputV(vector<int> & v){
	cout << "{ ";
	for (auto el : v)
		cout << el << " ";
	cout << "}\n";
}

unsigned long long generate(int n, vector<int> A) {
	unsigned long long np = 0;
	vector<int> c(n, 0);
	int i, cSwaps = 0;
	//outputV(A); 
	stopWatch sw;
	startTimer(&sw);
	np++;
	i = 0;
	while (i < n){
		if (c[i] < i){
			if (i % 2 == 0)
				swap(A[0], A[i]);
			else
				swap(A[c[i]], A[i]);
			cSwaps++;
			//outputV(A); 
			np++;
			c[i] += 1;
			i = 0;
		}
		else{
			c[i] = 0;
			i++;
		}
	}
	stopTimer(&sw);
	cout << "Time: " << fixed << setprecision(5) << getElapsedTime(&sw) << endl;
	cout << "Swaps: " << cSwaps << endl;
	return np;
}