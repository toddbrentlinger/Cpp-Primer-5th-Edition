#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

void Section31();
void Section32();

void Exercise32();
void Exercise33();
void Exercise34();
void Exercise34a();
void Exercise34b();
void Exercise35();
void Exercise35a();
void Exercise35b();
void Exercise36();
void Exercise37();
void Exercise38();
void Exercise39();
void Exercise310();
void Exercise311();

void NewSection(std::string text = "");
void NewExercise(std::string text = "");

int main()
{
	double choice;
	do
	{
		// Chapter 3 - Library string Type
		NewSection("Chapter 3 - Library string Type");

		cout << "\nWhat section number?: ";
		cin >> choice;

		int choiceInt = choice * 10;
		switch (choiceInt)
		{
		case 31: Section31(); break;
		case 32: Section32(); break;
		default: cout << "\nInvalid Choice";
		}

	} while (choice != 0);

	cout << "\n" << endl;

	system("pause");
	return 0;
}

void Section31()
{
	// Section 3.1 - Namespace using Declarations
	NewSection("Section 3.1 - Namespace using Declarations");

	// Exercise 3.1
	NewExercise("Exercise 3.1");
	{
		// Exercise 1.9
		cout << "\nExercise 1.9" << endl;
		int sum = 0, val = 50; // set initial values
							   // keep executing the while as long as val is less than or equal to 100
		while (val <= 100) {
			sum += val;		// assigns sum + val to sum
			++val;			// add 1 to val
		}
		cout << "Sum of 50 to 100 inclusive is "
			<< sum << endl;

		// Exercise 1.10

		cout << "\nExercise 1.10" << endl;
		sum = 0, val = 10;	// set initial values
		cout << "Numbers: ";
		// keep executing the while as long as val is more than or equal to 0
		while (val >= 0) {
			cout << val << " ";	// print value of val
			--val;	// subtract 1 to val
		}
		cout << endl;

		// Exercise 1.11

		cout << "\nExercise 1.11" << endl;
		cout << "Enter two numbers" << endl;
		int x1 = 0, x2 = 0;
		cin >> x1 >> x2;
		int min, max;
		// use the ternary operator ? to assign appropriate min and max
		(x1 >= x2) ? (max = x1, min = x2) : (max = x2, min = x1);
		/* The above statement is equivalent to the following:
		if (x1 >= x2)
		max = x1, min = x2;
		else
		max = x2, min = x1;
		*/
		cout << "The range of numbers between " << min
			<< " and " << max << " is: " << endl;
		while (min <= max) {
			cout << min << " ";
			++min;
		}
		cout << endl;

		// Exercise Section 2.6.2 (2.41)
		// see chapter_2.6.2_exercise.cpp in Dev-C++ for reference
	}
}

void Section32()
{
	// Section 3.2 - Library string Type
	NewSection("Section 3.2 - Library string Type");

	// Section 3.2.1 - Defining and Initializing strings
	NewSection("Section 3.2.1 - Defining and Initializing strings");

	// Section 3.2.2 - Operations on strings
	NewSection("Section 3.2.2 - Operations on strings");
	/*{
	string s;	// empty string
	cin >> s;	// read a whitespace-separated string into s
	cout << s << endl;	// write s to the output

	string s1, s2;
	cin >> s1 >> s2;	// read first input into s1, second into s2
	cout << s1 << s2 << endl;	// write both strings

	string word;
	while (cin >> word)			// read until end-of-file
	cout << word << endl;	// write each word followed by a new line

	string line;
	// read input a line at a time until end-of-file
	while (getline(cin, line))
	cout << line << endl;
	}*/

	double choice;
	do
	{
		cout << "\nWhat exercise number (3.2 - 3.5, 0 to skip)?: ";
		cin >> choice;
		int choiceInt = choice * 10;

		switch (choiceInt)
		{
		case 32: Exercise32(); break;
		case 33: Exercise33(); break;
		case 34: Exercise34(); break;
		case 35: Exercise35(); break;
		}
	} while (choice != 0);

	// Section 3.2.3 - Dealing with the Characters in a string
	NewSection("Section 3.2.3 - Dealing with the Characters in a string");
	{
		string str("some string");

		// print the characters in str one character to a line
		for (auto c : str)	// for every char in str
			cout << c << endl;	// print the current character followed by newline
	}
	{
		string s("Hello World!!!");

		// punct_cnt as the same type that s.size() returns; string::size_type
		decltype(s.size()) punct_cnt = 0;

		// count the number of punctuation characters in s
		for (auto c : s)	// for every char in s
			if (ispunct(c))	// if the character is punctuation
				++punct_cnt;	// increment the punctuation counter

		cout << punct_cnt
			<< " punctuation characters in " << s << endl;
	}
	{
		string s("Hello World!!!");

		// convert s to uppercase
		for (auto &c : s)	// for every char in s (note: c is a reference)
			c = toupper(c);	// c is a reference, so the assignment changes 
							// the char in s

		cout << s << endl;
	}
	{
		string s("some string");

		if (!s.empty())				// make sure there's a character in s[0]
			s[0] = toupper(s[0]);	// assign a new value to the first
									// character in s

		cout << s << endl;
	}
	{
		string s("some string");

		// process characters in s until we run out of characters or we
		// hit a whitespace
		for (decltype(s.size()) index = 0;
			index != s.size() && !isspace(s[index]);
			++index)
			s[index] = toupper(s[index]);	// capitalize the current character

		cout << s << endl;
	}
	{
		const string hexdigits = "0123456789ABCDEF";	// possible hex digits

		cout << "Enter a series of numbers between 0 and 15 \n"
			<< " separated by spaces. Hit ENTER when finished: "
			<< endl;

		string result;	// will hold the resulting hexify'd string

		string::size_type n;	// hold numbers from the input

		while (cin >> n)
			if (n < hexdigits.size())	// ignore invalid input
				result += hexdigits[n];	// fetch the indicated hex digit

		cin.clear();
		cout << "Your hex number is: " << result << endl;
	}

	do
	{
		cout << "\nWhat exercise number (3.6 - 3.11, 0 to skip)?: ";
		cin >> choice;

		if (choice == 3.6)
			Exercise36();
		else if (choice == 3.7)
			Exercise37();
		else if (choice == 3.8)
			Exercise38();
		else if (choice == 3.9)
			Exercise39();
		else if (choice == 3.10)
			Exercise310();
		else if (choice == 3.11)
			Exercise311();

	} while (choice != 0);
}

void Exercise32()
{
	// Exercise 3.2
	NewExercise("Exercise 3.2");

	cout << "Part a or b?: ";
	char choice;
	while (cin >> choice)
	{
		if (choice == 'a' || choice == 'A')
		{
			string line;
			while (getline(cin, line))
				cout << line << endl;
			cin.clear();
			break;
		}
		else if (choice == 'b' || choice == 'B')
		{
			string word;
			while (cin >> word)
				cout << word << endl;
			cin.clear();
			break;
		}
		else
		{
			cout << "Not a valid answer" << endl;
			cout << "Part a or b?: ";
		}
	}
}

void Exercise33()
{
	// Exercise 3.3
	NewExercise("Exercise 3.3");

	cout << "Explain how whitespace characters are handled in the string\n"
		"input operator and in the getline function:\n\n"

		"string input operator:\n"
		"The string input operator reads and discards any leading \n"
		"whitespace(e.g., spaces, newlines, tabs).It then reads \n"
		"characters until the next whitespace character is encountered. \n"
		"So, if the input to this program is Hello World!(note leading and \n"
		"trailing spaces), then the output will be Hello with no extra \n"
		"spaces. \n\n"

		"getline function:\n"
		"Sometimes we do not want to ignore the whitespace in our input. In \n"
		"such cases, we can use the getline function instead of the >> \n"
		"operator." << endl;
}
void Exercise34()
{
	// Exercise 3.4
	NewExercise("Exercise 3.4");

	cout << "Part a or b?: ";
	char choice;
	while (cin >> choice)
	{
		if (choice == 'a' || choice == 'A')
		{
			Exercise34a();
			break;
		}
		else if (choice == 'b' || choice == 'B')
		{
			Exercise34b();
			break;
		}
		else
		{
			cout << "Not a valid answer" << endl;
			cout << "Part a or b?: ";
		}
	}
}

void Exercise34a()
{
	cout << "Enter two strings: ";

	string firstString, secondString;

	while (cin >> firstString >> secondString)
	{
		if (firstString == secondString)
			cout << "String: \"" << firstString << "\" and String: \""
			<< secondString << "\" are equal." << endl;
		else
		{
			cout << "String: \"" << firstString << "\" and String: \""
				<< secondString << "\" are NOT equal." << endl;

			cout << "String: \"";
			if (firstString > secondString)
				cout << firstString;
			else
				cout << secondString;
			cout << "\" is the larger of the two strings." << endl;
		}
	}
	cin.clear();
	/*
	cout << "First string: ";
	cin >> firstString;

	cout << "\nSecond String: ";
	cin >> secondString;
	cout << endl;

	if (firstString == secondString)
	cout << "String: \""<< firstString << "\" and String: \""
	<< secondString << "\" are equal." << endl;
	else
	{
	cout << "String: \"" << firstString << "\" and String: \""
	<< secondString << "\" are NOT equal." << endl;

	cout << "String: \"";
	if (firstString > secondString)
	cout << firstString;
	else
	cout << secondString;
	cout << "\" is the larger of the two strings." << endl;
	}
	*/
}

void Exercise34b()
{
	cout << "Enter two strings: ";

	string firstString, secondString;

	while (cin >> firstString >> secondString)
	{
		if (firstString.size() == secondString.size())
			cout << "String: \"" << firstString << "\" and String: \""
			<< secondString << "\" have the same length." << endl;
		else
		{
			cout << "The two strings do NOT have equal length. "
				<< "String: \"";
			cout << ((firstString.size() > secondString.size() ? firstString : secondString));
			cout << " is larger.";
		}
	}
	cin.clear();
}

void Exercise35()
{
	// Exercise 3.5
	NewExercise("Exercise 3.5");

	cout << "Part a or b?: ";
	char choice;
	while (cin >> choice)
	{
		if (choice == 'a' || choice == 'A')
		{
			Exercise35a();
			break;
		}
		else if (choice == 'b' || choice == 'B')
		{
			Exercise35b();
			break;
		}
		else
		{
			cout << "Not a valid answer" << endl;
			cout << "Part a or b?: ";
		}
	}
}

void Exercise35a()
{
	cout << "Type String: ";

	string currString, totalString;

	while (cin >> currString)
	{
		totalString += currString;
		cout << "Concatenated String: " << totalString << endl;
	}
	cin.clear();
}

void Exercise35b()
{
	cout << "Type String: ";

	string currString, totalString;

	while (cin >> currString)
	{
		totalString += currString + " ";
		cout << "Concatenated String: " << totalString << endl;
	}
	cin.clear();
}

void Exercise36()
{
	// Exercise 3.6
	NewExercise("Exercise 3.6");

	string s("Hello World!!!");

	for (auto &c : s)
		c = 'X';

	cout << s << endl;
}

void Exercise37()
{
	// Exercise 3.7
	NewExercise("Exercise 3.7");

	string s("Hello World!!!");

	for (char &c : s)
		c = 'X';

	cout << s << endl;
}

void Exercise38()
{
	// Exercise 3.8a
	NewExercise("Exercise 3.8a");

	string s("Hello World!!!");

	// string::size_type index = 0;
	decltype(s.size()) index = 0;

	while (index < s.size())
	{
		s[index] = 'X';
		++index;
	}

	cout << s << endl;

	// Exercise 3.8b
	NewExercise("Exercise 3.8b");

	s = "Hello World!!!";

	s = "Hello World!!!";

	for (decltype(s.size()) index = 0; index != s.size(); ++index)
		s[index] = 'O';

	cout << s << endl;

	cout << "\nOf the three approaches, I prefer the range for approach \n"
		<< "when looping through a sequence from beginning to end." << endl;
}

void Exercise39()
{
	// The following program is NOT valid. Subscripting an empty string
	// is undefined.
	string s;
	cout << s[0] << endl;

	// Correction:
	string s2;
	if (!s2.empty())
		cout << s2[0] << "Should NOT output" << endl;

	string s3("Hello World");
	if (!s3.empty())
		cout << s3[0] << endl;
}

void Exercise310()
{
	string s("Hello, World!!!");

	string result;

	for (auto c : s)	// for every char in s
		if (!ispunct(c))	// if the character is NOT punctuation
			result += c;

	cout << "String: " << s << " has " << s.size() << " characters. \n"
		<< "Updated String: " << result << " has " << result.size()
		<< " characters." << endl;
}

void Exercise311()
{
	cout << "The following range for is legal but const string s can NOT \n"
		<< "be changed and has read-only access. Loop control variable c \n"
		<< "is a const reference equivalent to const char &c" << endl;

	const string s = "Keep out!";

	for (auto &c : s)
	{
		//  error: cannot assign new value to const reference
		// c = toupper(c);

		// valid:
		cout << c << endl;
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