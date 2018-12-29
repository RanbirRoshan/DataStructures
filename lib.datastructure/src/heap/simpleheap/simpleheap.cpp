#include "../../../libdatastruct.h"

/*!
* \brief	constructor for the class Heap
*
* \param[in] pKeyOffset	Offset of key in the node. Use offsetof to find the same.
* \param[in] pKeyCmpFunc  Key comparison function
* \param[in] pMinHeap     True if the heap is supposed to behave as min heap else false
*/
Heap::Heap(Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pMinHeap)
{
#ifdef _DEBUG
	if (pKeyCmpFunc == nullptr)
		DebugBreak();
#endif

	vRoot		= nullptr;
	vKeyCmpFunc	= pKeyCmpFunc;
	vKeyOffset	= pKeyOffset;
	vIsMinHeap	= pMinHeap;
}

/*!
 * \brief	Destructor for class Heap
 */
Heap::~Heap()
{
	if (vRoot) {
		// the tree has not been destroyed by the user or else the destroy would
		// have made the root as nullptr
		Destroy();
	}
}

/*!
* \brief	The function compares the two keys and based on the heap type (min/max) would return
*			true if the 2nd node is better as per the heap type
*
* \param[in] pKey1	First comparison key
* \param[in] pKey2	Second comparison key
*
* \return		true if the second key has less value and heap is min heap or second value is
*				greater and the heap is	a max heap. Else it would return false.
*/
bool Heap::IsSecondKeyBtr(void * pKey1, void * pKey2)
{

	// see if the current node should be the new node
	switch (vIsMinHeap) {

	case 1:	// Min Binomial Heap
		if (vKeyCmpFunc(pKey1, pKey2) > 0)
			return true;
		break;

	case 0: // Max Binomial Heap
		if (vKeyCmpFunc(pKey1, pKey2) < 0)
			return true;
		break;
	}

	return false;
}
/*!
* \brief	The function is useful in identifying the node type provided for
*			any tree operation. As most node types have some common hiererchy
*			it is reqired for verifying the node type in relevent tree operation
*
* \return the node type of the current tree node
*/
eNodeType HeapNode::NodeType()
{
	return NT_HEAP_NODE;
}

/*!
* \brief	The function destroys the tree by calling delete on all its node and setting the root as null
*
*/
void Heap::Destroy()
{
	HeapNode *node;

#ifdef _DEBUG
	if (vRoot->NodeType() != NT_HEAP_NODE)
		DebugBreak();
#endif

	while (PeekMinMax ())
	{
		node = RemoveMinMax();
		delete node;
	}
}

/*!
 * \brief	The public API to return the min/max node depending of heap type
 */
HeapNode * Heap::RemoveMinMax()
{
	return nullptr;
}
