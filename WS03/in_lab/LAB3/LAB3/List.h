/*

Name: Hsueh Chih Liu
ID: 116131186
Date: 5/31/2019

*/

#ifndef SICT_LIST_H
#define SICT_LIST_H



//defines a class template for a list of elements of any data type (for example, a list of ints)


namespace sict {


	template<typename T, int N>

	class List {
		T Array[N];
		size_t numOfArray; // unsigned int

	public:
		List() :numOfArray{ 0u } {}
		//a query that returns the number of elements stored in the array
		size_t size() const {
			return numOfArray;
		}
		//an overloaded operator that receives an index and returns a reference to the 
		//unmodifiable object stored at that index of the array.
		const T& operator[](size_t i) const {
			return  Array[i];
		}
		//If space to store the additional element is available, this operator appends a copy of the referenced object t to the set of elements currently stored in the array.

		void operator+=(const T& t) {
			if (numOfArray < N)
			{
				Array[numOfArray] = t;
				numOfArray++;
			}
			//else do nothing
		}

	};

}// end namespace


#endif // !SICT_LIST_H



