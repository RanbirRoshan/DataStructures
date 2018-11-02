/*!
* @brief	The file contains the non inline definitions for fibonacci heap and
*			other associated decleration.
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* lastmodified 01/11/2018
*/

#include "../../../libdatastruct.h"

//definition of initial mearge array size
#define FIBO_HEAP_INITIAL_MERGE_SIZE 8

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
 * \brief	Constructor for the fibonacci heap node
 * 
 */
FiboHeapNode::FiboHeapNode()
{
	vChild			= nullptr;
	vInHeap         = nullptr;
	vParent			= nullptr;
	vRightSibling	= nullptr;
	vRightSibling	= nullptr;
	vDegree			= 0;
	vChildCut		= 0;
}

/*!
 * \brief		Constructor for FibonacciHeap class
  * 
  * \param[in] pKeyOffset	Offset of key in the node class. Use "offsetof" to find the same.
  * \param[in] pKeyCmpFunc  Key comparison function
  *	\param[in] pIsMinHeap   True if the heap is supposed to behave as min heap else false for max heap
 */
FibonacciHeap::FibonacciHeap (Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pIsMinHeap): Heap (pKeyOffset, pKeyCmpFunc, pIsMinHeap)
{
	vMergeSize = FIBO_HEAP_INITIAL_MERGE_SIZE;
}

/*!
 * \brief	Destructor for the FibonacciHeap class
 * 
 */
FibonacciHeap::~FibonacciHeap()
{
	if (vRoot)
		Destroy();
}

/*!
 * \brief	The function is expected to cleans up the entire heap by calling delete on every node on the heap
 *			but as Fibbonaci heap does not own any node so no destroy of nodes happen only the
 *			root and other associated properties are reset. <strong>The nodes are not deleted</strong>.
 * 
 */
void FibonacciHeap::Destroy()
{
	vRoot = nullptr;
}

/*!
 * \brief		The funciton provides capability to insert a node in the heap
 * 
 * \param[in]	pNode	the pointer to the node being inserted. The node must point to an
 *						an object that is derived from FiboHeapNode class
 * 
 * \return	the function would return 
 *			- pNode			in case of sucessful insertion
 *			- nullptr		in case of insertion failure
 * 
 * \note	A node that is a part of any other heap will not be inserted and 
 *			the function would return nullptr or a node that is not of TNT_FIBO_HEAP
 *			type is tried to be inserted into it
 */
FiboHeapNode * FibonacciHeap::Insert(FiboHeapNode * pNode)
{
	if (!pNode || pNode->NodeType () != TNT_FIBO_HEAP)
		return nullptr;

	// this can be relaxed but is coded so that proper node sanity is maintained in code
	if (pNode->vLeftSibling || pNode->vRightSibling || pNode->vParent || pNode->vChildCut || pNode->vInHeap)
		return nullptr;

	pNode->vInHeap		= this;
	pNode->vHeapParent	= this;	// direct child identification

	// empty heap 
	if (!vRoot)
	{
		vRoot = pNode;
		return pNode;
	}
	// heap with a single element
	else if (!((FiboHeapNode*)vRoot)->vRightSibling)
	{
		((FiboHeapNode*)vRoot)->vRightSibling = pNode;
		((FiboHeapNode*)vRoot)->vLeftSibling  = pNode;

		pNode->vRightSibling = (FiboHeapNode*)vRoot;
		pNode->vLeftSibling  = (FiboHeapNode*)vRoot;
	} 
	else 
		AddSiblingToNode ((FiboHeapNode*)vRoot, pNode);

	// the new node that is being inserted is a potential candidate for being root so test it
	if (IsSecondNodeBtr(vRoot, pNode))
		vRoot = pNode;

	return pNode;
}

/*!
 * \brief	The function when called repeatedly merges nodes of same degree
 *          till all the nodes left at the top level have unique degree
 *
 */
void FibonacciHeap::MergeHeap ()
{
	FiboHeapNode ** degree_merge_map; // array of node pointer by degree
	FiboHeapNode *	node;
	FiboHeapNode *	temp;
	int				size;

	// no element or a single element
	if (!vRoot || !((FiboHeapNode*)vRoot)->vRightSibling)
		return;

	degree_merge_map = (FiboHeapNode**) calloc (vMergeSize, sizeof(FiboHeapNode*));

	//breaking the circular linked list
	((FiboHeapNode*)vRoot)->vLeftSibling->vRightSibling = nullptr;

	while (vRoot) {

		temp  = (FiboHeapNode*)vRoot;

		vRoot = ((FiboHeapNode*)vRoot)->vRightSibling;

		// loosing the link from individual nodes
		temp->vRightSibling = nullptr;
		temp->vLeftSibling  = nullptr;

		// repeateadly mearging to form a node with unique degree
		while (temp) {

			// array size insufficient so grow
			if (vMergeSize <= temp->vDegree) {

				FiboHeapNode**	temparr;
				
				size = vMergeSize;

				//atleast double the size as per old
				while (vMergeSize <= temp->vDegree)
					vMergeSize = vMergeSize << 1;

				temparr = (FiboHeapNode**)calloc(vMergeSize, sizeof(FiboHeapNode*));
				memcpy(temparr, degree_merge_map, sizeof(FiboHeapNode*)*size);
				free (degree_merge_map);
				degree_merge_map = temparr;
			}

			//checking for same degree conflict
			if (degree_merge_map[temp->vDegree])
				node = degree_merge_map[temp->vDegree];
			else
				node = nullptr;

			// two nodes of same degree found so merge is needed
			if (node) {

				degree_merge_map[temp->vDegree] = nullptr;

				// choosing the root
				if (IsSecondNodeBtr(temp, node)) {

					if (!node->vChild)
						node->vChild = temp;
					else
						AddSiblingToNode (node->vChild, temp);

					temp->vInHeap = this;
					node->vDegree += 1;
					temp->vParent = node;
					temp = node;
				}
				else {

					if (!temp->vChild)
						temp->vChild = node;
					else
						AddSiblingToNode(temp->vChild, node);

					node->vInHeap = this;
					node->vParent = temp;
					temp->vDegree += 1;
				}
			}
			else {
				temp->vInHeap = nullptr;
				temp->vParent = nullptr;
				temp->vChildCut = false;
				degree_merge_map[temp->vDegree] = temp;
				temp = nullptr;
			}
		}
	}

	size = 0;

	//adding nodes back to heap
	for (int iter = 0; iter < vMergeSize; iter++) {
		if (degree_merge_map[iter]) {
			Insert(degree_merge_map[iter]);
			size = iter;
		}
	}

	// in case the size has decreased after merge due to any reason
	while (size < vMergeSize>>1 && vMergeSize > FIBO_HEAP_INITIAL_MERGE_SIZE)
		vMergeSize = vMergeSize >> 1;

	free (degree_merge_map);
}

/*!
 *	\brief		The function adds the second node parameter to the sibling list of the 
 *				first node
 *
 *	\param[in]	pNode			The node to which the sibling is to be added
 *	\param[in]  pNewSibling		The new sibling node must be a single node not a list
 *
 */
void FibonacciHeap::AddSiblingToNode (FiboHeapNode *pNode, FiboHeapNode * pNewSibling)
{

// help developer if in case the assumption is broken
#ifdef _DEBUG
	if (pNewSibling->vRightSibling || !pNode)
		DebugBreak();
#endif

	// pNode has no sibling
	if (!pNode->vRightSibling) {

		pNode->vRightSibling = pNewSibling;
		pNode->vLeftSibling = pNewSibling;
		
		pNewSibling->vRightSibling = pNode;
		pNewSibling->vLeftSibling = pNode;
	}
	else {

		pNode->vRightSibling->vLeftSibling = pNewSibling;
		pNewSibling->vRightSibling = pNode->vRightSibling;

		pNewSibling->vLeftSibling = pNode;
		pNode->vRightSibling = pNewSibling;
	}
}

/*!
 * \brief	The MeldNode function is used to meld a circular linked node to the root node
 *
 * \param[in]	pNode	The node to be melded into heap can be a list of node as well
 *
 * \note	The MeldNode would be called in the following two scenario
 *			-	A node is removed and the child nodes are being melded
 *			-   A child cut triggered the meld of some children
 *			-	A increase/decrease key trigged the meld
 *			In the case of 2nd and 3rd point only a single node will be added. The same
 *			may compete for being the root only in the 3rd case as in the second the child node
 *			clearly cannot be root as it is some child below. So, when a meld happens it always
 *			try's to make a new root.
 *			The 1st case also creates new root candidates. But we don't know which one the elements
 *			in circular list is our true candidate. So we merge is without taking that into account.
 *			This would not have any side effect as the 1st operation will be followed by a merge
 *			which would take care of the root selection
 */
void FibonacciHeap::MeldNode(FiboHeapNode * pNode)
{
	FiboHeapNode *		temp;

	if (!pNode)
		return;

	temp = pNode;

	pNode->vHeapParent = this;
	temp->vChildCut = 0;

	temp = temp->vRightSibling;

	if (!vRoot)
	{
		vRoot = pNode;
		pNode->vChildCut = 0;
		return;
	}

	// root is a single element
	if (!((FiboHeapNode*)vRoot)->vRightSibling) {
		AddSiblingToNode(pNode, (FiboHeapNode*)vRoot);
	}
	// the node being added is a single element
	else if (!pNode->vRightSibling) {
		AddSiblingToNode((FiboHeapNode*)vRoot, pNode);
	}
	// both the nodes have sibling
	else {

		FiboHeapNode * temp2;

		// first we create the circular list
		temp = ((FiboHeapNode*)vRoot)->vLeftSibling;
		temp2= pNode->vLeftSibling;

		temp->vRightSibling = pNode;
		pNode->vLeftSibling = temp;

		temp2->vRightSibling = (FiboHeapNode*)vRoot;
		((FiboHeapNode*)vRoot)->vLeftSibling = temp2;
	}

	// contest of root
	if (IsSecondNodeBtr(vRoot, pNode))
		vRoot = pNode;
}

/*!
 * \breif	The function would remove and return the min node in case of a
 *			min heap and the max node in case of max heap.
 *
 * \return	The function would return the following:
 *			- nullptr	     -	In case the heap is empty 
 *			- FiboHeapNode * -	Node as per the heap's min/max property
 */
FiboHeapNode* FibonacciHeap::RemoveMinMax()
{
	FiboHeapNode*	node;

	// no element
	if (!vRoot)
		return nullptr;

	// exactly one element
	if (!((FiboHeapNode*)vRoot)->vRightSibling) {

#ifdef _DEBUG
		if (((FiboHeapNode*)vRoot)->vRightSibling)
			DebugBreak();
#endif
		node  = (FiboHeapNode*)vRoot;
		vRoot = nullptr;
	}
	// exactly two element
	else if (((FiboHeapNode*)vRoot)->vRightSibling->vRightSibling == vRoot)
	{
		node = (FiboHeapNode*)vRoot;

		vRoot = node->vRightSibling;
		((FiboHeapNode*)vRoot)->vLeftSibling  = nullptr;
		((FiboHeapNode*)vRoot)->vRightSibling = nullptr;

		node->vLeftSibling  = nullptr;
		node->vRightSibling = nullptr;
	}
	// more than 2 element
	else
	{
		node = (FiboHeapNode*)vRoot;

		vRoot = node->vRightSibling;

		node->vLeftSibling->vRightSibling = (FiboHeapNode*)vRoot;

		((FiboHeapNode*)vRoot)->vLeftSibling = node->vLeftSibling;

		node->vLeftSibling = nullptr;
		node->vRightSibling = nullptr;

	}
	MeldNode (node->vChild);

	MergeHeap ();

	// reset the values so that the node remains usable for next insert parent for these node is not possible
	node->vChildCut = 0;
	node->vDegree	= 0;
	node->vParent   = nullptr;
	node->vChild	= nullptr;
	node->vInHeap   = nullptr;

	return node;
}

/*!
 * \brief	The function attempts to remove the node from the Fiboncci Heap.
 *
 * \param[in]	pNode	The node that is to be removed.
 *
 * return	The function returns the following
 *			- The pointer to the node if it is removed
 *			- nullptr	If pNode is null, heap is empty, node does not belongs
 *						to the current heap
 */
FiboHeapNode * FibonacciHeap::Remove(FiboHeapNode * pNode)
{
	if (!vRoot || !pNode || pNode->vInHeap != this)
		return nullptr;

	if (vRoot == pNode)
		return RemoveMinMax();

	// case sibling/s exists
	if (pNode->vLeftSibling) {

		// case there is a single sibling
		if (pNode->vLeftSibling == pNode->vRightSibling)
		{
			pNode->vLeftSibling->vLeftSibling = nullptr;
			pNode->vLeftSibling->vRightSibling = nullptr;
		}
		else {
			pNode->vLeftSibling->vRightSibling = pNode->vRightSibling;
			pNode->vRightSibling->vLeftSibling = pNode->vLeftSibling;
		}
	}

	if (pNode->vParent && pNode->vHeapParent != this) {
		if(pNode->vParent->vChild == pNode)
			pNode->vParent->vChild = pNode->vRightSibling;

		ChildCut(pNode->vParent);
	}

	if (pNode->vChild)
		MeldNode(pNode->vChild);

	pNode->vParent		 = nullptr;
	pNode->vRightSibling = nullptr;
	pNode->vInHeap       = nullptr;
	pNode->vLeftSibling  = nullptr;
	pNode->vChild		 = nullptr;

	return pNode;
}

/*!
 * \brief	The function changes the key of the node to the specified key only if 
 *			the key is greater than the current key for a max heap and less than 
 *			the current key for a min heap
 *
 * \param[in] pNode		The node for which the key has to be changed
 * \param[in] pNewKey	The new value of the key that is to be set
 * \param[in] pSize		The size of key in bytes
 *
 * \return	The function would return the following:
 *			- True		If in case the change is successfull
 *			- False		Change key fails as the newly provided key is smaller than
 *						the existing key in case of max heap or is bigger than the
 *						existing key in case of the max heap
 */
bool FibonacciHeap::ChangeKey(FiboHeapNode * pNode, void * pNewKey, size_t pSize)
{
	FiboHeapNode * temp;
	FiboHeapNode * parent;

	if (!IsSecondKeyBtr(((byte*)pNode) + GetKeyOffset(), pNewKey))
		return false;

	memcpy((byte*)pNode + GetKeyOffset(), pNewKey, pSize);

	//check if the node is now better than the parent
	if (pNode->vParent && pNode->vHeapParent != this) {
		if (IsSecondNodeBtr(pNode->vParent, pNode))
		{
			parent = pNode->vParent;

			// call remove it will manage the child cut property of the nodes
			temp = Remove(pNode);
			pNode->vChildCut = false;

			Insert(pNode);
		}
	}
	else {
		if (pNode != vRoot)
		{
			if (IsSecondNodeBtr(vRoot, pNode))
				vRoot = pNode;
		}
	}

	return true;
}

/*!
 * \brief	The function manages the child cut behavior of the node
 *			if the child cut is attempted for the second time the node
 *			moves to the first level resulting in a call for child cut 
 *			on the parent. For nodes on first level the property is not
 *			applicable and is so no called
 *
 * \param[in] pNode		The pointer to the node for which the child cut
 *						has to be triggered
 *
 */
void FibonacciHeap::ChildCut(FiboHeapNode *pNode)
{
	FiboHeapNode * parent;
	FiboHeapNode * temp;

	if (!pNode)
		return;

	pNode->vDegree -= 1;

	if (pNode->vChildCut) {
		parent = pNode->vParent;
		if (parent) {

			// remove would have removed the node and called child cut on parent
			pNode->vChildCut = false;
			temp = Remove(pNode);
			Insert(temp);
		}
	}
	else {
		if (pNode->vParent)
			pNode->vChildCut = true;
	}
}