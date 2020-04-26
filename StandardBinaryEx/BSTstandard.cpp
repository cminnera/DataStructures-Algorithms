// P0Q2.cpp
#include <iostream>
#include "genBST.h"

class P2BST : public BST < int > {

};
int main(void){
	P2BST intTree;
	srand(35317);
	int val;
	cout << "Buiding the tree: ";
	for (int i = 0; i < 10; i++){
		val = rand() % 100 + 1;
		cout << val << " ";
		intTree.insert(val);
	}
	cout << endl;
	cout << "\nInorder traversal:\n";
	intTree.inorder();
	cout << "\n\nPreorder traversal:\n";
	intTree.preorder();
	cout << "\n\nPostorder traversal:\n";
	intTree.postorder();
	cout << "\n\nBreadth-First traversal:\n";
	intTree.breadthFirst();
	cout << endl;

	cout << "\nThe tree's height:\n";
	cout << intTree.height();
	cout << endl;

	return 0;
}

