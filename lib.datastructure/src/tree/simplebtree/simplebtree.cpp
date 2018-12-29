/*
* @brief	the file contains non-inline function definition for class SBTree
*
* @author	Ranbir Roshan
*
* @date		19/10/2018
*
* @last-modified 20/10/2018
*/

#include "../../../libdatastruct.h"

/*!
* \brief	The function is useful in identifying the node type provided for
*			any tree operation. As most node types have some common hiererchy
*			it is reqired for verifying the node type in relevent tree operation
*
* \return	The node type of the current tree node
*
* \note	The function cannot be inlined as it is a virtual function
*/
eNodeType SBTNode::NodeType ()
{
	return NT_SBTREE;
}

/*
	breif the custructor of the tree

	note: use the macro to call constructor or use the Offset API to provide the 
		  correct key offset for the class
*/
SBTree::SBTree(int pKeyOffset, KeyCmpFunc pKeyCmpFunc, TreeDestroyFunc pDestroyFunc)
{
	vKeyOffset		= pKeyOffset;
	vRoot			= nullptr;
	vKeyCmpFunc		= pKeyCmpFunc;
	vDestroyFunc	= pDestroyFunc;
}

/*!
 * \brief	The function provides a way for user defined distruction function
 *			to be called on each of the node stored inside the tree.
 */
void SBTree::Destroy()
{
	if (vRoot)
	{
		SBTNode *leftchild = vRoot->uLeftChild;
		SBTNode *rightchild = vRoot->uRightChild;
		
		vDestroyFunc(vRoot);
		
		vRoot = leftchild;
		Destroy();

		vRoot = rightchild;
		Destroy();
	}

	vRoot = nullptr;
}

/*!
 *	\brief	the destructor routine for the SBTree
 */
SBTree::~SBTree()
{
	Destroy();
}

/*!
 *	\brief	API to insert node inside the tree
 *
 *  \note	Currenly one can insert om;y the simple nodes into the
 *			tree. Insertion of nodes that have child will fail.
 */
bool SBTree::Insert(SBTNode * pNode)
{
		SBTNode **	node;
		__int64		ret;

	//	we do not support insertion of tree in a tree because we do not know the
	//	sub nodes in tree have been constructed as per the requirements of the
	//	present tree
	if (pNode->uLeftChild || pNode->uRightChild || pNode->NodeType() != NodeType())
		return false;

	if (!vRoot){
		vRoot = pNode;
		return true;
	}

	node = &vRoot;

	while (*node){

		ret = vKeyCmpFunc (node + vKeyOffset, pNode + vKeyOffset);

		if (ret > 0)
			node = &(*node)->uRightChild;
		else if (ret < 0)
			node = &(*node)->uLeftChild;
		else
			return false;
	}

	*node = pNode;
	return true;
}

/*!
 *	\brief	The function finds the requested node in the tree and returns 
 *			it to the caller. The node is not removed from the tree.
 *
 *	\Note	The user is not expected to delete the node or attempt to tamper 
 *			tree related data or operate the node with any other data structure.
 *			Doing so can lead to data corruption and the behavior of systemm post
 *			any such activity is undefined.
 */
SBTNode* SBTree::Find(void * pkey)
{
		SBTNode *	node;
		__int64		ret;

	node = vRoot;

	while (node) {
		ret = vKeyCmpFunc(node + vKeyOffset, pkey);

		if (ret > 0)
			node = node->uRightChild;
		else if (ret < 0)
			node = node->uLeftChild;
		else
			return node;
	}

	return nullptr;
}

/*!
 * \brief	The function returns the type of node that is supported by the tree
 */
eNodeType SBTree::NodeType()
{
	return NT_SBTREE;
}

SBTNode* SBTree::Remove(void * pKey)
{
	return nullptr;
}
