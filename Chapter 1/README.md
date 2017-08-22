# Chapter 1 

### Sample Code and Exercise Solutions

```C++
if (isAwesome)
  return true;
```
### -----1.2 A first look at input/output-----
	
## Exercise 1.3
	
	std::cout << "\nHello, World" << std::endl;
	
## Exercise 1.4
	
	std::cout << "Enter two numbers" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2				<< " is " << v1 * v2 << std::endl;
				
## Exercise 1.5
	
	std::cout << "The sum of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 + v2;
	std::cout << std::endl;
				
## Exercise 1.6

> Program fragment is illegal. Remove semicolon (termination statement)
> from first two lines.
	
## Exercise 1.8
	
	std::cout << "/*"; // legal
	std::cout << "*/"; // legal
	// std::cout << /* "*/" */; // illegal
	std::cout << /* "*/" */"; // fixed error
	std::cout << /* "*/" /* "/*" */; // legal
	std::cout << std::endl;
	
### -----1.4.1 The while Statement-----
	
	int sum = 0, val = 1;
	// keep executing the while as long as val is less than or equal to 10
	while (val <= 10) {
		sum += val;	// assigns sum + val to sum
		++val;		// add 1 to val
	}
	std::cout << "\nSum of 1 to 10 inclusive is "
				<< sum << std::endl;
				
## Exercise 1.9
	
	sum = 0, val = 50; // set initial values
	// keep executing the while as long as val is less than or equal to 100
	while (val <= 100) {
		sum += val;		// assigns sum + val to sum
		++val;			// add 1 to val
	}
	std::cout << "Sum of 50 to 100 inclusive is "
				<< sum << std::endl;
				
## Exercise 1.10
	
	sum = 0, val = 10;	// set initial values
	std::cout << "Numbers: ";
	// keep executing the while as long as val is more than or equal to 0
	while (val >= 0) {
		std::cout << val << " ";	// print value of val
		--val;	// subtract 1 to val
	}
	std::cout << std::endl;
	
##  Exercise 1.11
	
	std::cout << "Enter two numbers" << std::endl;
	int x1 = 0, x2 = 0;
	std::cin >> x1 >> x2;
	int min, max;
	// use the ternary operator ? to assign appropriate min and max
	(x1 >= x2) ? (max = x1, min = x2) : (max = x2, min = x1);
	/* The above statement is equivalent to the following:
	if (x1 >= x2)
		max = x1, min = x2;
	else
		max = x2, min = x1;
	*/
	std::cout << "The range of numbers between " << min
				<< " and " << max << " is: " << std::endl;
	while (min <= max) {
		std::cout << min << " ";
		++min;
	}
	std::cout << std::endl;
	
###  -----1.4.2 The for Statement-----
	
	sum = 0;
	// sum values from 1 through 10 inclusive
	for (int val = 1; val <= 10; ++val)
		sum += val;		// equivalent to sum = sum + val
	std::cout << "\nSum of 1 to 10 inclusive is "
				<< sum << std::endl;
	
##  Exercise 1.12
	
	sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	std::cout << "Sum of -100 to 100 inclusive is "
				<< sum << std::endl;
				
##  Exercise 1.13
	
	// Rewritten exercise 1.9
	sum = 0; // set initial values
	for (int val = 50; val <= 100; ++val)
		sum += val;
	std::cout << "Sum of 50 to 100 inclusive is "
				<< sum << std::endl;
	// Rewritten exercise 1.10			
	sum = 0, val = 10;	// set initial values
	std::cout << "Numbers: ";
	for (int val = 10; val >= 0; --val)
		std::cout << val << " ";	// print value of val
	std::cout << std::endl;
	// Rewritten exercise 1.11
	std::cout << "Enter two numbers" << std::endl;
	x1 = 0, x2 = 0;
	std::cin >> x1 >> x2;
	min, max;
	// use the ternary operator ? to assign appropriate min and max
	(x1 >= x2) ? (max = x1, min = x2) : (max = x2, min = x1);
	std::cout << "The range of numbers between " << min
				<< " and " << max << " is: " << std::endl;
	for (int i = min; i <= max; ++i)
		std::cout << i << " ";			
	std::cout << std::endl;
	
###  1.4.3 Reading an Unknown Number of Inputs
	
##  Exercise 1.16
	
	sum = 0;
	int value = 0;
	std::cout << "\nInput a set of numbers to sum ending with "
				<< "\nan end-of-file, or invalid input, such as "
				<< "\nreading a value that is not an integer"
				<< std::endl;
	// read until end-of-file, calculating a running total of all values read
	while (std::cin >> value)
		sum += value;	// equivalent to sum = sum  + value
	std::cout << "Sum is: " << sum << std::endl;
	//
### -----1.4.4 The if Statement-----
	
	std::cout << "\n-----Sec 1.4.4 The if Statement-----" << std::endl;
	
	// see chapter1_1.4.4.cpp
	std::cout << "\nsee chapter1_1.4.4.cpp" << std::endl;
