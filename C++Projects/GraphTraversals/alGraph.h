#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <list>
#pragma warning(disable : 4996)  // to get rid of the warnings on  sscanf_s
using namespace std;

const char NONAME = ' ';

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
typedef pair<vertex, vector<edge>> epair;
typedef map<vertex, vector<edge>> adjmap;
typedef map<vertex, int> numbering;
class graph{
protected:
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
public:
	graph():isDir(false),isWeight(false){}
	bool readfile(string name);
	void depthFirstSearch(void);
	void breadthFirstSearch(void);
};