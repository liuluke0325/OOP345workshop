#include "Sale.h"
#include <iostream>
#include <fstream>
#include "iProduct.h"
using namespace std;

namespace sict {


	Sale::Sale(char* nameOfFile) {

		int numOfRecord = 0;
		// open file
		ifstream file(nameOfFile);
		string tempString;
		if (!file) {
			//If this function fails to open the file, 
			// it throws an exception with an appropriate message.
			throw "Can not open the file";

		}

		//if successful, read from the file
		do {
			double id;
			double price;
			file >> id;
			file.get(); //discharge ' '
			file >> price; // discharge ' '
			getline(file, tempString);
			numOfRecord++;

			//store into vector
			//this->products.push_back(tempString);
			
			this->products.push_back(readRecord(file));

		} while (file);

			file.close();

	}






	void Sale::display(std::ostream& os) const {
		//displays the products that make up the sale 
		// and the total price in the format
		for (size_t i = 0; i < this->products.size(); i++)
		{

		}

	}












}