#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

void Section34();

void Exercise321();
void Exercise322();
void Exercise323();
void Exercise324();
void Exercise325();
void Exercise326();

void ShowVectorSequenceInt(const vector<int> &vec);
void ShowVectorSequenceString(const vector<string> &vec);

void NewSection(const string &text = "");

int main()
{
	Section34();

	system("pause");
	return 0;
}

void Section34()
{
	// Section 3.4 - Introducing Iterators
	NewSection("Section 3.4 - Introducing Iterators");

	cout << "Like pointers (§ 2.3.2, p. 52), iterators give us indirect \n"
		"access to an object. In the case of an iterator, that object is \n"
		"an element in a container or a character in a string.We can use an \n"
		"iterator to fetch an element and iterators have operations to move \n"
		"from one element to another.As with pointers, an iterator may be \n"
		"valid or invalid.A valid iterator either denotes an element or \n"
		"denotes a position one past the last element in a container. \n"
		"All other iterator values are invalid." << endl;

	// Section 3.4.1 - Using Iterators
	NewSection("Section 3.4.1 - Using Iterators");

	{
		string s("some string");
		if (s.begin() != s.end())	// make sure s is not empty
		{
			auto it = s.begin();	// it denotes the first character in s
			*it = toupper(*it);		// make that character uppercase
		}
	}
	{
		string s("some string");
		// process characters in s until we run out of characters 
		// or we hit whitespace
		for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
			*it = toupper(*it);	// capitalize the current character
	}

	double choice;
	do
	{
		cout << "\nWhich exercise number? (3.21-3.23, 0 to skip): ";
		cin >> choice;

		if (choice == 3.21)
			Exercise321();
		else if (choice == 3.22)
			Exercise322();
		else if (choice == 3.23)
			Exercise323();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);

	// Sec 3.4.2 - Iterator Arithmetic
	NewSection("Sec 3.4.2 - Iterator Arithmetic");
	{
		cout << "\nBinary Search: Classic algorithm that uses iterator arithmetic" << endl;

		// text must be sorted
		vector<int> text;
		for (int i = 0; i != 101; ++i)
			text.push_back(i);

		// beg and end will denote the range we're searching
		auto beg = text.begin(), end = text.end();

		// original midpoint
		auto mid = text.begin() + (end - beg) / 2;

		cout << "\nValue sought between 0-100: ";
		
		// value sought from input cin
		int sought;
		cin >> sought;

		// loop counter
		unsigned count(0);

		// while there are still elements to look at and we haven't yet
		while (mid != end && *mid != sought)
		{
			// is the element we want in the first half of the range?
			if (sought < *mid)
				// if so, adjust the range to ignore the second half
				end = mid;
			// the element we want is in the second half of the range
			else
				// start looking with the element just after mid
				beg = mid + 1;

			// new midpoint
			mid = beg + (end - beg) / 2;
			++count;
		}

		cout << "\nIt took " << count << " loops to find the value sought." << endl;
	}

	do
	{
		cout << "\nWhich exercise number? (3.24-3.26, 0 to skip): ";
		cin >> choice;

		if (choice == 3.24)
			Exercise324();
		else if (choice == 3.25)
			Exercise325();
		else if (choice == 3.26)
			Exercise326();
		else if (choice != 0)
			cout << "\nInvalid choice.\n" << endl;

	} while (choice != 0);
}

void Exercise321()
{
	// Exercise 3.21
	NewSection("Exercise 3.21");

	vector<int> v1;
	ShowVectorSequenceInt(v1);

	vector<int> v2(10);
	ShowVectorSequenceInt(v2);

	vector<int> v3(10, 42);
	ShowVectorSequenceInt(v3);

	vector<int> v4{ 10 };
	ShowVectorSequenceInt(v4);

	vector<int> v5{ 10, 42 };
	ShowVectorSequenceInt(v5);

	vector<string> v6{ 10 };
	ShowVectorSequenceString(v6);

	vector<string> v7{ 10, "hi" };
	ShowVectorSequenceString(v7);

	cout << endl;
}

void Exercise322()
{
	// Exercise 3.22
	NewSection("Exercise 3.22");

	// vector to hold data where each element is either a sentence or an
	// empty string representing a paragraph break
	vector<string> text;

	// Input
	text = { "One two three four five six seven eight nine ten",
			"eleven twelve thirteen fourteen fifteen sixteen",
			"seventeen eighteen nineteen twenty.",
			"",
			"Twenty-one twenty-two twenty-three twenty-four",
			"twenty-five." };

	cout << "(a)" << endl;

	// print each line in text up to the first blank line
	for (auto iter = text.cbegin();
		iter != text.cend() && !iter->empty();
		++iter)
		cout << *iter << endl;

	cout << "\n(b)" << endl;

	// change the elements in text that correspond to the first paragraph
	// to all uppercase
	for (auto sIter = text.begin();
		sIter != text.end() && !sIter->empty();
		++sIter)
	{
		for (auto cIter = sIter->begin();
			cIter != sIter->end();
			++cIter)
			*cIter = toupper(*cIter);
	}

	// print each line in text
	for (auto iter = text.cbegin();
		iter != text.cend();
		++iter)
		if (!iter->empty())
			cout << *iter << endl;
		else
			cout << endl;
}

void Exercise323()
{
	// Exercise 3.23
	NewSection("Exercise 3.23");

	// Vector with 10 int elements. 
	vector<int> ivec;
	// Equivalent to: ivec = {0,1,2,3,4,5,6,7,8,9}
	for (int i = 0; i != 10; ++i)
		ivec.push_back(i);

	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
		*iter *= 2;

	// Print vector
	ShowVectorSequenceInt(ivec);
}

void Exercise324()
{
	// Exercise 3.24
	NewSection("Exercise 3.24");

	// Vector to hold int values
	vector<int> ivec;

	cout << "\nEnter set of int values: ";

	// Read set of int values from input cin into vector
	int choice;
	while (cin >> choice)
		ivec.push_back(choice);
	cin.clear();

	ShowVectorSequenceInt(ivec);

	cout << "\n(a)" << endl;

	// Vector to hold values of sum
	vector<int> sumVec;

	for (auto iter = ivec.begin() + 1; iter != ivec.end(); ++iter)
		sumVec.push_back(*iter + *(iter - 1));

	ShowVectorSequenceInt(sumVec);

	cout << "\n(b)" << endl;

	// Vector to hold values of sum
	vector<int> specialSumVec;

	// Initial values for first and last element in vector
	for (auto first = ivec.begin(), last = ivec.end() - 1;
		first <= last; ++first, --last)
		specialSumVec.push_back(*first + *last);

	ShowVectorSequenceInt(specialSumVec);
}

void Exercise325()
{
	// Exercise 3.25
	NewSection("Exercise 3.25");

	// count the number of grades by clusters of ten: 
	// 0-9, 10-19, ..., 90-99, 100

	// 11 buckets, all initially 0
	vector<unsigned> scores(11, 0);

	cout << "Enter grades (0-100): ";

	unsigned grade;
	while (cin >> grade)
		if (grade <= 100)
			++*(scores.begin() + (grade / 10));
	cin.clear();

	if (!scores.empty())
	{
		for (const unsigned &index : scores)
			cout << index << " ";
		cout << "Vector Size: " << scores.size();
	}
	else
		cout << "Vector is empty";

	cout << endl;
}

void Exercise326()
{
	// Exercise 3.26
	NewSection("Exercise 3.26");

	cout << "In the binary search program, why did we write \n"
		"mid = beg + (end - beg) / 2; instead of \n"
		"mid = (beg + end) / 2;? \n"
		"\n"
		"The second equation only gives the difference between elements. \n"
		"We need to add this difference to the earlier element index to \n"
		"get the new mid iterator value. \n" << endl;
}

void ShowVectorSequenceInt(const vector<int> &vec)
{
	if (!vec.empty())
	{
		for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
			cout << *iter << " ";

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
		for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
			cout << *iter << " ";

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