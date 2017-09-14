#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

void Section49();

void Exercise428();
void Exercise429();
void Exercise430();

inline void NewSection(const string &text = "")
{
	cout << "\n\t" << text << "\n" << endl;
}

struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Section49();

	system("pause");
	return 0;
}

void Section49()
{
	// Section 4.9 - The sizeof Operator
	NewSection("Section 4.9 - The sizeof Operator");
	{
		Sales_data data, *p;

		// size required to hold an object of type Sales_data
		sizeof(Sales_data);

		// size of data's type, i.e., sizeof(Sales_data)
		sizeof data;

		// size of a pointer
		sizeof p;

		// size fo the type to which p points, i.e., sizeof(Sales_data)
		sizeof *p;

		// size of the type of Sales_data's revenue member
		sizeof data.revenue;

		// alternative way to get the size of revenue
		sizeof Sales_data::revenue;
	}
	{
		int ia[] = { 0,1,2,3,4,5,6 };

		// sizeof(ia)/sizeof(*ia) returns the number of elements in ia
		constexpr size_t sz = sizeof(ia) / sizeof(*ia);

		// ok: sizeof returns a constant expression § 2.4.4 (p. 65)
		int arr2[sz];
	}

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.28 - 4.30, 0 to skip): ";
		cin >> choice;

		if (choice == 4.28)
			Exercise428();
		else if (choice == 4.29)
			Exercise429();
		else if (choice == 4.30)
			Exercise430();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise428()
{
	// Exercise 4.28
	NewSection("Exercise 4.28");

	// Write a program to print the size of each of the built-in types.

	cout << "\nVoid Type" << endl
		<< "nullptr_t: " << sizeof(nullptr_t) << " bytes" << endl

		<< "\nBoolean Type" << endl
		<< "bool: " << sizeof(bool) << " bytes" << endl

		<< "\nCharacter Types" << endl
		<< "signed char: " << sizeof(signed char) << " bytes" << endl
		<< "unsigned char: " << sizeof(unsigned char) << " bytes" << endl
		<< "char: " << sizeof(char) << " bytes" << endl
		<< "wchar_t: " << sizeof(wchar_t) << " bytes" << endl
		<< "char16_t: " << sizeof(char16_t) << " bytes" << endl
		<< "char32_t: " << sizeof(char32_t) << " bytes" << endl

		<< "\nInteger Types" << endl
		<< "int: " << sizeof(int) << " bytes" << endl
		<< "signed: " << sizeof(signed) << " bytes" << endl
		<< "unsigned: " << sizeof(unsigned) << " bytes" << endl
		<< "short: " << sizeof(short) << " bytes" << endl
		<< "long: " << sizeof(long) << " bytes" << endl
		<< "long long: " << sizeof(long long) << " bytes" << endl

		<< "\nFloating Point Types" << endl
		<< "float: " << sizeof(float) << " bytes" << endl
		<< "double: " << sizeof(double) << " bytes" << endl
		<< "long double: " << sizeof(long double) << " bytes" << endl;
}

void Exercise429()
{
	// Exercise 4.29
	NewSection("Exercise 4.29");
	/*
	Predict the output of the following code and explain your reasoning.

	The sizeof the array x is equivalent to taking the sizeof the element
	type, int, times the number of elements in the array, 10 for x. Since
	an int object has 4 bytes, the array x has a total of 10 x 4 = 40 bytes.
	The sizeof a pointer returns the size needed to hold a pointer. The
	sizeof a dereferenced pointer returns the size of an object of the
	type to which the pointer points. The size needed to hold the pointer
	p is 4 bytes for 32bit machine or 8 bytes for 64bit machine and the
	size needed to hold the object of the type to which the pointer
	points, int, is 4 bytes.
	*/

	int x[10];	int *p = x;

	cout << "int x[10]: " << sizeof(x) << " bytes" << endl; // 40 bytes
	cout << "int *p: " << sizeof(p) << " bytes" << endl; // 4 bytes

	cout << sizeof(x) / sizeof(*x) << endl;	// output: 10
											// equivalent to 40 / 4 = 10
	cout << sizeof(p) / sizeof(*p) << endl;	// output: 1
											// equivalent to 4 / 4 = 1
}

void Exercise430()
{
	// Exercise 4.30
	NewSection("Exercise 4.30");

	/*
	Parenthesize the following expressions to match the default
	evaluation:

	(a) sizeof x + y
	The sizeof operator has higher precedence than the add operator.
	( (sizeof x) + y)

	(b) sizeof p->mem[i]
	The member selector operator, ->, has higher precedence than sizeof.
	sizeof (p->mem[i])

	(c) sizeof a < b
	The sizeof operator has higher precedence than the less than operator.
	( (sizeof a) < b)

	(d) sizeof f()
	The function call operator has higher precedence than the sizeof operator.
	(sizeof ( f() ) )
	*/
}