//Clare Minnerath

#include <iostream>
#include <list>
#include <iomanip>
#include <string>
using namespace std;


class frac{
private:
	int numer;
	int denom;
	double value;
	void reduce(){
		//cout << "reduce ... "; // FOR DEBUGGING PURPOSES ONLY
		int divisor = 2;
		while (divisor <= denom){
			if (numer%divisor == 0 && denom%divisor == 0){
				numer /= divisor; denom /= divisor;
			}
			else divisor++;
		}
	}
public:
	frac(int n = 1, int d = 1) :numer(n), denom(d), value(double(n) / double(d)){ reduce(); }
	bool satisfiesCondition(int level){
		return (value >= 0 && value <= 1 && denom <= level);
	}
	bool isOne(){
		return ((numer == 1) && (denom == 1));
	}
	bool operator<(frac& other){
		return numer*other.denom < denom*other.numer;
	}
	friend ostream& operator<<(ostream& o, frac& f){
		o << f.numer << "/" << f.denom;
		return o;
	}
	frac(frac lefty, frac righty)
	{
		numer = lefty.numer + righty.numer;
		denom = lefty.denom + righty.denom;
		value = double(numer) / double(denom);
		reduce();
	}
	int plusDenom(frac& other)
	{
		return (denom + other.denom);
	}

};

void extend(list<frac> &F, int level);
void printList(list<frac> &fractions, string type);

void extend(list<frac> &F, int level)
{
	list<frac>::iterator curr, next;
	for (list<frac>::iterator fit = F.begin();;)
	{
		curr = fit; next = ++fit;
		if (curr == F.end() || next == F.end())
			break;
		if (curr->plusDenom(*next) <= level)
		{
			//cout<< "Insert between " << *curr << " and " << *next << endl;
			F.insert(next, frac(*curr, *next));
		}
	}
}

void printList(list<frac> &fractions, string type)
{
	cout << type << " = {";
	for (auto f : fractions)
		cout << f << ", ";
	cout << "\b\b }\n";

}

//int main(void)
//{
//	frac test1(8, 16), test2(3, 4), test3(3, 8), test4(9, 12), test5(1, 1);
//	//frac test1={8, 16}, test2={3, 4}, test3={3, 8}, test4={9, 12}, test5={1, 1};
//	cout << endl;
//	frac test[] = { test1, test2, test3, test4, test5 };
//	int level = 7;
//	for (auto t : test)
//		if (!t.satisfiesCondition(level))
//			cout << t << " does not satisfy the Farey Condition for level " << level << endl;
//	cout << test1 << (test1 < test2 ? " isless than " : " is NOT less than ") << test2 << endl;
//	if (!test5.isOne())
//		cout << "Oops..." << test5 << " failed the isOne() predicate\n";
//	else
//		cout << test5 << " is 1" << endl;
//
//	cout << "A (non-Farey) list of fractions " << " = {";
//	for (auto f : test)
//		cout << f << ", ";
//	cout << "\b\b }\n";
//
//	return 0;
//}

int main(void)
{
	int i, n;
	char buffer[32];
	cout << "Enter max level for the Farey Sequence: ";
	cin >> n;

	list<frac> fseq = { frac(0, 1), frac(1, 1) };
	printList(fseq, "F1");
	for (i = 2; i <= n; i++)
	{
		extend(fseq, i);
		sprintf_s(buffer, 32, "%d", i);
		printList(fseq, "F" + string(buffer));
	}

	return 0;
}