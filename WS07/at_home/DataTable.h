/*
Hsueh Chih Liu
116131186
07/06/2019
*/


#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <algorithm>
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

			while (src >> tempX >> tempY)
			{

				dataX.push_back(tempX);
				dataY.push_back(tempY);
			}

		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;

			os << std::setw(FW) << "x" << " ";
			os << std::setw(FW) << "y" << std::endl;
			for (auto i = 0; i < dataX.size(); i++)
			{
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << dataX[i] << " "; // print out each data for X
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << dataY[i] << std::endl;
			}

		}

		void displayStatistics(std::ostream& os) const {
			std::vector <T> temp;

			//calculate the mean
			auto mean = std::accumulate(this->dataY.begin(), this->dataY.end(), (T)0) / this->dataY.size();

			//calculate the sigma (ssd)
			auto ssd = std::accumulate(this->dataY.begin(), this->dataY.end(), (T)0, [=](T x, T y) {
				return x + pow((y - mean), 2);
				});
			ssd /= this->dataY.size() - 1;
			ssd = sqrt(ssd);


			// median
			temp = this->dataY;
			std::sort(temp.begin(), temp.end());
			auto median = temp[temp.size() / 2];

			//slope
			auto sizeX = this->dataX.size();
			auto sumXY = std::inner_product(dataX.begin(), dataX.end(), dataY.begin(), (T)0);
			auto sumXX = std::accumulate(this->dataX.begin(), this->dataX.end(), (T)0, [](T x, T y) {return x + y * y; });
			auto sumX = std::accumulate(this->dataX.begin(), this->dataX.end(), (T)0);
			auto sumY = std::accumulate(this->dataY.begin(), this->dataY.end(), (T)0);
			auto slope = (sizeX * sumXY - sumX * sumY) / (sizeX * sumXX - sumX * sumX);


			//y_intercept
			auto y_intercept = (sumY - slope * sumX) / sizeX;

			//display
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;
			os << std::fixed << std::setprecision(ND);
			os << std::left << std::setw(12) << "  y mean" << " = " << std::setw(FW) << std::right << mean << std::endl;
			os << std::left << std::setw(12) << "  y sigma" << " = " << std::setw(FW) << std::right << ssd << std::endl;
			os << std::left << std::setw(12) << "  y median" << " = " << std::setw(FW) << std::right << median << std::endl;
			os << std::left << std::setw(12) << "  slope" << " = " << std::setw(FW) << std::right << slope << std::endl;
			os << std::left << std::setw(12) << "  intercept" << " = " << std::setw(FW) << std::right << y_intercept << std::endl;



		}


	};



}

#endif // !SICT_DATA_TABLE_H
