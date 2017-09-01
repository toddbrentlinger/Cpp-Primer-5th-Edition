#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section47();

void Exercise421();
void Exercise422();
void Exercise423();
void Exercise424();

inline void NewSection(const string &text = "")
{
	cout << "\n\t" << text << "\n" << endl;
}

int main()
{
	Section47();

	system("pause");
	return 0;
}

void Section47()
{
	// Section 4.7 - The Conditional Operator
	NewSection("Section 4.7 - The Conditional Operator");

	int grade = 75;
	string finalgrade = (grade < 60) ? "fail" : "pass";

	// Nesting Conditional Operations

	finalgrade = (grade > 90) ? "high pass"
							: (grade < 60) ? "fail" : "pass";

	// Using a Conditional Operator in an Output Expression

	// prints pass or fail
	cout << ((grade < 60) ? "fail" : "pass") << endl;

	// prints 1 or 0
	cout << (grade < 60) ? "fail" : "pass"; 
	cout << endl;

	// error: compares cout to 60
	// cout << grade < 60 ? "fail" : "pass";

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.21 - 4.24, 0 to skip): ";
		cin >> choice;

		if (choice == 4.21)
			Exercise421();
		else if (choice == 4.22)
			Exercise422();
		else if (choice == 4.23)
			Exercise423();
		else if (choice == 4.24)
			Exercise424();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);
}

void Exercise421()
{
	// Exercise 4.21
	NewSection("Exercise 4.21");

	vector<int> ivec{ 0,1,2,3,4,5,6,7,8,9,10 };

	for (auto &index : ivec)
	 	index = ((index % 2) != 0) ? (index * 2) : index;

	for (const auto &index : ivec)
		cout << index << " ";
	cout << endl;
}

void Exercise422()
{
	// Exercise 4.22
	NewSection("Exercise 4.22");

	int grade;
	cout << "\nEnter grade: ";
	cin >> grade;

	// (a) Using conditional operators
	NewSection("(a) Using conditional operators");

	string finalgrade = (grade > 90) ? "high pass"
							: (grade > 75) ? "pass" 
							: (grade < 60) ? "fail" : "low pass";

	cout << finalgrade << endl;

	// (b) Using if statements
	NewSection("(b) Using if statements");

	if (grade > 90)
		finalgrade = "high pass";
	else if (grade > 75)
		finalgrade = "pass";
	else if (grade >= 60)
		finalgrade = "low pass";
	else
		finalgrade = "fail";

	cout << finalgrade << endl;

	// Alternative
	if (grade > 90)
		finalgrade = "high pass";
	else if (grade > 75)
		finalgrade = "pass";
	else if (grade < 60)
		finalgrade = "fail";
	else
		finalgrade = "low pass";

	cout << finalgrade << endl;
}

void Exercise423()
{
	// Exercise 4.23
	NewSection("Exercise 4.23");

	string s = "word";
	// string p1 = s + s[s.size() - 1] == 's' ? "" : "s";

	/*
	Why does the expression fail to compile due to operator precedence?
	
	The add operator, +, has higher precedence than the equality 
	operator, ==. So the subexpression (s + s[s.size() - 1]) is evaluated
	first before being compared to literal character 's'. Depending on the
	result, the string p1 is assigned either the string literal "s" or
	an empty string "".

	Additionally, the result of the first subexpression is a string object
	which can NOT be compared to character literal.
	*/

	string p1 = s + s[s.size() - 1] == "s" ? "" : "s";
	cout << p1 << endl;
	// output: s

	// Correction with added parentheses
	string p2 = s + (((s[s.size() - 1]) == 's') ? "" : "s");

	cout << p2 << endl;
	// output: words
}

void Exercise424()
{
	// Exercise 4.24
	NewSection("Exercise 4.24");

	/*
	If conditional operator was left associative, the statement:

	finalgrade = grade > 90 ? "high pass"
							: grade < 60 ? "fail" : "pass";

	would be equivalent to:

	finalgrade = (grade > 90 ? "high pass" : grade < 60) ? "fail" : "pass";

	where if grade is greater than 90,  the string "high pass"
	is returned and converted to bool TRUE, since it's not an empty string,
	for the next nested conditional operator. If grade is less than or equal
	to 90, the subexpression (grade < 60) is evaluated and returns a bool
	for the next nested conditional operator. As a result, finalgrade
	will be assigned either string literal "fail" or "pass".
	*/
}