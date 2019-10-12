/*

name:hsueh chih liu
id : 116131186
date : 05/24/2019

*/


#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <string>

namespace sict {

	class Text {

		std::string* pstr;
		int numOfString;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator = (const Text&);
		~Text();
		size_t size() const;
		Text& operator = ( Text&&); // move assignment operator
		Text(Text&&);
			
	};


}





#endif // !SICT_TEXT_H
