// pqueue_pop.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main()
{
	using namespace std;
	priority_queue <int> q1, s2;

	q1.push(10);
	q1.push(20);
	q1.push(30);

	priority_queue <int>::size_type i, iii;
	i = q1.size();
	cout << "The priority_queue length is " << i << "." << endl;

	const int& ii = q1.top();
	cout << "The element at the top of the priority_queue is "
		<< ii << "." << endl;

	q1.pop();

	iii = q1.size();
	cout << "After a pop, the priority_queue length is "
		<< iii << "." << endl;

	const int& iv = q1.top();
	cout << "After a pop, the element at the top of the "
		<< "priority_queue is " << iv << "." << endl;
}