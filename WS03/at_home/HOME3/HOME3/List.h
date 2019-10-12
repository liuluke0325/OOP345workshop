/*

Name: Hsueh Chih Liu
ID: 116131186
Date: 5/31/2019

*/

#ifndef SICT_LIST_H
#define SICT_LIST_H
#include "LVPair.h"


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

	/*
	a) T - the type of any element in the array
b) L ¡V the type of the specified label
c) V ¡V the type of the summation value
d) N - the maximum number of elements in the array

	*/


	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {

	public:
		V accumulate(const L& label) const {
			//returns the sum of the values of all elements in the current LVList object that have label 
			// of the specified name(label) in a locally created value(V) object.


			// This function initializes the accumulator (V) object to the initial value for objects of the label-value pair (T) (see below)
			SummableLVPair <L, V> summableLVP;
			V sumOfValue = summableLVP.getInitialValue();

			//and then accumulates the values by calling the append query on each element in the list stored in the	base class.
			//(Hint: to access the size() and operator[]() member functions of the base class, cast the	current object(*this)
			// to a reference to the base class sub - object ¡V((List<T, N>&) * this) ¡V before calling the member function on the base class sub - object.)
			for (size_t i = 0; i < ((List<T, N>&) * this).size(); i++)
			{
				if (label == ((List<T, N>&) * this)[i].getLabel())
					sumOfValue = ((List<T, N>&) * this)[i].sum(label, sumOfValue);
			}


			return sumOfValue;




		}


	};








}// end namespace


#endif // !SICT_LIST_H



