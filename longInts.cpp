//Clare Minnerath

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int notmain(void)
{
	unsigned long long alonginteger;
	cout << sizeof(alonginteger) << " is the size in bytes\n";

	cout << "2^32 - 1 = " << ((unsigned int)pow(2, 32) - 1) << endl;

	union upperRange
	{
		unsigned char bytes[8];
		unsigned long long n;
	};

	upperRange maxVal;
	for (auto &b : maxVal.bytes)
	{
		b = 255;
	}
	cout << "Largest unsigned long long = " << maxVal.n << endl;

	

	return 0;
}

// We need a way to represent (and do I/O) for a "large number:
	typedef stack<int> lgInt;
	bool getLargeNumber(lgInt &ln, string numStr = "");
	void putLargeNumber(lgInt ln, string msg = "");

	int main(void){
		lgInt op;
		cout << "Enter a large number: ";
		if (getLargeNumber(op)){
			putLargeNumber(op, "The large number = ");
		}
		else {
			cout << "Error entering the large number\n";
		}
		return 0;
	}
	bool getLargeNumber(lgInt &ln, string numStr){
		// TODO - put the body here
		while (!ln.empty())
			ln.pop();
		if (numStr == "")
			cin >> numStr;
		for (char c : numStr)
		{
			if (!isdigit(c))
				return false;
			else
				ln.push(c - '0');
		}
		return true;
	}
	// Output the most significant digits first
	void putLargeNumber(lgInt ln, string msg){
		// TODO - put the body here
		cout << msg;
		vector<int> digits;
		while (!ln.empty())
		{
			digits.insert(digits.begin(), ln.top());
			ln.pop();
		}
		for (auto d : digits)
			cout << d;
		cout << endl;
	}


	// We need a way to represent (and do I/O) for a "large number:
	//typedef stack<int> lgInt;
	//bool getLargeNumber(lgInt &ln, string numStr = "");
	//void putLargeNumber(lgInt ln, string msg = "");
	lgInt addLargeNumbers(lgInt op1, lgInt op2);
	int nottmain(void){
		lgInt n1, n2, sum;
		bool ok1, ok2;
		cout << "Enter two large numbers:\n? ";
		ok1 = getLargeNumber(n1);
		cout << "? ";
		ok2 = getLargeNumber(n2);
		if (ok1 && ok2){
			sum = addLargeNumbers(n1, n2);
			putLargeNumber(sum, "The sum is ");
		}
		else {
			cout << "Error in input\n";
		}
		return 0;
	}
	lgInt addLargeNumbers(lgInt op1, lgInt op2){
		// TODO Complete the body here
		lgInt resultStack, resultStackReversed;
		int carry, digitSum, unitPart;
		carry = 0;
		while (!op1.empty() || !op2.empty())
		{
			digitSum = carry;
			if (!op1.empty())
			{
				digitSum += op1.top();
				op1.pop();
			}
			if (!op2.empty())
			{
				digitSum += op2.top();
				op2.pop();

			}
			unitPart = digitSum % 10;
			carry = digitSum / 10;
			resultStack.push(unitPart);
		}
		if (carry != 0)
			resultStack.push(carry);
		while (!resultStack.empty())
		{
			resultStackReversed.push(resultStack.top());
			resultStack.pop();
		}
		return resultStackReversed;
	}