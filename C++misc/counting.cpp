//Clare Minnerath
//Counting Example

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

unsigned int countAdds = 0, countMults = 0, countCalls = 0;

int main(void)
{
	//Look aat doing a bunch of root finding

	double a, b, c, r1, r2, disc;
	int nroots;
	int datasize;
	for (datasize = 100; datasize <= 1000; datasize += 100)
	{
		countCalls = 0;
		for (int i = 0; i < datasize; i++)
		{
			//y=ax^2 + bx + c
			a = (double)rand(); b = (double)rand(); c = (double)rand();
			disc = b*b - 4 * a*c;
			if (disc > 0)
			{
				r1 = (-b + sqrt(disc)) / (2 * a);
				r2 = (-b - sqrt(disc)) / (2 * a);
				nroots = 2;
			}
			else if (disc == 0)
			{
				r1 = (-b + sqrt(disc)) / (2 * a);
				r2 = 0;
				nroots = 1;
			}
			else
			{
				nroots = 0;
			}
			countCalls += nroots;
		}
	cout << datasize << "," << countCalls << "\n";
	}

	

	return 0;
}