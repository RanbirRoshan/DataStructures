/*
* @brief	the file contains inline function definition for class BinomialHeap
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* @last-modified 20/10/2018
*/

/*!
 * \brief	The function indentifies the min heap or max heap property of binomial heap
 * 
 * \return	True if Min Heap otherwise False for a max Heap
 */
bool BinomialHeap::IsMinHeap() {

	return (vIsMinHeap) ? true : false;
}

/*!
 * \brief	Helper function to access and see the min or max value as per the binomial heap property
 * 
 * \return 
 */
BinomialHeapNode* const BinomialHeap::PeekMinMax()
{
	return vRoot;
}