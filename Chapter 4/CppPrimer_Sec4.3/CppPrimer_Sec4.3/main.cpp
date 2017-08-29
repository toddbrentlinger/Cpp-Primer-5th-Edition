#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section43();

void Exercise48();
void Exercise49();
void Exercise410();
void Exercise411();
void Exercise412();

void NewSection(const string &text = "");

int main()
{
	// Section 4.3
	Section43();

	system("pause");
	return 0;
}

void Section43()
{
	// Section 4.3 - Logical and Relational Operators
	NewSection("Section 4.3 - Logical and Relational Operators");

	// Logical AND and OR Operators

	{
		const vector<string> text{ "Hello", "World.",
			"My", "name", "is", "Bond.", "James", 
			"Bond." };

		// note s as a reference to const
		// the elements aren't copied and can't be changed
		for (const auto &s : text) { // for each element in text
			cout << s;	// print the current element

			// blank lines and those that end with a period get a newline
			if (s.empty() || s[s.size() - 1] == '.')
				cout << endl;
			else
				cout << " ";	// otherwise, separate with space
		}
	}

	// Logical NOT Operator

	{
		const vector<int> vec{ 0,1,2,3,4,5,6 };

		// print the first element in vec, if there is one
		if (!vec.empty())
			cout << vec[0] << endl;
	}

	// The Relational Operators

	// Equality Tests and the bool Literals

	double choice;
	do {
		cout << "\nWhat exercise number? (4.8 - 4.12, 0 to skip): ";
		cin >> choice;

		if (choice == 4.8)
			Exercise48();
		else if (choice == 4.9)
			Exercise49();
		else if (choice == 4.10)
			Exercise410();
		else if (choice == 4.11)
			Exercise411();
		else if (choice == 4.12)
			Exercise412();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise48()
{
	// Exercise 4.8
	NewSection("Exercise 4.8");

	/* Explain when operands are evaluated in the logical AND, logical
	OR, or equality operators. 
	
	The overall result of the logical AND operator is true if and only if 
	both its operands evaluate to true. The logical OR (||) operator 
	evaluates as true if either of its operands evaluates as true.

	The logical AND and OR operators always evaluate their left operand 
	before the right. Moreover, the right operand is evaluated if and only 
	if the left operand does not determine the result. This strategy is 
	known as short-circuit evaluation:
	- The right side of an && is evaluated if and only if the left side 
		is true.
	- The right side of an || is evaluated if and only if the left side 
		is false.*/
}

void Exercise49()
{
	// Exercise 4.9
	NewSection("Exercise 4.9");

	// Explain the behavior of the condition in the following if:

	const char *cp = "Hello World";
	if (cp && *cp)
		cout << "Both cp and *cp are evaluated to TRUE" << endl;
	else
		cout << "One is FALSE" << endl;

	/* The condition first tests whether the pointer cp points to an object
	and is not a null pointer. If, and only if, there is an object for which 
	cp points, the condition then tests the value, converted to bool, of the 
	object to which cp points when converted to a bool, through the use of 
	the dereference operator. The right side of an && is evaluated if and 
	only if the left side is true. */

	cout << "cp = " << cp << endl;
	cout << "*cp = " << *cp << endl;

	if (cp)
		cout << "cp is TRUE" << endl;
	else
		cout << "cp is FALSE" << endl;

	if (*cp)
		cout << "*cp is TRUE" << endl;
	else
		cout << "*cp is FALSE" << endl;

	{
		// TEST: Pointer to uninitialized object
		cout << "\nPointer to uninitialized object" << endl;
		char text;
		char *cp = &text;
		if (cp && *cp)
			cout << "Both cp and *cp are evaluated to TRUE" << endl;
		else
			cout << "One is FALSE" << endl;

		cout << "cp = " << cp << " is " << (cp ? "TRUE" : "FALSE") << endl;
		cout << "*cp = " << *cp << " is " << (*cp ? "TRUE" : "FALSE") << endl;
	}
	{
		// TEST: Null pointer
		cout << "\nNull pointer" << endl;
		char *cp = nullptr;
		
		cout << "cp is " << (cp ? "TRUE" : "FALSE") << endl;
		// cout << "*cp is " << (*cp ? "TRUE" : "FALSE") << endl;
	}
}

void Exercise410()
{
	// Exercise 4.10
	NewSection("Exercise 4.10");

	cout << "\nEnter int numbers: ";

	int choice;
	while (cin >> choice && choice != 42)
		cout << choice << endl;
	cin.clear();
}

void Exercise411()
{
	// Exercise 4.11
	NewSection("Exercise 4.11");

	cout << "Enter four values: ";
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a >= b && b >= c && c >= d)
		cout << "\nValues are in descending order" << endl;
	else
		cout << "\nValues are NOT in descending order" << endl;
}

void Exercise412()
{
	// Exercise 4.12
	NewSection("Exercise 4.12");

	/* Assumng i, j, and k are all ints, explain what
	i != j < k
	means.
	
	Order of evaluation first tests whether j is less than k. This returns
	a bool value that is converted to an int equal to 1 or 0 before it tests
	whether i is equal to this converted int value of 1 or 0. */

	int i(0), j(5), k(10);
	if (i != j < k)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	// output: TRUE (0 != 1)

	i = 1;
	cout << (i != j < k ? "TRUE" : "FALSE") << endl;
	// output: FALSE (1 != 1)
}

void NewSection(const string &text)
{
	cout << "\n\t" << text << "\n" << endl;
}