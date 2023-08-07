#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _bTreeNode
{

    Data data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;

} BTreeNode;

BTreeNode *MakeNode();

void setData(BTreeNode *node, Data pdata);
Data getData(BTreeNode *node);

BTreeNode *getLeftSubTree(BTreeNode *parentNode);
BTreeNode *getRightSubTree(BTreeNode *parentNode);
void setLeftSubTree(BTreeNode *parentNode, BTreeNode *nodeToAadd);
void setRightSubTree(BTreeNode *parentNode, BTreeNode *nodeToAadd);

#endif