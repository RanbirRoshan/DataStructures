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
* \brief	The function indentifies the min heap or max heap property of fibonacci heap
*
* \return	True if Min Heap otherwise False for a max Heap
*/
bool FibonacciHeap::IsMinHeap() {

	return (vIsMinHeap) ? true : false;
}