/*

name:hsueh chih liu
id : 116131186
date : 05/24/2019

*/


#include "Text.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace sict {



	Text::Text() {

		this->numOfString = 0;
		this->pstr = nullptr;

	}



	Text::Text(const char* str) :Text() {
		string tempString; // hold the string from file


		std::ifstream fin; // connects to the file for reading
		fin.open(str);

		//check if file is open
		if (fin.is_open()) {


			//count the record infile;
			while (getline(fin, tempString, '\n'))
			{
				this->numOfString++;
			}

			//allocates memory for that number of pointers to std::string object
			this->pstr = new string[numOfString];


			//copies the records into the objects.

			for (int i = 0; i < numOfString; i++)
			{
				getline(fin, pstr[i], '\n');
			}

		}
		else { // file is not open
			cout << "File is not open" << endl; // do nothing

		}

	}


	Text::Text(const Text& src) {
		this->pstr = nullptr;
		*this = src;
	}

	Text& Text::operator = (const Text& src) {
		if (this != &src) // check self assign or not
		{
			delete[] this->pstr;
			this->numOfString = src.numOfString;


			if (src.pstr!=nullptr)
			{
				this->pstr = new string[this->numOfString];
				for (int i = 0; i < this->numOfString; i++)
				{
					this->pstr[i] = src.pstr[i];
				}
			}
			else {
				this->pstr = nullptr;
			}


		}

		return *this;

	}



	Text::~Text() {

		delete[] this->pstr;
	}

	size_t Text::size() const {

		return this->numOfString;
	}

	Text& Text::operator = ( Text&& src) {
		if (this != &src) { // check self assign or not
			delete[] pstr;
			this->numOfString = src.numOfString;
			this->pstr = src.pstr;

			//delete origin

			src.numOfString = 0;
			src.pstr = nullptr;

		}


		return *this;
	}

	Text::Text(Text&& src) {
		*this = src;
	}


}

