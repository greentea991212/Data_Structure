#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int Data;

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    Data data;

} BTreeNode;

void (*vistFuctionPtr)(Data);

BTreeNode *MakeBTreeNode();

void setData(BTreeNode *pnode, Data pdata);
Data getData(BTreeNode *pnode);

void setLeftSubTree(BTreeNode *root, BTreeNode *pnode);
void setRightSubTree(BTreeNode *root, BTreeNode *pnode);
BTreeNode *getLeftSubTree(BTreeNode *root);
BTreeNode *getRightSubTree(BTreeNode *root);

void inOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data));
void preOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data));
void postOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data));

#endif