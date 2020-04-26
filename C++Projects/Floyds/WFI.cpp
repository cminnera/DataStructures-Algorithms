/* The Floyd-Warshall algorithm, also variously known as Floyd's algorithm, the Roy-Floyd algorithm, the Roy-Warshall algorithm, 
or the WFI algorithm, is an algorithm for efficiently and simultaneously finding the shortest paths between every pair of vertices 
in a weighted and potentially directed graph.

The Floyd algorithm is essentially equivalent to the transitive closure algorithm independently discovered by Roy (1959) 
and Warshall (1962), which is the reason it is associated with all three authors.

In Season 4 episode "Black Swan" of the television crime drama NUMB3RS, mathematical genius Charles Eppes proposed 
using the Floyd-Warshall algorithm to analyze the most recent destinations of a bombing suspect.
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "alGraphV2.h"
bool isDir, isWeight;

int main(void){
	graph g;
	string fname;
	cout << "Enter data file (ex: fig8_11.txt) ? ";
	cin >> fname;
	bool haveData = g.readfile(fname);
	if (!haveData){
		cout << "There was some difficulty reading the file " << fname << endl;
		return 1;
	}
	cout << "The weighted (di-)graph\n";
	g.printWeightMatrix();
	cout << "Execute the WFI algorithm:\n";
	g.WFIalgorithm();
	cout << "\nThe matrix after WFI algorithm:\n";
	g.printWeightMatrix();
	// TODO:  
	// (1) Inspect the entries along the main diagonal to detect cycles;
	// if any of the diagonal values are changed, then the graph contains a cycle.
	// (2) Inspect the weight matrix for remaining INF entries to find
	// vertices that are unreachable from other vertices. (see pg 406.)
	// (3) Output the "distance" of each of the shortest paths, if not INF.
	return 0;
}
