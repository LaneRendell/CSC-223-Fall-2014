#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include "Book.h"
using namespace std;

const int CAPACITY = 30;

class Bookstore {

public:
	Bookstore();

	//*************************************************************************
	// adds a book to the list
	// If the array is full,return false, else add the book list 
	// and return true.
	// If the book  is already in the list
	bool addBook(Book aBook);

	bool deleteBook(Book aBook);

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