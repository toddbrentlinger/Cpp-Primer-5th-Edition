#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::begin; using std::end;

void Exercise343();
void Exercise344();
void Exercise345();

void NewSection(const string &text = "");

int main()
{
	// Section 3.6 - Multidimensional Arrays
	NewSection("Section 3.6 - Multidimensional Arrays");

	{
		// array of size 3; each element is an array of ints of size 4
		int ia1[3][4];

		// array of size 10; each element is a 20-element array who elements
		// are arrays of 30 ints
		int arr[10][20][30] = { 0 };	// initialize all elements to 0

		// three elements; each element is in array of size 4
		int ia[3][4] = {
			{0,1,2,3},	// initializers for the row indexed by 0
			{4,5,6,7},	// initializers for the row indexed by 1
			{8,9,10,11}	// initializers for the row indexed by 2
		};

		// equivalent initialization without the optional nested braces
		// for each row
		int ia2[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

		// explicitly initialize only element 0 in each row
		int ia3[3][4] = { { 0 },{ 4 },{ 8 } };

		// explicitly initialize row 0; 
		// the remaining elements are value initialized to 0
		int ix[3][4] = { 0,3,6,9 };

		// assigns the first element of arr to the last element in the last
		// row of ia. Array ia is 3x4 and uses index [2][3] to access last
		// element in array.
		ia[2][3] = arr[0][0][0];

		// binds row to the second four-element array in ia
		int(&row)[4] = ia[1];

		constexpr size_t rowCnt = 3, colCnt = 4;
		int ia4[rowCnt][colCnt];	// 12 uninitialized elements
		// for each row
		for (size_t i = 0; i != rowCnt; ++i) {
			// for each column
			for (size_t j = 0; j != colCnt; ++j) {
				// assign the element's positional index as its value
				ia4[i][j] = i * colCnt + j;
			}
		}
	}
	{
		// Using a Range for with Multidimensional Arrays

		constexpr size_t rowCnt = 3, colCnt = 4;
		int ia[rowCnt][colCnt];	// 12 uninitialized elements

		size_t cnt = 0;
		for (auto &row : ia)	// for every element in the outer array
			for (auto &col : row) {	// for every element in the inner array
				col = cnt;	// give this element the next value
				++cnt;		// increment cnt
			}
		/* The first for iterates through the elements in ia. Those elements 
		are arrays of size 4. Thus, the type of row is a reference to an 
		array of four ints. The second for iterates through one of those 
		4-element arrays. Hence, col is int&. On each iteration we assign 
		the value of cnt to the next element in ia and increment cnt. */

		for (const auto &row : ia)	// for every element in the outer array
			for (auto col : row)	// for every element in the inner array
				cout << col << endl;

		for (const auto &row : ia) {
			for (auto col : row)
				cout << col << " ";
			cout << endl;
		}

		/* To use a multidimensional array in a range for, the loop control 
		variable for all but the innermost array must be references. */
	} 
	{
		// Pointers and Multidimensional Arrays

		// array of size 3; each element is an array of ints of size 4
		int ia[3][4];

		// p points to an array of four ints
		int(*p)[4] = ia;

		// p now points to the last element in ia
		p = &ia[2];

		// assign values to each element in array ia
		size_t cnt = 0;
		for (auto &row : ia)	// for every element in the outer array
			for (auto &col : row) {	// for every element in the inner array
				col = cnt;	// give this element the next value
				++cnt;		// increment cnt
			}

		// print the value of each element in ia, with each inner array
		// on its own line
		// p points to an array of four ints
		for (auto p = ia; p != ia + 3; ++p) {
			// q points to the first element of an array of four ints;
			// that is, q points to an int
			for (auto q = *p; q != *p + 4; ++q)
				cout << *q << ' ';
			cout << endl;
		}

		// p points to the first array in ia
		for (auto p = std::begin(ia); p != std::end(ia); ++p) {
			// q points to the first element in an inner array
			for (auto q = std::begin(*p); q != std::end(*p); ++q)
				cout << *q << ' ';	// prints the int value to which q points
			cout << endl;
		}
		/* In the outer loop, that type is a pointer to an array of four
		ints. In the inner loop, that type is a pointer to int. */

		// Type Aliases Simiplify Pointers to Multidimensional Arrays

		// new style type alias declaration; see § 2.5.1 (p.68)
		using int_array = int[4];

		// equivalent typedef declaration; § 2.5.1 (p. 67)
		typedef int int_array2[4];

		// print the value of each element in ia, with each inner array
		// on its own line
		for (int_array *p = ia; p != ia + 3; ++p) {
			for (int *q = *p; q != *p + 4; ++q)
				cout << *q << ' ';
			cout << endl;
		}
	}

	double choice;
	do
	{
		cout << "\nWhat exercise number? (3.43 - 3.45, 0 to skip): ";
		cin >> choice;

		if (choice == 3.43)
			Exercise343();
		else if (choice == 3.44)
			Exercise344();
		else if (choice == 3.45)
			Exercise345();
		else if (choice != 0)
			cout << "\nInvalid Choice\n" << endl;

	} while (choice != 0);

	return 0;
}

void Exercise343()
{
	// Exercise 3.43
	NewSection("Exercise 3.43");

	// initialize ia, 3x4 array of ints
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];	// 12 uninitialized elements
	size_t cnt = 0;
	for (auto &row : ia)	// for every element in the outer array
		for (auto &col : row) {	// for every element in the inner array
			col = cnt;	// give this element the next value
			++cnt;		// increment cnt
		}

	/* Write three different versions of a program to print the elements
	of ia. Write all the types directly. */

	// Range for
	for (const int(&row)[colCnt] : ia) {
		for (const int col : row)
			cout << col << ' ';
		cout << endl;
	}
	// For loop using subscripts
	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j != colCnt; ++j)
			cout << ia[i][j] << ' ';
		cout << endl;
	}
	// For loop using pointers
	for (int(*row)[colCnt] = std::begin(ia); row != std::end(ia); ++row) {
		for (int *col = *row; col != std::end(*row); ++col)
			cout << *col << ' ';
		cout << endl;
	}
}

void Exercise344()
{
	// Exercise 3.44
	NewSection("Exercise 3.44");

	// initialize ia, 3x4 array of ints
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];	// 12 uninitialized elements
	size_t cnt = 0;
	for (auto &row : ia)	// for every element in the outer array
		for (auto &col : row) {	// for every element in the inner array
			col = cnt;	// give this element the next value
			++cnt;		// increment cnt
		}

	/* Rewrite the programs from the previous exercises using a type
	alias for the type of the loop control variables. */

	// Range for
	typedef const int(&rowArray)[colCnt];

	for (rowArray row : ia) {
		for (const int &col : row)
			cout << col << ' ';
		cout << endl;
	}

	// For loop using subscripts
	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j != colCnt; ++j)
			cout << ia[i][j] << ' ';
		cout << endl;
	}

	// For loop using pointers
	typedef const int(*rowPointer)[colCnt];

	for (rowPointer row = begin(ia); row != end(ia); ++row) {
		for (const int *col = *row; col != end(*row); ++col)
			cout << *col << ' ';
		cout << endl;
	}
}

void Exercise345()
{
	// Exercise 3.45
	NewSection("Exercise 3.45");

	// initialize ia, 3x4 array of ints
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];	// 12 uninitialized elements
	size_t cnt = 0;
	for (auto &row : ia)	// for every element in the outer array
		for (auto &col : row) {	// for every element in the inner array
			col = cnt;	// give this element the next value
			++cnt;		// increment cnt
		}

	/* Rewrite the programs again, this time using auto. */

	// Range for
	for (auto &row : ia) {
		for (auto col : row)
			cout << col << ' ';
		cout << endl;
	}

	// For loop using subscripts
	for (auto i = 0; i != rowCnt; ++i) {
		for (auto j = 0; j != colCnt; ++j)
			cout << ia[i][j] << ' ';
		cout << endl;
	}

	// For loop using pointers
	for (auto row = begin(ia); row != end(ia); ++row) {
		for (auto col = *row; col != end(*row); ++col)
			cout << *col << ' ';
		cout << endl;
	}
}

void NewSection(const string &text)
{
	cout << "\n\t" << text << "\n" << endl;
}