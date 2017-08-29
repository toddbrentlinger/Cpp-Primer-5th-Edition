#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section44();

void Exercise413();
void Exercise414();
void Exercise415();
void Exercise416();

void NewSection(const string &text = "");

int main()
{
	Section44();

	system("pause");
	return 0;
}

void Section44()
{
	// Section 4.4 - Assignment Operators
	NewSection("Section 4.4 - Assignment Operators");

	{
		int i = 0, j = 0, k = 0;	// initializations, not assignment
		const int ci = i;			// initialization, not assignment

		/* each of these assigments is illegal:
		1024 = k;	// error: literals are rvalues
		i + j = k;	// error: arithmetic expressions are rvalues
		ci = k;		// error: ci is a const (non-modifiable) lvalue
		*/

		k = 0;			// result: type int, value 0
		k = 3.14159;	// result: type int, value 3

		// k = { 3.14 };	// error: narrowing conversion
		vector<int> vi;	// initially empty
		vi = { 0,1,2,3,4,5,6,7,8,9 };	// vi now has ten elements, values 0-9
	}

	// Assignment Is Right Associative

	{
		int ival, jval;
		ival = jval = 0;	// ok: each assigned 0
	}

	{
		int ival, *pval;	// ival is an int; pval is a pointer to int
		// ival = pval = 0;	// error: cannot assign the value of a pointer to int
		string s1, s2;
		s1 = s2 = "OK";		// string literal "OK" converted to string
	}

	// Assignment Has Low Precedence


	// Beware of Confusing Equality and Assignment Operators


	// Compound Assignment Operators

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.13 - 4.16, 0 to skip): ";
		cin >> choice;

		if (choice == 4.13)
			Exercise413();
		else if (choice == 4.14)
			Exercise414();
		else if (choice == 4.15)
			Exercise415();
		else if (choice == 4.16)
			Exercise416();
		else if (choice != 0)
			cout << "\nNot Valid Choice" << endl;

	} while (choice != 0);
}

void Exercise413()
{
	// Exercise 4.13
	NewSection("Exercise 4.13");

	// What are the values of i and d after each assignment?
	int i;	double d;

	// (a)
	d = i = 3.5;
	cout << "i = " << i << "\td = " << d << endl;
	// output: i = 3	d = 3

	// (b)
	i = d = 3.5;
	cout << "i = " << i << "\td = " << d << endl;
	// output: i = 3	d = 3.5
}

void Exercise414()
{
	// Exercise 4.14
	NewSection("Exercise 4.14");

	/* 
	Explain what happens in each of the if tests:
	
	if (42 = i)		//	...

	Error: Left-hand operand must be lvalue. Literals are rvalues.

	if (i = 42)		//	...
	
	Variable i is assigned the value 42. Since it is a nonzero value, the 
	condition tests TRUE.
	*/
}

void Exercise415()
{
	// Exercise 4.15
	NewSection("Exercise 4.15");

	// The following assignment is illegal. Why? How would you correct it?

	double dval; int ival; int *pi;
	// dval = ival = pi = 0;
	// Error: Cannot assign a pointer to int to an int without the 
	// dereference operator.

	// Correction: Separate pointer assignment.
	dval = ival = 0;
	pi = 0;

	cout << "*pi is " << (pi != nullptr ? "NOT" : "") << " a null pointer.\n"
		<< "ival = " << ival << "\tdval = " << dval << endl;
}

void Exercise416()
{
	// Exercise 4.16
	NewSection("Exercise 4.16");

	/*
	Although the following are legal, they probably do not behave as the
	programmer expects. Why? Rewrite the expressions as you think they
	should be.

	(a)

	if (p = getPtr() != 0)

	The condition will test equality of the returned value of getPtr() 
	and 0. This bool value will then be assigned to p if it can be converted
	to the type of p. If p is a nonzero value, the condition will test TRUE.

	Correction: Add parentheses to ensure getPtr() is assigned to p before
	it is compared to literal 0 for equality.

	if ( ( p = getPtr() ) != 0 )

	(b)

	if (i = 1024)

	The value of 1024 is assigned to i. Since i is a nonzero value, the
	condition always test TRUE.

	Correction: Correct operator to compare equality to test if variable
	i is equal to 1024.

	if (i == 1024)
	*/
}

void NewSection(const string &text)
{
	cout << "\n\t" << text << "\n" << endl;
}