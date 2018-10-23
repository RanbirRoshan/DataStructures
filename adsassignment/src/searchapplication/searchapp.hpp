/*!
 * @brief	The file contains the programming project's actual application
 *			"SearchApp" class decleration.
 *
 * @author	Ranbir Roshan
 * 
 * @date	19/10/2018
 *
 * lastmodified 19/10/2018
 */

#ifndef SEARCH_APP
#define SEARCH_APP

#include <fstream>

#include "libdatastruct.h"

/*!
 * \brief	the actual search application code
 *
 * \warning	the user is expected to call Initialize API after object construction and before using any other class APIs
 */
class SearchApp {
public:

	// constructor and destructor
	SearchApp();
	~SearchApp();

	// the application management APIs
	bool Initialize(const char * pInputFileName);
	void Execute();
private:

	std::ifstream*	vInFile;		///< stream for reading input from file
};

#endif //SEARCH_APP