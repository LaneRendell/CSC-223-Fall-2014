#include "Book.h"
#include <string>

void Book::setISBN(int ISBN)
{
	Book::isbn = ISBN;
}

void Book::setAuthor(string author)
{
	Book::author = author;
}

void Book::setCost(double price)
{
	Book::cost = price;
}

void Book::setTitle(string title)
{
	Book::title = title;
}


int Book::getISBN()
{
	return isbn;
}

string Book::getAuthor()
{
	return author;
}

string Book::getTitle()
{
	return title;
}

double Book::getCost()
{
	return cost;
}