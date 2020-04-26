// Exam 2 Part 2 Problem 4
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <queue>
using namespace std;


/* Returns true if there is a path from source 's' to sink 't' in
residual graph. Also fills parent[] to store the path */
bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int>& parent){
	int nv = rGraph.size();
	// a visited array and mark all vertices as not visited
	vector<bool> visited(nv,false);

	// a queue, enqueue source vertex and mark it as visited
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// queue to do a breadth-first search
	while (!q.empty()){
		int u = q.front();
		q.pop();

		for (int v = 0; v<nv; v++){
			if (visited[v] == false && rGraph[u][v] > 0){
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// We reached sink in BFS starting from source
	return (visited[t] == true);
}

// Returns the maximum flow from s to t in the given graph
int EdmondsKarp(vector<vector<int>> & graph, int s, int t){
	int u,v,nv = graph.size();

	// a residual graph and fill the residual graph with given capacities
	vector<vector<int>> rGraph(nv,vector<int>(nv));	
	for (u = 0; u < nv; u++)
		for (v = 0; v < nv; v++)
			rGraph[u][v] = graph[u][v];

	vector<int> parent(nv);  // This array is filled by BFS and to store path

	int max_flow = 0;  // There is no flow initially

	cout << "Flow along edges that yield the maximum flow: " << endl;

	// Augment the flow while there is path from source to sink
	while (bfs(rGraph, s, t, parent)){
		// Find minimum residual capacity of the edges along the
		// path found by BFS.
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]){
			u = parent[v];
			if (path_flow == INT_MAX)
				cout << "edge " << u << " -> " << v << " has flow " << 0 << endl;
			else
				cout << "edge " << u << " -> " << v << " has flow " << path_flow << endl;
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// Update residual capacities of edges; reverse edges along the path
		for (v = t; v != s; v = parent[v]){
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
			//cout << "edge " << u << " -> " << v << " has flow " << path_flow << endl;
		}

		// Add path flow to overall flow
		max_flow += path_flow;


	}
	cout << endl;
	// output the resulting flow along each edge in the solution

	// Return the overall flow
	return max_flow;
}


int main(void){

	vector<vector<int>> flow(6, vector<int>(6, 0));

	flow[0][1] = 16;
	flow[2][1] = 4;
	flow[0][2] = 13;
	flow[1][2] = 10;
	flow[1][3] = 12;
	flow[3][2] = 9;
	flow[2][4] = 14;
	flow[4][3] = 7;
	flow[4][5] = 4;
	flow[3][5] = 20;

	int maxF = EdmondsKarp(flow, 0, 5);
	cout << "For the exam example, the max is: " << maxF << endl;

	cout << endl;

	vector<vector<int>> flow2(8, vector<int>(8, 0));

	flow2[0][1] = 2;
	flow2[0][3] = 4;
	flow2[0][5] = 1;
	flow2[1][2] = 5;
	flow2[2][7] = 3;
	flow2[3][1] = 2;
	flow2[3][6] = 3;
	flow2[4][2] = 5;
	flow2[4][7] = 2;
	flow2[5][4] = 2;
	flow2[5][6] = 3;
	flow2[6][7] = 1;

	maxF = EdmondsKarp(flow2, 0, 7);

	cout << "For Figure 8.20, the max flow is: " << maxF << endl;

	cout << endl;

	return 0;
}