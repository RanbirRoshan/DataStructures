/*
* @brief	the file contains inline function definition for class SBTree
*
* @author	Ranbir Roshan
*
* @date	20/10/2018
*
* @last-modified 20/10/2018
*/

/*!
 * \brief	The function is useful in identifying the node type provided for 
 *			any tree operation. As most node types have some common hiererchy
 *			it is reqired for verifying the node type in relevent tree operation
 * 
 * \return the node type of the current tree node
 */
eTreeNodeType SBTNode::NodeType()
{
	return TNT_SBTREE;
}