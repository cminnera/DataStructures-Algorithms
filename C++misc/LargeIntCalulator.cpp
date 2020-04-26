//Clare Minnerath

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

typedef stack<int> lgInt;
bool getLargeNumber(lgInt &ln, string numStr = "");
lgInt addLargeNumbers(lgInt op1, lgInt op2); 
void putLargeNumber(lgInt ln, string msg = "");
lgInt multLargeNumbers(lgInt op1, lgInt op2);
lgInt powLargeNumbers(lgInt op1, lgInt op2);
lgInt subLargeNumbers(lgInt op1, lgInt op2, vector<string> &e);
lgInt divLargeNumbers(lgInt op1, lgInt op2, lgInt &rem, vector<string> &e);
void errors(vector<string> e);
bool greaterEqual(lgInt op1, lgInt op2);

class calculator
{
public:
	lgInt accumulator;
	lgInt remainder;
	vector<string> errors;
};

bool greaterEqual(lgInt op1, lgInt op2)
{
	if (op1.size() > op2.size())
		return true;
	else if (op1.size() < op2.size())
		return false;

	lgInt o1;
	lgInt o2;

	while (!op1.empty() && !op2.empty())
	{
		o1.push(op1.top());
		o2.push(op2.top());
		op1.pop();
		op2.pop();
	}

	while (!o1.empty() && !o2.empty())
	{
		if (o1.top() > o2.top())
			return true;
		else if (o2.top() > o1.top())
			return false;
		else
			o1.pop();
			o2.pop();
	}

	return true;
}

void errors(vector<string> e)
{
	cout << endl;
	cout << "Error Log: " << endl;
	for (int i = 0; i < e.size(); i++)
	{
		cout << e[i] << endl;
	}
	if (e.size() == 0)
		cout << "There are no errors\n";
}

lgInt divLargeNumbers(lgInt op1, lgInt op2, lgInt &rem, vector<string> &e)
{
	if (op2.size() == 1 && op2.top() == 0)
	{
		e.push_back("Error: can't divide by zero\n");
		return op1;
	}
	lgInt num, resultStack, resultStackReversed, rtemp;
	lgInt count;
	lgInt inc;
	bool ok;
	ok = getLargeNumber(count, "0");
	ok = getLargeNumber(inc, "1");
	while (greaterEqual(op1, op2))
	{
		op1 = subLargeNumbers(op1, op2, e);
		count = addLargeNumbers(count, inc);
	}

	if (!op1.empty())
	{
		while (!rem.empty())
			rem.pop();
		while (!op1.empty())
		{
			rtemp.push(op1.top());
			op1.pop();
		}
		while (!rtemp.empty())
		{
			rem.push(rtemp.top());
			rtemp.pop();
		}
	}

	return count;
}

lgInt subLargeNumbers(lgInt op1, lgInt op2, vector<string> &e)
{
	if (!greaterEqual(op1, op2))
	{
		e.push_back("Error: Would result in negative\n");
		return op1;
	}
	lgInt resultStack, resultStackReversed;
	int digitSum, ntop, count = 0;
	while (!op1.empty() || !op2.empty())
	{
		digitSum = 0;
		if (!op1.empty())
		{
			digitSum += op1.top(); op1.pop();
		}
		if (!op2.empty() && digitSum >= op2.top())
		{
			digitSum -= op2.top(); op2.pop();
		}
		else if (!op2.empty())
		{
			digitSum += 10;
			while (op1.top() == 0)
			{
				op1.pop();
				count++;
			}
			ntop = op1.top() - 1;

			op1.pop();
			op1.push(ntop);
	
			for (int c = 0; c < count; c++)
				op1.push(9);
			digitSum -= op2.top(); op2.pop();
		}

		resultStack.push(digitSum);


	}

	while (resultStack.top() == 0 && !resultStack.empty() && resultStack.size() != 1)
		resultStack.pop();

	while (!resultStack.empty())
	{
		resultStackReversed.push(resultStack.top());
		resultStack.pop();
	}
	return resultStackReversed;
}

lgInt powLargeNumbers(lgInt op1, lgInt op2)
{
	bool ok;
	lgInt num;
	int i;
	ok = getLargeNumber(num, "1");
	int count = 0;
	while (!op2.empty())
	{
		i = op2.top() * ((int)pow(10, count));
		op2.pop();
		for (i; i > 0; i--)
		{
			num = multLargeNumbers(op1, num);
		}
		count++;
	}
	return num;
}

lgInt multLargeNumbers(lgInt op1, lgInt op2)
{
	bool ok;
	lgInt num;
	int i;
	ok = getLargeNumber(num, "0");
	int count = 0;
	while (!op2.empty())
	{
		i = op2.top() * ((int)pow(10, count));
		op2.pop();
		for (i; i > 0; i--)
		{
			num = addLargeNumbers(op1, num);
		}
		count++;
	}
	return num;
}

lgInt addLargeNumbers(lgInt op1, lgInt op2){
	lgInt resultStack, resultStackReversed;
	int carry, digitSum, unitPart;
	carry = 0;
	while (!op1.empty() || !op2.empty())
	{
		digitSum = carry;
		if (!op1.empty())
		{
			digitSum += op1.top(); op1.pop();
		}
		if (!op2.empty())
		{
			digitSum += op2.top(); op2.pop();
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

bool getLargeNumber(lgInt &ln, string numStr)
{
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

void putLargeNumber(lgInt ln, string msg)
{
	cout << msg;
	vector <int> digits;
	while (!ln.empty())
	{
		digits.insert(digits.begin(), ln.top());
		ln.pop();
	}

	for (auto d : digits)
		cout << d;
	cout << endl;
}

int main(void)
{
	char option;

	lgInt n1, sum;
	lgInt Sum, n2;
	int count = 0;
	bool ok1;
	calculator c;

	cout << "Enter num: " << endl;
	ok1 = getLargeNumber(c.accumulator);

	cout << "Option? (C,E,S,+,-,*,/,%,^) : ";
	cin >> option;

	if (option == 'S')
	{
		return 0;
	}

	while (true)
	{
		switch (option)
		{
		case 'C':
			putLargeNumber(c.accumulator, "The accumulated value is: ");
			cout<< endl;
			break;
		case 'E':
			errors(c.errors);
			break;
		case '+':
			cout << "Enter num: " << endl;
			ok1 = getLargeNumber(n1);
			c.accumulator = addLargeNumbers(n1, c.accumulator);
			break;
		case '-':
			cout << "Enter num: " << endl;
			ok1 = getLargeNumber(n1);
			c.accumulator = subLargeNumbers(c.accumulator, n1, c.errors);
			break;
		case '*':
			cout << "Enter num: " << endl;
			ok1 = getLargeNumber(n1);
			c.accumulator = multLargeNumbers(n1, c.accumulator);
			break;
		case '/':
			cout << "Enter num: " << endl;
			ok1 = getLargeNumber(n1);
			c.accumulator = divLargeNumbers(c.accumulator, n1, c.remainder, c.errors);
			count++;
			break;
		case '%':
			if (count > 0)
				c.accumulator = c.remainder;
			else
				ok1 = getLargeNumber(c.accumulator, "0");
			break;
		case '^':
			cout << "Enter num: " << endl;
			ok1 = getLargeNumber(n1);
			c.accumulator = powLargeNumbers(c.accumulator, n1);
			break;
		case 'S':
			return 0;
		default:
			cout << "Incorrect input try again.\n";
			break;
		}

		cout << "Option? (C,E,S,+,-,*,/,%,^) : ";
		cin >> option;
	}

	return 0;
}