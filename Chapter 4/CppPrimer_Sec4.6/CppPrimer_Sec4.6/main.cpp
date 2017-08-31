#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section46();
void Exercise420();

inline void NewSection(const string &text = "")
{
	cout << "\n\t" << text << "\n" << endl;
}

int main()
{
	Section46();

	system("pause");
	return 0;
}

void Section46()
{
	// Section 4.6 - The Member Access Operators
	NewSection("Section 4.6 - The Member Access Operators");

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.20, 0 to skip): ";
		cin >> choice;

		if (choice == 4.20)
			Exercise420();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise420()
{
	// Exercise 4.20
	NewSection("Exercise 4.20");

	/* 
	Assuming the iter is a vector<string>::iterator, indicate which, if
	any, of the following expressions are legal. Explain the behavior of the
	legal expressions and why those that aren't legal are in error. 
	*/
	
	vector<string>::iterator iter;
	vector<string> svec{ "My", "name", "is", "Bond,", "James", "Bond" };

	iter = svec.begin();

	// (a)
	cout << *iter++ << endl;
	/* 
	Legal. The precedence of postfix increment is higher than that of the
	dereference operator, so *iter++ is equivalent to *(iter++). The 
	subexpression iter++ increments iter and yields a copy of the previous
	value of iter as its result. Accordingly, the operand of * is the
	unincremented value of iter. Thus the statement outputs the element
	to which iter originally pointed and increments iter.
	*/

	// (b)
	// (*iter)++;
	// Illegal. Cannot increment a string object.

	// (c)
	// *iter.empty();
	/* 
	This expression attempts to fetch the empty member of the object iter.
	However, iter is a iterator, which has no members. This code will not compile.
	Because dereference has a lower precedence than dot, we must parenthesize the
	dereference subexpression. 
	*/
	// Correction:
	cout << (*iter).empty() << endl;;

	// (d)
	cout << iter->empty() << endl;
	/* 
	Fetches member function empty() after dereferencing iter.
	*/
	// Equivalent:
	cout << (*iter).empty() << endl;

	// (e)
	// ++*iter;
	// Illegal. Cannot increment a string object.

	// (f)
	cout << iter++->empty() << endl;
	/*
	Increments iter and yields a copy of the previous value of iter as
	its result. This previous iter value is dereferenced and fetches its 
	member function empty().
	*/
}