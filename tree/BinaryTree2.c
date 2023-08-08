#include <stdlib.h>
#include <stdio.h>
#include "../include/BinaryTree2.h"

BTreeNode *MakeBTreeNode()
{

    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void setData(BTreeNode *pnode, Data pdata)
{

    pnode->data = pdata;
}

Data getData(BTreeNode *pnode)
{

    return pnode->data;
}

void setLeftSubTree(BTreeNode *root, BTreeNode *pnode)
{

    root->left = pnode;
}
void setRightSubTree(BTreeNode *root, BTreeNode *pnode)
{

    root->right = pnode;
}

BTreeNode *getLeftSubTree(BTreeNode *root)
{

    return root->left;
}
BTreeNode *getRightSubTree(BTreeNode *root)
{
    return root->right;
}

void inOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data))
{

    if (pnode == NULL) // 탈출 조건 즉, 방문한 노드가 NULL인 경우 순회를 멈춘다.
        return;

    inOrderTraverse(pnode->left, vistFuctionPtr);
    vistFuctionPtr(getData(pnode));
    inOrderTraverse(pnode->right, vistFuctionPtr);
}
void preOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data))
{
    if (pnode == NULL)
        return;

    vistFuctionPtr(getData(pnode));
    preOrderTraverse(pnode->left, vistFuctionPtr);
    preOrderTraverse(pnode->right, vistFuctionPtr);
}
void postOrderTraverse(BTreeNode *pnode, void (*vistFuctionPtr)(Data))
{

    if (pnode == NULL)
        return;

    postOrderTraverse(pnode->left, vistFuctionPtr);
    postOrderTraverse(pnode->right, vistFuctionPtr);
    vistFuctionPtr(getData(pnode));
}