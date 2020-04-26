//Clare Minnerath
//Lab 5 Part 1

#include <PCDraw.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void findArea(int &count, int row, int col, int N, int M, vector<string> &lines);

void findArea(int &count, int row, int col, int N, int M, vector<string> &lines)
{
	if (lines[row].substr(col, 1) == "W")
	{
		count++;
		lines[row].replace(col, 1, "B");
		if (row + 1 <= M)
			findArea(count, row + 1, col, N, M, lines);
		if (col + 1 < N)
			findArea(count, row, col + 1, N, M, lines);
		if (col - 1 >= 0)
			findArea(count, row, col - 1, N, M, lines);
	}
}

int main(void)
{
	int m, n, x, y, xi, yi;
	string filename;
	string line;
	vector<string> inputLines;
	vector<string> inputLines2;

	cout << "Enter file name: ";
	cin >> filename;

	ifstream input;

	if (filename.find(".txt") == -1)
	{
		filename += string(".txt");
	}

	input.open(filename);

	if (input.fail())
	{
		cout << "Error Opening File.\n";
		exit(1);
	}

	input >> m;
	input >> n;


	for (int i = 0; i < inputLines.size(); i++)
	{
		cout << inputLines[i] << endl;
	}

	while (getline(input, line))
	{
		inputLines.push_back(line);
		inputLines2.push_back(line);
	}

	InitGraphics("Upper Left");
	SetPenColor("Black");
	
	x = 624 / m;
	y = 260 / n;
	if (x < y)
		y = x;
	if (y < x)
		x = y;

	xi = 0;
	yi = 0;

	for (int r = 0; r < m; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (inputLines[r + 1].substr(0, 1) == "B")
				DrawBar(xi, yi, xi + x, yi + y);
			else
				DrawBox(xi, yi, xi + x, yi + y);

			inputLines[r + 1].erase(inputLines[r + 1].begin());
			xi += x;
		}
			
		yi += y;
		xi = 0;
	}


	int count = 0;
	int countA = 0;
	int cols = 0;
	int rows = 1;
	bool notDone = true;

	while (notDone)
	{
		if (inputLines2[rows].substr(cols, 1) == "B")
		{
			if (cols == n - 1)
			{
				cols = 0;
				if (rows == m - 1)
				{
					notDone = false;
					break;
				}
				else
					rows++;
			}
			else
				cols++;
		}
		else
		{
			countA++;
			findArea(count, rows, cols, n, m, inputLines2);
			cout << "Area of size " << count << " starting at (" << rows - 1 << ", " << cols << ")" << endl;
			count = 0;

		}
	}
	cout << "There are " << countA << " white areas." << endl;

	
	return 0;
}