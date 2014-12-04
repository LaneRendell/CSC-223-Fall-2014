//
// Book.h
//
// Class to keep track of a book in the store
// the class to set and get information about an book: the ISBN author, title, and cost  


#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {

public:

	void setISBN(int ISBN);
	void setAuthor(string author);
	void setTitle(string title);
	void setCost(double cost);
	int getISBN();
	string getAuthor();
	string getTitle();
	double getCost();

private:
	int isbn;
	string author;
	string title;
	double cost;

};
#endif