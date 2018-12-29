/*
* @brief	the file contains non-inline function definition for class RedBalckTree
*
* @author	Ranbir Roshan
*
* @date		18/12/2018
*
* @last-modified 18/12/2018
*/

#include "../treedatastruct.h"

/*!
 *	\brief		The function is useful in identifying the node type provided for
*				any Red black tree operation. As most node types have some common hiererchy
*				it is reqired for verifying the node type in relevent tree operation
*
* \return		The node type of the current tree node
*
* \note			The function cannot be inlined as it is a virtual function
 */
eNodeType RBTreeNode::NodeType()
{
	return NT_RED_BLACK_NODE;
}


/*!
 *	\brief	Constructor for the RedBlackTree class
 */
RedBlackTree::RedBlackTree(int pKeyOffset, KeyCmpFunc pKeyCmpFunc, TreeDestroyFunc pDestroyFunc) : 
	SBTree (pKeyOffset, pKeyCmpFunc, pDestroyFunc)
{
}

/*!
 *	\brief	The destructor for the RedBlackTree class
 */
RedBlackTree::~RedBlackTree()
{
	// destruction will be handled by the SBTree destroy function as there is nothing special to be done here
}

eNodeType RedBlackTree::NodeType()
{
	return NT_RED_BLACK_NODE;
}