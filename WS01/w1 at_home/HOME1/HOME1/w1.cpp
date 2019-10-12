// hsueh chih liu
// 116 131 186
// date: 5/17/2019
#include <iostream>
#include "process.h"
using namespace sict;
using namespace std;

extern const int INITIAL = 3;

int main(int argc, char* argv[]) {
	int returnValue;

	// echo the command
	cout << "Command Line : ";

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << " ";
	}

	cout << endl;




	if (argc == 1) // if the user has not entered any string on the command line
	{
		cout << "***Insufficient number of arguments***" << endl;
		returnValue = 1;
	}
	else // passes the address of that string as the only argument
	{
		for (int i = 1; i < argc; i++)
		{
			process(argv[i]);
		}
		returnValue = 0;
	}


	return returnValue;
}