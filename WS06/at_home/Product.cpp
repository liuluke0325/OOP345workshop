
/*
Hsueh Chih Liu
116131186
06/26/2019
*/


#include "Product.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

extern int FW;
namespace sict {

	Product::Product() {}


	double Product::price() const {
		return this->priceM;
	}



	void Product::display(std::ostream& os) const {

		os << setw(FW) << right << this->productId << setw(FW) << right << this->priceM;
	}




	Product::Product(double id, double price) {

		this->productId = id;
		this->priceM = price;
	}

	std::ostream& operator <<(std::ostream& os, const iProduct& p) {

		p.display(os);
		os << endl;
		return os;

	}


	iProduct* readRecord(std::ifstream& file) {
		iProduct* iPro;
		double tempNo{ 0.0 };
		double tempPri{ 0.0 };
		std::string tempStr = {};
		char tax = { '\0' };


		if (!file.is_open()) {
			throw "nothing to read";
		}

		// count how many spaces in line
		std::getline(file, tempStr, '\n');
		size_t count = std::count(tempStr.begin(), tempStr.end(), ' ');
		std::stringstream stream(tempStr);

		//if include tax
		if (count == 2)
		{
			stream >> tempNo >> tempPri >> tax;
			iPro = new TaxableProduct(tempNo, tempPri, tax);

		}
		else
		{
			stream >> tempNo >> tempPri;
			iPro = new Product(tempNo, tempPri);

		}


		return iPro;

	}




	TaxableProduct::TaxableProduct(double productNum, double price, char tax) :Product(productNum, price) {
		if (tax == 'H')
		{
			taxType = Tax::HSP;
			taxRate = 0.13;
		}
		else if (tax == 'P') {

			taxType = Tax::PST;
			taxRate = 0.08;
		}

	}


	double TaxableProduct::price() const {

		return Product::price() * (taxRate + 1);

	}
	void TaxableProduct::display(std::ostream& os) const {


		Product::display(os);

		taxType == Tax::HSP ? os << " HST" : os << " PST";

	}


}