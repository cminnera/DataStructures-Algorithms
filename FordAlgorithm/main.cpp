// CSC 225 
// Clare

#include "FordAlgorithm.h"

int main(void){
	int source;
	graph myGraph;
	string file;
	cout << "Enter data file (such as graph.txt): ";
	getline(cin, file);
	if (!myGraph.readFile(file)){
		cout << "Error reading file\n";
		return 1;
	}
	myGraph.showGraph();
	cout << "Enter a source node (0 to 8): ";
	cin >> source;
	if (0 <= source && source <= 8){
		cout << "\nFord Algorithm:\n";
		myGraph.FordAlgorithm(source);
		cout << "\nLabel Correcting Algorithm using queue:\n";
		myGraph.labelCorrectingAlgorithmQueue(source);
		cout << "\nLabel Correcting Algorithm using deque:\n";
		myGraph.labelCorrectingAlgorithmDeque(source);
	}
	else
		cout << "Invalid source" << endl;
	return 0;
}