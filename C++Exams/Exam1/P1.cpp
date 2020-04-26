// CSC 103 Exam 1 Part 2 Fall 2017
// Problem 1

//Clare Minnerath

#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main(void){
	stack<string> revline;
	const string jabberwocky[] = {
		"'Twas brillig, and the slithy toves ",
		"Did gyre and gimble in the wabe: ",
		"All mimsy were the borogoves, ",
		"And the mome raths outgrabe ",
		"He took his vorpal sword in hand; ",
		"Long time the manxone foe he sought ",
		"So rested he by the Tuntum tree ",
		"And stood awhile in thought. " };
	cout << "The Jabberwocky by Lewis Carroll\n\n";
	for (const string s : jabberwocky){
		string word;
		istringstream ins = istringstream(s);
		while (!ins.fail())
		{
			getline(ins, word, ' ');
			revline.push(word);
		}
		while (!revline.empty())
		{
			cout << revline.top() << " ";
			revline.pop();
		}
		cout << endl;
	}
	return 0;
}
