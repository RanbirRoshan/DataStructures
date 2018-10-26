

#ifndef HEAP_HPP

#define HEAP_HPP

class HeapNode : public TreeNode {
public:
	eTreeNodeType NodeType();
};

class Heap
{
public:
	Heap(Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pMinHeap);
	~Heap();

	// property access or modification APIs
	inline	bool IsMinHeap();

	// heap operation API
	inline	HeapNode * const	PeekMinMax();
	virtual void				Destroy(); 
	HeapNode *					RemoveMinMax();

protected:
	HeapNode *			vRoot;
	bool	IsSecondNodeBtr(HeapNode * pNode1, HeapNode * pNode2);

private:
	friend class BinomialHeap;

	__int8				vIsMinHeap;// 1;		///< 0 implies min heap and 1 implies max heap
	KeyCmpFunc  		vKeyCmpFunc;		///< function to compare keys for decision making
	Offset				vKeyOffset;			///< offset of the key in the node of the tree

};

#include "simpleheap.hxx"

#endif // !HEAP_HPP
