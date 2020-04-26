// CSC 225
// Clare

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <deque>
using namespace std;

class graph{
private:
	int vertices; // # of vertices & edges
	map<pair<int, int>, int> edges; // pair<source,dest>, weight
public:
	graph(){
		vertices = 0;
	}
	bool readFile(string file);
	void showGraph();
	void friend printDist(vector<int> dist, vector<int> visits, int source);
	void FordAlgorithm(int source);
	void labelCorrectingAlgorithmQueue(int source);
	void labelCorrectingAlgorithmDeque(int source);
};