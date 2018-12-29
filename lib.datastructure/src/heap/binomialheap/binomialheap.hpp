/*
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

#include "../../../libdatastruct.h" 

#ifdef __linux__
typedef __int64_t __int64;
typedef __int32_t __int32;
#endif

class BinomialHeap;

/*!
* \class	BinomialHeapNode
* 
* \brief	this is the node class that is to be extended by anyone who intents to use
*			a binomial heap
*
* \note	Extend this node class to work with the following data structure
*			- "Binomial Heap" (Class: BinomialHeap)
*/
class BinomialHeapNode : public HeapNode {
public:

	BinomialHeapNode ();

	eNodeType NodeType();

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
class BinomialHeap : public Heap{
public:

	// constructor and destructor
	BinomialHeap	(Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pMinHeap);
	~BinomialHeap	();

	// heap operation API
virtual void						Destroy		();
		BinomialHeapNode *			Insert		(BinomialHeapNode* pNode);
		bool						Meld		(BinomialHeap *pMeldNode, bool pDeleteAfterMeld = true);
		BinomialHeapNode *			RemoveMinMax();

private:
	void	MergeHeap		();

	BinomialHeapNode *  vLastSibling;		///< the last sibling in the top level of tree

};

// include all inline definitions
#include "binomialheap.hxx"

#endif // !BINOMIAL_HEAP_HPP
