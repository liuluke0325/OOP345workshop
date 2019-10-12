/*
Hsueh Chih LIu
116131186
06/19/2019


*/


#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <utility>

namespace sict {
	//managing a dynamically allocated list of T objects.


	template <typename T>
	class KVList {

		T* list;
		int length;
		int currentSize;

	public:
		KVList() :list{ nullptr }, length{ 0 }, currentSize{ 0 } {}
		KVList(int n) :KVList() {


			if (n > 0)
			{
				this->length = n;
				list = new T[n];
			}
			else
			{
				throw n;
			}



		}

		KVList(KVList&& src) {

			this->length = src.length;
			this->currentSize = src.currentSize;
			this->list = new T[this->length];

			for (int i = 0; i < length; i++)
			{
				this->list[i] = src.list[i];
			}

			src.length = 0;
			delete[] src.list;
			src.list = nullptr;

		}


		~KVList() { delete[] this->list; }

		const T& operator[](size_t i) const {

			size_t returnValue = 0;


			if (i < this->length)
			{
				returnValue = list[i];
			}
			else {
				throw "The index passed to the subscripting operator is out - of - bounds.";
			}
			return returnValue;
		}

		template<typename F>void display(std::ostream& os, F f) const {
			//a templated query that inserts into the output stream os on a separate line each object in the list
			if (this->length > 0)
			{
				for (int i = 0; i < this->length; i++)
				{
					this->list[i].display(os, f);

				}


			}
		}
		//If there are no objects in the list or the object is in a safe empty state, this query does nothing.

		void push_back(const T& t) {
			//if there is room in the list, adds the object t to the list. If the list is full, this function does nothing.
			if (this->currentSize < this->length)
			{
				this->list[currentSize] = t;

				currentSize++;
			}
		}


		//Your design disables copy and move assignment operations and copy construction of the list.
		KVList(const KVList&) = delete;
		KVList& operator = (const KVList&) = delete;

	};

}









#endif // !SICT_KVLIST_H
