#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;
using std::begin; using std::end;

void Section35();

void Exercise327();
int txt_size();

void Exercise328();
void Exercise329();
void Exercise330();
void Exercise331();
void Exercise332();
void Exercise333();
void Exercise334();

void Exercise335();
void SetArrayElementZero(int *begArray, const size_t arraySize);

void Exercise336();
bool ArrayCompareEquality(const int *beginArray1, const int const *endArray1,
	const int *beginArray2, const int const *endArray2);
bool VectorCompareEquality(vector<int> &v1, vector<int> &v2);

void Exercise337();
void Exercise338();
void Exercise339();
void Exercise340();
void Exercise341();
void Exercise342();

void ShowVectorSequenceInt(const vector<int> &vec);
void ShowVectorSequenceString(const vector<string> &vec);

void NewSection(const string &text = "");

// for Exercise 3.28
string sa[10];	// default-initialized to ten elements, each empty string ""
int ia[10];	
/* default-initialized to ten elements, each value of 0 since
variable defined outside of any function body */ 

int main()
{
	Section35();

	system("pause");
	return 0;
}

void Section35()
{
	// Section 3.5 - Arrays
	NewSection("Section 3.5 - Arrays");

	cout << "An array is a data structure that is similar to the library vector \n"
		"type(§ 3.3, p. 96) but offers a different trade - off between \n"
		"performance and flexibility.Like a vector, an array is a container of \n"
		"unnamed objects of a single type that we access by position.Unlike a \n"
		"vector, arrays have fixed size; we cannot add elements to an array. \n"
		"Because arrays have fixed size, they sometimes offer better run - time \n"
		"performance for specialized applications.However, that run - time \n"
		"advantage comes at the cost of lost flexibility. \n" << endl;

	// Section 3.5.1 - Defining and Initializing Built-in Arrays
	NewSection("Section 3.5.1 - Defining and Initializing Built-in Arrays");

	{
		unsigned cnt = 42;		// not a constant expression
		constexpr unsigned sz = 42;		// constant expression
		const unsigned sz2 = 42;	// constant expression

		int arr[10];	// array of ten ints
		int *parr[sz];	// array of 42 pointers to int
		// string bad[cnt];	// error: cnt is NOT a constant expression
		string strs[sz];	// ok since sz is constexpr
		string strs2[sz2];	// ok since sz2 is const
	}
	{
		const unsigned sz = 3;
		int a1[sz] = { 0,1,2 };	// array of three ints with values 0,1,2
		int a2[] = { 0, 1, 2 };	// an array of dimensions 3
		int a3[5] = { 0, 1, 2 };	// equivalent to a3[]={0,1,2,0,0}
		string a4[3] = { "hi", "bye" };	// same as a4[]={"hi","bye",""}
		// int a5[2] = { 0, 1, 2 };	// error: too many initializers
	}
	{
		// list initialization, no null; dimension is 3
		char a1[] = { 'C', '+', '+' };

		// list initialization, explicit null; dimension is 4
		char a2[] = { 'C', '+', '+', '\0' };

		// null terminator added automatically; dimension is 4
		char a3[] = "C++";

		// error: no space for the null!
		// char a4[6] = "Daniel";
		// Although the literal contains only six explicit characters, the
		// array size must be at least seven (six to hold the literal and
		// one for the null).
	}
	{
		// ptrs is an array of ten pointers to int
		int *ptrs[10];

		// error: no arrays of references; arrays hold objects so there
		// are no arrays of references
		// int &refs[10] = /* ? */;

		int arr[10];

		// Parray points to an array of ten ints
		int(*Parray)[10] = &arr;

		// arrRef refers to an array of ten ints
		int(&arrRef)[10] = arr;

		// arry is a reference to an array of ten pointers
		int *(&arry)[10] = ptrs;
	}

	double choice;
	do
	{
		cout << "\nWhich exercise number? (3.27-3.29, 0 to skip): ";
		cin >> choice;

		if (choice == 3.27)
			Exercise327();
		else if (choice == 3.28)
			Exercise328();
		else if (choice == 3.29)
			Exercise329();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.5.2 - Accessing the Elements of an Array
	NewSection("Section 3.5.2 - Accessing the Elements of an Array");

	do
	{
		cout << "\nWhich exercise number? (3.30-3.33, 0 to skip): ";
		cin >> choice;

		if (choice == 3.30)
			Exercise330();
		else if (choice == 3.31)
			Exercise331();
		else if (choice == 3.32)
			Exercise332();
		else if (choice == 3.33)
			Exercise333();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.5.3 - Pointers and Arrays
	NewSection("Section 3.5.3 - Pointers and Arrays");

	{
		string nums[] = { "one", "two", "three" };	// array of strings
		string *p = &nums[0];	// p points to the first element in nums
		string *p2 = nums;	// equivalent to p2 = &nums[0]

		int ia[] = { 0,1,2,3,4,5,6,7,8,9 };	// ia is an array of ten ints
		auto ia2(ia);	// ia2 is an int* that points to the first element in ia
		// ia2 = 42;	// error: ia2 is a pointer, and we can't assign an int
					// to a pointer
		*ia2 = 42;	// Correction: use dereference operator

		// ia3 is an array of ten ints
		decltype(ia) ia3 = { 0,1,2,3,4,5,6,7,8,9 };
		// ia3 = p;	// error: can't assign an int* to an array
		ia3[4] = 42;	// ok: assigns the value of i to an element in ia3
	}
	{
		int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
		int *p = arr;	// p points to the first element in arr
		++p;	// p points to arr[1]

		int *e = &arr[10];	// pointer just past the last element in arr

		for (int *b = arr; b != e; ++b)
			cout << *b << endl;	// print the elements in arr
	}
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8,9 };	// ia is an array of ten ints
		int *beg = std::begin(ia);	// pointer to the first element in ia
		int *last = std::end(ia);	// pointer to one past the last element in ia

		cout << "*beg = " << *beg << "\n"
			<< "*last = " << *last << "\n"
			<< "*(last-1) = " << *(last-1) << "\n"
			<< "*(last-2) = " << *(last-2) << endl;
	}
	{
		int arr[] = { 5,4,3,2,1,0,-1,-2,-3,-4,-5 };

		// pbeg points to the first and pend points just past the last
		// elements in arr
		int *pbeg = std::begin(arr), *pend = std::end(arr);

		// find the first negative element, stopping if we've seen all
		// the elements
		while (pbeg != pend && *pbeg >= 0)
			++pbeg;
	}
	{
		constexpr size_t sz = 5;
		int arr[sz] = { 1,2,3,4,5 };
		int *ip = arr;	// equivalent to int *ip = &arr[0]
		int *ip2 = ip + 4;	// ip2 points to arr[4], the last element in arr

		// ok: arr is converted to a pointer to its first element;
		// p points one past the end of arr
		int *p = arr + sz;	// use caution -- do NOT dereference!
		int *p2 = arr + 10;	// error: arr has only 5 elements; 
							// p2 has undefined value

		// n is 5, the number of elements in arr; n is type ptrdiff_t
		auto n = std::end(arr) - std::begin(arr);
	}
	{
		int ia[] = { 0,2,4,6,8 };	// array with 5 elements of type int
		
		// ok: initializes last to 8, the value of ia[4]
		int last = *(ia + 4);

		// ok: last = 4, equivalent to ia[0] + 4
		last = *ia + 4;
	}
	{
		int ia[] = { 0,2,4,6,8 };

		int i = ia[2];	// ia is converted to a pointer to the first element in ia
						// ia[2] feteches the element to which (ia+2) points
		int *p1 = ia;	// p1 points to the first element in ia
		i = *(p1 + 2);	// equivalent to i = ia[2]

		int *p = &ia[2];	// p points to the element indexed by 2
		int j = p[1];	// p[1] is equivalent to *(p+1)
						// p[1] is the same element as ia[3]
		int k = p[-2];	// p[-2] is the same element as ia[0]
	}

	do
	{
		cout << "\nWhich exercise number? (3.34-3.36, 0 to skip): ";
		cin >> choice;

		if (choice == 3.34)
			Exercise334();
		else if (choice == 3.35)
			Exercise335();
		else if (choice == 3.36)
			Exercise336();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.5.4 - C-Style Character Strings
	NewSection("Section 3.5.4 - C-Style Character Strings");

	cout << "Character string literals are an instance of a more general \n"
		"construct that C++ inherits from C : C - style character strings. \n"
		"C - style strings are not a type.Instead, they are a convention \n"
		"for how to represent and use character strings. Strings that follow \n"
		"this convention are stored in character arrays and are null \n"
		"terminated. By nullterminated we mean that the last character in \n"
		"the string is followed by a null character. Ordinarily we \n"
		"use pointers to manipulate these strings." << endl;

	do
	{
		cout << "\nWhich exercise number? (3.37-3.40, 0 to skip): ";
		cin >> choice;

		if (choice == 3.37)
			Exercise337();
		else if (choice == 3.38)
			Exercise338();
		else if (choice == 3.39)
			Exercise339();
		else if (choice == 3.40)
			Exercise340();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.5.5 - Interfacing to Older Code
	NewSection("Section 3.5.5 - Interfacing to Older Code");

	{
		string s("Hello World");	// s holds Hello World

		// char *str = s;	// error: can't initialize a char* from a string
		const char *str = s.c_str();	// ok
	}
	{
		int intArr[] = { 0,1,2,3,4,5 };

		// ivec has six elements; each is a copy of the corresponding
		// element in intArr
		vector<int> ivec(begin(intArr), end(intArr));

		// copies three elements: intArr[1], intArr[2], intArr[3]
		vector<int> subVec(intArr + 1, intArr + 4);

		for (auto index : intArr)
			cout << index << " ";
		cout << endl;

		ShowVectorSequenceInt(ivec);
	}

	do
	{
		cout << "\nWhich exercise number? (3.41-3.42, 0 to skip): ";
		cin >> choice;

		if (choice == 3.41)
			Exercise341();
		else if (choice == 3.42)
			Exercise342();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);
}

void Exercise327()
{
	// Exercise 3.27
	NewSection("Exercise 3.27");

	// see txt_size() function below

	// Which of the following definitions are illegal? Explain why.

	unsigned buf_size = 1024;

	// (a)
	// int ia[buf_size];
	/* error: Dimension of array must be known at compile time, which means
	that the dimension must be a constant expression. Variable buf_size
	is not constant. */

	// (b)
	int ia[4 * 7 - 14];
	// equivalent to: int ia[42];

	// (c)
	// int ia[txt_size()];
	/* error: Dimension of array must be known at compile time, which means
	that the dimension must be a constant expression. Function txt_size
	returns an int, NOT a const int. */

	// (d)
	// char st[11] = "fundamental";
	/* error: No space or null character. Although the literal contains
	only eleven explicit characters, the array size must be at least twelve,
	eleven to hold the literal and one for the null. */
}

int txt_size()
{
	return 1;
}

void Exercise328()
{
	// Exercise 3.28
	NewSection("Exercise 3.28");

	// What are the values in the following arrays?

	/* See variable definitions of sa and ia outside main function body.
	Variables defined outside any function body are initialized to
	zero.*/

	// string sa[10];	
	// Default-initialized to ten elements, each empty string ""

	// int ia[10];
	/* Default-initialized to ten elements, each value of 0 since
	variable defined outside of any function body */

	string sa2[10];
	// Default-initialized to ten elements, each empty string ""

	int ia2[10];
	// Default-initialzed to ten elements of undefined int objects

	cout << "sa = " << sa[0] << "\n"
		<< "ia = " << ia[0] << "\n"
		<< "sa2 = " << sa2[0] << "\n"
		<< "ia2 = " << ia2[0] << endl;
}

void Exercise329()
{
	// Exercise 3.29
	NewSection("Exercise 3.29");

	cout << "List some of the drawbacks of using an array instead of a \n"
		"vector: \n"
		"\n"
		"\tAn array is a data structure that is similar to the library vector \n"
		"type (§ 3.3, p. 96) but offers a different trade - off between \n"
		"performance and flexibility. Unlike a vector, arrays have fixed \n"
		"size; we cannot add elements to an array. Because arrays have \n"
		"fixed size, they sometimes offer better run - time performance for \n"
		"specialized applications.However, that run - time advantage comes \n"
		"at the cost of lost flexibility. \n" 
		"\tDimension of array must be known at compile time, which means \n"
		"that the dimension must be a constant expression. \n"
		"\tWe cannot initialize an array as a copy of another array, nor \n"
		"is it legal to assign one array to another. \n"
		<< endl;
}

void Exercise330()
{
	// Exercise 3.30
	NewSection("Exercise 3.30");

	// Identfy the indexing errors in the following code:
	/*
	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 1; ix <= array_size; ++ix)
		ia[ix] = ix;
	*/
	/* Array ia is initialized to 10 element of undefined int values.
	In the for loop, the initialization statement, size_t ix = 1, begins
	to index the array at the second element, NOT first. The first element
	of the array is accessed with index 0. Since the array is initially
	full of undefined int elements, the first element is NOT equal to zero
	but is some undefined value. The condition in the for loop tests
	whether ix is less than or equal to the size of the array which
	includes the null character at the end of the array. As a result,
	the for loop accesses the null character at the end array and tries
	to assign the undefined object. */

	// First correction: Fix condition test to (ix != array_size)
	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 1; ix != array_size; ++ix)
		ia[ix] = ix;

	for (auto index : ia)
		cout << index << " ";
	cout << endl;

	// Second correction: Fix initial statement to begin for loop at
	// first element, index 0
	int ia2[array_size];
	for (size_t ix = 0; ix != array_size; ++ix)
		ia2[ix] = ix;

	for (auto index : ia2)
		cout << index << " ";
	cout << endl;
}

void Exercise331()
{
	// Exercise 3.31
	NewSection("Exercise 3.31");

	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 0; ix != array_size; ++ix)
		ia[ix] = ix;

	for (int &index : ia)
		cout << index << " ";
	cout << endl;
}

void Exercise332()
{
	// Exercise 3.32
	NewSection("Exercise 3.32");

	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 0; ix != array_size; ++ix)
		ia[ix] = ix;

	// Copy the array into another array
	int ia2[10];
	for (size_t ix = 0; ix != 10; ++ix)
		ia2[ix] = ia[ix];

	for (int &index : ia2)
		cout << index << " ";
	cout << endl;

	// Rewrite the program above to use vectors
	vector<int> iv;
	for (auto index : ia)
		iv.push_back(index);

	ShowVectorSequenceInt(iv);

	// Alternative:
	vector<int> iv2;
	for (size_t ix = 0; ix != 10; ++ix)
		iv2.push_back(ia[ix]);

	ShowVectorSequenceInt(iv2);
}

void Exercise333()
{
	// Exercise 3.33
	NewSection("Exercise 3.33");

	/* What would happen if we did NOT initialize the scores array in
	the program on page 116? */
	
	unsigned scores[11];
	unsigned grade;
	while (cin >> grade)
		if (grade <= 100)
			++scores[grade / 10];
	cin.clear();

	for (auto i : scores)
		cout << i << " ";
	cout << endl;

	/* Since the array is initialized inside function body, the
	default-initialized values of type unsigned is undefined, NOT zero.
	So when we try to increment one element of the array, we are
	incrementing some unknown object. */
}

void Exercise334()
{
	// Exercise 3.34
	NewSection("Exercise 3.34");

	// p1 += p2 - p1;
	// equivalent to: p1 = p1 + p2 - p1; which simplifies to:
	// p1 = p2;
	// Valid for any pointers that point to an element in the same array or
	// one past the end of the array.
	// The code assigns the pointer p1 to point to the object at which
	// the pointer p2 points.

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p1 = ia;	// equivalent to int* p1 = &ia[0]
	int* p2 = &ia[5];	// equivalent to int* p2 = ia + 5;
	int* p3 = ia + 5;

	if (p3 == p2)
		cout << "p2 and p3 are equal" << endl;
	else
		cout << "p2 and p3 are NOT equal" << endl;

	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;
	cout << "*p3 = " << *p3 << endl;

	p1 += p2 - p1;

	// output: *p1 = 5; *p2 = 5;
	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;
}

void Exercise335()
{
	// Exercise 3.35
	NewSection("Exercise 3.35");

	// Using pointers, write a program to set the elements in an array
	// to zero.

	// see SetArrayElementZero(int *ia)

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };

	for (size_t index : ia)
		cout << index << " ";
	cout << endl;

	SetArrayElementZero(ia, 10);

	for (auto index : ia)
		cout << index << " ";
	cout << endl;
}

void SetArrayElementZero(int *begArray, const size_t arraySize)
{
	/* begArray is a pointer to the first element in the array to which
	it's initialized. 
	arraySize is the size of the array. */

	// endArray is a pointer to one past element in ia
	// int *endArray = begArray + arraySize;

	for (int *endArray = begArray + arraySize; 
		begArray != endArray; ++begArray)
		if (*begArray != 0)
			*begArray = 0;
}

void Exercise336()
{
	// Exercise 3.36
	NewSection("Exercise 3.36");

	// See ArrayCompareEquality() and VectorCompareEquality()

	// Write a program to compare two arrays for equality.

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	int ia2[] = { 0,1,2,3,4,5,6,7,0,9 };
	int ia3[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int ia4[10];
	for (int i = 0; i != 10; ++i)
		ia4[i] = i;
	for (auto index : ia4)
		cout << index << " ";
	cout << endl;

	// output: False
	if (ArrayCompareEquality(begin(ia), end(ia), begin(ia2), end(ia2)))
		cout << "The two arrays are equal" << endl;
	else
		cout << "The two arrays are NOT equal" << endl;

	// output: False
	if (ArrayCompareEquality(begin(ia), end(ia), begin(ia3), end(ia3)))
		cout << "The two arrays are equal" << endl;
	else
		cout << "The two arrays are NOT equal" << endl;

	// output: True
	if (ArrayCompareEquality(begin(ia), end(ia), begin(ia4), end(ia4)))
		cout << "The two arrays are equal" << endl;
	else
		cout << "The two arrays are NOT equal" << endl;

	cout << endl;

	// Write a similar program to compare two vectors.

	vector<int> v1, v2;

	v1 = { 0,1,2,3,4,5,6,7,8,9 };
	v2 = { 0,1,2,3,4,5,6,7,0,9 };
	vector<int> v3 = { 0,1,2,3,4,5,6,7,8,9,10 };
	vector<int> v4{ 0,1,2,3,4,5,6,7,8,9 };

	// output: False
	if (VectorCompareEquality(v1, v2))
		cout << "Two vectors are equal" << endl;
	else
		cout << "Two vectors NOT equal" << endl;

	// output: False
	if (VectorCompareEquality(v1, v3))
		cout << "Two vectors are equal" << endl;
	else
		cout << "Two vectors NOT equal" << endl;

	// output: True
	if (VectorCompareEquality(v1, v4))
		cout << "Two vectors are equal" << endl;
	else
		cout << "Two vectors NOT equal" << endl;

	/*
	cout << "\nEnter first vector of ints: ";
	int numberChoice;
	while (cin >> numberChoice)
		v1.push_back(numberChoice);
	cin.clear();

	cout << "\nEnter second vector of ints: ";
	while (cin >> numberChoice)
		v2.push_back(numberChoice);
	cin.clear();
	*/
}

bool ArrayCompareEquality(const int *beginArray1, const int const *endArray1,
	const int *beginArray2, const int const *endArray2)
{
	// Check if length of arrays are equal;
	// result of subtracting two pointers is a library type ptrdiff_t
	if ((endArray1-beginArray1) != (endArray2-beginArray2))
		return false;
	else
	{
		for ( ; beginArray1 != endArray1 && beginArray2 != endArray2;
			++beginArray1, ++beginArray2)
			if (*beginArray1 != *beginArray2)
				return false;

		return true;
	}
}

bool VectorCompareEquality(vector<int> &v1, vector<int> &v2)
{
	if (v1 == v2)
		return true;
	else
		return false;
}

void Exercise337()
{
	// Exercise 3.37
	NewSection("Exercise 3.37");

	// ca is array of const chars that is NOT null terminated
	// No null character ('\0')
	const char ca[] = { 'h','e','l','l','o' };

	// pointer to first element in array ca; equivalent to &ca[0]
	const char *cp = ca;

	while (*cp) {
		cout << *cp << endl;
		++cp;
	}

	/* The while loop outputs each element in the array ca before
	incrementing the pointer to the next element in the array. The 
	conditions tests whether the pointer is valid and continues until
	it reaches a null character. 
	
	Since the array ca has no null character, the loop will keep looking
	through the memory that follows ca until it encounters a null 
	character. */

	// Correction: add null character to end of char array
	const char ca2[] = { 'h','e','l','l','o','\0' };
	const char *cp2 = ca;
	while (*cp2) {
		cout << *cp2 << endl;
		++cp2;
	}
}

void Exercise338()
{
	// Exercise 3.38
	NewSection("Exercise 3.38");

	// https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers

	cout << "Pointer addition is forbidden in C++, you can only subtract \n"
		"two pointers. \n"
		"The reason for this is that subtracting two pointers gives a \n"
		"logically explainable result - the offset in memory between two \n"
		"pointers. Similarly, you can subtract or add an integral number \n"
		"to / from a pointer, which means 'move the pointer up or down'. \n"
		"Adding a pointer to a pointer is something which is hard to \n"
		"explain. What would the resulting pointner represent? \n"
		"If by any chance you explicitly need a pointer to a place in \n"
		"memory whose address is the sum of some other two addresses, \n"
		"you can cast the two pointers to int, add ints, and cast back \n"
		"to a pointer.Remember though, that this solution needs huge \n"
		"care about the pointer arithmetic and is something you really \n"
		"should never do." << endl;
}

void Exercise339()
{
	// Exercise 3.39
	NewSection("Exercise 3.39");

	// Write a program to compare two strings

	string s1("Hello World!"), s2("Hello");

	if (s1 == s2)
		cout << "Two strings are equal\n" << endl;
	else
		cout << "Two strings are NOT equal\n" << endl;

	// Write a program to compare the values of two C-style character strings
	const char arr1[]("Hello World!");
	const char arr2[]("Hello");

	int stringCompareReturn = strcmp(arr1, arr2);

	if (stringCompareReturn == 0)
		cout << "The C-style character strings are equal" << endl;
	else if (stringCompareReturn > 0)
		cout << "First C-style character string is larger" << endl;
	else
		cout << "Second C-style character string is larger" << endl;
}

void Exercise340()
{
	// Exercise 3.40
	NewSection("Exercise 3.40");

	const char charArray1[] ("Hello World!");
	const char charArray2[] = "Welcome to C++";
	
	// Pointer to constant char which points to the first element in
	// each array
	const char* beginArray1 = charArray1;
	const char* beginArray2 = charArray2;

	// Constant pointer to constant char which points to the last
	// element, null character, in the arrays initialized from strings
	const char const *endArray1 = end(charArray1);
	const char const *endArray2 = end(charArray2);
	
	/*
	// Length of array to hold concatenation of two arrays.
	// Although t
	constexpr size_t sumArraySize = strlen(charArray1) + strlen(" ") + 
		strlen(charArray2) + 1;
	// Note: Compiler has issues with strlen that isn't const but we
	// need a constexpr value to specify number of elements in array
	// when the array is initialized.

	char sumArray[sumArraySize];

	std::strcpy(sumArray, charArray1);
	std::strcat(sumArray, " ");
	std::strcat(sumArray, charArray2);
	*/
}

void Exercise341()
{
	// Exercise 3.41
	NewSection("Exercise 3.41");

	/* Write a program to initialize a vector from an array of ints */

	int intArr[] = { 0,1,2,3,4,5 };

	vector<int> intVec(begin(intArr), end(intArr));

	ShowVectorSequenceInt(intVec);
}

void Exercise342()
{
	// Exercise 3.42
	NewSection("Exercise 3.42");

	/* Write a program to copy a vector of ints into an array of ints */

	vector<int> intVec{ 0,1,2,3,4,5 };

	int intArr[6];

	for (unsigned i = 0; i != intVec.size(); ++i)
		intArr[i] = intVec[i];

	for (const auto &index : intArr)
		cout << index << " ";
	cout << endl;
}

void ShowVectorSequenceInt(const vector<int> &vec)
{
	if (!vec.empty())
	{
		for (const int &index : vec)
			cout << index << " ";

		cout << "Vector Size: " << vec.size();
	}
	else
		cout << "Vector is empty";

	cout << endl;
}
void ShowVectorSequenceString(const vector<string> &vec)
{
	if (!vec.empty())
	{
		for (const string &stringIndex : vec)
			cout << stringIndex << " ";

		cout << "Vector Size: " << vec.size();
	}
	else
		cout << "Vector is empty";

	cout << endl;
}

void NewSection(const string &text)
{
	cout << "\n" << text << "\n" << endl;
}