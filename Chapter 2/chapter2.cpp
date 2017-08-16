#include <iostream>

// for exercise 2.10
std::string global_str;
int global_int;

int main() {
	
	// Chapter 2: Variables and Basic Types
	
	std::cout << "\nChapter 2: Variables and Basic Types" << std::endl;
	
	// Exercise Section 2.1.2 - Type Conversions
	
	std::cout << "\nExercise Section 2.1.2" << std::endl;
	
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
	
	// Exercise Section 2.1.3 - Literals
	
	std::cout << "\nExercise Section 2.1.3" << std::endl;
	
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
	
	// 2.2 - Variables
	
	// Exercise Section 2.2.1 - Variable Definitions
	
	std::cout << "\nExercise Section 2.2.1" << std::endl;
	
	// Exercise 2.9
	
	std::cout << "\nExercise 2.9\n" << std::endl;
	
	long double ld = 3.1415926536;
	int a{ld}, b = {ld};
	int c(ld), d = ld;
	
	// std::cin >> int input_value;	// error
	int input_value;
	std::cout << "Input int: ";
	std::cin >> input_value;
	int j = { 3.14 };
	// double salary = wage = 9999.99;	// error: wage not declared in this scope
	double salary = 9999.99, wage = 9999.99;
	int k = 3.14;	// output: k = 3
	
	std::cout << "\nOutput" << std::endl;
	std::cout << "input_value = " << input_value << std::endl;
	std::cout << "j = " << j << std::endl;
	std::cout << "salary = " << salary << std::endl;
	std::cout << "wage = " << wage << std::endl;
	std::cout << "k = " << k << std::endl;
	
	std::cout << "\n" << ld << ", " << a << ", " << b
				<< ", " << c << ", " << d << std::endl;
	std::cout << (a == c) << (b == d) << (ld == a) << (ld == c) << std::endl;
	
	// Exercise 2.10
	
	std::cout << "\nExercise 2.10\n" << std::endl;
	
	int local_int;
	std::string local_str;
	
	std::cout << "global_int: " << global_int << std::endl;
	std::cout << "local_int: " << local_int << std::endl;
	std::cout << "global_str: " << global_str << std::endl;
	std::cout << "local_str: " << local_str << std::endl;
	
	// Exercise Section 2.2.2 - Variable Declarations and Definitions
	
	std::cout << "\nExercise Section 2.2.2" << std::endl;
	
	
	
	return 0;
}
