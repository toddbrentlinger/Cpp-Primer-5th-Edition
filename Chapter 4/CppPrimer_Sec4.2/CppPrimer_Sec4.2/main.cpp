#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

void Section42();
void Exercise44();
void Exercise45();
void Exercise46();
void Exercise47();

void NewSection(const string &text = "");

int main()
{
	Section42();

	system("pause");
	return 0;
}

void Section42()
{
	// Section 4.2 - Arithmetic Operators
	NewSection("Section 4.2 - Arithmetic Operators");
	{
		int i = 1024;
		int k = -i;	// i is -1024
		bool b = true;
		bool b2 = -b;	// b2 is true!

		/* In § 2.1.1 (p. 34) we noted that bool values should not be used 
		for computation. The result of -b is a good example of what we had 
		in mind.
		For most operators, operands of type bool are promoted to int. In 
		this case, the value of b is true, which promotes to the int value 
		1 (§ 2.1.2, p. 35). That (promoted) value is negated, yielding -1. 
		The value -1 is converted back to bool and used to initialize b2. 
		This initializer is a nonzero value, which when converted to bool is 
		true. Thus, the value of b2 is true! */
	}
	{
		// Caution: Overflow and Other Arithmetic Exceptions

		short short_value = 32767;	// max value if shorts are 16 bits
		short_value += 1;	// this calculation overflows
		cout << "short_value: " << short_value << endl;
	}
	{
		int ival = 42;
		double dval = 3.14;
		cout << ival % 12 << endl;	// ok: result is 6
		// cout << ival % dval << endl;	// error: floating-point operand
	}
	{
		cout << "21 % 6: " << 21 % 6 << "\t 21 / 6: " << 21 / 6 << endl;
		// result is 3 3

		cout << "21 % 7: " << 21 % 7 << "\t 21 / 7: " << 21 / 7 << endl;
		// result is 0 3

		cout << "-21 % -8: " << -21 % -8 << "\t -21 / -8: " << -21 / -8 << endl;
		// result is -5 2

		cout << "21 % -5: " << 21 % -5 << "\t 21 / -5: " << 21 / -5 << endl;
		// result if 1 -4
	}

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.4 - 4.7, 0 to skip): ";
		cin >> choice;

		if (choice == 4.4)
			Exercise44();
		else if (choice == 4.5)
			Exercise45();
		else if (choice == 4.6)
			Exercise46();
		else if (choice == 4.7)
			Exercise47();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise44()
{
	// Exercise 4.4
	NewSection("Exercise 4.4");

	cout << "12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 = "
		<< 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

	cout << "((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) = " 
		<< ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) << endl;
}

void Exercise45()
{
	// Exercise 4.5
	NewSection("Exercise 4.5");

	// Determine the result for the following expressions:

	// (a)
	cout << "-30 * 3 + 21 / 5 = " << -30 * 3 + 21 / 5 << endl;
	// result: (-30 * 3) + (21 / 5) = -90 + 4 = -86

	// (b)
	cout << "-30 + 3 * 21 / 5 = " << -30 + 3 * 21 / 5 << endl;
	// result: -30 + ((3 * 21) / 5) = -30 + (63 / 5) = -30 + 12 = -18

	// (c)
	cout << "30 / 3 * 21 % 5 = " << 30 / 3 * 21 % 5 << endl;
	// result: (((30 / 3) * 21) % 5) = ((10 * 21) % 5) = 210 % 5 = 0

	// (d)
	cout << "-30 / 3 * 21 % 4 = " << -30 / 3 * 21 % 4 << endl;
	// result: (((-30 / 3) * 21) % 4) = ((-10 * 21) % 4) = -210 % 4 = -2

}

void Exercise46()
{
	// Exercise 4.6
	NewSection("Exercise 4.6");

	/* Write an expression to determine whether an int value is
	even or ordd. */

	int intChoice;
	do
	{
		cout << "\nEnter int number (0 to skip): ";
		cin >> intChoice;

		if (intChoice == 0)
			continue;
		else if (intChoice % 2 == 0)
			cout << "\nNumber " << intChoice << " is EVEN" << endl;
		else
			cout << "\nNumber " << intChoice << " is ODD" << endl;

	} while (intChoice != 0);
}

void Exercise47()
{
	// Exercise 4.7
	NewSection("Exercise 4.7");

	/* What does overflow mean? 
	
	Overflow happens when a value is computed that is outside the range
	of values that the type can represent. */

	/* Show three expressions that will overflow. */

	short short_value = 32767;	// max value of shorts are 16 bits
	short_value += 1;	// this calculation overflows
	// short_value: -32768	// value "wrapped around"
	cout << short_value << endl;

	unsigned ui_value = 0;
	--ui_value;
	// ui_value: 4294967295
	cout << ui_value << endl;

	unsigned short us_value = 65535;
	++us_value;
	// us_value: 0
	cout << us_value << endl;
}

void NewSection(const string &text)
{
	cout << "\n\t" << text << "\n" << endl;
}