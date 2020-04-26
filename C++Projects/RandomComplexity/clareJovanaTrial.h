//Clare and Jovana Header Trial file

#ifndef CLAREJOVANATRIAL_H
#define CLAREJOVANATRIAL_H

#include <vector>
#include <iostream>
using namespace std;

class trial
{
private:
	int N;
	vector<int> trialdata;
	int cComps, cMiniUpdates, cSwaps;
	unsigned int seed;
public:
	// The constructor will seed the random number generator
	trial(unsigned int s = 1729);
	~trial();

	// init() will clear, resize, and initialize the vector with n unique integers
	void init(int n = 100, int max = RAND_MAX / 4);
	inline void initCounts()
	{
		cComps = cMiniUpdates = cSwaps = 0;
	}
	int selectkth(int k);

	// access the preformance counters
	void getCounters(int &comps, int &updates, int &swaps)
	{
		comps = cComps;
		updates = cMiniUpdates;
		swaps = cSwaps;
	}
	//output ns elements from the vector to std out
	void display(int ns = 25);
};

#endif