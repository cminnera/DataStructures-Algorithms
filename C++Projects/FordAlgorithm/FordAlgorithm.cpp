// CSC 225 
// Clare

#include "FordAlgorithm.h"

bool graph::readFile(string file){
	string line;
	ifstream f(file);
	if (!f.good())
		return false;
	// READ FIRST LINE THAT CONTAINS LIST OF VERTICES
	getline(f, line);
	stringstream temp(line);
	string val;
	while (getline(temp, val, ' '))
		vertices++;
	// READ THE REST THAT CONTAINS LIST OF EDGES
	while (getline(f, line)){
		stringstream temp(line);
		string val;
		int curr[3], i = 0;
		while (getline(temp, val, ' ')){
			curr[i] = atof(val.c_str());
			i++;
		}
		i = 0;
		edges.insert(make_pair(make_pair(curr[0], curr[1]), curr[2]));
	}
	return true;
}

void graph::showGraph(){
	cout << "===================================================================\n";
	cout << "There are " << vertices << " vertices and " << edges.size() << " edges: " << endl;
	for (map<pair<int, int>, int>::const_iterator i = edges.begin(); i != edges.end(); ++i){
		cout << "\t" << i->first.first << " -> " << i->first.second << " with weight " << i->second << endl;
	}
	cout << "===================================================================\n";
	return;
}

void printDist(vector<int> dist, vector<int> visits, int source){
	cout << "Shortest paths: " << endl;
	for (unsigned int i = 0; i < dist.size(); i++)
		if (dist[i] != INT_MAX)
			cout << "\t" << source << " -> " << i << " : " << dist[i] << endl;
		else
			cout << "\t" << source << " -> " << i << " : no possible path" << endl;
	cout << "Number of visits per vertex:\n";
	for (unsigned int i = 0; i < visits.size(); i++)
		cout << "\tVertex " << i << ": " << visits[i] << " visit(s)\n";
	return;
}

void graph::FordAlgorithm(int source){
	vector<int> visits(vertices, 0);
	vector<int> dist(vertices, INT_MAX);
	dist[source] = 0;
	for (unsigned int i = 1; i < dist.size(); i++){
		for (map<pair<int, int>, int>::const_iterator j = edges.begin(); j != edges.end(); ++j){
			int u = j->first.first;
			int v = j->first.second;
			visits[v]++;
			int weight = j->second;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
			}
		}
	}
	printDist(dist, visits, source);
	return;
}

void graph::labelCorrectingAlgorithmQueue(int source){
	vector<int> visits(vertices, 0);
	vector<int> dist(vertices, INT_MAX);
	dist[source] = 0;
	queue<int> tobeChecked;
	tobeChecked.push(source);
	while (!tobeChecked.empty()){
		int v = tobeChecked.front();
		tobeChecked.pop();
		for (map<pair<int, int>, int>::const_iterator i = edges.begin(); i != edges.end(); ++i){
			if (i->first.first == v){
				int weight = i->second;
				int u = i->first.second;
				visits[u]++;
				if (dist[u] > dist[v] + weight){
					dist[u] = dist[v] + weight;
					tobeChecked.push(u);
				}
			}
			else if (i->first.first > v)
				break;
		}
		
	}
	printDist(dist, visits, source);
}

void graph::labelCorrectingAlgorithmDeque(int source){
	vector<int> visits(vertices, 0);
	vector<int> dist(vertices, INT_MAX);
	dist[source] = 0;
	deque<int> tobeChecked;
	vector<bool> enqueue(vertices, false);
	tobeChecked.push_back(source);
	enqueue[source] = true;
	while (!tobeChecked.empty()){
		int v = tobeChecked.back();
		tobeChecked.pop_back();
		for (map<pair<int, int>, int>::const_iterator i = edges.begin(); i != edges.end(); ++i){
			if (i->first.first == v){
				int weight = i->second;
				int u = i->first.second;
				visits[u]++;
				if (dist[u] > dist[v] + weight){
					dist[u] = dist[v] + weight;
					if (enqueue[u] == false){
						tobeChecked.push_back(u);
						enqueue[u] = true;
					}
					else
						tobeChecked.push_front(u);
				}
			}
			else if (i->first.first > v)
				break;
		}
	}
	printDist(dist, visits, source);
}