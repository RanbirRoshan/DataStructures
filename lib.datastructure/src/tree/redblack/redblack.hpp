/*
 * @brief: the file contains decleration of simple binary tree class
 *
 * @author	Ranbir Roshan
 *
 * @date	18/12/2018
 *
 * @last-modified 18/12/2018
 */

#ifndef RED_BLACK_TREE

#define RED_BLACK_TREE

class RBTreeNode : public SBTNode {

public:
	eNodeType		NodeType();

private:
	bool	vIsBlackNode;	//identifies the black colored node of the red black tree
};

class RedBlackTree : public SBTree {
public:

	RedBlackTree(int pKeyOffset, KeyCmpFunc pKeyCmpFunc, TreeDestroyFunc pDestroyFunc);
	~RedBlackTree();

	virtual bool			Insert(RBTreeNode * pNode);
	virtual RBTreeNode*		Find(void * pKey);
	virtual RBTreeNode*		Remove(void * pKey);
	virtual void			Destroy(TreeDestroyFunc * pDestroyFunc);
	virtual eNodeType		NodeType();

};

#endif //RED_BLACK_TREE