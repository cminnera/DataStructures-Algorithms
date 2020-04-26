// Exam 2 Part 2 Problem 2
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "genBST.h";
using namespace std;

typedef BSTNode<int> treeNode;
class P2_BST : public BST < int > {
private:
	void multiplyBy(treeNode *p, double m) {
		treeNode *tmp;
		if (p != nullptr)
		{
			if (m < 0)
			{
				tmp = p->left;
				p->left = p->right;
				p->right = tmp;
			}
			multiplyBy(p->left,m);
			p->el *= m;
			multiplyBy(p->right,m);
		}
	}
public:
	void insert(int el){  // overrides base class insert; parameter here is not const
		treeNode *p = root, *prev = nullptr;
		while (p != nullptr) {  
			prev = p;
			if (el < p->el)
				p = p->left;
			else p = p->right;
		}
		if (root == nullptr)    // tree is empty;
			root = new treeNode(el);
		else if (el < prev->el)
			prev->left = new treeNode(el);
		else prev->right = new treeNode(el);

	}
	void output(){
		this->inorder();
		cout << endl;
	}
	void multiplyBy(double m){
		if (m == 0){
			this->clear();
			this->insert(0);
		}
		else {
			multiplyBy(root, m);
		}
	}
};

int main(void){
	const int N = 10;
	list<int> items(10);
	P2_BST tree;

	srand(2743);   // This may change
	cout << "================ Exam 2 Part 2 Problem 2 ===================\n";
	cout << "============================================================\n";
	cout << "data:\t  ";
	for (auto &i : items){
		i = rand() % 9999 + 1;
		cout << i << " ";
	}
	cout << endl;
	for (auto i : items){
		tree.insert(i);
	}
	cout << "in-order: ";
	tree.output();

	bool done = false;
	double multiplier;
	while (!done){
		cout << "\nEnter multiplier: ";
		cin >> multiplier;
		tree.multiplyBy(multiplier);
		cout << "new tree:  ";
		tree.output();
		if (multiplier == 0)
			done = true;
	}
	return 0;
}
