//Clare Minnerath

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

void outVec(const vector<int> &v);

int main(void)
{
	bool isitHeap;
	vector<int> ex(10);
	for (auto &el : ex)
	{
		el = rand() % 100;
	}
	outVec(ex);
	isitHeap = is_heap(ex.begin(), ex.end());
	if (isitHeap)
		cout << "It's a heap!\n";
	else
		cout << "It's not a heap...\n";

	make_heap(ex.begin(), ex.end());

	isitHeap = is_heap(ex.begin(), ex.end());
	if (isitHeap)
		cout << "It's a heap!\n";
	else
		cout << "It's not a heap...\n";

	return 0;
}

void outVect(const vector<int> &v)
{
	for (auto el : v)
		cout << el << " ";
	cout << endl;
}