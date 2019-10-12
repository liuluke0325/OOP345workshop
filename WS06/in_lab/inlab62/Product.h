#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include <string>
#include "iProduct.h"

namespace sict {
	extern int FW;

	class Product :public iProduct {


		//std::string record{ "" };
		double productId{ 0.0 };
		//size_t numOfRecord{ 0u };
		double priceM{ 0.0 };


	public:
		//Product();
		Product(double id, double price);
		double price() const;
		void display(std::ostream& os) const;



	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);



}


#endif // !SICT_PRODUCT_H
