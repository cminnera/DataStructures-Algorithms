// Exam 2 Part 2 Problem 1
#include <iostream>
#include <iomanip>
#include "genSplay.h"
#include <vector>
#include <algorithm>
using namespace std;

typedef SplayingNode<int> intNode;
class intSplay : public SplayTree < int > {
private:
	unsigned long long countComparisons=0;
	unsigned long long countSemiSplays=0;
	unsigned long findHeight(intNode *p){

		if (p == nullptr)
		{
			return 0;
		}
		int l = findHeight(p->left);
		int r = findHeight(p->right);
		
		if (l >= r)
			return 1 + l;
		else
			return 1 + r;
	}
public:
	int * search(int & el) {

		intNode *p = root;
		while (p != nullptr){
			countComparisons++;
			if (p->info == el) 
			{						   // if el is in the tree,
				semisplay(p);          // move it upward;
				countSemiSplays++;
				return &p->info;
			}
			else if (el < p->info)
			{
				countComparisons++;
				p = p->left;
			}
			else
			{
				p = p->right;
				countComparisons++;
			}
		}
		return nullptr;
	}
	void initStats(){
		countComparisons = countSemiSplays = 0;
	}
	void getStats(unsigned long long & cc, unsigned long long & css){
		cc = countComparisons;
		css = countSemiSplays;
	}
	int findHeight(){
		return findHeight(root);
	}
};

int main(void){
	intSplay tree1, tree2;
	vector<int> data(10000);
	int i, index, countGood, oneMillion = 1000000;
	srand(15485863);  // this may change
	
	// create the tree
	for (auto &d : data){
		d = rand() % 30000 + 99;
	}
	for (int i = 0; i < 10000; i++){
		tree1.insert(data[i]);
		tree2.insert(data[i]);
	}
	cout << "Before searching, the tree heights are both "
		 << tree1.findHeight() << endl;

	unsigned long long comparisons, splays;
	// Perform 1000000 searches, but in a specific order:
	// We will access every 50th element in the data set, 
	// wrapping back around to start over when necessary.	
	cout << "\nPerform ordered searches:\n";
	tree1.initStats();
	index = 0;
	countGood = 0;
	for (i = 0; i < oneMillion; i++){
		if (tree1.search(data[index]) != nullptr)
			countGood++;
		index = (index + 50) % 10000;
	}
	tree1.getStats(comparisons, splays);
	if (countGood != oneMillion)
		cout << "Error occurred\n";
	else {
		cout << "Counts: " << comparisons << " comparisons, and "
			<< splays << " semi-splays\n";
		cout << "\t==>Average of " << fixed << setprecision(1) 
			<< double(comparisons) / oneMillion << " comparisons per search\n";
		cout << "The tree's height is " << tree1.findHeight() << endl;
	}

	cout << "\nPerform random searches:\n";
	tree2.initStats();
	index = 0;
	countGood = 0;
	for (i = 0; i < oneMillion; i++){
		index = rand() % 10000;
		if (tree2.search(data[index]) != nullptr)
			countGood++;
	}
	tree2.getStats(comparisons, splays);
	if (countGood != oneMillion)
		cout << "Error occurred\n";
	else{
		cout << "Counts: " << comparisons << " comparisons, and " 
		     << splays << " semi-splays\n";
		cout << "\t==>Average of " << fixed << setprecision(1)
			<< double(comparisons) / oneMillion << " comparisons per search\n";
		cout << "The tree's height is " << tree2.findHeight() << endl;
	}
	return 0;
}