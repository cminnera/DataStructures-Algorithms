//Clare
//Lab 6 Part1

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "dateClass.h"
#include "genBST.h"
using namespace std;

class patron;
class book{
private:
	string title;
	patron *borrower;
	cDate dueDate;
public:
	// implement constructor(s), predicate(s), and appropriate getters:
	book(string t = "") :
		title(t), borrower(nullptr){}
	bool available()
	{
		if (borrower == nullptr)
			return true;
		else
			return false;
	}
	string getTitle()
	{
		return title;
	}

	void due(cDate &today)
	{
		dueDate = today;
		for (int i = 0; i < 14; i++)
			++dueDate;
	}
	cDate getDue()
	{
		return dueDate;
	}

	// implement methods to allow a book to be borrowed, and to be checked in.
	bool borrow(patron* requester, cDate& takeOutDate)
	{
		if (!available())
			return false;
		borrower = requester;
		due(takeOutDate);
		return true;

	}
	patron* checkIn()
	{
		patron* temp = borrower;
		borrower = nullptr;
		return temp;
	}
	friend bool operator==(const book& b1, const book& b2)
	{
		if (b1.title == b2.title)
			return true;
		else
			return false;
	}
	friend bool operator<(const book& b1, const book& b2)
	{
		int n = 0;
		while (n < b1.title.size() && n < b2.title.size())
		{
			if (b1.title.substr(n, 1) < b1.title.substr(n, 1))
				return true;
			else
				n++;
		}
		return false;
	}
	friend ostream& operator<<(ostream& o, book& b){
		o << b.title << endl;
		return o;
	}
};
class patron{
	string name;
	list<book> borrowedBooks; // This is the ONLY container allowed
public:
	// implement constructor(s), predicate(s), and appropriate getter(s):
	patron(string nm = "") :name(nm){}
	bool hasBook(book bk)
	{
		for (auto v : borrowedBooks)
		{
			if (bk == v)
				return true;
		}
		return false;
	}
	string getName()
	{
		return name;
	}
	// implement methods for borrowing, returning, and displaying books
	void borrowBook(book bk)
	{
		borrowedBooks.push_back(bk);
	}
	bool returnBook(book bk)
	{
		for (auto v : borrowedBooks)
		{
			if (bk == v)
			{
				borrowedBooks.remove(v);
				return true;
			}
		}
		return false;
	}
	void showBooks()
	{
		if (borrowedBooks.empty())
			cout << "None. \n";
		for (auto v : borrowedBooks)
		{
			cout << v << " due " << v.getDue() << endl;
		}
	}
	friend bool operator==(const patron& p1, const patron& p2)
	{
		if (p1.name==p2.name)
			return true;
		else
			return false;
	}
	friend bool operator<(const patron& p1, const patron& p2)
	{
		int n = 0;
		while (n < p1.name.size() && n < p2.name.size())
		{
			if (p1.name.substr(n, 1) < p2.name.substr(n, 1))
				return true;
			else
				n++;
		}
		return false;
	}
	friend ostream& operator<<(ostream& o, patron& p){
		o << "Patron: " << p.name << endl;
		return o;
	}
};

class bookBST : public BST < book > {
	virtual void visit(BSTNode<book>* p) {
		book& bk = p->el;
		if (visitAll){
			cout << bk << endl;
		}
		else if (!bk.available()){
			cout << bk.getTitle() << " due " << bk.getDue() << endl;
		}
	}
	bool visitAll = false;
};



int main(void)
{
	ifstream file;
	string line;
	char choice;
	cDate todaysDate;
	cout << todaysDate << endl;
	cDate tomorrowDate = todaysDate;
	patron tmpP;
	book tmpB;
	tomorrowDate++;
	BST<patron> patronTree;
	string name;
	string bookName;
	BST<book> booktree;
	vector<patron> borrowers;

	file.open("patrons.txt");
	while (getline(file, line))
	{
		patron p = patron(line);
		patronTree.insert(p);
	}
	file.close();

	file.open("books.txt");
	while (getline(file, line))
	{
		string str = " by";
		char *cstr = &str[0u];
		size_t prev = 0, pos;
		pos = line.find(str, prev);
		if (pos > prev){
			booktree.insert(line.substr(prev, pos - prev));
			}
		
		
	}
	file.close();

	cout << "The library is opening - it is " << todaysDate << endl;
	cout << "Library options " << endl;
	cout << "		H  => Help" << endl;
	cout << "		T ==> Take a book out" << endl;
	cout << "		R ==> Return a book" << endl;
	cout << "		P ==> List books that a specified patron has out" << endl;
	cout << "		B ==> List all books in the library" << endl;
	cout << "		O ==> List the books that are out" << endl;
	cout << "		C ==> Close for the day" << endl;
	cout << "		Q ==> Quit the simulation" << endl;

	do {
		bool found = false;
		cout << endl << "? "; cin >> choice;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (toupper(choice)){
		case 'T':
			cout << "Enter the patron's name: ";
			cin >> name;
			tmpP = patron(name);
			getline(cin, bookName);
			if (patronTree.search(tmpP) == nullptr)
			{
				cout << "The patron is not in the list.\n";
				break;
			}
			else
			{
				cout << "Enter the book title: ";
				getline(cin, bookName);
				tmpB = book(bookName);
				if (booktree.search(tmpB) == nullptr)
				{
					cout << "The book is not in the list.\n";
					break;
				}
				else
				{
					if (booktree.search(tmpB)->borrow(patronTree.search(tmpP), todaysDate))
					{
						cout << bookName << " is now checked out to " << name << endl;
						book b1 = *booktree.search(tmpB);
						patronTree.search(tmpP)->borrowBook(b1);
						bool isthere = false;
						for (auto p : borrowers)
						{
							if (tmpP == p)
								isthere = true;
						}
						if (!isthere)
							borrowers.push_back(tmpP);
					}
					else
					{
						cout << "Sorry, " << bookName << " is already checked out!\n";
						cout << "It is due back, " << booktree.search(tmpB)->getDue() << endl;
					}
				}

			}

			break;
		case 'C':
			cout << "Closing for the evening...." << endl;
			cout << "Opening again on " << tomorrowDate << endl;
			todaysDate = tomorrowDate;
			tomorrowDate++;
			break;
		case 'Q':
			cout << "Ending the simulation" << endl;
			break;
		case 'R':
			cout << "Enter the book title: ";
			getline(cin, bookName);
			tmpB = book(bookName);
			if (booktree.search(tmpB) == nullptr)
			{
				cout << "The book is not in the list.\n";
				break;
			}
			else
			{
				book b = *booktree.search(tmpB);
				patron* pat;
				pat = b.checkIn();
				if (pat->returnBook(tmpB))
					cout << tmpB << " has been checked in.\n";
			}
			break;
		case 'P':
			cout << "Enter the patron's name: ";
			cin >> name;
			tmpP = patron(name);
			getline(cin, bookName);
			if (patronTree.search(tmpP) == nullptr)
			{
				cout << "The patron is not in the list.\n";
				break;
			}
			else
			{
				cout << "Books checked out by " << name <<": "<< endl;
				patronTree.search(tmpP)->showBooks();
				cout << endl;
			}
			break;
		case 'O':
			cout << "Books that are checked out: " << endl;
			for (auto p : borrowers)
			{
				patronTree.search(p)->showBooks();
			}
			cout << endl;
			break;
		case 'B':
			cout << "All books in the Library: \n";
			booktree.inorder();
			break;
		case 'H':
			cout << "Library options " << endl;
			cout << "		H  => Help" << endl;
			cout << "		T ==> Take a book out" << endl;
			cout << "		R ==> Return a book" << endl;
			cout << "		P ==> List books that a specified patron has out" << endl;
			cout << "		B ==> List all books in the library" << endl;
			cout << "		O ==> List the books that are out" << endl;
			cout << "		C ==> Close for the day" << endl;
			cout << "		Q ==> Quit the simulation" << endl;
			break;
		default:
			cout << "Invalid input. " << endl;
			break;
		}
	} while (choice != 'Q' && choice != 'q');

	return 0;
}
