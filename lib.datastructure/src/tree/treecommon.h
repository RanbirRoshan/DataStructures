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
 * \enum    eNodeType
 *
 * \brief	enumuration for identifying the tree node type
 *
 * \var  NT_UNKNOWN
 */
enum eNodeType {
	NT_UNKNOWN = 0,	///< Unknown node type
	NT_SBTREE,			///< Simple binary tree node
	NT_HEAP_NODE,		///< Simple Heap Node
	NT_BINOMIAL_HEAP,	///< Binomial heap node
	NT_FIBO_HEAP,		///< Fibonacci heap node
	NT_RED_BLACK_NODE, ///< Red Black Tree Nodes
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

	eNodeType NodeType() { return NT_UNKNOWN; };
};

/*!
 *	\brief	the function prototype for destory interface of tree
*/
typedef void(*TreeDestroyFunc) (TreeNode *pNode);

/*!
 * \class	Tree
 *
 * \brief	this is a pure virtual class for all the tree related data structure 
 *			to inherit from
 *
 */
class Tree {

public:
	virtual bool			Insert(TreeNode * pNode) = 0;
	virtual TreeNode *		Find(void * pKey) = 0;
	virtual TreeNode *		Remove(void * pKey) = 0;
	virtual void			Destroy(TreeDestroyFunc * pDestroyFunc) = 0;
	virtual eNodeType		NodeType()=0;
};

#endif // !TREE_COMMON_HPP
