#include "Bookstore.h"
#include "Book.h"
#include <iostream>
#include <ostream>

Bookstore::Bookstore()
{
	Bookstore::count = 0;
}

bool Bookstore::addBook(Book aBook)
{
	int i = 0;
	if (Bookstore::count >= CAPACITY)
	{
		return false;
	}

	// If book is in list replace it with new book
	for (int i = 0; i < Bookstore::count; i++)
	{
		if (Bookstore::list[i].getISBN() == aBook.getISBN())
		{
			if (aBook.getAuthor() != "")
			{
				Bookstore::list[i].setAuthor(aBook.getAuthor());
			}
			if (aBook.getTitle() != "")
			{
				Bookstore::list[i].setTitle(aBook.getTitle());
			}
			if (aBook.getCost() >= 0)
			{
				Bookstore::list[i].setCost(aBook.getCost());
			}
			return true;
		}
	}
	// Just add the book in normally
	Bookstore::list[count] = aBook;

	// increment count
	Bookstore::count += 1;

	return true;
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

double Bookstore::totalInvestment()
{
	double total = 0.00;

	for (int i = 0; i < Bookstore::count; i++)
	{
		total += Bookstore::list[i].getCost();
	}

	return total;
}

std::ostream& operator << (std::ostream& out, Bookstore& store)
{
	store.sort();

	for (int i = 0; i < store.count; i++)
	{
		out << store.list[i].getISBN() << ", ";
		out << store.list[i].getAuthor() << ", ";
		out << store.list[i].getTitle() << ", ";
		out << store.list[i].getCost();
		out << endl;
	}
	return out;
}

// Insertion sort
void Bookstore::sort()
{
	Book iBook, tmp;
	int j;
	for (int i = 0; i < count; i++)
	{
		j = i;

		// While left hand element is greater than next index
		while (j >= 0 && Bookstore::list[j - 1].getCost() > Bookstore::list[j].getCost())
		{
			tmp = Bookstore::list[j]; // temporary holder
			Bookstore::list[j] = Bookstore::list[j - 1]; 
			Bookstore::list[j - 1] = tmp; // move lower value down
			j--; // decrement counter
		}
	}
}

bool Bookstore::deleteBook(Book aBook)
{
	int index = 0;

	if (Bookstore::count == 0 || Bookstore::retrieveBook(aBook) == false)
	{
		return false;
	} else {
		
		// get the index of the element of the Book
		for (int i = 0; i < count; i++)
		{
			if (aBook.getISBN() == Bookstore::list[i].getISBN())
			{
				index = i;
			}
		}
		
		//
		for (int i = index; i < count; i++)
		{
			// Shift everything to the right by one
			Bookstore::list[index] = Bookstore::list[index + 1];
		}
		// decrement count
		//count--;

		return true;
	}
}