/*
 * @brief: the file contains decleration of simple binary tree class
 *
 * @author	Ranbir Roshan
 *
 * @date	19/10/2018
 *
 * @last-modified 19/10/2018
 */
#ifndef SIMPLE_BINARY_TREE
#define SIMPLE_BINARY_TREE

#include "../common/treecommon.h"

/*!
 * /brief	this is the node class that is to be extended by anyone who intents to use 
 *			a simple binary tree
 * 
 * /note	Extend this node class to work with the following data structure
 *			- Simple Binary Tree (Class: SBTree)
 */
class SBTNode: public TreeNode {
public:

	eTreeNodeType NodeType();

private:
	
	// the node property can only be viewed and modified by the following library classes
	friend class SBTree;

	SBTNode	*		uLeftChild;		///< left child of tree
	SBTNode *		uRightChild;	///< right child of tree
};

/*
	brief	the comparision function used by the tree class

	return   0	means the keys are equal
			>0  means the pKey1 is greater than pKey2
			<0  means the pKey1 is smaller than pKey2
*/
typedef __int64 (*KeyCmpFunc) (const void* pKey1, const void *pKey2);

/*
	brief	the function prototype for destory interface of simple binary tree
*/
typedef void	(*SBTreeDestroyFunc) (SBTNode *pNode);

/*!
 * 
 * /brief	a simple binary tree class
 * /note:	the nodes used with the interface provided by this class
			should extend SBTNode class
			the tree is not height balanced
 *
 * /TODO	the implementation for this class is not complete
*/
class SBTree {
public:
	// constructor and destructor
	SBTree  (int pKeyOffset, KeyCmpFunc *pKeyCmpFunc, SBTreeDestroyFunc *pDestroyFunc);
	~SBTree ();

	// tree operations
	bool		Insert	(SBTNode *	pNode);
	SBTNode*	Find	(void *	pkey);
	SBTNode*	Remove	(void * pKey);
	void		Destroy (SBTreeDestroyFunc *pDestroyFunc);


private:
	SBTNode *			vRoot;				///< Root of the tree.
	int					vKeyOffset;			///< The offset of the key in the user defined node.
	KeyCmpFunc*			vKeyCmpFunc;		///< User callback function for key comparision.
	SBTreeDestroyFunc * vDestroyFunc;		///< User callback function to destroy the nodes that are in the tree.
};

#include "simplebtree.hxx"

#endif