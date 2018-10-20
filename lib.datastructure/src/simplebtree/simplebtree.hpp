/**
	brief: the file contains decleration of simple binary tree class

	author: ranbir roshan
*/
#ifndef SIMPLE_BINARY_TREE
#define SIMPLE_BINARY_TREE

class SBTNode {
public:
	SBTNode	*		uLeftChild;
	SBTNode *		uRightChild;
};

/*
	brief	the comparision function used by the tree class

	return   0	means the node are equal
			>0  means the node will go to right
			<0  means the node will go to left
*/
typedef __int64 (*KeyCmpFunc) (void* pCmpNode1, void *pCmpNode2);

/*
	brief	the function prototype for destory interface of simple binary tree
*/
typedef void	(*SBTreeDestroyFunc) (SBTNode *pNode);

/*
	brief:	a simple binary tree class

	note:	the nodes used with the interface provided by this class
			should extend SBTNode class
			the tree is not height balanced
*/
class SBTree {
public:
	SBTree  (int pKeyOffset, KeyCmpFunc *pKeyCmpFunc, SBTreeDestroyFunc *pDestroyFunc);
	~SBTree ();

	bool		Insert	(SBTNode *	pNode);
	SBTNode*	Find	(void *	pkey);
	SBTNode*	Remove	(void * pKey);

	void		Destroy	(SBTreeDestroyFunc *pDestroyFunc);
private:
	SBTNode *			vRoot;
	int					vKeyOffset;			// the offset of the key in the user defined node
	KeyCmpFunc*			vKeyCmpFunc;		// user callback function for key comparision
	SBTreeDestroyFunc * vDestroyFunc;		// user callback function to destroy the nodes that are in the tree
};

#endif