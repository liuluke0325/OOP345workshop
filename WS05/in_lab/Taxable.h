#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {

	//functor (function object) named Taxable that receives a value and returns the sum of the value with the tax on it.



	class Taxable {


		const float taxRate;
	public:
		Taxable(float TAXRATE) :taxRate{ TAXRATE } {}
		float operator()(float price) {
			return price * (1 + taxRate);
		}

	};





}



#endif // !SICT_TAXABLE_H
