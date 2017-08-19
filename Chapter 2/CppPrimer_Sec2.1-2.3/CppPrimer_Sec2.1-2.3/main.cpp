#include <iostream>
#include <string>

// for exercise 2.10
std::string global_str;
int global_int;

// for exercise 2.13
int l = 42;

int main() {

	// Chapter 2: Variables and Basic Types

	std::cout << "\nChapter 2: Variables and Basic Types" << std::endl;

	// Section 2.1.2 - Type Conversions

	std::cout << "\n\tSection 2.1.2 - Variables and "
		"Basic Types" << std::endl;

	// Exercise 2.3

	std::cout << "\nExercise 2.3 - 2.4" << std::endl;

	unsigned u = 10, u2 = 43;
	std::cout << u2 - u << std::endl;	// output: 33
	std::cout << u - u2 << std::endl;	// output: 4294967263

	int i = 10, i2 = 43;
	std::cout << i2 - i << std::endl;	// output: 33
	std::cout << i - i2 << std::endl;	// output: -33

	std::cout << i - u << std::endl;	// output: 0
	std::cout << u - i << std::endl;	// output: 0

										// Section 2.1.3 - Literals

	std::cout << "\n\tSection 2.1.3 - Literals" << std::endl;

	std::cout << "\na really, really long string literal "
		"that spans two lines" << std::endl;

	std::cout << "\n newline" << std::endl;
	std::cout << "\v vertical tab" << std::endl;
	std::cout << "\\ backslash" << std::endl;
	std::cout << "\r carriage return" << std::endl;
	std::cout << "\t horizontal tab" << std::endl;
	std::cout << "\b backspace" << std::endl;
	std::cout << "\? question mark" << std::endl;
	std::cout << "\f form feed" << std::endl;
	std::cout << "\a alert(bell)" << std::endl;
	std::cout << "\" double quote" << std::endl;
	std::cout << "\' single quate" << std::endl;

	// Exercise 2.8

	std::cout << "\nExercise 2.8" << "\n" << std::endl;

	std::cout << "2\x4d" << "\n" << std::endl;
	std::cout << "2" << "\t" << "\115" << "\n" << std::endl;

	// Section 2.2.1 - Variable Definitions

	std::cout << "\n\tSection 2.2.1 - Variable Definitions" << std::endl;

	// Exercise 2.9

	std::cout << "\nExercise 2.9\n" << std::endl;

	long double ld = 3.1415926536;
	// int a{ ld }, b = { ld };	// error: narrowing conversion required
	int c(ld), d = ld;	// ok: but value will be truncated

						// std::cin >> int input_value;	// error
	int input_value;
	std::cout << "Input int: ";
	std::cin >> input_value;
	// int j = { 3.14 };	// error: narrowing conversion required
	// double salary = wage = 9999.99;	// error: wage not declared in this scope
	double salary = 9999.99, wage = 9999.99;
	int k = 3.14;	// output: k = 3

	std::cout << "\nOutput" << std::endl;
	std::cout << "input_value = " << input_value << std::endl;
	// std::cout << "j = " << j << std::endl;
	std::cout << "salary = " << salary << std::endl;
	std::cout << "wage = " << wage << std::endl;
	std::cout << "k = " << k << std::endl;

	// Exercise 2.10

	std::cout << "\nExercise 2.10\n" << std::endl;

	// uninitialized local variable
	int local_int;
	// will produce error if program tries to access local_int

	std::string local_str;
	std::string local_str_test("TEST");

	// global_int = 0 - variables of built-in type defined 
	// outside any function body are initialized to zero
	std::cout << "global_int: " << global_int << std::endl;
	// error: uninitialized local variable used
	// std::cout << "local_int: " << local_int << std::endl;
	// empty string
	std::cout << "global_str: " << global_str << std::endl;
	// empty string
	std::cout << "local_str: " << local_str << std::endl;
	// TEST
	std::cout << "local_str_test: " << local_str_test << std::endl;

	// Section 2.2.2 - Variable Declarations and Definitions

	std::cout << "\n\tSection 2.2.2 - Variable Declarations "
		"and Definitions" << std::endl;

	// Exercise 2.11

	std::cout << "\nExercise 2.11\n" << std::endl;

	std::cout << "extern int ix = 1024; // definition" << std::endl;
	std::cout << "int iy; // declares and defines iy" << std::endl;
	std::cout << "extern int iz; // declares but does not define iz"
		<< std::endl;

	// Section 2.2.3 - Identifiers

	std::cout << "\n\tSection 2.2.3 - Identifiers" << std::endl;

	// Exercise 2.12

	std::cout << "\nExercise 2.12\n" << std::endl;

	// int double = 3.14;	// invalid: double is an illegal identifier
	int _;	// valid
			// invalid: catch is an illegal identifier; - is illegal
			// int catch-22;
			// int 1_or_2 = 1;	// invalid: identiier can't start with number
	double Double = 3.14;	// valid

							// Section 2.2.4 - Scope of a Name

	std::cout << "\n\tSection 2.2.4 - Scope of a Name" << std::endl;

	// Exercise 2.13

	std::cout << "\nExercise 2.13\n" << std::endl;

	int l = 100;
	int m = l;	// output: m =  100

	std::cout << "m = " << m << std::endl;

	// Exercise 2.14

	std::cout << "\nExercise 2.14\n" << std::endl;

	int n = 100, sum = 0;
	for (int n = 0; n != 10; ++n)
		sum += n;
	std::cout << n << " " << sum << std::endl;
	// output: 100 45 (0+1+2+3+4+5+6+7+8+9 = 45)

	// Section 2.3 - Compound Types

	std::cout << "\n\tSection 2.3 - Compound Types" << std::endl;

	// Section 2.3.1 - References

	std::cout << "\n\tSection 2.3.1 - References" << std::endl;

	// Exercise 2.15

	std::cout << "\nExercise 2.15\n" << std::endl;

	// valid
	int ival = 1.01;

	// error: referenence must be bound to an object, not to a 
	// literal
	// int &rval1 = 1.01;

	// valid: rval2 refers to (is another name for) ival
	int &rval2 = ival;

	// error: There is no way to rebind a reference to refer to a
	// different object. Because there is no way to rebind a 
	// reference, references must be initialized.
	// int &rval3;

	// Exercise 2.16

	std::cout << "\nExercise 2.16\n" << std::endl;

	int i4 = 1, &r1 = i4; double d2 = 0.0, &r2 = d2;

	// valid: assigns 3.14159 to the object to which r2 refers,
	// i.e., to d2
	r2 = 3.14159;

	// valid: assigns the object to which r1 refers (to i2) to the
	// object to which r2 refers (to d2); d2 = i2;
	r2 = r1;

	// valid: assigns the object to which r2 refers (to d2) to the
	// object i2; value is truncated from a double 1.0 to int 1 ?
	i4 = r2;

	// error: 
	r1 = d2;

	// output: 1 1 1 1
	std::cout << i4 << " " << r1 << " " << d2 << " " << r2 << std::endl;
	// output: true
	std::cout << (i4 == d2) << std::endl;

	// Exercise 2.17

	std::cout << "\nExercise 2.17\n" << std::endl;

	// output: 10 10
	int i3, &r3 = i3;
	i3 = 5; r3 = 10;
	std::cout << i3 << " " << r3 << std::endl;

	// Section 2.3.2 - Pointers

	std::cout << "\n\tSection 2.3.2 - Pointers" << std::endl;

	int itest = 23;
	int *test_ptr = &itest;
	int *test_ptr2 = nullptr;
	test_ptr2 = &itest;
	int *test_ptr3 = nullptr;

	// error: cannot assign address to int
	// *test_ptr = &itest;

	std::cout << "\n(test_ptr == test_ptr2) = " <<
		(test_ptr == test_ptr2) << std::endl;

	// Exercise 2.18

	std::cout << "\n\tExercise 2.18\n" << std::endl;

	int i18 = 18, *ptr18 = nullptr;
	std::cout << "ptr18 = " << "nullptr" << "; *ptr18 = "
		<< "nullptr" << std::endl;

	std::cout << "\nChange the value of a pointer" << std::endl;
	ptr18 = &i18;
	std::cout << "ptr18 = " << ptr18 << "; *ptr18 = "
		<< *ptr18 << std::endl;

	std::cout << "\nChange the value to which the pointer points" << std::endl;
	*ptr18 = 23;
	std::cout << "ptr18 = " << ptr18 << "; *ptr18 = "
		<< *ptr18 << std::endl;

	// Exercise 2.19

	std::cout << "\n\tExercise 2.19\n" << std::endl;

	std::cout << "A pointer is a compound type that “points to another type. Like references, pointers \n"
		"are used for indirect access to other objects.Unlike a reference, a pointer is an object \n"
		"in its own right. Pointers can be assigned and copied; a single pointer can point to \n"
		"several different objects over its lifetime. Unlike a reference, a pointer need not be \n"
		"initialized at the time it is defined. Like other built - in types, pointers defined at block \n"
		"scope have undefined value if they are not initialized. Because references are not objects, \n"
		"they don’t have addresses. Hence, we may not define a pointer to a reference.\n"
		"Both pointers and references give indirect access to other objects. However, there are \n"
		"important differences in how they do so. The most important is that a reference is not \n"
		"an object. Once we have defined a reference, there is no way to make that reference \n"
		"refer to a different object. When we use a reference, we always get the object to \n"
		"which the reference was initially bound. \n"
		"There is no such identity between a pointer and the address that it holds.As with \n"
		"any other (nonreference) variable, when we assign to a pointer, we give the pointer \n"
		"itself a new value. Assignment makes the pointer point to a different object." << std::endl;

	// Exercise 2.20

	std::cout << "\n\tExercise 2.20\n" << std::endl;

	int i20 = 42;
	int *pl20 = &i20;	// pl20 initialized to hold the address of i20
	*pl20 = *pl20 * *pl20; // value in i20 is changed; 42 * 42
	std::cout << "*pl20 = " << *pl20 << " " << 42 * 42 << std::endl;

	// Exercise 2.21

	std::cout << "\n\tExercise 2.21\n" << std::endl;

	int i21 = 0;

	// error: Types of dp and i21 differ. The types of the pointer
	// and the object to which it points must match.
	// double* dp = &i21;

	// error: Can't initialize a pointer to a variable. Must use
	// the address of the object when initializing a pointer
	// int *ip = i21;
	// Correction:
	int *ip = 0;	// nullptr
	ip = &i21;

	// valid
	int *p = &i21;

	// Exercise 2.22

	std::cout << "\n\tExercise 2.22\n" << std::endl;

	int i22 = 23, *ptr22 = &i22;
	if (ptr22)
		std::cout << "ptr22 = " << ptr22 << " (true)" << std::endl;
	else
		std::cout << "ptr22 = " << ptr22 << " (false)" << std::endl;
	if (*ptr22)
		std::cout << "*ptr22 = " << *ptr22 << " (true)" << std::endl;
	else
		std::cout << "*ptr22 = " << *ptr22 << " (false)" << std::endl;

	std::cout << std::endl;

	ptr22 = nullptr;
	if (ptr22)
		std::cout << "ptr22 = " << ptr22 << " (true)" << std::endl;
	else
		std::cout << "ptr22 = " << ptr22 << " (false)" << std::endl;
	/* error: can't dereference a nullptr
	if (*ptr22)
	std::cout << "*ptr22 = " << "nullptr" << " (true)" << std::endl;
	else
	std::cout << "*ptr22 = " << "nullptr" << " (false)" << std::endl;
	*/

	std::cout << std::endl;

	i22 = 0, ptr22 = &i22;
	if (ptr22)
		std::cout << "ptr22 = " << ptr22 << " (true)" << std::endl;
	else
		std::cout << "ptr22 = " << ptr22 << " (false)" << std::endl;
	if (*ptr22)
		std::cout << "*ptr22 = " << *ptr22 << " (true)" << std::endl;
	else
		std::cout << "*ptr22 = " << *ptr22 << " (false)" << std::endl;

	// Exercise 2.23

	std::cout << "\n\tExercise 2.23\n" << std::endl;

	// Exercise 2.24

	std::cout << "\n\tExercise 2.24\n" << std::endl;

	std::cout << "int i = 42; \t void *p = &i; \t long *lp = &i;" << std::endl;

	int i24 = 42;
	void *p24 = &i24;
	// error: Types of lp and i differ. The types of the pointer
	// and the object to which it points must match, unless the 
	// pointer of type void. Type void pointer can hold the address
	// of any object.
	// long *lp24 = &i24;

	// Section 2.3.3 - Understandng Compound Type Declarations

	std::cout << "\n\tSection 2.3.3 - Understanding Compound "
		"Type Declarations" << std::endl;

	// Exercise 2.25

	std::cout << "\n\tExercise 2.25\n" << std::endl;

	{
		// ip is a pointer to a int. r is a reference to an int
		int* ip = 0, &r = *ip;
		std::cout << typeid(ip).name() << std::endl;
		std::cout << typeid(r).name() << std::endl;
		// i is an int. ip0 is a pointer to an int iniitialized to nullptr
		int i, *ip0 = 0;
		std::cout << typeid(i).name() << std::endl;
		std::cout << typeid(ip0).name() << std::endl;
		// ip1 is pointer to an int. ip2 is an int
		int* ip1, ip2;
		std::cout << typeid(ip1).name() << std::endl;
		std::cout << typeid(ip2).name() << std::endl;
	}

	system("pause");
	return 0;
}