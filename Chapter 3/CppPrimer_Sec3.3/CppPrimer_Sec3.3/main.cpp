#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section33();
void Exercise312();
void Exercise313();
void Exercise314();
void Exercise315();
void Exercise316();
void Exercise317();
void Exercise318();
void Exercise319();
void Exercise320();

void ShowVectorSequenceInt(const vector<int> &vec);
void ShowVectorSequenceString(const vector<string> &vec);

void NewSection(const string &text = "");
void NewExercise(const string &text = "");

int main()
{
	double choice;
	do
	{
		// Chapter 3 - Library string Type
		NewSection("Chapter 3 - Library string Type");

		cout << "\nWhat section number (3.3, 0 to skip)?: ";
		cin >> choice;

		if (choice == 3.3)
			Section33();
		else if (choice != 0)
			cout << "\nInvalid Choice";

	} while (choice != 0);

	cout << "\n" << endl;

	system("pause");
	return 0;
}

void Section33()
{
	// Section 3.3 - Library vector Type
	NewSection("Section 3.3 - Library vector Type");

	cout << "We can define vectors to hold objects of most any type. Because \n"
		"references are not objects(§ 2.3.1, p. 50), we cannot have a vector of \n"
		"references.However, we can have vectors of most other(nonreference) \n"
		"built - in types and most class types. \n"
		"In particular, we can have vectors whose elements are themselves \n"
		"vectors." << endl;

	// Section 3.3.1 - Defining and Initializing vectors
	NewSection("Section 3.3.1 - Defining and Initializing vectors");

	double choice;
	do
	{
		cout << "\nWhich exercise number? (3.12-3.13, 0 to skip): ";
		cin >> choice;

		if (choice == 3.12)
			Exercise312();
		else if (choice == 3.13)
			Exercise313();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.3.2 - Adding Elements to a vector
	NewSection("Section 3.3.2 - Adding Elements to a vector");

	do
	{
		cout << "\nWhich exercise number? (3.14-3.15, 0 to skip): ";
		cin >> choice;

		if (choice == 3.14)
			Exercise314();
		else if (choice == 3.15)
			Exercise315();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Section 3.3.3 - Other vector Operations
	NewSection("Section 3.3.3 - Other vector Operations");

	{
		vector<int> v{ 1,2,3,4,5,6,7,8,9 };
		for (auto &i : v)	// for each element in v (note: i is a reference)
			i *= i;			// square the element value
		for (auto i : v)	// for each element in v
			cout << i << " ";	// print the element
		cout << endl;
	}
	{
		// Input: 42 65 95 100 39 67 95 76 88 76 83 92 76 93
		cout << "Input 11 grade scores: ";

		// count the number of grades by clusters of 
		//ten: 0--9, 10--19,..., 90--99, 100
		vector<unsigned> scores(11, 0);	// 11 buckets, all initially 0
		unsigned grade;
		while (cin >> grade)	// read the grades
			if (grade <= 100)	// handle only valid grades
				++scores[grade / 10];	// increment the counter for
										// the current cluster

		cin.clear();

		for (unsigned &index : scores)
			cout << index << " ";
		cout << endl;

		// Output: 0 0 0 1 1 0 2 3 2 4 1
	}

	do
	{
		cout << "\nWhich exercise number? (3.16-3.20, 0 to skip): ";
		cin >> choice;

		if (choice == 3.16)
			Exercise316();
		else if (choice == 3.17)
			Exercise317();
		else if (choice == 3.18)
			Exercise318();
		else if (choice == 3.19)
			Exercise319();
		else if (choice == 3.20)
			Exercise320();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);
}

void Exercise312()
{
	// Exercise 3.12
	NewExercise("Exercise 3.12");
	
	// (a)
	// Valid: Vector whose elements are vectors of elements int
	vector<vector<int>> ivec;

	// (b)
	// Error: Cannot assign to vector of different type
	// vector<string> svec = ivec;

	// (c)
	// Valid: Vector of 10 strings; each string element is "null"
	vector<string> svec(10, "null");
}

void Exercise313()
{
	// Exercise 3.13
	NewExercise("Exercise 3.13");

	// How many elements are there in each of the following vectors?
	// What are the values of the elements?

	// (a)
	// Empty vector capable of holding int type objects
	vector<int> v1;
	
	if (v1.empty())
		cout << "Vector is empty" << endl;
	else
		cout << "Vector is NOT empty" << endl;
	
	// (b)
	// v2 has 10 default-initialized elements with value 0
	vector<int> v2(10);
	ShowVectorSequenceInt(v2);

	// (c)
	// v3 has 10 elements of value 42
	vector<int> v3(10, 42);
	ShowVectorSequenceInt(v3);

	// (d)
	// v4 has one element of value 10
	vector<int> v4{ 10 };
	ShowVectorSequenceInt(v4);

	// (e)
	// v5 has two elements with values 10 and 42
	vector<int> v5{ 10, 42 };
	ShowVectorSequenceInt(v5);

	// (f)
	// v6 has 10 default-initialized elements of string
	vector<string> v6{ 10 };
	ShowVectorSequenceString(v6);

	// (g)
	// v7 has ten string elements with value "hi"
	vector<string> v7{ 10, "hi" };
	ShowVectorSequenceString(v7);

	cout << endl;
}

void Exercise314()
{
	// Exercise 3.14
	NewExercise("Exercise 3.14");

	vector<int> intVec;

	cout << "Enter values: ";

	int value;

	while (cin >> value)
		intVec.push_back(value);

	cin.clear();

	ShowVectorSequenceInt(intVec);

	cout << endl;
}

void Exercise315()
{
	// Exercise 3.15
	NewExercise("Exercise 3.15");

	vector<string> stringVec;

	cout << "Enter strings: ";

	string text;

	while (cin >> text)
		stringVec.push_back(text);

	cin.clear();

	for (string &index : stringVec)
		cout << index << " ";
}

void Exercise316()
{
	// Exercise 3.16
	NewExercise("Exercise 3.16");

	cout << "See exercise 3.13 as well as the functions \n"
		"ShowVectorSequenceInt and ShowVectorSequenceString"<< endl;
}

void Exercise317()
{
	// Exercise 3.17
	NewExercise("Exercise 3.17");

	// Vector to hold words input from cin
	vector<string> svec;

	// String to hold current word input from cin
	string word;

	cout << "Type sequence of words: ";

	while (cin >> word)
		svec.push_back(word);
	cin.clear();

	// if vector is NOT empty
	if (!svec.empty())
	{
		// for each string element in vector svec
		for (string &stringIndex : svec)
		{
			// if string element of vector is NOT empty
			if (!stringIndex.empty())
			{
				// for each character element in string stringIndex
				for (char &charIndex : stringIndex)
					charIndex = toupper(charIndex);	// capitalize each character
			}
		}

		// keep track of words per line with wordCount
		unsigned wordCount(1);

		cout << "\nTransformed Vector: \n";
		for (const string &index : svec)
		{
			cout << index << " ";

			if (wordCount < 8)
				++wordCount;
			else
			{
				cout << "\n";
				wordCount = 1;
			}
		}

		cout << "\nVector Size: " << svec.size() << endl;
	}
}

void Exercise318()
{
	// Exercise 3.18
	NewExercise("Exercise 3.18");

	// Illegal. Vector ivec has no elements. The subscript operator on
	// vector (and string) fetches an existing element; it does NOT add
	// an element.
	vector<int> ivec;
	// ivec[0] = 42;	// error: value is undefined

	// Correction: use push_back()
	ivec.push_back(42);
	ShowVectorSequenceInt(ivec);
}

void Exercise319()
{
	// Exercise 3.19
	NewExercise("Exercise 3.19");

	// Three ways to define vector with ten elements, each a value of 42

	// Preferred way to define vector because of it's simple and easy to read
	vector<int> ivec1(10, 42);
	ShowVectorSequenceInt(ivec1);

	vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	ShowVectorSequenceInt(ivec2);

	vector<int> ivec3;
	for (unsigned i = 0; i < 10; ++i)
		ivec3.push_back(42);
	ShowVectorSequenceInt(ivec3);
}

void Exercise320()
{
	// Exercise 3.20
	NewExercise("Exercise 3.20");

	// Vector to hold int values from input cin
	vector<int> ivec;

	// Variable to hold current value in input cin
	int choice;

	while (cin >> choice)
		ivec.push_back(choice);
	cin.clear();

	ShowVectorSequenceInt(ivec);

	// Vector to hold values of sum
	vector<int> sumVec;

	// for each element except the last element
	for (unsigned i = 0; i < (ivec.size() - 1); ++i)
		sumVec.push_back(ivec[i] + ivec[i + 1]);

	ShowVectorSequenceInt(sumVec);

	// Vector to hold values of sum
	vector<int> specialSumVec;

	// Length of specialSumVec, vector to hold values of sum
	int ssVecLength;

	if (ivec.size() % 2 == 0)
		ssVecLength = ivec.size() / 2;
	else
		ssVecLength = (ivec.size() / 2) + 1;

	for (unsigned i = 0; i < ssVecLength; ++i)
		specialSumVec.push_back(ivec[i] + ivec[ivec.size() - 1 - i]);

	ShowVectorSequenceInt(specialSumVec);
}

void ShowVectorSequenceInt(const vector<int> &vec)
{
	if (!vec.empty())
	{
		for (auto &index : vec)
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
		for (auto &index : vec)
			cout << index << " ";

		cout << "Vector Size: " << vec.size();
	}
	else
		cout << "Vector is empty";

	cout << endl;
}

void NewSection(const string &text)
{
	std::cout << "\n\t" << text << "\n" << std::endl;
}

void NewExercise(const string &text)
{
	std::cout << "\n\t" << text << "\n" << std::endl;
}