/*!
* @brief	The file contains the fibonacci heap class declaration and associated
*			other decleration.
*
* @author	Ranbir Roshan
*
* @date		20/10/2018
*
* lastmodified 01/11/2018
*/

#ifndef FIBONACCI_HEAP_HPP

#define FIBONACCI_HEAP_HPP

class FibonacciHeap;
class FiboHeapNode;

/*
 * \brief	The structure is for storing parent identity at each level
 */
struct FHNodeParrentDet
{
	int				uUseCount;
	FiboHeapNode *	uParent;
};

/*!
* \class	FiboHeapNode
*
* \brief	This is the node class that is to be extended by anyone who intents to use
*			a "fibonacci heap"
*
* \note		Extend this node class to work with the following data structure
*			- "Fibonacci Heap" (Class: FibonacciHeap)
*/
class FiboHeapNode : public HeapNode {
public:

	FiboHeapNode();

	eTreeNodeType NodeType ();

private:

	friend class FibonacciHeap;

	__int64				vDegree;			///< the number of  child to the current node
	FiboHeapNode *      vChild;				///< pointer to one of the element in the child cicular link list 
	FHNodeParrentDet *	vParentDet;		///< pointer to the parent of the current node
	FiboHeapNode *		vRightSibling;		///< next itme in circular link list
	FiboHeapNode *		vLeftSibling;		///< previous item in circular link list
	bool				vChildCut;			///< flag to show if a child was lost since it was added to its parent
	FibonacciHeap*      vInHeap;			///< pointer to the heap it belong to, used for stopping cross heap operation
};

/*!
 * \class	FibonacciHeap
 * 
 * \brief	The class provides fibonacci heap functionality. The heap works similar to binomial heap
 *			but in addition to binomial heap provides the API for arbitrary node removal
 *			along with Increase Key of an arbitrary node for a Max FibonacciHeap and Decrease Key for an
 *			arbitrary node in a Min FibonacciHeap.
 * 
 * \note	The data structue does not owns the nodes and so it is the responsibility of the 
 *			user to free nodes stored in the.
 *
 */
class FibonacciHeap : public Heap{
public:
	//constructor and destructor
	FibonacciHeap  (Offset pKeyOffset, KeyCmpFunc pKeyCmpFunc, bool pIsMinHeap);
	~FibonacciHeap ();

	//heap manipulation APIs
	FiboHeapNode *  Insert (FiboHeapNode * pNode);
	FiboHeapNode *  Remove (FiboHeapNode * pNode);
	FiboHeapNode *  RemoveMinMax ();

inline	bool	IncreaseKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);
inline	bool	DecreaseKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);

virtual void	Destroy();

private:

static	void	AddSiblingToNode (FiboHeapNode *pNode, FiboHeapNode * pNewSibling);

		void	MergeHeap ();
		bool	ChangeKey (FiboHeapNode * pNode, void * pNewKey, size_t pSize);
		void	MeldNode  (FiboHeapNode * pNode);
		void	ChildCut  (FiboHeapNode * pNode);

		int		vMergeSize;		///< Stores the last merge array size to avoid un-necesaary expansion every time the merge occurs
};

#include "fibonacciheap.hxx"

#endif // !FIBONACCI_HEAP_HPP
