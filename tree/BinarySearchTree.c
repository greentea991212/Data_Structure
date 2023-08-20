#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree2.h"
#include "../include/BinarySearchTree.h"

void bstMakeAndInit(BTreeNode **rootNode)
{

    *rootNode = NULL;
}

Data bstGetNodeData(BTreeNode *bst)
{

    return getData(bst);
}

void bstInsert(BTreeNode **rootNode, Data insertData)
{

    BTreeNode *newNode = NULL;
    BTreeNode *currNode = *rootNode;
    BTreeNode *parentNode = NULL;

    newNode = MakeBTreeNode();
    setData(newNode, insertData);

    /*
        데이터가 삽입되어야할 위치를 찾는 알고리즘
    */

    if (*rootNode == NULL)
    {

        *rootNode = newNode;

        return;
    }

    while (currNode != NULL)
    {

        if (insertData == currNode->data)
            return; // 데이터의 중복을 허락하지 않음.

        parentNode = currNode;

        if (parentNode->data < insertData)
        {

            currNode = getRightSubTree(parentNode);
        }
        else
            currNode = getLeftSubTree(parentNode);
    }
    /*
        찾은 위치를 기반으로, 데이터를 삽입하는 알고리즘
    */

    if (parentNode->data < insertData)
    {

        setRightSubTree(parentNode, newNode);
    }
    else
    {

        setLeftSubTree(parentNode, newNode);
    }
}

BTreeNode *bstSearch(BTreeNode *rootNode, Data target)
{

    BTreeNode *currentNode = rootNode;
    Data currentData;

    while (currentNode != NULL)
    {

        currentData = getData(currentNode);
        if (currentData == target)
            return currentNode;

        if (currentData < target)
        {

            currentNode = getRightSubTree(currentNode);
        }
        else
            currentNode = getLeftSubTree(currentNode);
    }

    return NULL;
}