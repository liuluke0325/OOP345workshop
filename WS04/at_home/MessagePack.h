
/*
Name:HsuehChihLiu
id: 116131186
Date: 6/12/19
*/


#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include "Message.h"
#include <iostream>
namespace sict {

	//manages a composition of Message objects
	class MessagePack {

		//	The number of objects is defined at run - time by the client module.
		Message* message;
		size_t numOfMsg;
		// Copy and Move

	public:

		// A default constructor that places the object in a safe empty state
		MessagePack();
		MessagePack(Message** message, size_t numOfMessage);
		// Copy
		MessagePack(const MessagePack& src);
		MessagePack& operator= (const MessagePack& src);

		// Move
		MessagePack(MessagePack&& src);
		MessagePack& operator= (MessagePack&& src);

		void display(std::ostream& os) const;
		size_t size() const;
		~MessagePack();


	};


	std::ostream& operator<< (std::ostream& os, const MessagePack& messagePack);

}



#endif // !SICT_MESSAGEPACK_H
