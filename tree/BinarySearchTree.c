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

    // if (*rootNode == NULL) // 루트 노드가 비어있다면, 즉 트리 자체가 없다면
    // {

    //     newNode = MakeNode(); // 새로운 노드를 만든다.
    //     SetNodeData(newNode, insertData);
    //     *rootNode = newNode; // 새로만든 노드가 루트 노드가 된다.
    //     return;
    // }
    // else // 그렇지 않고, 루트 노드가 존재한다면,
    //{

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

    if (parentNode != NULL) // 부모노드가 NULL이라는 것은 곧 트리가 비어있다는 사실과 같다.
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
        *rootNode = newNode; // 메인에서 rootNode = newNode;와 동일하게 된다(이중 포인터에 의해)
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
    Node *virtualRoot = MakeNode(); // 더미노드 생성. 이는 루트노드의 부모역할을 하게 한다.
    Node *parentNode;
    Node *currentNode;
    Node *delNode;

    ChangeRightSubTree(virtualRoot, *rootNode); // 더미노드의 오른쪽에, 루트로 하여금 기존 트리 연결

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

    // 조건1: 삭제할 노드가 leaf노드 일때.
    if (GetLeftSubTree(delNode) == NULL && GetRightSubTree(delNode))
    {

        if (delNode == GetLeftSubTree(parentNode))
            RemoveLeftSubTree(parentNode);
        else
            RemoveRightSubTree(parentNode);
    }
    // 조건2: 삭제할 노드의 자식 노드가 1개 일때.
    else if (GetLeftSubTree(delNode) == NULL || GetRightSubTree(delNode) == NULL)
    {

        Node *childOfDelNode;

        // 새로 연결할 노드의 위치가 어딘지 탐색한다.
        if (GetLeftSubTree(delNode) != NULL)
            childeOfDelNode = GetLeftSubTree(delNode);
        else
            childOfDelNode = GetRightSubTree(delNode);

        // 삭제할 데이터가 부모노드의 왼쪽인지 오른쪽인지 탐색한다.

        if (GetLeftSubTree(parentNode) == delNode)
            ChangeLeftSubTree(parentNode, childOfDelNode);
        else
            ChangeRightSubTree(parentNode, childOfDelNode);
    }

    // 조건3: 삭제할 노드의 자식노드가 2개 일때.
}