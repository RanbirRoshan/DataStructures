/*
* @brief	the file contains non-inline function definition for class BinomialHeap
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* @last-modified 20/10/2018
*/

#include "..\..\libdatastruct.h"
#include <assert.h>
#include <queue>
#include <map>

 /*!
  * \brief	constructor for the class BinomialHeap
  * 
  * \param pKeyOffset	Offset of key in the node. Use offsetof to find the same.
  * \param pKeyCmpFunc  Key comparison function
  */
BinomialHeap::BinomialHeap (Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc)
{
	// the developer is expected to provide this for data structure to work
	assert(pKeyCmpFunc == nullptr);

	vRoot		= nullptr;
	vLastSibling= nullptr;
	vKeyOffset	= pKeyOffset;
	vKeyCmpFunc = pKeyCmpFunc;
}

/*!
 * \brief	The destructor is expected to destroy the tree and its content
 * 
 * \note	The nodes cannot be part of two trees so the nodes if not already
 *			destroyed by the user will be destroyed here. 
 */
BinomialHeap::~BinomialHeap()
{
	if (vRoot) {
		// the tree has not been destroyed by the user or else the destroy would
		// have made the root as nullptr
		Destroy();
	}
}

/*!
* \brief	The function is useful in identifying the node type provided for
*			any tree operation. As most node types have some common hiererchy
*			it is reqired for verifying the node type in relevent tree operation
*
* \return the node type of the current tree node
*/
eTreeNodeType BinomialHeapNode::NodeType()
{
	return TNT_BINOMIAL_HEAP;
}

/*!
 * \brief	constructor for the class BinomialHeapNode
 * 
 */
BinomialHeapNode::BinomialHeapNode()
{
	uDegree			= 0;
	uChild			= nullptr;
	uRightSibling	= nullptr;
}

/*!
 * \brief	The function would attempt to insert the new node into the Binomial Heap.
 * 
 * \param[in] pNode	The new node that is to be inserted into the binomial heap
 * 
 * \return	The following are the return possibility:
 *			- nullptr	if the insertion failed
 *			- pNode		if the insertion is successful
 * 
 * \note	The insertion would fail if the following scenario:
 *			-	nullptr has been attempted to insert
 *			-	the node being inserted has siblings. Use merge for this scenario.
 * 
 * \warning	If an attempt is made tp insert a wrong node type in the tree. A debug assertion would
 *			be triggered in debug mode. However, in release condition this is unhandled and the impact of
 *			this is undefined. To enable this remove assertion and write if and return nullptr when true.
 */
BinomialHeapNode *	BinomialHeap::Insert(BinomialHeapNode* pNode)
{

	if (!pNode || pNode->uRightSibling) {
		// make developer life easy if he has passed some wrong node by mistake
#ifdef _DEBUG
		if (pNode)
			assert(pNode->uRightSibling == nullptr);  
#endif
		return nullptr;
	}

	// make developer life easy by pointing out wrong node use for the data structure
	assert(pNode->NodeType () != TNT_BINOMIAL_HEAP);

	if (!vRoot) {
		
		vRoot		 = pNode;
		vLastSibling = pNode;

		return pNode;
	}

	// add the node as the sibling of the current root
	pNode->uRightSibling = vRoot->uRightSibling;
	vRoot->uRightSibling = pNode;

	if (vRoot == vLastSibling)
		vLastSibling = pNode;

	if (IsSecondNodeBtr(vRoot, pNode)) {

		vLastSibling = vRoot;
		vRoot = pNode;
	}

	return pNode;
}

/*!
 * \brief	The function destroys the tree by calling delete on all its node and setting the root as null
 * 
 */
void BinomialHeap::Destroy()
{
		BinomialHeapNode * node;
		BinomialHeapNode * tempnode;

	// if we have reached start of the circular list then we return as this node is already accounted for
	if (!vRoot)
		return;

	node = vRoot;

	// destroying the circular link
	vLastSibling->uRightSibling = nullptr;

	while (node) {
		tempnode = node;
		node = node->uRightSibling;
		delete tempnode->uChild;
		delete tempnode;
	}

	vRoot = nullptr;
	vLastSibling = nullptr;
}

/*!
 * \brief The function melds all the childs on the passed Binomial Heap into itslef
 * 
 * \param[in] pMeldHeap	The Binomial Heap that is to be meld
 * \param[in] pDeleteAfterMeld	The parameter has following behavior
 *								- True	-pMeldHeap will be deleted post sucessful meld 
 *								- False -If operation is successful pMeldNode will become empty but will not be deleted. It is the responsiility of caller to free the memory.
 * 
 * \return	The function have the following return behavior:
 *			-	True - The meld was successful
 *			-	Flase - The meld failed because the heap type does not match. In this case pMeldHeap is untouched
 */
bool BinomialHeap::Meld(BinomialHeap* pMeldHeap, bool pDeleteAfterMeld)
{
	if (!pMeldHeap)
		return true;

	// heap type mismatch
	if (vIsMinHeap != pMeldHeap->vIsMinHeap)
		return false;

	// request to meld empty binomial heap
	if (!pMeldHeap->vRoot) {

		if (pDeleteAfterMeld)
			delete pMeldHeap;
		
		return true;
	}

	if (!vRoot)
	{
		vRoot = pMeldHeap->vRoot;
		vLastSibling = pMeldHeap->vLastSibling;

		if (pDeleteAfterMeld)
			delete pMeldHeap;
		else {
			// as we have moved the nodes emptying the other heap beore deletion
			pMeldHeap->vRoot = nullptr;
			pMeldHeap->vLastSibling = nullptr;
		}

		return true;
	}

	// creating the new sibling circular link list
	vLastSibling->uRightSibling = pMeldHeap->vRoot;
	pMeldHeap->vLastSibling->uRightSibling = vRoot;

	if (IsSecondNodeBtr (vRoot, pMeldHeap->vRoot))
		vRoot = pMeldHeap->vRoot;
	else
		vLastSibling = pMeldHeap->vLastSibling;

	if (pDeleteAfterMeld)
		delete pMeldHeap;
	else {
		// as we have moved the nodes emptying the other heap beore deletion
		pMeldHeap->vRoot = nullptr;
		pMeldHeap->vLastSibling = nullptr;
	}

	return true;
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
bool BinomialHeap::IsSecondNodeBtr(BinomialHeapNode * pNode1, BinomialHeapNode * pNode2)
{

	// see if the current node should be the new node
	switch (vIsMinHeap) {

	case 0:	// Min Binomial Heap
		if (vKeyCmpFunc(pNode1 + vKeyOffset, pNode2 + vKeyOffset) > 0)
			return true;
		break;

	case 1: // Max Binomial Heap
		if (vKeyCmpFunc(pNode1 + vKeyOffset, pNode2 + vKeyOffset) < 0)
			return true;
		break;
	}

	return false;
}

/*!
 * \brief	The function provides the min node if the heap is of min type else the max node
 * 
 * \return  A valid node pointer or null pointer
 */
BinomialHeapNode * BinomialHeap::RemoveMinMax()
{
		BinomialHeapNode * node;
	
	if (!vRoot)
		return nullptr;

	node = vRoot;

	if (vRoot == vLastSibling)
	{
		vLastSibling = nullptr;
		vRoot = nullptr;
	}
	else if (vLastSibling->uRightSibling == vRoot) {
		vRoot = vLastSibling;
		vRoot->uRightSibling = nullptr;
	}
	else {
			BinomialHeapNode * prev_node;

		vRoot = vRoot->uRightSibling;
		prev_node = vRoot;

		for (BinomialHeapNode* temp = vRoot->uRightSibling; temp != node; temp = temp->uRightSibling)
		{
			if (IsSecondNodeBtr(vRoot, temp)) {
				vLastSibling = prev_node;
				vRoot = temp;
			}
			prev_node = temp;
		}

		vLastSibling->uRightSibling = vRoot;
	}

	Meld(node->uChild);

	MergeHeap ();

	node->uRightSibling = nullptr;
	node->uDegree = 0;

	return node;
}

/*!
 * \brief	The function when called repeatedly merges nodes of same degree till all the nodes left at the 
 *			top level have unique degree
 * 
 */
void BinomialHeap::MergeHeap()
{
		std::map<__int64, BinomialHeapNode*>			map;
		std::map<__int64, BinomialHeapNode*>::iterator	iter;

		BinomialHeapNode * node;
		BinomialHeapNode * temp;

	// no element or a single element
	if (!vRoot || vRoot == vLastSibling)
		return;

	//breaking the circular linked list
	vLastSibling->uRightSibling = nullptr;
	vLastSibling = nullptr;

	while (vRoot) {

		temp = vRoot;
		vRoot = vRoot->uRightSibling;
		
		// loosing the link from individual nodes
		temp->uRightSibling = nullptr;

		// repeateadly mearging to form a node with unique degree
		while (temp) {

			node = map.at(temp->uDegree);
			
			// merge is needed
			if (node) {

				map.erase(vRoot->uDegree);

				if (IsSecondNodeBtr(temp, node)) {
					node->uChild->Insert(temp);
					node->uDegree += temp->uDegree;
					temp = node;
				}
				else {
					temp->uChild->Insert (node);
					temp->uDegree += node->uDegree;
				}
			}
			else {
				map.insert(std::pair<__int64, BinomialHeapNode*>(temp->uDegree, temp));
				temp = nullptr;
			}
		}
	}

	// the heap is empty now and we insert all the nodes the root and lastsibling will be taken care by insert
	while (!map.empty()) {
		iter = map.begin();
		Insert(iter->second);
		map.erase(iter);
	}
}