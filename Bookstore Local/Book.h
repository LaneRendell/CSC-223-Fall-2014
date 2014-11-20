#ifndef BOOK_H
#define BOOK_H

#include <string>
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