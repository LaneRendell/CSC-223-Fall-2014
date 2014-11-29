#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include "Book.h"
using namespace std;

const int CAPACITY = 30;

class Bookstore {

public:

	//****************************************************************************
	// Sets count to zero.
	//****************************************************************************
	Bookstore();

	//*************************************************************************
	// adds a book to the list
	// If the array is full,return false, else add the book list 
	// and return true.
	// If the book  is already in the list replace it with aBook
	//*************************************************************************
	bool addBook(Book aBook);

	bool deleteBook(Book aBook);


	//*************************************************************************
	// a function that returns a book from a list
	// the input parameter aBook may hold only part or all  of the information about
	// the book, but must have the isbn number (to be able to compare it with a book
	// in the list) The function will returns true if aBook was in the list,
	// else it returns false
	//8************************************************************************
	bool retrieveBook(Book& abook);

	double totalInvestment();

	void printBookStore();

	ostream& operator <<(Bookstore store);

	~Bookstore();

private:
	int count;
	Book list[CAPACITY];
	void sort();
};

#endif