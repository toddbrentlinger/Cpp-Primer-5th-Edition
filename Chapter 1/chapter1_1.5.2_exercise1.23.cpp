#include <iostream>
#include "Sales_item.h"

int main() {
	
	// Exercise 1.23
	std::cout << "\nExercise 1.23" << std::endl;
	
	// currVal is the number we're counting; we'll read new values into val
	Sales_item currItem, item;
	// read first number and ensure that we have data to process
	if (std::cin >> currItem) {
		int cnt = 1;	// store the count for the current value we're processing
		while (std::cin >> item) {	// read the remaining numbers
			if (currItem.isbn() == item.isbn())	{	// if the values are the same
				currItem += item; 
				++cnt;				// add 1 to cnt
			}
			else {		// otherwise, print the count or the previous value
				std::cout << currItem << " occurs "
							<< cnt << " times" << std::endl;
				currItem = item;		// remember the new value
				cnt = 1;			// reset the counter
			}
		}	// while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currItem << " occurs " << cnt
					<< " times" << std::endl;
	}	// outermost if statement ends here
	
	return 0;
}
