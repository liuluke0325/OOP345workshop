
/*
Hsueh Chih Liu
116131186
06/26/2019
*/



#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>
#include <string>

namespace sict {

	//Design and code an inheritance hierarchy named iProduct for holding data on products for sale.
	class iProduct {

	public:
		//a query that returns the price of a product.
		virtual double price() const = 0;

		// ¡V a query that displays the information about the product.
		virtual void display(std::ostream& os) const = 0;


	}; //!iProduct iclass
	std::ostream& operator <<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}


#endif // !SICT_IPRODUCT_H
