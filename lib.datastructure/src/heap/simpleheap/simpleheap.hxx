

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