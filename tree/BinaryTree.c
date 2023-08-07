#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree.h"

BTreeNode *MakeNode()
{

    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void setData(BTreeNode *node, Data pdata)
{

    node->data = pdata;
}

Data getData(BTreeNode *node)
{

    return node->data;
}

BTreeNode *getLeftSubTree(BTreeNode *parentNode)
{

    return parentNode->left;
}

BTreeNode *getRightSubTree(BTreeNode *parentNode)
{

    return parentNode->right;
}

void setLeftSubTree(BTreeNode *parentNode, BTreeNode *nodeToAadd)
{

    if (parentNode->left != NULL)
    {

        free(parentNode->left);
    }

    parentNode->left = nodeToAadd;
}

void setRightSubTree(BTreeNode *parentNode, BTreeNode *nodeToAadd)
{

    if (parentNode->right != NULL)
    {

        free(parentNode->right);
    }

    parentNode->right = nodeToAadd;
}
