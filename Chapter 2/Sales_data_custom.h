#ifndef SALES_DATA_CUSTOM_H
#define SALES_DATA_CUSTOM_H

#include <string>

struct Sales_data_custom {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif
