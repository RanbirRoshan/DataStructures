/*!
* @brief	The file contains the binomial heap class declaration and associated 
*			other decleration.
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* lastmodified 20/10/2018
*/

#ifndef BINOMIAL_HEAP_HPP

#define BINOMIAL_HEAP_HPP

/*!
* \class	BinomialHeapNode
* 
* \brief	this is the node class that is to be extended by anyone who intents to use
*			a binomial heap
*
* \note	Extend this node class to work with the following data structure
*			- Binomial Heap (Class: BinomialHeap)
*/
class BinomialHeapNode : public TreeNode {
public:

	BinomialHeapNode ();

	eTreeNodeType NodeType();

private:

	// the node property can only be viewed and modified by the following library classes
	friend class BinomialHeap;

	__int64				uDegree;			///< number of child for a given node
	BinomialHeap  *		uChild;				///< pointer to the child 
	BinomialHeapNode *  uRightSibling;		///< next item in circular link list
};

#define ALLOC_BinomialHeap(pClassName,pKeyVariable,pKeyCmpFunc) new BinomialHeap (offsetof (pClassName, pKeyVariable), pKeyCmpFunc)

/*!
 * \class   BinomialHeap
 * 
 * \brief	Contains binomial heap class implementation. Both min and max heap property are
 *			supported. The property can only be defined while constructiona and cannot be changed
 *			there after. 
 * 
 * \note	Wiki Page : https://en.wikipedia.org/wiki/Binomial_heap
 * 
 * \todo    Improve merge algorithm
 */
class BinomialHeap {
public:

	// constructor and destructor
	BinomialHeap	(Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pMinHeap);
	~BinomialHeap	();

	// property access or modification APIs
inline	bool IsMinHeap();

	// heap operation API
virtual void						Destroy		();
		BinomialHeapNode *			Insert		(BinomialHeapNode* pNode);
		bool						Meld		(BinomialHeap *pMeldNode, bool pDeleteAfterMeld = true);
		BinomialHeapNode *			RemoveMinMax();
inline	BinomialHeapNode * const	PeekMinMax  ();

private:
	bool	IsSecondNodeBtr	(BinomialHeapNode * pNode1, BinomialHeapNode * pNode2);
	void	MergeHeap		();

	BinomialHeapNode *	vRoot;				///< root of the binomial heap
	BinomialHeapNode *  vLastSibling;		///< the last sibling in the top level of tree
	KeyCmpFunc  		vKeyCmpFunc;		///< function to compare keys for decision making
	Offset				vKeyOffset;			///< offset of the key in the node of the tree

	__int8				vIsMinHeap;// 1;		///< 0 implies min heap and 1 implies max heap
};

// include all inline definitions
#include "binomialheap.hxx"

#endif // !BINOMIAL_HEAP_HPP
