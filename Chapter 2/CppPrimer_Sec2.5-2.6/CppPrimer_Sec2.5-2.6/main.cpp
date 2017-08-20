#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Sales_data_custom.h"

void Section25();
void Section26();

void NewSection(std::string text = "");
void NewExercise(std::string text = "");

int main()
{
	double choice;
	do
	{
		std::cout << "\n\tChapter 2 - Variables and Basic Types" << std::endl;

		std::cout << "\nWhat section number? (2.5 - 2.6, 0 to skip): ";
		std::cin >> choice;

		if (choice == 2.5)
			Section25();
		else if (choice == 2.6)
			Section26();
		else if (choice != 0)
			std::cout << "\nInvalid Choice\n" << std::endl;
		std::cout << std::endl;

	} while (choice != 0);

	std::cout << "\n" << std::endl;

	system("pause");
	return 0;
}

void Section25()
{
	// Section 2.5 - Dealing with Types
	NewSection("Section 2.5 - Dealing with Types");

	// Section 2.5.1 - Type Aliases
	NewSection("Section 2.5.1 - Type Aliases");

	// Section 2.5.2 - The auto Type Specifier
	NewSection("Section 2.5.2 - The auto Type Specifier");

	// Exercise 2.33
	NewExercise("Exercise 2.33");
	{
		int i = 0, &r = i;
		auto a = r;	// a is an int (r is an alias for i, which has type int)

		const int ci = i, &cr = ci;
		auto b = ci;	// b is an int (top-level const in ci is dropped)
		auto c = cr;	// c is an int (cr is an alias for ci whose const is top-level)
		auto d = &i;	// d is an int* (& of an int object is int*)
		auto e = &ci;	// e is const int* (& of a const object is low-level object)

		const auto f = ci;	// deduced type of ci is int; f has type const int

		auto &g = ci;	// g is a const int& that is bounds to ci
						// auto &h = 42;	// error: we can't bind a plain reference to a literal
		const auto &j = 42;	// ok: we can bind a const reference to a literal

		auto k = ci, &l = i;	// k is int; l is int&
		auto &m = ci, *p = &ci;	// m is a const int&; p is a pointer to const int
								// error: type deduced from i is int; type deduced from &ci is const int
								// auto &n = i, *p2 = &ci;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << *d << std::endl;
		std::cout << "e = " << *e << std::endl;
		std::cout << "g = " << g << std::endl;

		{
			a = 42;	// a is an int assigned to literal 42
			b = 42;	// b is an int assigned to literal 42
			c = 42;	// c is an int assigned to literal 42
					// d = 42; // error: d is an int* and cannot be assigned to literal.
					// Must assign pointer to address or another pointer.
					// e = 42;	// error: e is a const int* and cannot be assigned to a literal
					// g = 42; // error: g is a const int& (reference to const int).
					// Cannot re-assign constant reference (reference to const)
		}

		// Exercise 2.34
		NewExercise("Exercise 2.34");

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << *d << std::endl;
		std::cout << "e = " << *e << std::endl;
		std::cout << "g = " << g << std::endl;

	}

	// Exercise 2.35
	NewExercise("Exercise 2.35");
	{
		/*
		Auto ordinarily ignores top-level consts. As usual in initializations,
		low-level consts, such as when an initializer is a pointer to const, are kept.

		If we want the deduced type to have a top-level const, we must say
		so explicitly.

		When we ask for a reference to an auto-deduced type, top-level
		consts in the initializer are NOT ignored. As usual, consts are
		not top-level when we bind a reference to an initializer.
		*/

		const int i = 42;

		auto j = i;	// j is an int (top-level const in i is dropped)

		const auto &k = i;	// k is a const int& (constant reference) that 
							// is bound to i. Same result as { auto &k = i }
							// Compare k with k2:
		auto &k_test = i;
		std::cout << "(k == k_test) = " << (k == k_test) << std::endl;
		// output: true
		// Can you assign to k? Should produce error. Cannot change variable
		// using const reference.
		// k = 23;	// error
		int j3 = 23;
		auto &k_test2 = j3;	// normal reference to int
		k_test2 = 0;	// can use normal reference to change non-const 
						// variable

		auto *p = &i;	// p is a pointer to const int
						// Can you use p, pointer to const int, to change i?
						// Should produce error. Cannot use pointer to const int to change
						// variable.
						// *p = 0;	// error
		auto *p2 = &j;	// p2 is a pointer to int
		*p2 = 0;	// can use normal pointer to change non-const variable

		const auto j2 = i, &k2 = i; // deduced type of i is int; j2 has
									// type const int
									// k2 is a reference to const int (const reference) that is bound
									// to i.
	}

	// Section 2.5.3 - The decltype Type Specifier
	NewSection("Section 2.5.3 - The decltype Type Specifier");

	/*
	The way decltype handles top-level const and references differ subtly
	from the way auto does. When the expression to which we apply decltype
	is a variable, decltype returns the type of that variable, including
	top-level const and references.
	*/

	// Exercise 2.36
	NewExercise("Exercise 2.36");
	{
		int a = 3, b = 4;

		// c has type int and initialized to value in a
		// equivalent to int c = 3
		// output: c = 3
		decltype(a) c = a;

		// d has type int&, reference to int, and bound to variable a
		// output: d = 3
		decltype((b)) d = a;

		// output: c = 4
		++c;

		// output: d = 4
		++d;

		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
	}

	// Exercise 2.37
	NewExercise("Exercise 2.37");
	{
		int a = 3, b = 4;

		// c has type int and initialized to value in variable a
		// c = 3
		decltype(a) c = a;

		// d has type int&, reference to int, and bound to variable a
		// d = 3
		decltype(a = b) d = a;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
	}

	// Exercise 2.38
	NewExercise("Exercise 2.38");
	{
		/*
		Describe the differences in type deduction between decltype and auto.

		auto:

		It is not uncommon to want to store the value of an expression in a variable.
		To declare the variable, we have to know the type of that expression. When
		we write a program, it can be surprisingly difficult—and sometimes even
		impossible—to determine the type of an expression. Under the new standard,
		we can let the compiler figure out the type for us by using the auto type
		specifier.

		A variable that uses auto as its type specifier must have an initializer,
		since auto tells the compiler to deduce the type from the initializer.

		We can define multiple variables using auto. Because a declaration can
		involve only a single base type, the initializers for all the variables
		in the declaration must have types that are consistent with each other.

		The type that the compiler infers for auto is not always exactly the same
		as the initializer’s type. Instead, the compiler adjusts the type to
		conform to normal initialization rules.

		First, as we’ve seen, when we use a reference, we are really using the
		object to which the reference refers. In particular, when we use a
		reference as an initializer, the initializer is the corresponding object.
		The compiler uses that object’s type for auto’s type deduction.

		Second, auto ordinarily ignores top-level consts. As usual n initializations,
		low-level consts, such as when an initializer is a pointer to const, are kept.
		If we want the deduced type to have a top-level const, we must say so
		explicitly.

		We can also specify that we want a reference to the auto-deduced type.
		Normal initialization rules still apply.

		When we ask for a reference to an auto-deduced type, top-level consts in the
		initializer are not ignored. As usual, consts are not top-level when we bind
		a reference to an initializer.

		When we define several variables in the same statement, it is important to
		remember that a reference or pointer is part of a particular declarator and
		not part of the base type for the declaration. As usual, the initializers
		must provide consistent auto-deduced types.

		decltype:

		Sometimes we want to define a variable with a type that the compiler
		deduces from an expression but do not want to use that expression to
		initialize the variable. For such cases, the new standard introduced a
		second type specifier, decltype, which returns the type of its operand.
		The compiler analyzes the expression to determine its type but does not
		evaluate the expression.

		The way decltype handles top-level const and references differs subtly
		from the way auto does. When the expression to which we apply decltype
		is a variable, decltype returns the type of that variable, including
		top-level const and references.

		It is worth noting that decltype is the only context in which a variable
		defined as a reference is not treated as a synonym for the object to which
		it refers.

		When we apply decltype to an expression that is not a variable, we get
		the type that that expression yields. As we’ll see in § 4.1.1 (p. 135),
		some expressions will cause decltype to yield a reference type. Generally
		speaking, decltype returns a reference type for expressions that yield
		objects that can stand on the left-hand side of the assignment.

		Another important difference between decltype and auto is that the
		deduction done by decltype depends on the form of its given expression.
		What can be confusing is that enclosing the name of a variable in
		parentheses affects the type returned by decltype. When we apply decltype
		to a variable without any parentheses, we get the type of that variable.
		If we wrap the variable’s name in one or more sets of parentheses, the
		compiler will evaluate the operand as an expression. A variable is an
		expression that can be the left-hand side of an assignment. As a result,
		decltype on such an expression yields a reference.

		Remember that decltype((variable)) (note, double parentheses) is always
		a reference type, but decltype(variable) is a reference type only if
		variable is a reference.
		*/

		// Give an example of an expression where auto and decltype will deduce
		// the same type and an example where they will deduce differing types.

		int i = 23;
		const int ci = 0;

		// Same deduced type:
		auto a1 = i;	// a1 has type int
		decltype(i) a2 = i;	// a2 has type int

							// Different deduced type:
		auto b1 = ci;	// b1 has type int
		decltype(ci) b2 = ci;	// b2 as type const int

	}
}

void Section26()
{
	// Section 2.6 - Defining our Own Data Structures
	NewSection("Section 2.6 - Defining our Own Data Structures");

	// Section 2.6.1 - Defining the Sales_data Type
	NewSection("Section 2.6.1 - Defining the Sales_data Type");
	{
		struct Sales_data {
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		// Exercise 2.39
		NewExercise("Exercise 2.39");
		{
			// struct Foo { /* empty */ }	// Note: no semicolon
			// error: expected a ";" on line after struct definition
		}

		// Exercise 2.40
		NewExercise("Exercise 2.40");
		{
			// see struct Sales_data definition under Section 2.6.1
		}
	}

	// Section 2.6.2 - Using the Sales_data Class
	NewSection("Section 2.6.2 - Using the Sales_data Class");
	{
		// See Sales_data Class in main function

		// Exercsise 2.41
		NewExercise("Exercise 2.41");
		{
			// see chapter_2.6.2_exercise.cpp using Dev-C++
		}
	}

	// Section 2.6.3 - Writing Our Own Header Files
	NewSection("Section 2.6.3 - Writing Our Own Header Files");
	{
		// Exercise 2.42
		NewExercise("Exercise 2.42");
		{
			// see chapter_2.6.3_exercise.cpp using Dev-C++
		}
	}
}

void NewSection(std::string text)
{
	std::cout << "\n\t" << text << std::endl;
}

void NewExercise(std::string text)
{
	std::cout << "\n\t" << text << "\n" << std::endl;
}