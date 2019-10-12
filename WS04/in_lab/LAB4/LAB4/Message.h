
/*
Name:HsuehChihLiu
id: 116131186
Date: 6/8/19


*/


#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <string>
namespace sict {



	class Message {
		//managing a single message between users

		std::string msgFrom;
		std::string msgTo;
		std::string msgContent;


	public:
		Message();

		Message(const std::string& str);

		bool empty() const;

		void display(std::ostream& os) const;

	};


} // !sict



#endif // !SICT_MESSAGE_H
