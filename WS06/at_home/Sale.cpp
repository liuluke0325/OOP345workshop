
/*
Hsueh Chih Liu
116131186
06/26/2019
*/


#include "Sale.h"
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include <iomanip>
using namespace std;
extern int FW;
namespace sict {


	Sale::Sale(char* nameOfFile) {

		int numOfRecord = 0;
		// open file
		ifstream file(nameOfFile);
		string tempString;
		if (!file.is_open()) {
			//If this function fails to open the file, it throws an exception with an appropriate message.
			throw "Can not open the file";

		}

		//if successful, read from the file
		do {
	
			this->products.push_back(readRecord(file));

		} while (!file.eof());

		file.close();

	}






	void Sale::display(std::ostream& os) const {
		//displays the products that make up the sale 
		// and the total price in the format

		os << "\nProduct No" << setw(FW) << "Cost" << ' ' << "Taxable" << endl;

		double total = { 0.0 };
		for (auto& i : this->products)
		{
			os << *i;
			total += i->price();
		}
		os << fixed << setprecision(2) << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;

	}






}