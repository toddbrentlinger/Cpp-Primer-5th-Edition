#include <iostream>
#include <string>

// Function prototypes
void NewSectionTitle(std::string customText = "");
void NewExerciseTitle(std::string customText = "");

int main()
{
	// Section 2.4 - const Qualifier

	std::cout << "\n\tSection 2.4 - const Qualifier" << std::endl;

	// Exercise 2.26

	std::cout << "\n\tExercise 2.26\n" << std::endl;
	std::cout << "See code" << std::endl;

	// error: buf is uninitialized const
	//const int buf;

	// legal
	int cnt = 0;

	// legal
	const int sz = cnt;

	// error: cannot assign to const object sz
	// ++cnt; ++sz;

	// Section 2.4.1 - References to const

	std::cout << "\n\tSection 2.4.1 - References to const" << std::endl;

	{
		int i = 42;
		const int &r1 = i;
		const int &r2 = 42;
		const int &r3 = r1 * 2;
		// error: can't initialize non-const reference, r4, to const, (i * 2)
		// int &r4 = i * 2;
		// int &r5 = r1 * 2;

		double dval = 3.14;
		const int &rd = dval;

		const int temp = dval;
		const int &rd2 = temp;
	}

	// Section 2.4.2 - Pointers and const

	// std::cout << "\n\tSection 2.4.2 - Pointers and const" << std::endl;
	NewSectionTitle("Section 2.4.2 - Pointers and const");

	// Exercise 2.27

	// std::cout << "\n\tExercise 2.27\n" << std::endl;
	NewExerciseTitle("Exercise 2.27");
	std::cout << "See code" << std::endl;

	{
		// (a)
		// error: Non-const reference r needs to initialize to non-const object
		// int i = -1, &r = 0;
		// Correction:
		int ia = -1;
		const int &ra = 0;

		// (b)
		// legal: Constant pointer p2 initialized to i. Address stored in p2
		// cannot be changed.
		int ib = -1;
		int *const p2 = &ib;

		// (c)
		// legal: Reference to a constant rc can be binded to a literal 0.
		const int ic = -1, &rc = 0;

		// (d)
		// legal: Constant pointer to a constant p3 can be initialized to
		// non-constant int ib. Address stored in p3 cannot be changed.
		// Cannot use pointer p3 to change int ib.
		const int *const p3 = &ib;

		// (e)
		// legal: Pointer to a constant p1 can be initialized to point to a
		// non-constant int. Can't use pointer p1 to chang int ib.
		const int *p1 = &ib;

		// (f)
		// error: Cannot define constant reference to a constant because
		// references are not objects that can be made constant.
		// const int &const r2;

		// (g)
		// legal: Reference to a constant r can be binded to a non-constant
		// or constant int.
		const int ig1 = ib, &r1 = ib;	// ib is int
		const int ig2 = ic, &r2 = ic;	// ic is const int
	}

	// Exercise 2.28

	NewExerciseTitle("Exercise 2.28");
	std::cout << "See code" << std::endl;

	{
		// (a)
		// error: Constant pointer cp needs to be initialized.
		// int i, *const cp;
		// Correction: Initialize constant pointer cp to address of int i.
		int i, *const cp = &i;

		// (b)
		// error: Constant pointer p2 needs to be initialized.
		// int *p1, *const p2;
		// Correction: Initialize pointer p1 to i and
		// constant pointer p2 to pointer p1
		int *p1 = &i, *const p2 = p1;

		// (c)
		// error: Constant int ic needs to be initialized
		// const int ic, &r = ic;
		// Correction: Initialize constant int ic to literal int 0.
		const int ic = 0, &r = ic;

		// (d)
		// error: Constant pointer to a constant p3 needs to be initialized
		// const int *const p3;
		// Correction: Initialize constant pointer to a constant p3 to
		// address of constant int ic
		const int *const p3 = &ic;

		// (e)
		// legal: Pointer to a constant does not need to be initialized.
		// Pointer can be assigned a different address but cannot be used
		// to change the value that p points.
		const int *p;

		NewExerciseTitle("Exercise 2.29");
		std::cout << "See code" << std::endl;

		// (a)
		// legal:
		i = ic;

		// (b)
		// error: Cannot assign constant pointer to a constant p3 to a 
		// non-constant pointer p1. Pointed-to types don't match.
		// p1 = p3;

		// (c)
		// error: Cannot assign a const int ic to a non-constant 
		// pointer p1
		// p1 = &ic;

		// (d)
		// error: Cannot assign to constant pointer to a constant p3. Address 
		// stored in pointer p3 cannot be changed.
		// p3 = &ic;

		// (e)
		// error: Cannot assign to constant pointer p2. Address stored in 
		// pointer p2 cannot be changed.
		// p2 = p1;

		// (f)
		// error: Cannot assign to constant int ic. 
		// ic = *p3;
	}

	// Section 2.4.3 - Top-Level const

	NewSectionTitle("Section 2.4.3 - Top-Level const");

	// Exercise 2.30

	NewExerciseTitle("Exercise 2.30");

	{
		int i = 0;

		// Constant int v2 has top-level const
		const int v2 = 0;

		// v1 has no const and v2 has top-level const. Both have 
		// no low-level const. Same low-level const qualifications.
		int v1 = v2;

		// p1 has no const and v1 has no const. Same low-level const 
		// qualifications. r1 has no const as well.
		int *p1 = &v1, &r1 = v1;

		// p2 has low-level const and v2 has top-level const. p3 has 
		// top-level const and i has no const. r2 has low-level const.
		// const in reference types is always low-level
		const int *p2 = &v2, *const p3 = &i, &r2 = v2;

		// Exercise 2.31

		NewExerciseTitle("Exercise 2.31");

		// ok: Equivalent to v1 = v2.
		// Reference r1 is not a constant, can be used to reassign v1.
		// The value in v2 is copied into v1. It doesn't matter whether
		// either or both of the objects are consts.
		r1 = v2;

		// error: p2 has low-level const but p1 does not
		// p1 = p2;

		// ok: can convert non-const int*(p1) to const int*(p2)
		p2 = p1;

		// error: p3 has low-level const but p1 does not
		// p1 = p3;

		// ok: p2 has same low-level const qualifications as p3
		p2 = p3;
	}

	// Section 2.4.4 - constexpr and Constant Expressions

	NewSectionTitle("Section 2.4.4 - constexpr and Constant Expressions");

	// Exercise 2.32

	NewExerciseTitle("Exercise 2.32");
	{
		// illegal: No address-of operator. Need to initialize pointer to
		// address of object, not the object itself.
		// int null = 0, *p = null;

		int null = 0, *p = &null;
	}

	system("pause");
	return 0;
}

void NewSectionTitle(std::string customText)
{
	std::cout << "\n\t" << customText << std::endl;
}

void NewExerciseTitle(std::string customText)
{
	std::cout << "\n\t" << customText << "\n" << std::endl;
}