/*
 * @brief	the file contains the programming project's actual application
 *			"SearchApp" class decleration.
 *
 * @author	Ranbir Roshan
 * 
 * @date	19/10/2018
 *
 * @last-modified 19/10/2018
 */

#ifndef SEARCH_APP
#define SEARCH_APP

#include <fstream>

#include "libdatastruct.h"

/*
 * @brief	the actual search application code
 *
*/
class SearchApp {
public:

	// constructor and destructor
	SearchApp();
	~SearchApp();

	// the application starts here
	bool Initialize(const char * pInputFileName);
	void Execute();
private:

	std::ifstream*	vInFile;		// for reading input from file
};

#endif //SEARCH_APP