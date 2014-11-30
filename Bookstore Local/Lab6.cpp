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
void MenuCall(string operationCall, Bookstore &bookstore, ostream &out);

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
void MenuCall(int choice, Bookstore &bookstore, ofstream &out);

//*****************************************************************************
// Method Function: Trims leading whitespace in string.
// Precondition: None (valid string).
// Postcondition: Leading & trailining whitespace is thrown into the abyss and
//				  forgotten  returns new string.
//*****************************************************************************
string TrimWhiteSpace(string &inString);

void createBookstore(string inString, Bookstore &store, ostream &out);

//*****************************************************************************
// Method Function: Takes a line of input and attempts to make a book.
// Precondition: Nonempty string
// Postcondition: Returns a book object.
///****************************************************************************
Book parseBookInput(string inputBook);

int main()
{
	Bookstore store;
	ofstream out;

	OpenFile(out);
	out.open("out.txt");

	out << "Create the Database\n";
	out << "---------------------\n";
	out << endl;
	MenuCall("1, bookInput.txt", store, out);
	store.printBookStore(out);
	out << "add a book\n";
	out << "------------\n";
	out << endl;
	store.printBookStore(out);
	MenuCall("2, 667788,	Intro to Java, Daniel Ling, 150", store, out);
	store.printBookStore(out);
	MenuCall("4, 667788", store, out);

	out << "Delete a book\n";
	out << "---------------\n";
	out << endl;
	MenuCall("3, 23456", store, out);

	out << "Retrieve a book and print it.\n";
	out << "---------------\n";
	out << endl;
	MenuCall("4, 23456", store, out);	// if the book is not in the database
									// give an appropriate message

	out << "Retrieve a book and print it.\n";
	out << "---------------\n";
	out << endl;
	MenuCall("4, 34567", store, out);

	out << "Update the store cost.\n";
	out << "------------------------\n";
	out << endl;
	MenuCall("5, 45678, 250", store, out);
	MenuCall("4, 45678", store, out);

	out << "Print the database in ascending order. \n";
	out << "---------------------------------------\n";
	out << endl;
	MenuCall("6", store,out);

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

void MenuCall(string operationCall, Bookstore &store, ostream &out)
{
	// We need to get the choice which will be the first character,
	// cast it to an integer
	string delimter = ",", token;
	Book book;

	token = operationCall.substr(0, operationCall.find(delimter));
	// Erase the line up to the token
	operationCall.erase(0, operationCall.find(delimter) + delimter.length());

	switch (stoi(token)) {

	case 1:				// Create a bookstore
		createBookstore(operationCall, store, out);
		break;
	case 2:
		//store.printBookStore(out);
		book = parseBookInput(operationCall);
		store.addBook(book);
		//store.printBookStore(out);
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

void MenuCall(int choice, Bookstore &bookstore, ofstream &out_file)
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

string TrimWhiteSpace(string &inString)
{
	// Find first nonwhitespace character
	int strBegin, strEnd, strRange;
	string whitespace = " \t";

	// Check if for some reason we got a string that doesnt need pruned
	if (inString.find_first_not_of(whitespace) == string::npos)
	{
		return inString;
	}

	strBegin = inString.find_first_not_of(whitespace);
	strEnd = inString.find_last_not_of(whitespace);
	strRange = strEnd - strBegin + 1;

	return inString.substr(strBegin, strRange);
}

void createBookstore(string inString, Bookstore &store, ostream &out)
{
	string inputLine;
	Book book;
	inString = TrimWhiteSpace(inString);
	// Declare an istream variable to open the file
	ifstream in_stream;

	in_stream.open(inString);
	OpenFile(in_stream);

	// While the file is open parse it line by line
	while (!in_stream.eof())
	{
		getline(in_stream, inputLine);
		book = parseBookInput(inputLine);

		// Load into bookstore 
		store.addBook(book);
	}

	// Confirmation that we added the books into the database
	//store.printBookStore(out);

	in_stream.close(); // close the input file
}

Book parseBookInput(string inputBook)
{
	Book book;
	int iISBN, count = 0, size = 0;
	double dPrice;
	string delimeter, token, isbn, author, title, price;
	delimeter = ",";

	// We need to count how many iterations we are doing
	// to assign the string to the correct variable
	while ((size = inputBook.find_first_of(delimeter)) != string::npos) {
		token = inputBook.substr(0, size);
		inputBook.erase(0, size + delimeter.length());

		if (count == 0)
		{
			isbn = token;
		}
		else if (count == 1) {
			author = token;
		}
		else if (count == 2) {
			title = token;
		}
		count++;
	}

	count = 0;

	// grab leftover stuff which won't be seperated by delimeter
	price = inputBook;

	// Trim whitespace in strings
	isbn = TrimWhiteSpace(isbn);
	title = TrimWhiteSpace(title);
	author = TrimWhiteSpace(author);
	price = TrimWhiteSpace(price);

	// cast variables
	iISBN = stoi(isbn);
	dPrice = stod(price);

	// Create book
	book.setISBN(iISBN);
	book.setAuthor(author);
	book.setTitle(title);
	book.setCost(dPrice);

	return book;
}