#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree2.h"

void bstMakeAndInit(BTreeNode** rootNode);
Data bstGetNodeData(BTreeNode* bst);
void bstInsert(BTreeNode** rootNode, Data insertData);
BTreeNode* bstSearch(BTreeNode* bst, Data target);

#endif
