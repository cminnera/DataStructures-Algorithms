#include "alGraph.h"
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

	while (vstream.good()){
		vstream >> charbuff;
		charval = charbuff[0];
		vertices.push_back(charval);
		alist.insert(epair(charval, vector<edge>()));
		nums.insert(pair<char,int>(charval,0));
	}

	char es, ed;
	int ew;
	bool readOK;
	int edgecount = 0;

	while (!fin.eof()){
		ew = 0;
		buff.clear();
		getline(fin, buff);
		//cout << "reading line " << buff << endl;
		if (buff.size() == 0) // skip blank lines
			continue;
		if (isWeight){ // weighted edges have 3 components, unweighted only 2
			readOK = (sscanf(buff.c_str(), "%c %c %d", &es, &ed, &ew) == 3);
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
	cout << "The graph has " << vertices.size() << " vertices, and " << edgecount << " edges\n";
	return true;
}

void graph::DFS(vertex & v, int &i){
	//cout<<"DFS at "<<v.name<<endl;
	num(v) = i++;
	vector<edge> &ve = edgesFrom(v);
	for (auto &e : ve)
	{
		//look at edges incident to v
		vertex &u = edgeDest(e);	//get the destination vertex
		if (num(u) == 0)
		{
			searchEdges.push_back(e);
			DFS(u, i);
		}
	}
}
// 
void graph::depthFirstSearch( ){
	// for all vertices v num(v) = 0
	for (auto & v : vertices)
	{
		num(v) = 0;
	}

	searchEdges.clear();
	int nsubGraphs = 0;
	int i = 1;
	bool done;

	do
	{
		done = true;
		for (auto & v : vertices)
		{
			if (num(v) == 0)
			{
				done = false;
				nsubGraphs++;
				cout << "Start depth-first-search at vertex " << v << endl;
				DFS(v, i);
				break;
			}
		}
	} while (!done);
	cout << "We ended up with " << nsubGraphs << " subgraphs\n";
	cout << "Here are the edges in the DFS tree: \n";
	for (auto e : searchEdges)
		cout << e << " ";
	cout << endl;
}
void graph::breadthFirstSearch(){
	// TODO: add the body

}