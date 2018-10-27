/*!
* @brief	The file contains the fibonacci heap class declaration and associated
*			other decleration.
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* lastmodified 25/10/2018
*/

#ifndef FIBONACCI_HEAP_HPP

#define FIBONACCI_HEAP_HPP

class FibonacciHeap;

/*!
* \class	FiboHeapNode
*
* \brief	this is the node class that is to be extended by anyone who intents to use
*			a "fibonacci heap"
*
* \note	Extend this node class to work with the following data structure
*			- "Fibonacci Heap" (Class: FibonacciHeap)
*/
class FiboHeapNode : public HeapNode {
public:

	FiboHeapNode();

	eTreeNodeType NodeType ();

private:

	friend class FibonacciHeap;

	__int64				vDegree;			///< the number of child to the current node
	FiboHeapNode *      vChild;				///< pointer to one of the element in the child cicular link list 
	FiboHeapNode *		vParent;			///< pointer to the parent of the current node
	FiboHeapNode *		vRightSibling;		///< next itme in circular link list
	FiboHeapNode *		vLeftSibling;		///< previous item in circular link list
	bool				vChildCut;			///< flag to show if a child was lost since it was added to its parent
	FibonacciHeap*      vInHeap;			///< pointer to the heap it belong to, used for stopping across heap operation
};

/*!
 * \class	FibonacciHeap
 * 
 * \brief	the class provides fibonacci heap. The heap works similar to binomial heap
 *			but in addition to binomial heap provides the API for arbitrary node removal
 *			along with Increase Key of an arbitrary for Max Heap and Decrease Key for an
 *			arbitrary node in a Min Heap.
 * 
 * \note	the data structue does not own the nodes and so it is the responsibility of the 
 *			user to free nodes stored in the 
 *
* \todo		FibonacciHeap class implementation
 */
class FibonacciHeap : public Heap{
public:
	//constructor and destructor
	FibonacciHeap  (Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pIsMinHeap);
	~FibonacciHeap ();

	// the fibonacci heap does not owns the node and so does not provide a destroy
	virtual void Destroy ();

	//heap manipulation APIs
	FiboHeapNode *  Insert (FiboHeapNode * pNode);
	FiboHeapNode *  RemoveMinMax ();
	FiboHeapNode *  Remove (FiboHeapNode * pNode);

inline	bool	IncreaseKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);
inline	bool	DecreaseKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);

private:
		void	MergeHeap ();
static	void	AddSiblingToNode (FiboHeapNode *pNode, FiboHeapNode * pNewSibling);
		bool	ChangeKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);
		void	MeldNode (FiboHeapNode *pNode);
		void	ChildCut (FiboHeapNode *pNode);
};

#include "fibonacciheap.hxx"

#endif // !FIBONACCI_HEAP_HPP
