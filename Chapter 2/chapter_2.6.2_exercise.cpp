#include <iostream>
#include <string>

struct Sales_data {
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

int main()
{
	// Section 2.6.2 - Using the Sales_data Class
	std::cout << "\nSection 2.6.2 - Using the Sales_data Classs\n" << std::endl;;
	{
// -------------------------------------------------------------------------------
		/*
		Sales_data data1, data2;

		double price = 0;	// price per book, used to calculate total revenue
							// read first transaction: ISBN, number of books sold, price per book
		std::cin >> data1.bookNo >> data1.units_sold >> price;
		// calculate total revenue from price and units_sold
		data1.revenue = data1.units_sold * price;

		// read the second transaction
		std::cin >> data2.bookNo >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;

		if (data1.bookNo == data2.bookNo) {
			unsigned totalCnt = data1.units_sold + data2.units_sold;
			double totalRevenue = data1.revenue + data2.revenue;
			// print ISBN, total sold, total revenue, average price per book
			std::cout << data1.bookNo << " " << totalCnt
				<< " " << totalRevenue << " ";
			if (totalCnt != 0)
				std::cout << totalRevenue / totalCnt << std::endl;
			else
				std::cout << "(no sales)" << std::endl;
			// return 0;	// return success
		}
		else {	// transactions weren't for the same ISBN
			std::cerr << "Data must refer to the same ISBN" << std::endl;
			return -1;	// indicate failure
		}
		*/
		// -----------------------------------------------------------
		// currSale is the value we're counting; we'll read new values into sale
		Sales_data currSale, sale;
		// read first value and ensure that we have data to process
		if (std::cin >> currSale.bookNo) {
			// price per book, used to calculate total revenue
			double price = 0;
			std::cin >> currSale.units_sold >> price;
			// calculate total revenue from price and units_sold
			currSale.revenue = currSale.units_sold * price;
			// store the count for the current book we're processing
			unsigned cnt = 1;
			while (std::cin >> sale.bookNo) {
				std::cin >> sale.units_sold >> price;
				// calculate total revenue from price and units_sold
				sale.revenue = sale.units_sold * price;
				if (currSale.bookNo == sale.bookNo) {
					currSale.units_sold += sale.units_sold;
					currSale.revenue += sale.revenue;
					++cnt;	// add 1 to cnt
				}
				else {	// otherwise, print the count or the previous value
					std::cout << currSale.bookNo << " " << currSale.units_sold
						<< " " << currSale.revenue << " occurs " << cnt
						<< " times" << std::endl;
					currSale.bookNo = sale.bookNo;
					currSale.units_sold = sale.units_sold;
					currSale.revenue = sale.revenue;
					cnt = 1;
				}
			}	// while loop ends here
			//  remember to print the count for the last value in the file
			std::cout << currSale.bookNo << " " << currSale.units_sold
				<< " " << currSale.revenue << " occurs " << cnt
				<< " times" << std::endl;
		}	// outermost if statement ends here

		// Exercise 2.41
		std::cout << "\nExercise 2.41\n" << std::endl;
		{
			/*
			0-201-70353-X 4 20.00
			0-201-70353-X 2 22.00
			0-201-70353-X 1 26.00
			0-201-78345-X 3 20.00
			0-201-78345-X 2 25.00
			*/

			// Write a pogram that reads a set of book sales transactions,
			// writing each transaction to the standard output

			// Write a program that reads two Sales_data objects that have
			// the same ISBM and produces their sum

			// Write a program that reads several transactions for the same
			// ISBN. Write the sum of all transactions that were read.

			// Write a program that reads several transactions and counts how
			// many transactions occur for each ISBN.

			// Test the previous program by giving multiple transactions
			// representing multiple ISBNs. The records for each ISBN should
			// be grouped together.
		}
	}
	
	return 0;
}
