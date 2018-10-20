#include "..\..\libdatastruct.h"

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