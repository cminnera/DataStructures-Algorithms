//Example btree implementation 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct btnode {
	int count;
	int order;
	vector<int> value;
	vector<btnode *> child;
	btnode(int orderM = 5) :order(orderM){
		value.resize(order);
		child.resize(order);
	}
};
class btree {
protected:        
	btnode *root;
	int order;
	int MAX, MIN;
public:
	btree(int orderM = 5):order(orderM),root(nullptr){
		MAX = order - 1;
		MIN = ceil(order / 2.0) -1;
	}
	void insert(int val);
	int setval(int val, btnode *n, int *p, btnode **c);
	btnode * search(int val, btnode *root, int *pos);
	int searchnode(int val, btnode *n, int *pos);
	void fillnode(int val, btnode *c, btnode *n, int k);
	void split(int val, btnode *c, btnode *n,
		int k, int *y, btnode **newnode);
	void del(int val);
	int delhelp(int val, btnode *root);
	void clear(btnode *root, int k);
	void copysucc(btnode *root, int i);
	void restore(btnode *root, int i);
	void rightshift(int k);
	void leftshift(int k);
	void merge(int k);
	void show();
	void display(btnode *root, int level = 0);
	void deltree(btnode *root);
	~btree();
};


void btree::insert(int val)
{
	int i;
	btnode *c, *n;
	int flag;
	flag = setval(val, root, &i, &c);
	if (flag)
	{
		n = new btnode(order);
		n->count = 1;
		n->value[1] = i;
		n->child[0] = root;
		n->child[1] = c;
		root = n;
	}
}
int btree::setval(int val, btnode *n, int *p, btnode **c)
{
	int k;
	if (n == nullptr)
	{
		*p = val;
		*c = nullptr;
		return 1;
	}
	else
	{
		if (searchnode(val, n, &k))
			cout << endl << "Key value already exists." << endl;
		if (setval(val, n->child[k], p, c))
		{
			if (n->count < MAX)
			{
				fillnode(*p, *c, n, k);
				return 0;
			}
			else
			{
				split(*p, *c, n, k, p, c);
				return 1;
			}
		}
		return 0;
	}
}
btnode * btree::search(int val, btnode *root, int *pos)
{
	if (root == nullptr)
		return nullptr;
	else
	{
		if (searchnode(val, root, pos))
			return root;
		else
			return search(val, root->child[*pos], pos);
	}
}
int btree::searchnode(int val, btnode *n, int *pos)
{
	if (val < n->value[1])
	{
		*pos = 0;
		return 0;
	}
	else
	{
		*pos = n->count;
		while ((val < n->value[*pos]) && *pos > 1)
			(*pos)--;
		if (val == n->value[*pos])
			return 1;
		else
			return 0;
	}
}
void btree::fillnode(int val, btnode *c, btnode *n, int k)
{
	int i;
	for (i = n->count; i > k; i--)
	{
		n->value[i + 1] = n->value[i];
		n->child[i + 1] = n->child[i];
	}
	n->value[k + 1] = val;
	n->child[k + 1] = c;
	n->count++;
}
void btree::split(int val, btnode *c, btnode *n,
	int k, int *y, btnode **newnode)
{
	int i, mid;

	if (k <= MIN)
		mid = MIN;
	else
		mid = MIN + 1;

	*newnode = new btnode(order);

	for (i = mid + 1; i <= MAX; i++)
	{
		(*newnode)->value[i - mid] = n->value[i];
		(*newnode)->child[i - mid] = n->child[i];
	}

	(*newnode)->count = MAX - mid;
	n->count = mid;

	if (k <= MIN)
		fillnode(val, c, n, k);
	else
		fillnode(val, c, *newnode, k - mid);

	*y = n->value[n->count];
	(*newnode)->child[0] = n->child[n->count];
	n->count--;
}
void btree::del(int val){
	btnode * temp;

	if (!delhelp(val, root))
		cout << endl << "Value " << val << " not found.";
	else
	{
		if (root->count == 0)
		{
			temp = root;
			root = root->child[0];
			delete temp;
		}
	}
}
int btree::delhelp(int val, btnode *root)
{
	int i;
	int flag;

	if (root == nullptr)
		return 0;
	else
	{
		flag = searchnode(val, root, &i);
		if (flag)
		{
			if (root->child[i - 1])
			{
				copysucc(root, i);
				flag = delhelp(root->value[i], root->child[i]);
				if (!flag)
					cout << endl << "Value " << val << " not found.";
			}
			else
				clear(root, i);
		}
		else
			flag = delhelp(val, root->child[i]);
		if (root->child[i] != nullptr)
		{
			if (root->child[i]->count < MIN)
				restore(root, i);
		}
		return flag;
	}
}
void btree::clear(btnode *root, int k)
{
	int i;
	for (i = k + 1; i <= root->count; i++)
	{
		root->value[i - 1] = root->value[i];
		root->child[i - 1] = root->child[i];
	}
	root->count--;
}
void btree::copysucc(btnode *root, int i)
{
	btnode *temp = root->child[i];

	while (temp->child[0])
		temp = temp->child[0];

	root->value[i] = temp->value[1];
}
void btree::restore(btnode *root, int i)
{
	if (i == 0)
	{
		if (root->child[1]->count > MIN)
			leftshift(1);
		else
			merge(1);
	}
	else
	{
		if (i == root->count)
		{
			if (root->child[i - 1]->count > MIN)
				rightshift(i);
			else
				merge(i);
		}
		else
		{
			if (root->child[i - 1]->count > MIN)
				rightshift(i);
			else
			{
				if (root->child[i + 1]->count > MIN)
					leftshift(i + 1);
				else
					merge(i);
			}
		}
	}
}
void btree::rightshift(int k)
{
	int i;
	btnode *temp;

	temp = root->child[k];

	for (i = temp->count; i > 0; i--)
	{
		temp->value[i + 1] = temp->value[i];
		temp->child[i + 1] = temp->child[i];
	}

	temp->child[1] = temp->child[0];
	temp->count++;
	temp->value[1] = root->value[k];
	temp = root->child[k - 1];
	root->value[k] = temp->value[temp->count];
	root->child[k]->child[0] = temp->child[temp->count];
	temp->count--;
}
void btree::leftshift(int k)
{
	btnode *temp;

	temp = root->child[k - 1];
	temp->count++;
	temp->value[temp->count] = root->value[k];
	temp->child[temp->count] = root->child[k]->child[0];
	temp = root->child[k];
	root->value[k] = temp->value[1];
	temp->child[0] = temp->child[1];
	temp->count--;
	for (int i = 1; i <= temp->count; i++)
	{
		temp->value[i] = temp->value[i + 1];
		temp->child[i] = temp->child[i + 1];
	}
}
void btree::merge(int k){
	int i;
	btnode *temp1, *temp2;
	temp1 = root->child[k];
	temp2 = root->child[k - 1];
	temp2->count++;
	temp2->value[temp2->count] = root->value[k];
	temp2->child[temp2->count] = root->child[0];
	for (i = 1; i <= temp1->count; i++)
	{
		temp2->count++;
		temp2->value[temp2->count] = temp1->value[i];
		temp2->child[temp2->count] = temp1->child[i];
	}
	for (i = k; i < root->count; i++)
	{
		root->value[i] = root->value[i + 1];
		root->child[i] = root->child[i + 1];
	}
	root->count--;
	delete temp1;
}
void btree::show()
{
	display(root);
}


void btree::display(btnode *root, int level){
	int i, k;
	static int previousLevel;
	if (level == 0){
		previousLevel = 0;
	}
	else if (level != previousLevel){
		cout << endl;
		previousLevel = level;
	}
	if (root != nullptr)
	{
		cout << "[ ";
		k = root->count;
		for (i = 0; i < k; i++){
			cout << root->value[i + 1];
			if (i < k - 1)
				cout << " | ";
			else cout << "]\t";
		}
		for (i = 0; i <= k; i++){
			if ((root->child[i]) != nullptr && ((root->child[i]->count) > 0))
				display(root->child[i], level + 1);
		}
	}
}
void btree::deltree(btnode *root)
{
	int i;
	if (root != nullptr)
	{
		for (i = 0; i < root->count; i++)
		{
			deltree(root->child[i]);
			delete (root->child[i]);
		}
		deltree(root->child[i]);
		delete (root->child[i]);
	}
}

btree :: ~btree()
{
	deltree(root);
}
class improvedBtree : public btree{
private:
	vector<queue<btnode*> *> displayQueues;
	void display(btnode *treePtr, int level){
		int i, k;
		static int previousLevel;

		if (level == 0){
			previousLevel = 0;
		}
		else if (level != previousLevel){
			previousLevel = level;
		}
		if (level >= displayQueues.size()){
			displayQueues.push_back(new queue<btnode*>);
		}
		if (treePtr != nullptr){
			queue<btnode*> *qptr = displayQueues[level];
			qptr->push(treePtr);

			k = treePtr->count;
			for (i = 0; i <= k; i++){
				if ((treePtr->child[i]) != nullptr && ((treePtr->child[i]->count) > 0))
					display(treePtr->child[i], level + 1);
			}
		}
	}
public:
	improvedBtree(int order = 5) :btree(order){}
	void show(){
		display(root, 0);

		int j, k, nlevs = displayQueues.size();

		for (int i = 0; i < nlevs; i++){
			queue<btnode*> *qptr = displayQueues[i];
			cout << "Level " << i << ": ";
			while (!qptr->empty()){
				btnode* ndptr = qptr->front();
				qptr->pop();
				k = ndptr->count;
				cout << "[";
				for (j = 0; j < k; j++){
					cout << ndptr->value[j + 1];
					if (j < k - 1)
						cout << "|";
					else cout << "] ";
				}
			}
			cout << endl;
		}
		displayQueues.clear();
	}
};