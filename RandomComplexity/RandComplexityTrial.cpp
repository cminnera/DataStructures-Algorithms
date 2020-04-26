//Clare and Jovana trial 

#include "clareJovanaTrial.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

trial::trial(unsigned int s)
{
	seed = s;
	srand(s);
	cComps = 0;
	cSwaps = 0;
	cMiniUpdates = 0;
}

trial::~trial()
{

}

void trial::init(int n, int max)
{
	trialdata.clear();
	trialdata.resize(n);

	int i, j;
	bool unique;
	N = n;

	for (i = 0; i < n; i++)
	{
		//get ith data value
		do
		{
			unique = true;
			trialdata[i] = rand() % max;	//0 and max-1
			for (j = 0; j < i; j++)
			{
				if (trialdata[i] == trialdata[j])
				{
					unique = false;
					break;
				}
			}
			//break takes us here
		} while (!unique);
	}
}

int trial::selectkth(int k)
{
	int i, j, mini, tmp;
	cComps = 0;
	cSwaps = 0;

	for (i = 0; i < k; i++)
	{

		mini = i;
		for (j = i + 1; j < N; j++)
		{
			if (trialdata[j] < trialdata[mini])
			{
				mini = j;
			}
			cComps++;
			tmp = trialdata[i];
			trialdata[i] = trialdata[mini];
			trialdata[mini] = tmp;
		}
		cSwaps++;
	}
	return trialdata[k - 1];
}

void trial::display(int ns)
{
	int increment;
	
	cout << "Enter increment for k values (ex: 5th, 10th, 15th... the increment would be 5): ";
	cin >> increment;
	//increment = N / 2;
	int k = increment;

	cout << "Here is some of the data: " << endl;

	for (int i = 0; i < ns; i ++)
		cout << trialdata[i] << "\t";
	cout << endl << endl;
	cout << "N" << "\t" << "K" << "\t" << "Comparisons" << "\t" << "i-Updates" << "\t" << "Swaps" << endl;
	while (k < N)
	{
		cMiniUpdates = 0;
		cMiniUpdates = selectkth(k);
		
		getCounters(cComps, cMiniUpdates, cSwaps);
		cout << N << "\t" << k << "\t" << cComps << "\t\t" << cMiniUpdates << "\t\t" << cSwaps << "\t" << endl;
		k += increment;
	}
	cout << endl;
}

int main(void)
{
	int seed, dataSize, increment;
	bool done = false;
	trial t1;


	cout << "Enter the seed (ex: a prime such as 6563 or the taxicab number 1729:" << endl;
	cin >> seed;
	srand(seed);
	cout << "Initialize random number generator with the seed " << seed << endl;
	while (!done)
	{
		cout << "Enter data size <= 8191 (0 to stop): " << endl;
		cin >> dataSize;
		if (dataSize == 0)
		{
			done = true;
			exit(1);
		}
		/*cout << "Enter increment for k values (ex: 5th, 10th, 15th... the increment would be 5): ";
		cin >> increment;*/
		
		//cout << "N" << "\t" << "K" << "\t" << "Comparisons" << "\t" << "i-Updates" << "\t" << "Swaps" << endl;

		/*for (int i = 1000; i <= 10000; i += 1000)
		{
			t1.init(i, i * 4);
			t1.display();
		}*/
		t1.init(dataSize, dataSize * 4);
		t1.display();


	}


	return 0;
}