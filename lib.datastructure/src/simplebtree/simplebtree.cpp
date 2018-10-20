/*
* @brief	the file contains non-inline function definition for class SBTree
*
* @author	Ranbir Roshan
*
* @date		19/10/2018
*
* @last-modified 20/10/2018
*/

#include "..\..\libdatastruct.h"

/*!
* \brief	The function is useful in identifying the node type provided for
*			any tree operation. As most node types have some common hiererchy
*			it is reqired for verifying the node type in relevent tree operation
*
* \return	The node type of the current tree node
*
* \note	The function cannot be inlined as it is a virtual function
*/
eTreeNodeType SBTNode::NodeType ()
{
	return TNT_SBTREE;
}

/*
	breif the custructor of the tree

	note: use the macro to call constructor or use the Offset API to provide the 
		  correct key offset for the class
*/
SBTree::SBTree(int pKeyOffset, KeyCmpFunc *pKeyCmpFunc, SBTreeDestroyFunc *pDestroyFunc)
{
	vKeyOffset		= pKeyOffset;
	vRoot			= nullptr;
	vKeyCmpFunc		= pKeyCmpFunc;
	vDestroyFunc	= pDestroyFunc;
}

SBTree::~SBTree()
{
	if (vDestroyFunc)
		Destroy(vDestroyFunc);
}

bool SBTree::Insert(SBTNode * pNode)
{
		SBTNode **	node;
		__int64		ret;

	if (!vRoot){
		vRoot = pNode;
		return true;
	}

	if (pNode->NodeType() != TNT_SBTREE)
		return false;

	node = &vRoot;

	while (*node){
		ret = 0;//vKeyCmpFunc (node + vKeyOffset, pNode + vKeyOffset);

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


SBTNode* SBTree::Find(void * pkey)
{
		SBTNode *	node;
		__int64		ret;

	node = vRoot;

	while (node) {
		ret = 0;// vKeyCmpFunc(node + vKeyOffset, pkey + vKeyOffset);

		if (ret > 0)
			node = node->uRightChild;
		else if (ret < 0)
			node = node->uLeftChild;
		else
			return node;
	}

	return nullptr;
}

SBTNode* SBTree::Remove(void * pKey)
{
	return nullptr;
}