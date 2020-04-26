// Drozdek's Chessboard code
// Does NOT take symmetry into account
// https://en.wikipedia.org/wiki/Eight_queens_puzzle
#include <iostream>
#include <string>
using namespace std;

bool seeSolutions = true;

class ChessBoard {
public:
    ChessBoard();    // 8 x 8 chessboard;
    ChessBoard(int); // n x n chessboard;
    void findSolutions();
private:
    const bool available;
    const int squares, norm;
    bool *column, *leftDiagonal, *rightDiagonal;
	int  *positionInRow;
	unsigned long howMany;
    void putQueen(int);
    void printBoard(ostream&);
    void initializeBoard();
};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1) {
    initializeBoard();
}
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
    initializeBoard();
}
void ChessBoard::initializeBoard() {
    register int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal  = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];
    for (i = 0; i < squares; i++)
        positionInRow[i] = -1;
    for (i = 0; i < squares; i++)
        column[i] = available;
    for (i = 0; i < squares*2 - 1; i++)
        leftDiagonal[i] = rightDiagonal[i] = available;
    howMany = 0;
}
void ChessBoard::printBoard(ostream& out) { // LMW
	if (!seeSolutions)
		return;
	int i, j;
	cout << "Solution found:\n";
	for (i = 0; i < squares; i++){
		for (j = 0; j < squares; j++) cout << "----";
		cout << "-\n";
		for (j = 0; j < squares; j++)
			if (positionInRow[i] == j)
				cout << "| Q ";
			else
				cout << "|   ";
		cout << "|\n";
	}
	for (j = 0; j < squares; j++) cout << "----";
	cout << "-\n";
}

void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++)
        if (column[col] == available &&
            leftDiagonal [row+col] == available &&
            rightDiagonal[row-col+norm] == available) {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;
            if (row < squares-1)
                 putQueen(row+1);
			else{
				printBoard(cout); 
				howMany++;         // LMW
			}
            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        }
}
void ChessBoard::findSolutions() {
    putQueen(0);
    cout << howMany << " solutions found.\n";
}

int main() {
	int dim;
	string seeEm;
	cout << "Enter dimension and Y/N for seeing the solutions: ";
	cin >> dim >> seeEm;
	seeSolutions = (toupper(seeEm[0]) == 'Y');
	cout << "Find solutions to the " << dim << "-Queens problem:\n";
    ChessBoard board(dim);
    board.findSolutions();
    return 0;
}
