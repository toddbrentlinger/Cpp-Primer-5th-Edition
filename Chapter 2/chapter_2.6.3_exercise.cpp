#include <iostream>
#include "Sales_data_custom.h"

int main()
{
	// Exercise Section 2.6.3
	std::cout << "\nExercise Section 2.6.3\n" << std::endl;
	
	/*
	0-201-70353-X 4 20.00
	0-201-70353-X 2 22.00
	0-201-70353-X 1 26.00
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00
	.


	Write a pogram that reads a set of book sales transactions,
	writing each transaction to the standard output

	Write a program that reads two Sales_data objects that have
	the same ISBM and produces their sum

	Write a program that reads several transactions for the same
	ISBN. Write the sum of all transactions that were read.

	Write a program that reads several transactions and counts how
	many transactions occur for each ISBN.

	Test the previous program by giving multiple transactions
	representing multiple ISBNs. The records for each ISBN should
	be grouped together.
	*/
	
	// totalSale is the value we're counting; we'll read new values into sale
	Sales_data_custom totalSale, sale;
	
	// price per book, used to calculate total revenue
	double price = 0.0;
	
	// read first value and ensure that we have data to process
	if (std::cin >> totalSale.bookNo >> totalSale.units_sold >> price)
	{
		// calculate total revenue from price and units_sold
		totalSale.revenue = totalSale.units_sold * price;
		
		// store the count for the current sale we're processing
		unsigned cnt = 1;
		
		while (std::cin >> sale.bookNo >> sale.units_sold >> price)
		{
			// calculate total revenue from price and units_sold
			sale.revenue = sale.units_sold * price;
			
			if (totalSale.bookNo == sale.bookNo)
			{
				totalSale.units_sold += sale.units_sold;
				totalSale.revenue += sale.revenue;
				
				// add 1 to cnt
				++cnt;
			}
			else
			{
				std::cout << totalSale.bookNo << " " << totalSale.units_sold
						<< " " << totalSale.revenue << " occurs " << cnt
						<< " times" << std::endl;
				
				totalSale.bookNo = sale.bookNo;
				totalSale.units_sold = sale.units_sold;
				totalSale.revenue = sale.revenue;
				
				// reset cnt to 1
				cnt = 1;
			}
		}	// while loop ends here
		
		//  remember to print the count for the last value in the file
		std::cout << totalSale.bookNo << " " << totalSale.units_sold
					<< " " << totalSale.revenue << " occurs " << cnt
					<< " times" << std::endl;
		
	}	// outermost if statement ends here
	
	return 0;
}
