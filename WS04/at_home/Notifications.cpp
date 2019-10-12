
/*
Name:HsuehChihLiu
id: 116131186
Date: 6/12/19
*/


#include "Notifications.h"
#include <iostream>
#include <utility>
using namespace std;
namespace sict {




	Notifications::Notifications() :ptrMessagePtr{ nullptr }, maxNumAddress{ 0u }, currentNumAddress{ 0u } {}


	Notifications::Notifications(int maxNumAddress) : Notifications() {
	
		if (maxNumAddress > 0)
		{
			this->maxNumAddress = maxNumAddress;
			this->ptrMessagePtr = new const Message * [maxNumAddress];

		}
	}


	Notifications& Notifications::operator+=(const Message& msg) {
		//a modifier that receives a reference to an unmodifiable Message object.
		//If the object is not empty and the current object has room to store an address to a Message object, 
		if (!msg.empty() && maxNumAddress > currentNumAddress)
		{
			//your function stores that address. Otherwise, this function does nothing. 
			ptrMessagePtr[currentNumAddress] = &msg;
			currentNumAddress++;
		}
		//In both cases, this function returns a reference to the current object.
		return *this;


	}


	Notifications& Notifications::operator-=(const Message& msg) {
	

// Your function searches the current object for the address of the Message object. 
//If your function finds the address stored in the current object, it removes that object from the aggregation (replaces its address with nullptr). 
		int index = -1;
		for (size_t i = 0; i < currentNumAddress; i++) {
			
			if (ptrMessagePtr[i] == &msg) {
				ptrMessagePtr[i] = nullptr;
				index = i;
			}
		}
		
		// (Hint: in your design, you may choose to compress the address set by shifting each subsequent address to fill
		// the gap created by the address removal allowing newly added addresses to always be added to the end.)
		if (index != -1) {
			
			for (size_t i = index; i < currentNumAddress - 1; i++) {
				ptrMessagePtr[i] = ptrMessagePtr[i + 1];
			}

			ptrMessagePtr[--currentNumAddress] = nullptr; // add the nullptr to the end
		}

		//In any case, your function returns a reference to the current object. 
		return *this;

	}


	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0; i < currentNumAddress; i++)
		{
		
			this->ptrMessagePtr[i]->display(os);
		}

	}



	size_t Notifications::size() const {

		return this->currentNumAddress;

	}

	Notifications& Notifications::operator= (const Notifications& src) {

		//deep copy
		if (this != &src)
		{
			delete[] this->ptrMessagePtr;
			this->currentNumAddress = src.currentNumAddress;
			this->maxNumAddress = src.maxNumAddress;
			this->ptrMessagePtr = new const Message * [this->maxNumAddress];
			for (size_t i = 0; i < this->maxNumAddress; i++)
			{
				this->ptrMessagePtr[i] = src.ptrMessagePtr[i];
			}

		}



		return *this;

	}

	Notifications::Notifications(const Notifications& src) :Notifications() {

		*this = src;

	}




	std::ostream& operator<<(std::ostream& os, const Notifications& notifications) {

		notifications.display(os);
		return os;

	}



	Notifications::~Notifications() {

		delete[] this->ptrMessagePtr;

	}



	Notifications::Notifications(Notifications&& src) :Notifications() {

		*this = move(src);

	}


	Notifications& Notifications::operator= (Notifications&& src) {


		if (this != &src)
		{
			*this = src;
			src.currentNumAddress = 0u;
			src.maxNumAddress = 0u;
			src.ptrMessagePtr = nullptr;


		}
		return *this;

	}

}