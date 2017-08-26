#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section411();

void Section412();
void Exercise41();
void Exercise42();

void Section413();
void Exercise43();

void NewSection(const string &text = "");

int main()
{
	// Chapter 4 - Expressions
	NewSection("Chapter 4 - Expressions");

	// Chapter 4.1 - Fundamentals
	NewSection("Chapter 4.1 - Fundamentals");

	// Section 4.1.1
	Section411();

	// Section 4.1.2
	Section412();

	// Section 4.1.3
	Section413();
}

void Section411()
{
	// Section 4.1.1 - Basic Concepts
	NewSection("Section 4.1.1 - Basic Concepts");
	
	/* 
	Lvalues and Rvalues

	Roughly speaking, when we use an object as an rvalue, we
	use the object’s value(its contents). When we use an object as
	an lvalue, we use the object’s identity(its location in memory).
	*/
}

void Section412()
{
	// Section 4.1.2 - Precedence and Associativity
	NewSection("Section 4.1.2 - Precedence and Associativity");

	cout << 6 + 3 * 4 / 2 + 2 << endl;	// prints 14

	// parentheses in this expression match default precedence and associativity
	cout << ((6 + ((3 * 4) / 2)) + 2) << endl;

	// Parentheses Override Precedence and Associativity

	// parantheses result in alternative groupings
	cout << (6 + 3)*(4 / 2 + 2) << endl;	// prints 36
	cout << ((6 + 3) * 4) / 2 + 2 << endl;	// prints 20
	cout << 6 + 3 * 4 / (2 + 2) << endl;	// prints 9

	// When Precedence and Associativity Matter

	int ia[] = { 0,2,4,6,8 };	// array with five elements of type int
	int last = *(ia + 4);	// initializes last to 8, the value of ia[4]
	last = *ia + 4;	// last = 4, equivalent to ia[0] + 4

	double choice;
	do {
		cout << "\nWhat exercise number? (4.1 - 4.2, 0 to skip): ";
		cin >> choice;

		if (choice == 4.1)
			Exercise41();
		else if (choice == 4.2)
			Exercise42();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;
	} while (choice != 0);
}

void Exercise41()
{
	// Exercise 4.1
	NewSection("Exercise 4.1");

	// What is the value returned?
	// output: 105
	cout << 5 + 10 * 20 / 2 << endl;
}

void Exercise42()
{
	// Exercise 4.2
	NewSection("Exercise 4.2");

	/* Using Table 4.12 (p. 166), parenthesize the following 
	expressions to indicate the order in which the operands are
	grouped: */

	vector<int> vec = { 0,2,4,6,8 };

	// (a) * vec.begin()
	cout << *vec.begin() << endl;
	cout << ( * ( vec.begin() ) ) << endl;
	// Order: 

	// (b) * vec.begin() + 1
	cout << *vec.begin() + 1 << endl;
	cout << ( ( * ( vec.begin() ) ) + 1 ) << endl;

	/* 
	Order of operator precedence:
	First: Member selectors ( object.member )
			function call ( name(expr_list) )
	Second: Dereference ( *expr )
	Third: Add ( expr + expr)
	*/
}

void Section413()
{
	// Section 4.1.3 - Order of Evaluation
	NewSection("Section 4.1.3 - Order of Evaluation");

	int i = 0;
	cout << i << " " << ++i << endl;	// undefined

	/* Because this program is undefined, we cannot draw any conclusions 
	about how it might behave. The compiler might evaluate ++i before 
	evaluating i, in which case the output will be 1 1. Or the compiler 
	might evaluate i first, in which case the output will be 0 1. Or the 
	compiler might do something else entirely. Because this expression 
	has undefined behavior, the program is in error, regardless of what 
	code the compiler generates. */

	// Order of Evaluation, Precedence, and Associativity

	double choice;
	do {
		cout << "\nWhat exercise number? (4.3, 0 to skip): ";
		cin >> choice;

		if (choice == 4.3)
			Exercise43();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;
	} while (choice != 0);
}

void Exercise43()
{
	// Exercise 4.3
	NewSection("Exercise 4.3");

	/* Order of evaluation for most of the binary operators is left
	undefined to give the compiler opportunities for optimization. This
	strategy presents a trade-off between efficient code generation and
	potential pitfalls in the use of the language by the programmer.
	Do you consider that an acceptable trade-off? Why or why not? 
	
	Yes, this is an acceptable trade-off because the programmer can 
	easily change one compound expression, that may or may not affect
	the same object, into separate expressions. The efficent code
	generation is important for the speed of C++ which is a major
	advantage of the language. 
	
	When you write compound expressions, two rules of thumb can be 
	helpful:

	1. When in doubt, parenthesize expressions to force the grouping 
	that the logic of your program requires.
	2. If you change the value of an operand, don’t use that operand 
	elsewhere in the same expresion.

	An important exception to the second rule occurs when the 
	subexpression that changes the operand is itself the operand of 
	another subexpression. For example, in *++iter, the increment changes 
	the value of iter. The (now changed) value of iter is the operand to 
	the dereference operator. In this (and similar) expressions, order of 
	evaluation isn’t an issue. The increment (i.e., the subexpression 
	that changes the operand) must be evaluated before the dereference 
	can be evaluated. Such usage poses no problems and is quite common.*/
}

void NewSection(const string &text)
{
	cout << "\n\t" << text << "\n" << endl;
}