// Lab 2 Part 0 file worddistance0.cpp
// A Naive recursive C++ program to find minimum number
// operations to convert str1 to str2
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


_int64 countdistCalls; // Microsoft-specific 8-byte signed integer
_int64 countmin3Calls;
// https://msdn.microsoft.com/en-us/library/aa298973(v=vs.60).aspx
// Utility functions
inline int min2(int x, int y){	
	return (x <= y ? x : y);
}
int min3(int x, int y, int z){
	countmin3Calls++;

	return min2(min2(x, y), z);
}

int worddist(string str1, string str2, int n, int m);
int worddist(string str1, string str2);

int main(void ){
	string s1, s2;
	cout << "string1? ";
	getline(cin, s1);
	cout << "string2? ";
	getline(cin, s2);

	
	countdistCalls = 0;
	countmin3Calls = 0;
	cout << "Distance is "
		<< worddist(s1, s2) << endl;
	cout << "Number of calls to distance function: " << countdistCalls << endl;

	cout << "Number of calls to min3 function: " << countmin3Calls << endl;
	
	return 0;
}

int worddist(string str1, string str2, int n, int m){
	countdistCalls++;
	// If first string is empty, the only option is to
	// insert all characters of second string into first
	if (n == 0) return m;

	// If second string is empty, the only option is to
	// remove all characters of first string
	if (m == 0) return n;

	// If last characters of two strings are same, nothing
	// much to do. Ignore last characters and get count for
	// remaining strings.
	if (str1[n - 1] == str2[m - 1])
		return worddist(str1, str2, n - 1, m - 1);

	// If last characters are not same, consider all three
	// operations on last character of first string, recursively
	// compute minimum cost for all three operations and take
	// minimum of three values.
	return 1 + min3(worddist(str1, str2, n, m - 1),    // Insert
		worddist(str1, str2, n - 1, m),   // Remove
		worddist(str1, str2, n - 1, m - 1) // Replace
		);
}

int worddist(string str1, string str2)
{
	int i, j, n = str1.length(), m = str2.length();

	vector<vector<int>> table(n + 1, vector<int>(m + 1));

	countdistCalls++;

	for (j = 0; j <= m; j++)
	{
		table[0][j] = j;
	}
	for (i = 0; i <= n; i++)
	{
		table[i][0] = i;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				table[i][j] = table[i - 1][j - 1];
			else 
				table[i][j] = 1 + min3(table[i][j - 1], table[i - 1][j], table[i - 1][j - 1]);

		}
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
			cout << setw(3) << table[i][j];
		cout << endl;
	}

	return table[n][m];
}