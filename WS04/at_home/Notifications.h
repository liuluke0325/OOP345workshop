
/*
Name:HsuehChihLiu
id: 116131186
Date: 6/12/19
*/


#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include "Message.h"
#include <iostream>
namespace sict {

	class Notifications {
		//manages an aggregation of Message objects
		const Message** ptrMessagePtr; // a pointer to a dynamically allocated array of addresses to unmodifiable Message objects
		size_t maxNumAddress;//  the maximum number of addresses that can be stored in the aggregation
		size_t currentNumAddress;// the number of addresses currently stored in the aggregation
		
	public:
		//In addition to the standard five functions that a class needs to manage dynamically allocated memory,
		// your class includes the following public member functions and helper function

		Notifications();
		Notifications(int maxNumAddress);


		Notifications& operator+=(const Message& msg);


		Notifications& operator-=(const Message& msg);

		void display(std::ostream& os) const;

		size_t size() const;


		// Copy
		Notifications(const Notifications& src);
		Notifications& operator= (const Notifications& src);
		// Move
		Notifications(Notifications&& src);
		Notifications& operator= (Notifications&& src);


		~Notifications();


	};


	std::ostream& operator<<(std::ostream& os, const Notifications& notifications);



}

#endif // !SICT_NOTIFICATIONS_H
