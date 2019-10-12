#include "Product.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

	extern int FW;
namespace sict {

	//Product::Product() {}


	double Product::price() const {
		return this->priceM;
	}



	void Product::display(std::ostream& os) const {

		//os << "Product No Cost" << setw(FW) << right << "Cost";
		os << setw(FW) << right << this->productId << setw(FW) << right << this->priceM << endl;

	}




	Product::Product(double id, double price) {

		this->productId = id;
		this->priceM = price;

	}

	std::ostream& operator <<(std::ostream& os, const iProduct& p) {


		p.display(os);
		return os;

	}


	iProduct* readRecord(std::ifstream& file) {

		double tempNo{0.0};
		double tempPri{ 0.0 };


		if (!file.is_open()) {
			throw "nothing to read";
		}
		// check read error
	
	
		file >> tempNo;
		//file.get(); //descharge space;
		file >> tempPri;
		//file.get(); // descharge \n
		cout << tempNo << "**********" << tempPri << endl;;
		//allocate memory
		iProduct* itemp = new Product(tempNo, tempPri);

		return itemp;

	}

}