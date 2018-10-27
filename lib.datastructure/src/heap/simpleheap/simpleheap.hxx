/*
* @brief	the file contains inline function definition for class Heap
*
* @author	Ranbir Roshan
*
* @date		26/10/2018
*
* @last-modified 27/10/2018
*/

/*!
* \brief	The function indentifies the min heap or max heap property of binomial heap
*
* \return	True if Min Heap otherwise False for a max Heap
*/
bool Heap::IsMinHeap() {

	return (vIsMinHeap) ? true : false;
}

/*!
* \brief	Helper function to access and see the min or max value as per the binomial heap property
*
* \return
*/
HeapNode* const Heap::PeekMinMax()
{
	return vRoot;
}

/*!
* \brief	The function compares the two nodes and based on the heap type (min/max) would return
*			true if the 2nd node is better as per the heap type
*
* \param[in] pNode1	First comparison node
* \param[in] pNode2	Second comparison node
*
* \return		true if the second node has less value and heap is min heap or second value is
*				greater and the heap is	a max heap. Else it would return false.
*/
bool Heap::IsSecondNodeBtr(HeapNode * pNode1, HeapNode * pNode2)
{
	return IsSecondKeyBtr(((char*)pNode1) + vKeyOffset, ((char*)pNode2) + vKeyOffset);
	/*
	// see if the current node should be the new node
	switch (vIsMinHeap) {

	case 1:	// Min Binomial Heap
	if (vKeyCmpFunc(((char*)pNode1) + vKeyOffset, ((char*)pNode2) + vKeyOffset) > 0)
	return true;
	break;

	case 0: // Max Binomial Heap
	if (vKeyCmpFunc(((char*)pNode1) + vKeyOffset, ((char*)pNode2) + vKeyOffset) < 0)
	return true;
	break;
	}

	return false;*/
}

/*
 * \brief	Helper function for child class to acess key offset value with respect to node
 */
int  Heap::GetKeyOffset()
{
	return vKeyOffset;
}