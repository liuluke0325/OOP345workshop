/*

name:hsueh chih liu
id : 116131186
date : 05/24/2019

*/



#include "Timekeeper.h"
#include <chrono>
#include <iomanip>
using namespace std;
namespace sict {


	Timekeeper::Timekeeper() {
		
		this->numRecords = 0;
	}

	void Timekeeper::start() {
		this->startTime = chrono::steady_clock::now(); // set the start time

	}

	void Timekeeper::stop() {

		this->endTime = chrono::steady_clock::now(); // set the end time
	}

	void Timekeeper::recordEvent(const char* str) { // holds the description of the event

		//this function copies the address of the description into the next time record,
		record[numRecords].pmsg = str;
		//calculates the duration of the eventand copies it into the next time record,
		record[numRecords].recordDur = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		//copies the address of the literal string containing a description of the units of time into the next time records
		record[numRecords].punits = " seconds";
		// and increments the instance variable that identifies the next empty time record.
		this->numRecords++;

	}


	ostream& Timekeeper::report(std::ostream& os) const {

		os <<endl<< "Execution Times:" << endl;
		for (int i = 0; i < numRecords; i++) {
			os << record[i].pmsg <<" "<< setw(5) <<record[i].recordDur.count()/ 1000000 << record[i].punits<< endl;
		}

		return os;
	}

}