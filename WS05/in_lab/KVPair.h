#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>
#include <iomanip>


namespace sict {



	template<typename K, typename V>
	class KVPair {
		K key;
		V value;

	public:
		KVPair() :key{ "" }, value{ 0 } {}
		KVPair(const K& KEY, const V& VALUE) :key{ KEY }, value{ VALUE }{}

		template<typename F>void display(std::ostream& os, F f) const {
			if (key != "")
			{
				os << std::left << std::setw(10) << this->key << " : "
					<< std::setw(10) << std::right << this->value 
					<< std::setw(10) << std::right << f(this->value) << std::endl;

			}
			//If the current object is in a safe empty state, this query does nothing.
		}

	};



}





#endif // !SICT_KVPAIR_H
