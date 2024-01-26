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

    if (*rootNode == NULL) // 루트 노드가 비어있다면, 즉 트리 자체가 없다면
    {

        newNode = MakeNode(); // 새로운 노드를 만든다.
        SetNodeData(newNode, insertData);
        *rootNode = newNode; // 새로만든 노드가 루트 노드가 된다.
        return;
    }
    else // 그렇지 않고, 루트 노드가 존재한다면,
    {

        currentNode = *rootNode; // 루트 노드 부터 방문한다.

        while (currentNode != NULL) // 현재 노드가 공집합 노드일때 까지 반복문을 실행한다.
        {
            parentNode = currentNode;           // 현재 노드를 부모노드로 설정하고
            if (insertData > currentNode->data) // 만약 현재 노드의 키값 보다, 삽입할 키값이 더 크다면
            {

                currentNode = GetRightSubTree(currentNode); // 부모 노드로 하여금, 오른쪽 주소를 알아낸다.
            }
            else if (insertData < currentNode->data) // 그렇지 않으면, 왼쪽 주소를 알아낸다.
            {

                currentNode = GetLeftSubTree(currentNode); // 즉, 새로운 데이터가 삽입될 위치를 알아낸다.
            }
            else
                return; // 중복 키값 허용X
        }

        newNode = MakeNode(); // 삽입할 위치를 알아냈으니, 노드를 생성하고 삽입할 차례
        SetNodeData(newNode, insertData);
        if (parentNode->data < insertData)
        {
            SetRightSubTree(parentNode, newNode);
        }
        else if (parentNode->data > insertData)
        {

            SetLeftSubTree(parentNode, newNode);
        }
    }
}
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