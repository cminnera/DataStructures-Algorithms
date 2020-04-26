// Lab1P0Q2a.cpp  Example of a lambda in C++
// https://msdn.microsoft.com/en-us/library/dd293608(v=vs.120).aspx
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> v;
	for (int i = 1; i < 10; ++i) {
		v.push_back(rand() % 10);
	}
	for (auto val : v)
		cout << val << " ";
	cout << endl;
	// Count the number of even numbers in the vector by 
	// using the for_each function and a lambda.
	int evenCount = 0;
	for_each(v.begin(), v.end(),  [&evenCount](int n) {
		cout << n;
		if (n % 2 == 0) {
			cout << " is even " << endl;
			++evenCount;
		}
		else {
			cout << " is odd " << endl;
		}
	});
	// Print the count of even numbers to the console.
	cout << "There are " << evenCount
		<< " even numbers in the vector." << endl;
}
