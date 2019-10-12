#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <vector>
#include <iostream>
#include "iProduct.h"


namespace sict {
 
	//Design and code a class named Sale for managing a sequence of iProduct objects





	class Sale {
		std::vector<iProduct*> products;

	public:
		//receives the address of an unmodifiable C-style null terminated string that contains the name of the file holding records of iProduct type
		Sale(char* nameOfFile);
		void display(std::ostream& os) const;
		~Sale();
	}; //!Sale






}






#endif 
