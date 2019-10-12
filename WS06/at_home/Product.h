
/*
Hsueh Chih Liu
116131186
06/26/2019
*/



#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include <string>
#include "iProduct.h"

namespace sict {

	class Product :public iProduct {

		double productId{ 0.0 };
		double priceM{ 0.0 };

	public:
		Product();
		Product(double id, double price);
		double price() const;
		void display(std::ostream& os) const;



	};

	class TaxableProduct :public Product {
		// an enumeration list of tax types and a class variable with corresponding rates
		double taxRate;
		enum class Tax { HSP, PST } taxType; // 0.13 , 0.08

	public:
		//receives and stores the product number, its price and its tax status.
		TaxableProduct(double, double, char);
		double price() const;
		void display(std::ostream&) const;

	};

}


#endif // !SICT_PRODUCT_H
