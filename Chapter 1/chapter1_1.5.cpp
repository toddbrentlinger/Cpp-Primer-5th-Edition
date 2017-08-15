#include <iostream>
#include "Sales_item.h"

int main() {
	
	std::cout << "\nIntroducing Classes" << std::endl;
	
	// 1.5.1 The Sales_item Class
	
	std::cout << "\n1.5.1 The Sales_item Class" << std::endl;
	
	// Reading and Writing Sales_items
	std::cout << "\nReading and Writing Sales_items" << std::endl;
	
	Sales_item book;
	
	// read ISBN, number of copies sold, and sales price
	std::cin >> book;
	
	// write ISBN, number of copies sold, total revenue, and average price
	std::cout << book << std::endl;
	
	// Adding Sales_items
	std::cout << "\nAdding Sales_items" << std::endl;
	
	Sales_item item1, item2;
	std::cin >> item1 >> item2;	// read a pair of transactions
	std::cout << item1 + item2 << std::endl;	// print their sum
	
	// Exercise Section 1.5.1
	
	// Exercise 1.22
	std::cout << "\nExercise 1.22" << std::endl;
	
	Sales_item currItem, sumItem;
	if (std::cin >> sumItem) {
		while (std::cin >> currItem) {
			sumItem += currItem;
	}
	std::cout << sumItem << std::endl;
	}
	
	// 1.5.2 A First Look at Member Functions
	
	std::cout << "\n1.5.2 A First Look at Member Functions" << std::endl;
	
	std::cin >> item1 >> item2;
	// first check that item1 and item2 represent the same book
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
		return 0;
	} else {
		std::cerr << "Data must refer to same ISBN"
					<< std::endl;
		return -1;	// indicate failure
	}
	

	return 0;
}
