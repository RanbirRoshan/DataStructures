/*
* @brief	the file contains the programming project's actual application
 *			"SearchApp" class non inline function definition.
*
* @author	Ranbir Roshan
*
* @date		19/10/2018
*
* @last-modified 19/10/2018
*/

#include <iostream>

#include "searchapp.hpp"

using namespace std;

/*
 * @brief	constructor of the class
 */
SearchApp::SearchApp()
{
	vInFile = nullptr;
}

/*
* @brief	destructor of the class
*/
SearchApp::~SearchApp()
{
	// close the file if open and free memory if aquired
	if (vInFile) {
		if (vInFile->is_open())
			vInFile->close();

		delete vInFile;
	}
}

/*
 *
*/
bool SearchApp::Initialize(const char * pInputFileName)
{
	if (pInputFileName == NULL || *pInputFileName == EOS)
	{
		cout << TEXT"\nThe input file name cannot be empty. \
					 Please provide a input file name as first command line argument and try again.";
		return false;
	}

	vInFile = new ifstream(pInputFileName, std::ifstream::in);

	if (!vInFile->is_open()) {
		cout << "\nFailed to open the file.";
		return false;
	}

	return true;
}

/*
* @brief	execution of the application starts from here
*/
void SearchApp::Execute()
{
	SBTNode * node = new SBTNode();
	delete node;
	cout << "The code from library called and executed.";
}