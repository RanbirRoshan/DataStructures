/*
* @brief	the file contains inline function definition for class FibonacciHeap
*
* @author	Ranbir Roshan
*
* @date		25/10/2018
*
* @last-modified 25/10/2018
*/


/*!
* \brief	The function changes the key of the node to the specified key only if
*			the key is greater than the current key and the heap is a max heap
*
* \param[in] pNode		The node for which the key has to be changed
* \param[in] pNewKey	The new value of the key that is to be set
* \param[in] pSize		The size of key in bytes
*
* \return	The function would return the following:
*			- True		If in case the change is successfull
*			- False		Change key fails as the newly provided key is smaller than or equal to
*						the existing key in case of max heap. if the API is accessed
*						for a min heap it would still return false. If the node is not
*						a part of current heap it would return false. If no new key is provided 
*						or its size is 0 it will return false;
*/
bool FibonacciHeap::IncreaseKey(FiboHeapNode * pNode, void * pNewKey, size_t pSize)
{
	if (!vRoot || IsMinHeap() || !pNode || pNode->vInHeap != this || !pNewKey || !pSize)
		return false;

	return ChangeKey(pNode, pNewKey, pSize);
}

/*!
* \brief	The function changes the key of the node to the specified key only if
*			the key is smaller than the current key and the heap is a min heap
*
* \param[in] pNode		The node for which the key has to be changed
* \param[in] pNewKey	The new value of the key that is to be set
* \param[in] pSize		The size of key in bytes
*
* \return	The function would return the following:
*			- True		If in case the change is successfull
*			- False		Change key fails as the newly provided key is bigger than the
*						existing key in case of the max heap. if the API is accessed
*						for a max heap it would still return false. If the node is not 
*						a part of current heap it would return false.
*/
bool FibonacciHeap::DecreaseKey(FiboHeapNode * pNode, void * pNewKey, size_t pSize)
{
	if (!vRoot || !IsMinHeap() || !pNode || pNode->vInHeap != this || !pNewKey || !pSize)
		return false;

	return ChangeKey(pNode, pNewKey, pSize);
}