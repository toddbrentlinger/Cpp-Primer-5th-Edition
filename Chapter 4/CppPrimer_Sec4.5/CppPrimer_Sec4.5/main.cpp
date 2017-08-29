#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section45();
void Exercise417();
void Exercise418();
void Exercise419();

inline void NewSection(const string &text = "") 
{
	cout << "\n\t" << text << "\n" << endl;
}

int main()
{
	Section45();

	system("pause");
	return 0;
}

void Section45()
{
	// Section 4.5 - Increment and Decrement Operators
	NewSection("Section 4.5 - Increment and Decrement Operators");

	{
		int i = 0, j;
		j = ++i;	// j = 1, i = 1: prefix yields the incremental value
		j = i++;	// j = 1, i = 2: postfix yields the unincremental value

		/*
		These operators require lvalue operands. The prefix operators return 
		the object itself as an lvalue. The postfix operators return a copy of 
		the object’s original value as an rvalue.
		*/
	}

	// Combining Dereference and Increment in a Single Expression

	{
		const vector<int> v = { 5,4,3,2,1,0,-1,-2,-3 };

		auto pbeg = v.begin();
		// print the elements up to the first negative value
		while (pbeg != v.end() && *pbeg >= 0)
			cout << *pbeg++ << endl;	// print the current value and advance pbeg

		/*
		The precedence of postfix increment is higher than that of the 
		dereference operator, so *pbeg++ is equivalent to *(pbeg++). The 
		subexpression pbeg++ increments pbeg and yields a copy of the previous 
		value of pbeg as its result. Accordingly, the operand of * is the 
		unincremented value of pbeg. Thus, the statement prints the element to 
		which pbeg originally pointed and increments pbeg.

		This usage relies on the fact that postfix increment returns a copy of 
		its original, unincremented operand. If it returned the incremented 
		value, we’d dereference the incremented value, with disastrous results. 
		We’d skip the first element. Worse, if the sequence had no negative 
		values, we would attempt to dereference one too many elements.
		*/
	}

	// Remember That Operands Can Be Evaluated in Any Order

	{
		string s("hello world");

		for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
			*it = toupper(*it);	// capitalize the current character
		/*
		auto beg = s.begin();
		// the behavior of the following loop is undefined!
		while (beg != s.end() && !isspace(*beg))
			*beg = toupper(*beg++);	// error: this assignment is undefined
		// compiler might evaluate this expression as either:
		*beg = toupper(*beg);	// execution if left-hand side is evaluated first
		*(beg + 1) = toupper(*beg);	// execution if right-hand is evaluated first
		// or it might evaluate it in yet some other way
		*/
	}

	double choice;
	do
	{
		cout << "\nWhat exercise number? (4.17 - 4.19, 0 to skip): ";
		cin >> choice;

		if (choice == 4.17)
			Exercise417();
		else if (choice == 4.18)
			Exercise418();
		else if (choice == 4.19)
			Exercise419();
		else if (choice != 0)
			cout << "\nInvalid Choice" << endl;

	} while (choice != 0);
}

void Exercise417()
{
	// Exercise 4.17
	NewSection("Exercise 4.17");

	/*
	Explain the difference between prefix and postfix increment.
	
	There are two forms of these operators: prefix and postfix. So far, we 
	have used only the prefix form. This form increments (or decrements) its 
	operand and yields the changed object as its result. The postfix operators 
	increment (or decrement) the operand but yield a copy of the original, 
	unchanged value as its result:
	*/
	int i = 0, j;
	j = ++i; //	j = 1, i = 1: prefix yields the incremented value
	j = i++; // j = 1, i = 2: postfix yields the unincremented value
	/*
	These operators require lvalue operands. The prefix operators return the 
	object itself as an lvalue. The postfix operators return a copy of the 
	object’s original value as an rvalue.
	*/
}

void Exercise418()
{
	// Exercise 4.18
	NewSection("Exercise 4.18");

	/*
	What would happen if the while loop on page 148 that prints the elements 
	from a vector used the prefix increment operator?

	The pointer pbeg would be incremented first before before dereferenced.
	The first element would be skipped and if the sequence had no negative
	values, the while loop would attempt to dereference one too many elements.
	*/
}

void Exercise419()
{
	// Exercise 4.19
	NewSection("Exercise 4.19");

	/*
	Given that ptr points to an int, that vec is a vector<int>, and that ival 
	is an int, explain the behavior of each of these expressions. 
	Which, if any, are likely to be incorrect? Why? How might each be corrected?
	*/

	int ival, *ptr = &ival;
	vector<int> vec{ 0,1,2,3,4,5 };

	// (a)

	cout << "\n(a)\n" << endl;

	/*
	
	ptr != 0 && *ptr++;
	
	The condition first tests whether pointer ptr points to an object, 
	resulting in a nonzero bool value, or a null pointer, resulting in a 
	bool value of zero. If the pointer is NOT a null pointer, meaning there is
	on object to which the pointer points, the condition then continues to the 
	second expression. Since the precedence of postfix increment is higher than 
	that of the dereference operator, the expression *ptr++ is equivalent to 
	*(ptr++). The subexpression ptr++ increments ptr and yields a copy of the 
	previous value of ptr as its result. Accordingly, the operand of * is the 
	unincremented value of ptr. Thus, the statement prints the element to which 
	ptr originally pointed, converts to logical bool which outputs TRUE
	for any nonzero value, and then increments ptr.

	Incorrect since ptr is a pointer to an int and when the pointer itself is
	incremented, it will then point to some random piece of memory. The error
	can be corrected by using parentheses to dereference the ptr before incrementing
	the value.

	Correction: 

	ptr != 0 && (*ptr)++

	*/

	ival = 0;
	cout << "If int ival = " << ival << ", *ptr = " << *ptr << "\t"
		<< (ptr != 0 && (*ptr)++ ? "TRUE" : "FALSE") << endl;
	// Output: FALSE

	ival = 23;
	cout << "If int ival = " << ival << ", *ptr = " << *ptr << "\t"
		<< (ptr != 0 && (*ptr)++ ? "TRUE" : "FALSE") << endl;
	// Output: TRUE

	*ptr = -1;
	cout << "If int ival = " << ival << ", *ptr = " << *ptr << "\t"
		<< (ptr != 0 && (*ptr)++ ? "TRUE" : "FALSE") << endl;
	// Output: TRUE

	ptr = 0;	// null pointer
	cout << "If int *ptr = 0 (null pointer)	\t"
		<< (ptr != 0 && (*ptr)++ ? "TRUE" : "FALSE") << endl;
	// Output: FALSE
	cout << "ptr is " << (ptr == 0 ? "" : "NOT") << " a null pointer" << endl;
	cout << "ptr is " << (ptr == nullptr ? "" : "NOT") << " a null pointer" << endl;

	// (b)

	cout << "\n(b)\n" << endl;

	/*
	
	ival++ && ival;
	
	The condition first increments ival and yields a copy of the
	previous value of ival at its result to be converted to a logical bool.
	If the first, original value of ival is nonzero, then the condition
	continues to test the new, incremented value of ival. If this incremented
	value of ival is nonzero, it will output TRUE, and if the value of ival
	is zero, it will output FALSE.
	The condition will output FALSE if ival is initially equal to -1 or 0.
	It will output TRUE for other int values.
	*/

	ival = -1;
	cout << "If ival = " << ival << "\t"
		<< (ival++ && ival ? "TRUE" : "FALSE") << endl;
	// Output: FALSE

	ival = 0;
	cout << "If ival = " << ival << "\t"
		<< (ival++ && ival ? "TRUE" : "FALSE") << endl;
	// Output: FALSE

	ival = 1;
	cout << "If ival = " << ival << "\t"
		<< (ival++ && ival ? "TRUE" : "FALSE") << endl;
	// Output: TRUE

	// (c)

	cout << "\n(c)\n" << endl;

	/*
	 
	vec[ival++] <= vec[ival];
	
	Most operators give no guarantee as to the order in which operands will
	be evaluated. This matters when one subexpression changes the value of
	an operand that is unsed in another subexpression. Increment and
	decrement operators change their operands.
	
	The expression is undefined since both the left- and right-hand operands
	use ival and the left-hand operand chanes ival. The compiler might
	evaluate this expression as either:

	vec[ival] <= vec[ival + 1];	// execution if left-operand evaluated first
	vec[ival] <= vec[ival];		// execution if right-operand evaluated first
	

	Correction:

	vec[ival] <= vec[ival + 1]
	
	*/

	ival = 0;
	// undefined
	if (vec[ival++] <= vec[ival])
		cout << "TRUE" << endl;

	ival = 0;
	// correction
	if (vec[ival] <= vec[ival + 1])
		cout << "TRUE" << endl;
}