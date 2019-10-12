// hsueh chih liu
// 116 131 186
// date: 5/20/2019
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <cstring>

using namespace std;
extern const int INITIAL;
namespace sict {
	


	String::String(const char* str) {
		
		if (str != nullptr)
		{
			pstr = new char[strlen(str) + 1];
			strcpy(pstr, str);
			
		}
		else // if is null address and store an empty string
		{
			pstr = nullptr;
		}



	}

	// receives a reference to an std::ostream object 
	 void String::display(ostream& out) const {

		 out << pstr;
		 
		}


	std::ostream& operator << (std::ostream& os, const String& src) {
		static int counter = INITIAL;
		//inserts an item number followed by a colon and a single space
		os << counter << ": ";
		src.display(os);
		//increments the current item number after the insertion.
		++counter;
		return os;
	}

	String::~String() {

		delete[] pstr; // deallocation

	}


}