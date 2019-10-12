// hsueh chih liu
// 116 131 186
// date: 5/17/2019
#ifndef  SICT_STRING_H
#define SICT_STRING_H

#include <iostream>
namespace sict {

	class String {
		char* pstr; // hold the pointer of the string
	public:
		String(const char* str);
		void display(std::ostream& out) const;
		~String();
	};

	std::ostream& operator << (std::ostream& os, const String& src);
}



#endif // ! STRING_H
