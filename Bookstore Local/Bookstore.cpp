#include "Bookstore.h"
#include "Book.h"
#include <iostream>
#include <string>

Bookstore::Bookstore()
{
	Bookstore::count = 0;
}

Bookstore::~Bookstore()
{
}

bool Bookstore::addBook(Book aBook)
{
	if (Bookstore::count >= CAPACITY)
	{
		return false;
	}

	// If book is in list replace it with new book
	if (Bookstore::retrieveBook(aBook) == true)
	{

	} else {
		// Just add the book in normally
		Bookstore::list[count] = aBook;

		// increment count
		Bookstore::count += 1;

		return true;
	}
}

bool Bookstore::retrieveBook(Book& aBook)
{
	// if we don't get an a book with ISBN throw a fit
	if (aBook.getISBN() == NULL || aBook.getISBN() == 0)
	{
		cout << "Error: Invalid ISBN number.";
		return false;
	}

	// Otherwise let's search the bookstore for the ISBN
	for (int i = 0; i < Bookstore::count; i++)
	{
		if (Bookstore::list[i].getISBN() == aBook.getISBN())
		{
			// Get the information from the book we found and shove it aBook
			aBook.setAuthor(Bookstore::list[i].getAuthor());
			aBook.setCost(Bookstore::list[i].getCost());
			aBook.setTitle(Bookstore::list[i].getTitle());

			return true;
		}
	}
	return false;
}

void Bookstore::printBookStore(ostream &out)
{
	for (int i = 0; i < count; i++)
	{
		out << Bookstore::list[i].getISBN() << "\t";
		out << Bookstore::list[i].getAuthor() << ", ";
		out << Bookstore::list[i].getTitle() << ", \t";
		out << Bookstore::list[i].getCost() << endl;
	}
	out << endl;
}