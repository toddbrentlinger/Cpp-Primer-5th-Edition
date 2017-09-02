#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

void Section48();

void Exercise425();
void Exercise426();
void Exercise427();

inline void NewSection(const string &text = "")
{
	cout << "\n\t" << text << "\n" << endl;
}

int main()
{
	Section48();

	system("pause");
	return 0;
}

void Section48()
{
	// Section 4.8 - The Bitwise Operators
	NewSection("Section 4.8 - The Bitwise Operators");

	// Bitwise Shift Operators

	// Bitwise NOT Operator

	// Bitwise AND, OR, and XOR Operators

	// Using Bitwise Operators
	{
		// we'll use this value as a collection of bits
		unsigned long quiz1 = 0;

		// generate a value with only bit number 27 set:
		// 1UL << 27;

		// indicate student number 27 passed
		quiz1 |= 1UL << 27;
		// equivalent to: 
		// quiz1 = quiz1 | 1UL << 27;

		// student number 27 failed
		quiz1 &= ~(1UL << 27);

		// how did student number 27 do?
		bool status = quiz1 & (1UL << 27);

		cout << (status ? "TRUE" : "FALSE") << endl;
	}

	// Shift Operators (aka IO Operators) Are Left Associative
	{
		// ok: + has a higher precedence, so the sum is printed
		cout << 42 + 10 << endl;

		// ok: parentheses force intended grouping; prints 1
		cout << (10 < 42) << endl;

		/* error: attempt to compare cout to 42
		cout << 10 < 42;
		equivalent to:
		(cout << 10) < 42;
		*/
	}

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.25 - 4.27, 0 to skip): ";
		cin >> choice;

		if (choice == 4.25)
			Exercise425();
		else if (choice == 4.26)
			Exercise426();
		else if (choice == 4.27)
			Exercise427();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise425()
{
	// Exercise 4.25
	NewSection("Exercise 4.25");

	/*
	What is the value of ~'q' << 6 on a machine with 32-bit ints and
	8 bit chars, that uses Latin-1 character set in which 'q' has the
	bit pattern 01110001?

	('q') -									   01110001
	(~'q') -		11111111 11111111 11111111 10001110
	(~'q' << 6) -	11111111 11111111 11100011 10000000

	*/
}

void Exercise426()
{
	// Exercise 4.26
	NewSection("Exercise 4.26");

	/*
	What would happen if we used unsigned int as the type for quiz1?

	Unsigned ints are only guaranteed to have 16 bits, and we need at least
	17. Using the bitwise OR operator, |, with one operand as unsigned int
	and the other operand as unsigned long will result in undefined behavior.
	*/
}

void Exercise427()
{
	// Exercise 4.27
	NewSection("Exercise 4.27");

	// What is the result of each of these expressions?

	unsigned long u11 = 3, u12 = 7;

	// u11			00000000 00000000 00000000 00000011
	// u12			00000000 00000000 00000000 00000111

	// (a)	u11 & u12
	// (u11 & u12)	00000000 00000000 00000000 00000011
	// equivalent to u11 = 3
	cout << (u11 & u12) << endl;
	// output: 3

	// (b)	u11 | u12
	// (u11 & u12)	00000000 00000000 00000000 00000111
	// equivalent to u12 = 7
	cout << (u11 | u12) << endl;
	// output: 7

	// (c)	u11 && u12
	// both operands of conditional && operator are nonzero
	cout << (u11 && u12) << endl;
	// output: true, bool 1

	// (d)	u11 || u12
	// both operands of conditional || operator are nonzero
	cout << (u11 || u12) << endl;
	// output: true, bool 1
}