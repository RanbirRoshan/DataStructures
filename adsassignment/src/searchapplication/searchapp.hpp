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

/*!
 * \class	SearchAppHeapNode
 *
 * \brief	The class defines the node that is used by the search application
 *			to store keyword and associated frequency in the heap.
 */
class SearchAppHeapNode : public FiboHeapNode {
public:

	//constructors and destructors
	SearchAppHeapNode(std::string *pKeyword, int pFrequency);
   ~SearchAppHeapNode();

   // public get API to access the properties of the object
static	inline	int				GetKeyOffset();
		inline	int				GetFrequency();
		inline	std::string* const	GetKeyword();

private:
	int				vFrequency;		///< the frequency of the keyword stored in the node
	std::string *	vKeyWord;		///< the keyword that the node identifies
};

/*!
 * \class	SearchApp
 *
 * \brief	The actual search application code is contained and controlled
 *			by this class
 *
 * \note	The following are assumptions for the code
 *			-	The length of single line is less than or equal to 4096 char
 *			-	A line starting with '$' conatins space seperated keyword and frequency
 *			-	A line starting with 's' or 'S' is signal for termination
 *			-	Any line different from above two will contain a single integer that denotes
 *				the number of top keywords to be printed by the application
 *
 * \warning	The user is expected to call Initialize API after object 
 *			construction and before using any other class APIs
 */
class SearchApp {
public:

	// constructor and destructor
	SearchApp ();
   ~SearchApp ();

	// the application management APIs
	bool Initialize (const char * pInputFileName, const char * pOutFileName);
	void Execute ();
private:

	bool ProcessNewEntry (char* pKeyword, int pFrequency);
	bool PrintTopResult  (int pCount);

	FibonacciHeap *		vHeap;			///< The datastructure to store the keyword sorted by frequency
	std::ifstream*		vInFile;		///< stream for reading input from file
	std::ofstream*		vOutFile;		///< stream of writing output

	std::unordered_map<std::string, SearchAppHeapNode*>   vKeywordMap;	///< a map for keyword to node to find node
};

#include "searchapp.hxx"

#endif //SEARCH_APP