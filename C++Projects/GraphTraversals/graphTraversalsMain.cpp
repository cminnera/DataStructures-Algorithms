// This will use an adjacency list representation
// We will assume that the graph may be directed or undirected,
// and edges may be weighted or unweighted.
// For depth-first and breadth-first traversals, weighting doesn't matter.
// References: https://msdn.microsoft.com/en-us/library/t6z7bya3(v=vs.120).aspx
#include "alGraph.h"
#include <list>
bool isDir, isWeight;

int main(void){
	graph g;
	string fname;
	cout << "Enter data file (ex: fig8_3.txt) ? ";
	cin >> fname;
	bool haveData = g.readfile(fname);
	if (!haveData){
		cout << "There was some difficulty reading the file " << fname << endl;
		return 1;
	}
	g.depthFirstSearch();
	return 0;
}

