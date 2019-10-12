/*

Name: Hsueh Chih Liu
ID: 116131186
Date: 5/31/2019

*/



#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H                            
#include <iostream>
#include <iomanip>

// defines a class template for a label-value pair (for example, a product label stored in an std::string object and a quantity stored in an int object)

namespace sict {

	template <typename L, typename V>
	class LVPair {

		L label;
		V value;

	public:
		LVPair() {}

		LVPair(const L& labelData, const V& valueData) :label{ labelData }, value{ valueData }{}

		virtual void display(std::ostream& os) const { os << label << " : " << value << std::endl; }

		const L& getLabel() const { return label; }
		const V& getValue() const { return value; }
	};


	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}



	template <typename L, typename V>
	class SummableLVPair :public LVPair<L, V> {
		//two class variables
		static V value; // initial value for starting a summation
		static size_t swidth;// holds the minimum field width for pretty columnar output of label-value pairs

	public:
		//SummableLVPair() ¡V default constructor ¡V leaves the object in a safe empty state
		SummableLVPair() { }


		SummableLVPair(const L& label, const V& v) :LVPair<L, V>(label, v) {

			//calls the base class 2-argument constructor
			//assumes that the type of the first parameter has a member function named size()

			//(label.size() > this.width) ? this.width = label.size() : this.width;
			swidth = (label.size() > swidth) ? label.size() : swidth;

		}


		//a class function that returns the initial value for the summation of a set of LVPair objects of label type L.
		static const V& getInitialValue() {
			return value;

		}


		V sum(const L& label, const V& sum) const {
			return LVPair<L,V>::getValue() + sum; 

		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(swidth);
			LVPair<L, V>::display(os);
		}

	};


	template <typename L, typename V>
	size_t SummableLVPair<L, V>::swidth = 0u;


	// A template specialization 
	template<>
	int SummableLVPair< std::string, int >::value{ 0 };


	//A template specialization that initializes the starting value for an LVPair<std::string, std::string> type to an empty string.
	template<>
	std::string SummableLVPair<std::string, std::string>::value{ "" };



	//A template specialization of the sum() query for LVPair<std::string, std::string> types that inserts a single space between concatenating strings.
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const {

		return (value + " " + LVPair<std::string, std::string>::getValue());
	}

}
#endif // !1
