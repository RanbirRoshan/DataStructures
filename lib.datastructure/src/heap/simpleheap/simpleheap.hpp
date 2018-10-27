/*!
* \file     simpleheap.hpp
*
* @brief	The file contains the heap class declaration and associated
*			other decleration.
*
* @author	Ranbir Roshan
*
* @date		26/10/2018
*
* lastmodified 27/10/2018
*/

#ifndef HEAP_HPP

#define HEAP_HPP

/*!
* \class	HeapNode
*
* \brief	this is the node class that is to be extended by anyone who intents to use
*			a "heap"
*
* \note		Extend this node class to work with the following data structure
*			- "Heap" (Class: Heap)
*/
class HeapNode : public TreeNode {
public:
	eTreeNodeType NodeType();
};

/*!
* \class	Heap
*
* \brief	the class provides heap. Both min and max heap are supported by this class. Subjected to
			intialization only one of them can be used in an object.
*
* \todo		Heap class implementation
*/
class Heap
{
public:
	Heap(Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pMinHeap);
virtual	~Heap();

	// property access or modification APIs
	inline	bool IsMinHeap();

	// heap operation API
	inline	HeapNode * const	PeekMinMax();
	virtual void				Destroy(); 
	HeapNode *					RemoveMinMax();

protected:
	HeapNode *			vRoot;

inline	bool	IsSecondNodeBtr (HeapNode * pNode1, HeapNode * pNode2);
		bool	IsSecondKeyBtr  (void * pKey1, void * pKey2);
inline 	int     GetKeyOffset    ();

private:
	friend class BinomialHeap;

	bool 				vIsMinHeap; // 1;		///< 0 implies min heap and 1 implies max heap
	KeyCmpFunc  		vKeyCmpFunc;		///< function to compare keys for decision making
	Offset				vKeyOffset;			///< offset of the key in the node of the tree

};

#include "simpleheap.hxx"

#endif // !HEAP_HPP
