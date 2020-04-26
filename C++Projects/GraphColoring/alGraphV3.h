#include <iostream>
#include <iomanip>  // to output the weight matrix
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <list>
#include <queue>
#pragma warning(disable : 4996)  // to get rid of the warnings on  sscanf_s
using namespace std;

const char NONAME = ' ';
const int INF = INT_MAX;

typedef char vertex;
struct edge{
	vertex source, dest;
	int weight;
	edge(vertex s, vertex d, int w = 0) :source(s), dest(d), weight(w){}
	friend ostream & operator<<(ostream & os, edge e){
		cout << "(" << e.source << "," << e.dest << ")";
		return os;
	}
};

class graph{
protected:
	typedef pair<vertex, vector<edge>> epair;
	typedef map<vertex, vector<edge>> adjmap;
	typedef map<vertex, int> numbering;
	bool isDir, isWeight;
	adjmap alist;
	vector<vertex> vertices;
	list<edge> searchEdges;
	numbering nums;
	
	void DFS(vertex & v, int &i);
	
	vector<edge> &edgesFrom(const vertex& v){
		return alist.at(v);
	}
	vertex &edgeSource(edge& e){
		return  e.source;
	}
	vertex &edgeDest(edge& e){
		return  e.dest;
	}
	inline int &num(vertex v){ return nums.at(v); }
	
	//============================================== V2
	// Added to support WFI and similar algorithms
	int NV, NE;
	vector<vector<int>> weight;
	int isum(int oper1, int oper2);
	//============================================== V3
	// NEW for alGraphV3
	typedef map<vertex, int> indexing;
	indexing vindices;		// indices into the adjacency matrix
	inline int vi(vertex v){ return vindices.at(v); }
	//=============================================
public:
	graph():isDir(false),isWeight(false){}
	bool readfile(string name);
	void depthFirstSearch(void);
	void breadthFirstSearch(void);

	//============================================= V2
	// Added to support WFI algorithm
	void printWeightMatrix(void);
	void WFIalgorithm(void);
	//============================================= V3
	// Added for graph coloring
	int colorVertices(void);
};