/*!
 * @brief	the file contains the programming project's actual application
 *			"SearchApp" class non inline function definition.
 *
 * @author	Ranbir Roshan
 *
 * @date	19/10/2018
 *
 * @last-modified 19/10/2018
 */

#include <iostream>

#include "searchapp.hpp"

using namespace std;

/*!
 * \brief	constructor of the class
 */
SearchApp::SearchApp()
{
	vInFile = nullptr;
}

/*!
 * \brief	destructor of the class 
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

/*!
 *
 * \brief	The function initializes the application class so that the execution
 *			pre-requisites are met.
 * 
 * \param[in] pInputFileName	The path of the input file. The details about the format
 *								of input file can be found in the project file persent in
 *								the reposiotry.
 * 
 * \return	True if the initialization is sucessfull else false.
 * 
 * \note	The function returns false only if the file cannot be opened or no or empty name provided.
 * 
 * \warning	The user is expected to call Initialize after construct and before calling any other public APIs
 *			else the behavior of program is undefined.
 */
bool SearchApp::Initialize(const char * pInputFileName)
{
	if (pInputFileName == NULL || *pInputFileName == EOS)
	{
		cout << "\nThe input file name cannot be empty. \
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

/*!
 * 
 * \brief	execution of the application starts from here
 */
void SearchApp::Execute()
{
	SBTNode * node = new SBTNode();
	delete node;
	cout << "The code from library called and executed.";
}