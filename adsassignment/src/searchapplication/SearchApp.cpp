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
#include <stack>

#include "searchapp.hpp"

using namespace std;

static long long IntCmpFunc(const void * pCmpVal1, const void * pCmpVal2)
{
	int *val1 = (int *)pCmpVal1;
	int *val2 = (int *)pCmpVal2;

	if (*val1 > *val2)
		return 1;

	if (*val1 < *val2)
		return -1;

	return 0;
}

SearchAppHeapNode::SearchAppHeapNode(std::string *pKeyword, int pFrequency)
{
	vKeyWord    = pKeyword;
	vFrequency	= pFrequency;
}

SearchAppHeapNode::~SearchAppHeapNode()
{
	delete vKeyWord;
}

/*!
 * \brief	constructor of the class
 */
SearchApp::SearchApp()
{
	vInFile = nullptr;
	vHeap   = new FibonacciHeap(SearchAppHeapNode::GetKeyOffset(), IntCmpFunc, false);
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

	delete vHeap;
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

class FiboHeapTestIntNode : public FiboHeapNode {
public:
	__int64		uKey;
};

int ParseFrequency(char * pStrBuf, int len = MAX_BUFFER_LENGTH)
{
	int pos = 0;

	while (pStrBuf[pos] != ' ') {
		pos++;
	}

	pStrBuf[pos] = '\0';

	return atoi(pStrBuf + pos + 1);
}

/*!
 * 
 * \brief	execution of the application starts from here
 */
void SearchApp::Execute()
{
	char		linebuf[MAX_BUFFER_LENGTH];
	int			frequency;
	
	while (!vInFile->eof()) {

		switch (vInFile->peek()) {
		case '$':
			// the input is a string and a number
			vInFile->getline(linebuf, 4096, '\n');
			frequency = ParseFrequency(linebuf + 1);

			if (ProcessNewEntry(linebuf + 1, frequency) == false)
			{
				std::cout << "\nFailed processing this line: " << linebuf;
				return;
			}
			break;
		case 's':
		case 'S':
			return;
		default:
			vInFile->getline(linebuf, 4096, '\n');
			PrintTopResult(atoi(linebuf));
			break;
		}
	}
	return;
}

bool SearchApp::PrintTopResult(int pCount)
{
	std::stack<SearchAppHeapNode*>  stack;
	SearchAppHeapNode *				node;

	while (pCount && vHeap->PeekMinMax()) {
		node = (SearchAppHeapNode*) vHeap->RemoveMinMax();
		cout << *node->GetKeyword() << "\n";
		stack.push(node);
		pCount--;
	}

	while (!stack.empty()) {
		vHeap->Insert(stack.top());
		stack.pop();
	}

	return true;
}

bool SearchApp::ProcessNewEntry(char * pKeyword, int pFrequency) 
{
	std::unordered_map<std::string, SearchAppHeapNode*>::iterator iter;
	std::string *			keyword;
	SearchAppHeapNode *		node;
	int						frequency;

	keyword = new std::string(pKeyword);

	iter = vKeywordMap.find(*keyword);

	if (iter == vKeywordMap.end()) {
		node = new SearchAppHeapNode(keyword, pFrequency);

		vKeywordMap.insert(std::make_pair(*keyword, node));
		if (vHeap->Insert(node) == node)
			return true;
		else
			return false;
	}

	frequency = iter->second->GetFrequency() + pFrequency;
	
	return vHeap->IncreaseKey(iter->second, &frequency, sizeof(int));;
}

void TestCode()
{
	/*
	FiboHeapTestIntNode *node, *nodes[50];
	int					 iter;
	__int64     val;

	FibonacciHeap *testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	for (iter = 0; iter < 50; iter++)
	{
	nodes[iter] = new FiboHeapTestIntNode();
	nodes[iter]->uKey = std::rand() * 10000000000;
	nodes[iter]->uKey *= (nodes[iter]->uKey % 8) ? 1 : -1;
	testheapintmax->Insert(nodes[iter]);
	}

	for (iter = 0; iter < 50; iter++)
	{
	val = nodes[iter]->uKey * 10;
	testheapintmax->IncreaseKey(nodes[iter], &val, sizeof (__int64));
	}

	for (iter = 0; iter < 50; iter++)
	{
	val = nodes[iter]->uKey * 10;
	delete testheapintmax->Remove(nodes[iter]);
	}
	for (iter = 0; iter < 50; iter++)
	{
	nodes[iter] = new FiboHeapTestIntNode();
	nodes[iter]->uKey = std::rand() * 10000000000;
	nodes[iter]->uKey *= (nodes[iter]->uKey % 8) ? 1 : -1;
	testheapintmax->Insert(nodes[iter]);
	}

	for (iter = 0; iter < 50; iter++)
	{
	val = nodes[iter]->uKey * 10;
	testheapintmax->IncreaseKey(nodes[iter], &val, sizeof(__int64));
	}

	for (iter = 0; iter < 500; iter++)
	{
	for (int i = 0; i < iter % 5; i++)
	{
	node = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();
	if (node) {
	delete node;
	}
	}

	for (int i = 0; i < iter % 5; i++) {
	__int64 temp;
	node = new FiboHeapTestIntNode();
	node->uKey = std::rand() * 2;
	node->uKey *= (node->uKey % 8) ? 1 : -1;
	testheapintmax->Insert(node);
	temp = node->uKey;
	node = new FiboHeapTestIntNode();
	node->uKey = temp;
	testheapintmax->Insert(node);
	}
	}

	delete testheapintmax;*/
}