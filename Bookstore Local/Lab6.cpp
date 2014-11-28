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

//*****************************************************************************
// Method Function: Ensures the file can be opened and read safely.
// Preconditions: The ofstream has been opened.
// Postconditions: None
//*****************************************************************************
void OpenFile(ofstream &out_File);

//*****************************************************************************
// Method Function: Takes first character of string and determines operation to
//					be performed. Rest of string is appropriate options for each
//					option.
// Precondition: String is formatted approrpriately and is parsable.
//				 Second parameter is declared bookstore object.
// Postcondition: Method calls other appropriate methods.
//
// Options: 1 - Create inventory (from provided file)
//			2 - Add a book
//			3 - Delete a book
//			4 - Retrieve a book and print information about it.
//			5 - Update a book.
//			6 - Print the inventory in ascending order.
//			7 - Quit
//*****************************************************************************
void MenuCall(string operationCall, Bookstore bookstore);

//*****************************************************************************
// Method Function: Takes first character of string and determines operation to
//					be performed. Rest of string is appropriate options for each
//					option. Operator overloaded for integers.
// Precondition: Integer for choice.
//				 Second parameter is declared bookstore object.
// Postcondition: Method calls other appropriate methods.
//
// Options: 1 - Create inventory (from provided file)
//			2 - Add a book
//			3 - Delete a book
//			4 - Retrieve a book and print information about it.
//			5 - Update a book.
//			6 - Print the inventory in ascending order.
//			7 - Quit
//*****************************************************************************
void MenuCall(int choice, Bookstore bookstore, ofstream &out);

int main()
{
	Bookstore store;
	int isbn;
	string author, title;
	double cost;
	ofstream out;

	OpenFile(out);
	out.open("out.txt");

	out << "Create the Database\n";
	out << "---------------------\n";
	out << endl;
	MenuCall("1, bookInput.txt", store);

	out << "add a book\n";
	out << "------------\n";
	out << endl;
	MenuCall("2, 667788,	Intro to Java, Daniel Ling, 150", store);
	MenuCall("4, 667788", store);

	out << "Delete a book\n";
	out << "---------------\n";
	out << endl;
	MenuCall("3, 23456", store);

	out << "Retrieve a book and print it.\n";
	out << "---------------\n";
	out << endl;
	MenuCall("4, 23456", store);	// if the book is not in the database
									// give an appropriate message

	out << "Retrieve a book and print it.\n";
	out << "---------------\n";
	out << endl;
	MenuCall("4, 34567", store);

	out << "Update the store cost.\n";
	out << "------------------------\n";
	out << endl;
	MenuCall("5, 45678, 250", store);
	MenuCall("4, 45678", store);

	out << "Print the database in ascending order. \n";
	out << "---------------------------------------\n";
	out << endl;
	MenuCall("6", store);

	out << "Quit\n";
	out << "-------\n";
	out << endl;
	MenuCall(7, store, out);


	return 0;
}

void OpenFile(ifstream &in_stream)
{
	if (in_stream.fail())
	{
		cout << "Cannot open file." << endl;
		exit(1);	// kill program
	}
}

void OpenFile(ofstream &out)
{
	if (out.fail())
	{
		cout << "Cannot open output file." << endl;
		exit(1);
	}
}

void MenuCall(string operationCall, Bookstore store)
{
	// We need to get the choice which will be the first character,
	// cast it to an integer
	string delimter = ",", token;
	string inputLine, isbn, author, title, price;
	int iISBN;
	double dPrice;
	int size = 0;

	// Declare an istream variable to open the file
	ifstream in_stream;

	token = operationCall.substr(0, operationCall.find(delimter));
	cout << token << endl;
	// Erase the line up to the token
	operationCall.erase(0, operationCall.find(delimter) + delimter.length());

	switch (stoi(token)) {

	case 1:				// Create a bookstore
		// We need to read in a file
		in_stream.open("bookInput.txt");
		OpenFile(in_stream);

		// While the file is open parse it line by line
		while (!in_stream.eof())
		{
			getline(in_stream, inputLine);
			delimter = ",";
			while ((size = inputLine.find_first_of(delimter)) != string::npos) {
				token = inputLine.substr(0, size);
				std::cout << token << std::endl;
				inputLine.erase(0, size + delimter.length());
			}
		}

		in_stream.close(); // close the input file
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		cout << "Invalid menu choice." << endl;
		break;
	}
}

void MenuCall(int choice, Bookstore bookstore, ofstream &out_file)
{
	switch (choice)
	{
	case 6:
		break;
	case 7:
		// close Files
		out_file.close();
		bookstore.~Bookstore();
		break;
	default:
		cout << "Invalid menu choice." << endl;
		break;
	}
}