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
#include <unordered_map>
#include <string>

#define MAX_BUFFER_LENGTH 4096

class SearchAppHeapNode : public FiboHeapNode {
public:
		SearchAppHeapNode(std::string *pKeyword, int pFrequency);
	   ~SearchAppHeapNode();

static	inline	int				GetKeyOffset();
		inline	int				GetFrequency();
		inline	std::string*	GetKeyword();

private:
	int				vFrequency;
	std::string *	vKeyWord;
};

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

	bool ProcessNewEntry (char* pKeyword, int pFrequency);
	bool PrintTopResult  (int pCount);

	FibonacciHeap *		vHeap;
	std::ifstream*		vInFile;		///< stream for reading input from file

	std::unordered_map<std::string, SearchAppHeapNode*>   vKeywordMap;
};

#include "searchapp.hxx"

#endif //SEARCH_APP