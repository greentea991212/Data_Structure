#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree.h"
#include "../include/BinarySearchTree.h"

void BstMakeAndInit(Node **rootNode)
{

    *rootNode = NULL;
}
Data BstGetNodeData(Node *bst)
{

    return bst->data;
}
void BstInsert(Node **rootNode, Data insertData)
{
    Node *parentNode = NULL;
    Node *currentNode = NULL;
    Node *newNode = NULL;

    // if (*rootNode == NULL) // ��Ʈ ��尡 ����ִٸ�, �� Ʈ�� ��ü�� ���ٸ�
    // {

    //     newNode = MakeNode(); // ���ο� ��带 �����.
    //     SetNodeData(newNode, insertData);
    //     *rootNode = newNode; // ���θ��� ��尡 ��Ʈ ��尡 �ȴ�.
    //     return;
    // }
    // else // �׷��� �ʰ�, ��Ʈ ��尡 �����Ѵٸ�,
    //{

    currentNode = *rootNode; // ��Ʈ ��� ���� �湮�Ѵ�.

    while (currentNode != NULL) // ���� ��尡 ������ ����϶� ���� �ݺ����� �����Ѵ�.
    {
        parentNode = currentNode;           // ���� ��带 �θ���� �����ϰ�
        if (insertData > currentNode->data) // ���� ���� ����� Ű�� ����, ������ Ű���� �� ũ�ٸ�
        {

            currentNode = GetRightSubTree(currentNode); // �θ� ���� �Ͽ���, ������ �ּҸ� �˾Ƴ���.
        }
        else if (insertData < currentNode->data) // �׷��� ������, ���� �ּҸ� �˾Ƴ���.
        {

            currentNode = GetLeftSubTree(currentNode); // ��, ���ο� �����Ͱ� ���Ե� ��ġ�� �˾Ƴ���.
        }
        else
            return; // �ߺ� Ű�� ���X
    }

    newNode = MakeNode(); // ������ ��ġ�� �˾Ƴ�����, ��带 �����ϰ� ������ ����
    SetNodeData(newNode, insertData);

    if (parentNode != NULL) // �θ��尡 NULL�̶�� ���� �� Ʈ���� ����ִٴ� ��ǰ� ����.
    {

        if (parentNode->data < insertData)
        {
            SetRightSubTree(parentNode, newNode);
        }
        else if (parentNode->data > insertData)
        {

            SetLeftSubTree(parentNode, newNode);
        }
    }
    else
    {
        *rootNode = newNode; // ���ο��� rootNode = newNode;�� �����ϰ� �ȴ�(���� �����Ϳ� ����)
    }
}
//}
Node *BstSearch(Node *bst, Data target)
{
    if (bst == NULL)
        return NULL;

    Node *currentNode;

    currentNode = bst;

    while (currentNode != NULL)
    {
        if (currentNode->data < target)
        {
            // printf("Current : %d\n", currentNode->data);
            currentNode = GetRightSubTree(currentNode);
        }
        else if (currentNode->data > target)
        {
            // printf("Current : %d\n", currentNode->data);

            currentNode = GetLeftSubTree(currentNode);
        }
        else if (currentNode->data == target)
            break;
    }

    if (currentNode != NULL)
        return currentNode;

    else
        return NULL;
}

Node *BstRemove(Node **rootNode, Data target)
{
    Node *virtualRoot = MakeNode(); // ���̳�� ����. �̴� ��Ʈ����� �θ����� �ϰ� �Ѵ�.
    Node *parentNode;
    Node *currentNode;
    Node *delNode;

    ChangeRightSubTree(virtualRoot, *rootNode); // ���̳���� �����ʿ�, ��Ʈ�� �Ͽ��� ���� Ʈ�� ����

    parentNode = virtualRoot;
    currentNode = *rootNode;

    while (currentNode != NULL && GetNodeData(currentNode) != target)
    {

        parentNode = currentNode;
        if (target < GetNodeData(currentNode))
        {

            currentNode = GetLeftSubTree(currentNode);
        }
        else
            currentNode = GetRightSubTree(currentNode);
    }

    if (currentNode == NULL)
        return NULL;

    delNode = currentNode;

    // ����1: ������ ��尡 leaf��� �϶�.
    if (GetLeftSubTree(delNode) == NULL && GetRightSubTree(delNode))
    {

        if (delNode == GetLeftSubTree(parentNode))
            RemoveLeftSubTree(parentNode);
        else
            RemoveRightSubTree(parentNode);
    }
    // ����2: ������ ����� �ڽ� ��尡 1�� �϶�.
    else if (GetLeftSubTree(delNode) == NULL || GetRightSubTree(delNode) == NULL)
    {

        Node *childOfDelNode;

        // ���� ������ ����� ��ġ�� ����� Ž���Ѵ�.
        if (GetLeftSubTree(delNode) != NULL)
            childeOfDelNode = GetLeftSubTree(delNode);
        else
            childOfDelNode = GetRightSubTree(delNode);

        // ������ �����Ͱ� �θ����� �������� ���������� Ž���Ѵ�.

        if (GetLeftSubTree(parentNode) == delNode)
            ChangeLeftSubTree(parentNode, childOfDelNode);
        else
            ChangeRightSubTree(parentNode, childOfDelNode);
    }

    // ����3: ������ ����� �ڽĳ�尡 2�� �϶�.
}