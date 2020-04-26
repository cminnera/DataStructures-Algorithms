//************************  genSLList.h  **************************
// singly-linked list class to store a generic type T
/* Modifications to the Original Version:
(1) use nullptr instead  
is less vulnerable to misuse and works better in most situations.
https://msdn.microsoft.com/en-us/library/jj651642(v=vs.120).aspx
(2) return true or false from predicateisEmpty()
*/
#ifndef GEN_LINKED_LIST
#define GEN_LINKED_LIST
#include <iostream>
using namespace std;

template<class T>
class SLLNode {
public:
    SLLNode() {
        next = 0;
    }
    SLLNode(T el, SLLNode *ptr = nullptr) {
        info = el; next = ptr;
    }
    T info;
    SLLNode *next;
};
template<class T>
class SLList {
public:
    SLList() {
		head = tail = nullptr;
    }
    ~SLList();
    bool isEmpty() {
		return head == nullptr;
    }
    void addToHead(T);
    void addToTail(T);
    T  deleteFromHead(); // delete the head and return its info;
    T  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(T);
//    bool isInList(T) const;  // Modify to return a pointer to what's there if it is found
	T* isInList(T) const;
	void printAll() const;
	int size() const;


private:
    SLLNode<T> *head, *tail;
};
template<class T>
SLList<T>::~SLList() {
	for (SLLNode<T> *p; !isEmpty();) {
		p = head->next;
		delete head;
		head = p;
	}
}
template<class T>
void SLList<T>::addToHead(T el) {
	head = new SLLNode<T>(el, head);
	if (tail == nullptr)
		tail = head;
}
template<class T>
void SLList<T>::addToTail(T el) {
	if (tail != nullptr) {      // if list not empty;
		tail->next = new SLLNode<T>(el);
		tail = tail->next;
	}
	else head = tail = new SLLNode<T>(el);
}
template<class T>
T SLList<T>::deleteFromHead() {
	T el = head->info;
	SLLNode<T> *tmp = head;
	if (head == tail)     // if only one node on the list;
		head = tail = nullptr;
	else head = head->next;
	delete tmp;
	return el;
}
template<class T>
T SLList<T>::deleteFromTail() {
	T el = tail->info;
	if (head == tail) {   // if only one node on the list;
		delete head;
		head = tail = nullptr;
	}
	else {                // if more than one node in the list,
		SLLNode<T> *tmp; // find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;      // the predecessor of tail becomes tail;
		tail->next = nullptr;
	}
	return el;
}
template<class T>
void SLList<T>::deleteNode(T el) {
	if (head != nullptr)                     // if non-empty list;
		if (head == tail && el == head->info) { // if only one
			delete head;                       // node on the list;
			head = tail = nullptr;
		}
		else if (el == head->info) {  // if more than one node on the list
			SLLNode<T> *tmp = head;
			head = head->next;
			delete tmp;              // and old head is deleted;
		}
		else {                        // if more than one node in the list
			SLLNode<T> *pred, *tmp;
			for (pred = head, tmp = head->next; // and a non-head node
				tmp != nullptr && !(tmp->info == el);// is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != nullptr) {
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
}
/*
template<class T>
bool SLList<T>::isInList(T el) const {
	SLLNode<T> *tmp;
	for (tmp = head; tmp != nullptr && !(tmp->info == el); tmp = tmp->next);
	return tmp != nullptr;
}
*/
template<class T>
T* SLList<T>::isInList(T el) const {
	SLLNode<T> *tmp;
	for (tmp = head; tmp != nullptr && !(tmp->info == el); tmp = tmp->next);
	if (tmp != nullptr)
		return &tmp->info;
	return nullptr;
}
template<class T>
void SLList<T>::printAll() const {
	for (SLLNode<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
		cout << tmp->info << " ";
	cout << endl;
}
template<class T>
int SLList<T>::size() const {
	int count = 0;
	for (SLLNode<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
		count++;
	return count;
}

#endif
