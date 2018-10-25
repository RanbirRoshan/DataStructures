/*!
* @brief	The file contains the non inline definitions for fibonacci heap and
*			other associated decleration.
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* lastmodified 25/10/2018
*/

#include "../../libdatastruct.h"

/*!
* \brief	The function is useful in identifying the node type provided for
*			any tree operation. As most node types have some common hiererchy
*			it is reqired for verifying the node type in relevent tree operation
*
* \return the node type of the current tree node
*/
eTreeNodeType FiboHeapNode::NodeType()
{
	return TNT_FIBO_HEAP;
}

/*!
 * \brief	cunstructor for the fibonacci heap node
 * 
 */
FiboHeapNode::FiboHeapNode()
{
	vChild			= nullptr;
	vParent			= nullptr;
	vRightSibling	= nullptr;
	vRightSibling	= nullptr;
	vDegree			= 0;
	vChildCut		= 0;
}

/*!
 * \brief constructor for Fibonacci Heap class
  * 
  * \param[in] pKeyOffset	Offset of key in the node. Use offsetof to find the same.
  * \param[in] pKeyCmpFunc  Key comparison function
  *	\param[in] pMinHeap     True if the heap is supposed to behave as min heap else false
 */
FibonacciHeap::FibonacciHeap (Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pIsMinHeap)
{
	vKeyOffset  = pKeyOffset;
	vKeyCmpFunc = pKeyCmpFunc;
	vIsMinHeap  = pIsMinHeap;
	vRoot		= nullptr;
}

/*!
 * \brief	destructor for the fibonacci heap class
 * 
 */
FibonacciHeap::~FibonacciHeap()
{

}

/*
/*!
 * \brief	The function cleans up the entire heap by calling delete on every node on the heap
 * 
 *
void FibonacciHeap::Destroy()
{

}*/

/*!
 * \brief		the funciton provides capability to insert a node in the tree
 * 
 * \param[in] pNode	the pointer to the node being inserted
 * 
 * \return	the function would return 
 *			- pNode			in case of sucessful insertion
 *			- nullptr		in case of insertion failure
 * 
 * \note	a node that is a part of any other heap will not be inserted and 
 *			the function would return nullptr
 */
FiboHeapNode * FibonacciHeap::Insert(FiboHeapNode * pNode)
{
	if (!pNode)
		return nullptr;

	if (pNode->vLeftSibling || pNode->vRightSibling || pNode->vParent || pNode->vChild || pNode->vDegree || pNode->vChildCut)
		return nullptr;

	// empty heap 
	if (!vRoot)
	{
		vRoot = pNode;
		return pNode;
	}


}