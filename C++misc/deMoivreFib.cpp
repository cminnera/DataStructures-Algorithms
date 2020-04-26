// Comparing Fibonacci versions - neither one is recursive!!!
// https://oeis.org/A000045/b000045.txt
// fib(40) = 102334155
// fib(50) = 12586269025
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned __int64 ulong;
// Drozdek's version
ulong Drozdek(ulong n) {
	return (ulong) ceil(exp(n*log(1.6180339897) - log(2.2360679775)) - 0.5);
}
ulong iterativeFib(ulong n){
	if (n <= 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else {
		ulong prev, curr = 1, next = 1;
		for (ulong i = 3; i <= n; i++){
			prev = curr; curr = next;
			next = prev + curr;
		}
		return next;
	}
}


//[Stackoverflow.com]
ulong Binet(ulong n)
{
	static const double phi = (1 + sqrt(5))*0.5;
	double fib = (pow(phi, n) - pow(1 - phi, n)) / sqrt(5);
	return ulong(round(fib));
}


int main(void){
	cout << endl;
	cout << " N   Iterative Fib         Binet's Formula          Drozdek's implementation\n";
	cout << "============================================================================\n";
	for (ulong i = 10; i <= 80; i += 10){
		cout << setw(4) << left << i << setw(25) << iterativeFib(i) << setw(25) << Binet(i) << setw(25) << Drozdek(i) << endl;
	}
	return 0;
}