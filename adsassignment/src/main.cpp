/*
 * @brief	this file contains only the main function 
 *			that calls and execute the application code
 *
 * @author	Ranbir Roshan
 *
 * @date		19/10/2018
 *
 * @last-modified 19/10/2018
 */

#include "../assignment.h"
#include <iostream>

/*!
 * \brief  main function starting point of the program
 * 
 * \param[in] argc	argument count 
 * \param[in] argv[]	argument vector
 * \return int
 * 
 * \note	the program need 1 arguments if more than 1 arguments are provided
 *			only the first argument will be considered and the others will be 
 *			ignored
 */
int main(int argc, char *argv[])
{
		SearchApp myApp;

	if (argc < 2)
		std::cout << ("\n\nPlease provide the input file name as command line argument.");
	else {

		if (myApp.Initialize (argv[1], "output_file.txt"))
			myApp.Execute();	///< execute as initialization was successful
		else
			std::cout << ("\n\nProblem in operating the inlput file. The file provided is:") << argv[1];
	}

	return 0;
}
