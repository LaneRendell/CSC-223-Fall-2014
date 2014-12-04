#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <ostream>
#include "Book.h"

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
	// a function to delete a book from the list
	//  if the array is empty, or the book is not in the array return false, else remove  
	// the book from the list and return true


	//*************************************************************************
	// a function that returns a book from a list
	// the input parameter aBook may hold only part or all  of the information about
	// the book, but must have the isbn number (to be able to compare it with a book
	// in the list) The function will returns true if aBook was in the list,
	// else it returns false
	//8************************************************************************
	bool retrieveBook(Book& abook);

	double totalInvestment();
	// a function that returns the total cost that the bookStore invested in books

	void printBookStore(ostream &out);
	// For each book print the book ISBN number, book author, book title and cost

	friend std::ostream& operator << (std::ostream& out, Bookstore& store);
	// overload the << operator a function to print all the books in the bookStore in 
	// ascending order by cost of  the book.  
	// For each book print the book ISBN number, book author, book title and cost


private:
	int count;
	Book list[CAPACITY];
	void sort();
};

#endif