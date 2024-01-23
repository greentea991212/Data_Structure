#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

void BstMakeAndInit(Node **rootNode);
Data BstGetNodeData(Node *bst);
void BstInsert(Node **rootNode, Data insertData);
Node *BstSearch(Node *bst, Data target);

#endif
