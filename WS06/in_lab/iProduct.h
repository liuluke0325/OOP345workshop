#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>
#include <string>

namespace sict {


	//extern int FW;

	//Design and code an inheritance hierarchy named iProduct for holding data on products for sale.
	class iProduct {

	public:
		//a query that returns the price of a product.
		virtual double price() const = 0;

		// ¡V a query that displays the information about the product.
		virtual void display(std::ostream& os) const = 0;

		//Your interface also includes prototypes to meet the following global function requirements:
		//a helper that inserts the product information into the stream os.
		//std::ostream& operator << (std::ostream& os, const iProduct& p);
		// a function that reads a single record from
		//file object file, allocates memory for a product in the hierar
	}; //!iProduct iclass
	std::ostream& operator <<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}


#endif // !SICT_IPRODUCT_H
