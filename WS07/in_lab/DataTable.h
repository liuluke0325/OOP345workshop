#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>
extern int ND;
extern int FW;

namespace sict {


	template <typename T>
	class DataTable {

		std::vector<T> dataX;
		std::vector<T> dataY;


	public:
		DataTable(std::ifstream& src) {
			T tempX;
			T tempY;

			while (!src.eof())
			{
				src >> tempX >> tempY;
				dataX.push_back(tempX);
				dataY.push_back(tempY);
			}

		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;

			os << std::setw(FW) << "x" <<" ";
			os << std::setw(FW) << "y" << std::endl;
			for (auto i = 0; i < dataX.size(); i++)
			{
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << dataX[i] << " "; // print out each data for X
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << dataY[i] << std::endl;
			}

		}

		void displayStatistics(std::ostream& os) const {
			//calculate the mean
			auto mean = std::accumulate(this->dataY.begin(), this->dataY.end(), (T)0) / this->dataY.size();

			//calculate the sigma (ssd)
			auto ssd = std::accumulate(this->dataY.begin(), this->dataY.end(), (T)0, [=](T x, T y) {
				return x + pow((y - mean), 2);
				});
			ssd /= this->dataY.size() - 1;
			ssd = sqrt(ssd);


			//display
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;

			os << "  y " << std::setw(FW) << std::left << "mean" << " = " << std::setw(FW) << std::right << mean << std::endl;
			os << "  y " << std::setw(FW) << std::left << "sigma" << " = " << std::setw(FW) << std::right << ssd << std::endl;
		}


	};



}

#endif // !SICT_DATA_TABL	E_H
