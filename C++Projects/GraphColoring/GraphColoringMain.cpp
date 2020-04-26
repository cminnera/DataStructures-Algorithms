//=========================================================================
// Exact vertex color is NP-complete
// There are approximate algorithms to solve the problem though. 
// The basic Greedy Algorithm to assign colors doesn’t guarantee to use 
// a minimum color number of colors, but it guarantees an upper bound on 
// the number of colors. The basic algorithm never uses more than d+1 colors 
// where d is the maximum degree of a vertex in the given graph.
// ==========================================================================
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "alGraphV3.h"
bool isDir, isWeight;

int main(void){
	graph g;
	string fname;
	cout << "Enter data file (ex: coloringFig1.txt) ? ";
	cin >> fname;
	bool haveData = g.readfile(fname);
	if (!haveData){
		cout << "There was some difficulty reading the file " << fname << endl;
		return 1;
	}

	int nc = g.colorVertices();

	return 0;
}
