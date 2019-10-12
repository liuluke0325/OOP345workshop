/*

name:hsueh chih liu
id : 116131186
date : 05/24/2019

*/


#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict {
	// predefines the maximum number of record objects at 10
	const int MAXRD = 10;

	class Timekeeper {
		//a.The number records currently stored
		int numRecords;
		// b.The start time for the current event(an std::chrono::steady_clock::time_point object)
		std::chrono::steady_clock::time_point startTime;
		//c.The end time for the current event(an std::chrono::steady_clock::time_point object)
		std::chrono::steady_clock::time_point endTime;
		//d.An array of records of anonymous structure(no Tag) type named record where each element contains :
		struct
		{
			//a.The address of a C - style null - terminated string containing a message in a literal string.
			const char* pmsg;
			//b.The address of a C - style null - terminated string containing the predefined units of time
			const char* punits;
			//c.The duration of the recorded event(an std::chrono::steady_clock::duration object)
			std::chrono::steady_clock::duration recordDur;

		}  record[MAXRD];

	public:
		Timekeeper();
		//start() a modifier that starts the stopwatch for an event
		void start();
		// stop() a modifier that stops the stopwatch for an event
		void stop();
		//recordEvent()
		void recordEvent(const char* );

		std::ostream& report( std::ostream & os)const;


	};
}// end of namespace

#endif // !SICT_TIMEKEEPER_H
