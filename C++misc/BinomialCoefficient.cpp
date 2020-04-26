// Finding Binomial Coefficients
// Exercise 9, page 207
#include <iostream>
#include <string>
using namespace std;

unsigned long long RBC(int n, int k);
unsigned long long IBC(int n, int k);
int nCallsToRBC = 0;
int main(void){
	int nval, kval;
	string response;
	do {
		nCallsToRBC = 0;
		cout << "Finding binomial coefficent C(n,k): enter n and k: ";
		cin >> nval >> kval;
		if (nval < 0 || kval < 0 || kval > nval){
			cout << "Please use non-negative values with k <= n\n";
		}
		else{
			cout << "C(" << nval << "," << kval << ") = " << /*RBC(nval, kval)*/ IBC(nval,kval) << endl;
			//cout << "This compuation took " << nCallsToRBC << " calls to the function\n";
		}
		cout << "Continue (Y | N): "; cin >> response;
	} while (toupper(response[0]) == 'Y');
	return 0;
}
// recursive version
unsigned long long RBC(int n, int k){
	nCallsToRBC++;
	if (k == 0 || k == n)
		return 1;
	else return RBC(n - 1, k - 1) + RBC(n - 1, k);
}

// iterative version
unsigned long long IBC(int n, int k){

	unsigned long long numerator = 1, denominator = 1;
	int factor, diff = n - k;
	int kk = (k > diff ? diff : k);
	cout << "kk = " << kk << endl;
	for (factor = n; factor > n - kk; factor--)
		numerator *= factor;
	for (factor = 1; factor <= kk; factor++)
		denominator *= factor;

	cout << "numerator = " << numerator << ", and denominator = " << denominator << endl;
	return numerator / denominator;

	return 0;
}