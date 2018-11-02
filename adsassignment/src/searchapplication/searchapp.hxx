/*!
 *	\file	searchapp.hxx
 *
 *	\brief	The file contains the inline function definition for class
 *			SearchApp and its associated classes
 *
 *	\author	Ranbir Roshan
 *
 *  \modified 2/11/2018
 *
 */


/*!
 * \brief	The public static interface to get the offset of the key for the node
 *
 * \return	the offset of the frequency relative to the node class
 */
int SearchAppHeapNode::GetKeyOffset()
{
	return offsetof(SearchAppHeapNode, vFrequency);
}
	
/*!
 * \brief	The interface to access the keyword stored in the node
 *
 * \return	A pointer to std::string object that stores the keyword
 */
std::string* const SearchAppHeapNode::GetKeyword()
{
	return vKeyWord;
}

/*!
 * \brief	The interface is to access the frequency stored in the node
 *
 * \return  An integer value that is the frequency of the element in the node
 */
int SearchAppHeapNode::GetFrequency()
{
	return vFrequency;
}