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
        �����Ͱ� ���ԵǾ���� ��ġ�� ã�� �˰���
    */

    if (*rootNode == NULL)
    {

        *rootNode = newNode;

        return;
    }

    while (currNode != NULL)
    {

        if (insertData == currNode->data)
            return; // �������� �ߺ��� ������� ����.

        parentNode = currNode;

        if (parentNode->data < insertData)
        {

            currNode = getRightSubTree(parentNode);
        }
        else
            currNode = getLeftSubTree(parentNode);
    }
    /*
        ã�� ��ġ�� �������, �����͸� �����ϴ� �˰���
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