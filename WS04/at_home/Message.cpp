/*
Name:HsuehChihLiu
id: 116131186
Date: 6/8/19


*/


#include "Message.h"
#include <iostream>
#include <string>
using namespace std;

namespace sict {

	Message::Message() : msgFrom{ "" }, msgTo{ "" }, msgContent{ "" }{}

	Message::Message(const std::string& str) {
		size_t  endIndex = 0u; // to control the substring;
		string tempStr;


		//search user , start from index 0, end in first space
		endIndex = str.find(' ');
		this->msgFrom = str.substr(0, endIndex);



		// str - user = replyto (optional) + text content
		if (str.size() != msgFrom.size())// check if msg exisits or not
		{
			tempStr = str.substr(endIndex + 1);


			// check if reply name exisits or not
			// start from @, end in space

			if (tempStr.find('@') != string::npos) // if yes
			{
				endIndex = tempStr.find(' ');
				this->msgTo = tempStr.substr(1, endIndex - 1); // index from 1 because remove @

				// - rest of them are msg
				tempStr = tempStr.substr(endIndex + 1); // from next char to the end
			}



			this->msgContent = tempStr;



		}
		else
		{
			//If there is no text in the message 
			//this function places the object into a safe empty state.

			*this = Message();

		}



	}




	bool Message::empty() const {
		return this->msgFrom.empty();
	}


	void Message::display(std::ostream& os) const {
		if (!this->empty())
		{

			cout << ">User  : " << this->msgFrom << endl;

			if (this->msgTo.size() > 0)
			{
				cout << " Reply : " << this->msgTo << endl;
			}

			cout << " Tweet : " << this->msgContent << '\r' << endl;

		}

	}
}// !sict