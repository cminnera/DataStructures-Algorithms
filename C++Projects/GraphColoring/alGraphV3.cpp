#include "alGraphV3.h"
extern bool isDir;
extern bool isWeight;
bool graph::readfile(string name){
	string buff, charbuff;
	char charval;
	ifstream  fin(name);
	if (!fin.good()){
		cout << "Cannot open the file " << name << endl;
		return false;
	}
	fin >> buff;
	if (buff == "directed")
		isDir = true;
	else if (buff == "undirected")
		isDir = false;
	else{
		cout << "Need to know if it is directed or undirected\n";
		return false;
	}
	fin >> buff;
	if (buff == "weighted")
		isWeight = true;
	else if (buff == "unweighted")
		isWeight = false;
	else{
		cout << "Graph should be either weighted or unweighted\n";
		return false;
	}
	cout << "The graph is " << (isDir ? "directed" : "undirected") << " and "
		<< (isWeight ? "weighted" : "unweighted") << endl;
	getline(fin, buff); // flush the newline from the input stream

	// Read the vertices
	getline(fin, buff);
	cout << "We have the line of vertices: " << buff << endl;
	istringstream vstream = istringstream(buff);

	int vindex=0;
	while (vstream.good()){
		vstream >> charbuff;
		charval = charbuff[0];
		vertices.push_back(charval);
		alist.insert(epair(charval, vector<edge>()));
		nums.insert(pair<char,int>(charval,0));
		// ADD to the vector indices as well
		vindices[charval] = vindex++;  // maps support [key] operation
	}

	char es, ed;
	int ew;
	bool readOK;
	int edgecount = 0;
	//================================================================================
	// Added the following to support algorithms such as WFI that use a weight matrix
	// NV, NE, and weight are added instance variables;
	NV = vertices.size(); 
	weight.resize(NV);   
	for (int i = 0; i < NV; i++){
		weight[i] = vector<int>(NV);
		for (int j = 0; j < NV; j++)
			weight[i][j] = INF;
		weight[i][i] = 0;
	}
	//==================================================================================
	while (!fin.eof()){
		ew = 0;
		buff.clear();
		getline(fin, buff);
		//cout << "reading line " << buff << endl;
		if (buff.size() == 0) // skip blank lines
			continue;
		if (isWeight){ // weighted edges have 3 components, unweighted only 2
			readOK = (sscanf(buff.c_str(), "%c %c %d", &es, &ed, &ew) == 3);
			weight[vi(es)][vi(ed)] = ew;  
		}
		else {
			readOK = (sscanf(buff.c_str(), "%c %c", &es, &ed) == 2);
		}
		if (readOK){ // undirected edges go 2 ways; directed only 1-way
			edgecount++;
			alist[es].push_back(edge(es, ed, ew));
			if (!isDir)
				alist[ed].push_back(edge(ed, es, ew));
		}
	}
	NE = edgecount;
	cout << "The graph has " << vertices.size() << " vertices, and " << edgecount << " edges\n";
	return true;
}


void graph::DFS(vertex & v, int &i){
	// TODO: add the body
}
// 
void graph::depthFirstSearch( ){
	// TODO:  add the body
}
void graph::breadthFirstSearch(){
	// TODO: add the body

}

// Additions to support the WFI algorithm
int graph::isum(int oper1, int oper2){
	if (oper1 == INF || oper2 == INF)
		return INF;
	else
		return oper1 + oper2;
}
void graph::printWeightMatrix(void){
	int i, j, w;
	cout << "     ";

	for (j = 0; j < NV; j++)
		cout << setw(5) << left << vertices[j];
	cout << endl;
	for (i = 0; i < NV; i++){
		cout << setw(5) << left << vertices[i];
		for (j = 0; j < NV; j++){
			w = weight[i][j];
			if (w == INF)
				cout << setw(5) << left << char(236);
			else
				cout << setw(5) << left << w;
		}
		cout << endl;
	}
	cout << endl;
}

// See page 406 of Dijkstra
// Note:  if any of the diagonal values are changed,
// then the graph contains a cycle.
// If an initial value of INF between two verices in 
// the matrix is not changed to a finite value, it is an 
// indication that one vertex cannot be reached from another.
void graph::WFIalgorithm(void){
	// TODO: add the body
}
/*
Basic Greedy Coloring Algorithm :
1. Color first vertex with first color.
2. Do following for remaining vertices:
     Consider the currently picked vertex and color it with the
     lowest numbered color that has not been used on any previously
     colored vertices adjacent to it.If all previously used colors
     appear on vertices adjacent to v, assign a new color to it.
*/
int graph::colorVertices(void){ // return the number of colors used;
	const int unAssigned = -1;
	const int nColors = 7;
	int nColorsUsed;
	vector<int> vColor(NV, unAssigned);
	string colors[] = { "Pink", "Turquoise", "Gold", "Blue", "Red", "Purple", "Black" };
	vector<bool> colorAvail(nColors);

	vColor[0] = 0;
	nColorsUsed = 1;
	int i, j, vc;
	for (i = 0; i < NV; i++)
	{
		for (auto &b : colorAvail)
			b = true;
	}

}