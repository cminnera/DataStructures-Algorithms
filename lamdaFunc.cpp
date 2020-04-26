//// Lab1P0Q2a.cpp  Example of a lambda in C++
//// https://msdn.microsoft.com/en-us/library/dd293608(v=vs.120).aspx
//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//	vector<int> v;
//	for (int i = 1; i < 10; ++i) {
//		v.push_back(rand() % 10);
//	}
//	for (auto val : v)
//		cout << val << " ";
//	cout << endl;
//	// Count the number of even numbers in the vector by 
//	// using the for_each function and a lambda.
//	int evenCount = 0;
//	for_each(v.begin(), v.end(),  [&evenCount](int n) {
//		cout << n;
//		if (n % 2 == 0) {
//			cout << " is even " << endl;
//			++evenCount;
//		}
//		else {
//			cout << " is odd " << endl;
//		}
//	});
//	// Print the count of even numbers to the console.
//	cout << "There are " << evenCount
//		<< " even numbers in the vector." << endl;
//}



//B

//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v1{ 1, 2, 3, 4 };
//	vector<int> v2;
//	transform(v1.begin(), v1.end(), back_inserter(v2), [](int x){return x + 1; });
//	for (auto v:v2)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//}


//C

//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> vect(25);
//	auto singleDigit = [](int x)->bool{return (x < 9); };
//	for (auto &v : vect)
//	{
//		v = rand() % 50;
//		cout << v << " ";
//	}
//	cout << endl;
//	auto iterator = remove_if(vect.begin(), vect.end(), singleDigit);
//	vect.erase(iterator, vect.end());
//	for (auto v : vect)
//		cout << v << " ";
//	cout << endl;
//	return 0;
//}


//D

#include <numeric>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main(void)
{
	vector<double> v = { 2.5, -8.6, 9.2, 14.3 };
	double sum = accumulate(v.begin(), v.end(), 0.0);
	double product = accumulate(v.begin(), v.end(), 1.0, multiplies<double>());
	cout << "sum = " << sum << ", and product = " << product << endl;
}