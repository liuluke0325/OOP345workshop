
/*
Name:HsuehChihLiu
id: 116131186
Date: 6/12/19
*/





#include "MessagePack.h"
#include <iostream>
#include <utility>
using namespace std;
namespace sict {


	MessagePack::MessagePack() :message{ nullptr }, numOfMsg{ 0u } {}


	// A two-argument constructor that receives the address of an array of Message objects and the number of elements in that array.
	MessagePack::MessagePack(Message** message, size_t numOfMessage) {

		//If the number of messages is positive - valued and the address is a valid address,
		if (numOfMessage > 0)
		{
			//	your function allocates dynamic memory for the specified number of Message objects
			this->message = new Message[numOfMessage];
			// TODO : stores ""copies""" of those objects that are not empty. ??
			this->numOfMsg = 0;
			for (size_t i = 0; i < numOfMessage; i++)
			{
				if (message[i] != nullptr && !message[i]->empty()) {
					this->message[numOfMsg] = *message[i];
					this->numOfMsg++;
				}

			}
		}
		else
		{
			//Otherwise, your function places the object in a safe empty state.
			*this = MessagePack();
		}



	}


	void MessagePack::display(std::ostream& os) const {


		for (size_t i = 0; i < numOfMsg; i++)
		{
			this->message[i].display(os);
		}
	}



	size_t MessagePack::size() const {

		return this->numOfMsg;
	}


	MessagePack::~MessagePack() {
		delete[] this->message;

	}

	ostream& operator<< (ostream& os, const MessagePack& messagePack) {
		messagePack.display(os);
		return os;

	}

	MessagePack& MessagePack::operator= (const MessagePack& src) {

		//deep copy
		if (this != &src)
		{
			delete[] this->message;
			this->numOfMsg = src.numOfMsg;
			this->message = new Message[this->numOfMsg];
			for (size_t i = 0; i < this->numOfMsg; i++)
			{
				this->message[i] = src.message[i];
			}

		}



		return *this;

	}


	MessagePack::MessagePack(MessagePack&& src) :MessagePack() {

		*this = move(src);

	}


	MessagePack& MessagePack::operator= (MessagePack&& src) {


		if (this != &src)
		{

			*this = src;
			src.message = nullptr;
			src.numOfMsg = 0u;

		}
		return *this;

	}


	MessagePack::MessagePack(const MessagePack& src) :MessagePack() {

		*this = src;

	}



}