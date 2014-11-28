#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>
#include "Book.h"
#include "Bookstore.h"

using namespace std;

//*****************************************************************************
// Method Function: Ensures the file can be opened and read safely.
// Preconditions: The ifstream has been opened.
// Postconditions: None
//*****************************************************************************
void OpenFile(ifstream &in_File);

int main()
{
	Bookstore store;

	int isbn;
	string author, title;
	double cost;

	return 0;
}