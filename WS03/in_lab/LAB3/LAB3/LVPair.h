/*

Name: Hsueh Chih Liu
ID: 116131186
Date: 5/31/2019

*/



#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H                            
#include <iostream>


// defines a class template for a label-value pair (for example, a product label stored in an std::string object and a quantity stored in an int object)

namespace sict {

	template <typename L, typename V>
	class LVPair {

		L label;
		V value;

	public:
		LVPair() : value{ 0 }{}

		LVPair(const L& labelData, const V& valueData) :label{ labelData }, value{ valueData }{}

		void display(std::ostream& os) const { os << label << " : " << value << std::endl; }


	};


	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}


}
#endif // !1
