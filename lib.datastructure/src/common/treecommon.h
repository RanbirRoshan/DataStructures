/*
* @brief	this file contains the declerations common to all
*			tree data structures
*
* @author	Ranbir Roshan
*
* @date		19/10/2018
*
* @last-modified 19/10/2018
*/

#ifndef TREE_COMMON_HPP

#define TREE_COMMON_HPP

/*!
 * \enum    eTreeNodeType
 *
 * \brief	enumuration for identifying the tree node type
 *
 * \var  TNT_UNKNOWN
 */
enum eTreeNodeType {
	TNT_UNKNOWN = 0,	///< Unknown node type
	TNT_SBTREE,			///< Simple binary tree node
	TNT_HEAP_NODE,		///< Simple Heap Node
	TNT_BINOMIAL_HEAP,	///< Binomial heap node
	TNT_FIBO_HEAP,		///< Fibonacci heap node
};

/*!
 * \class	TreeNode
 *
 * \brief	virtual base class for all the node types.
 * 
 * \note	this is a pure virtual class and hence cannot be instantiated
 */
class TreeNode {
public:
	virtual ~TreeNode() {};

	eTreeNodeType NodeType() { return TNT_UNKNOWN; };
};

#endif // !TREE_COMMON_HPP
