#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree2.h"

Node *MakeTreeNode()
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BinarySearchTreeInit(Tree *bst)
{

    bst->root = NULL;
}

void SetNodeData(Node *node, int data)
{
    node->data = data;
}

int GetNodeData(Node *node)
{

    return node->data;
}

Node *GetLeftChildNode(Node *parentNode)
{

    if (parentNode->left == NULL)
        return NULL;
    else
        return parentNode->left;
}
Node *GetRightChildNode(Node *parentNode)
{

    if (parentNode->right == NULL)
        return NULL;
    else
        return parentNode->right;
}

void SetLeftChildNode(Node *parentNode, Node *node)
{

    if (parentNode == NULL)
        return;

    parentNode->left = node;
}
void SetRightChildNode(Node *parentNode, Node *node)
{
    if (parentNode == NULL)
        return;

    parentNode->right = node;
}
void Insert(Tree *bst, int data)
{
    Node *parentNode = NULL; // 탐색하고자 하는 노드의 부모노드를 가르킨다.
    Node *currentNode = NULL;
    Node *newNode;
    // 이미 이진탐색트리가 갖춰진 경우
    currentNode = bst->root;    // 루트노드에서 부터 설정하여 탐색을 시작한다.
    while (currentNode != NULL) // NULL을 만날때 까지 탐색을 한다. 왜냐하면, 크기 비교 연산을 통해 비어있는 (NULL)곳이 삽입할 위치이기 때문이다.
    {
        parentNode = currentNode;             // 부모노드를 현재 노드에 위임한다.
        if (GetNodeData(currentNode) == data) // 이진탐색트리는 키값에 대한 중복을 허용하지 않는다.
            return;
        if (GetNodeData(currentNode) > data)
        {

            currentNode = GetLeftChildNode(currentNode);
        }
        else
            currentNode = GetRightChildNode(currentNode);
    }
    newNode = MakeTreeNode();
    SetNodeData(newNode, data);
    if (parentNode == NULL)
    { // parentNode가 NULL이라는 것은, 현재 삽입할 데이터가 트리의 첫 노드라는 것이다.

        bst->root = newNode;
    }
    else
    {
        if (GetNodeData(parentNode) > data)
            SetLeftChildNode(parentNode, newNode);
        else
            SetRightChildNode(parentNode, newNode);
    }

    return;
}
void Remove(Tree *bst, int target)
{
    Node *virtualRootNode = MakeTreeNode();
    Node *parentNode = NULL;              // 삭제할 노드의 부모노드
    Node *currentNode = NULL;             // 삭제할 노드(현재노드)
    Node *replacementNode = NULL;         // 대체할 노드
    Node *parentOfReplacementNode = NULL; // 대체할 노드의 부모노드
    Node *delNode = NULL;
    if (bst->root == NULL)
        return;

    SetRightChildNode(virtualRootNode, bst->root); // 가상루트노드의 오른쪽 자식으로 루트노드를 설정한다.
    // 삭제할 노드가 어디있는지 찾아낸다.
    printf("?\n");
    parentNode = virtualRootNode;
    currentNode = bst->root;
    printf("currentNode : %d\n", currentNode->data);
    while (currentNode != NULL && GetNodeData(currentNode) != target)
    {
        parentNode = currentNode;
        if (GetNodeData(currentNode) > target)
        {

            currentNode = GetLeftChildNode(currentNode);
        }
        else
        {

            currentNode = GetRightChildNode(currentNode);
        }
        printf("?\n");
    }
    if (currentNode == NULL)
        return;

    delNode = currentNode;
    // 조건1. 삭제할 노드가 단말노드인 경우 (즉, 그어떠한 자식 노드가 없는 경우)
    if (GetLeftChildNode(delNode) == NULL && GetRightChildNode(delNode) == NULL)
    {
        if (GetLeftChildNode(parentNode) == delNode)
        {
            parentNode->left = NULL;
        }
        else
        {
            parentNode->right = NULL;
        }
    }
    // 조건2. 삭제할 노드의 자식노드가 하나인 경우
    else if (GetLeftChildNode(delNode) == NULL || GetRightChildNode(delNode) == NULL)
    {
        Node *childOfDelNode;
        // 삭제할 노드 의 자식노드가 왼쪽에 있는지, 오른쪽에 있는지 탐색해야한다.
        // 만약 왼쪽에 있다면, 삭제할 노드의 자식을 삭제할 노드의 부모 왼쪽에 연결

        if (GetLeftChildNode(delNode) != NULL)
        {

            childOfDelNode = GetLeftChildNode(delNode);
        }
        else
        {

            childOfDelNode = GetRightChildNode(delNode);
        }
        if (GetLeftChildNode(parentNode) == delNode)
        {
            parentNode->left = childOfDelNode;
        }
        else
        {

            parentNode->right = childOfDelNode;
        }
    }
    // 조건3. 삭제할 노드의 자식노드가 두개인 경우
    else
    {
        parentOfReplacementNode = delNode;
        replacementNode = GetRightChildNode(delNode);

        while (GetLeftChildNode(replacementNode) != NULL)
        {
            parentOfReplacementNode = replacementNode;
            replacementNode = GetLeftChildNode(replacementNode);
        }

        SetNodeData(delNode, replacementNode->data);

        if (GetLeftChildNode(parentOfReplacementNode) == replacementNode)
        {
            parentOfReplacementNode->left = GetRightChildNode(replacementNode);
        }
        else
        {
            parentOfReplacementNode->right = GetRightChildNode(replacementNode);
        }
    }

    if (virtualRootNode->right != bst->root)
    {

        bst->root = virtualRootNode->right;
    }

    return;
    /*
    1. 루트에서 부터 삭제할 노드를 탐색한다.
    2. 삭제할 노드에 대해 대체할 노드를 탐색한다.
    2-1. 대체할 노드는 오른쪽 서브트리에서 가장 작은 노드를 채택한다.
    3. 대체할 노드의 데이터를 삭제할 노드에 대입하고, 삭제한 자식노드와 삭제한 부모노를 연결한다.
    위 세가지 사항이 기본적인 매커니즘이다.
    */
}
void Preorder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}
void Inorder(Node *node)
{
    if (node == NULL)
        return;

    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}
void Postorder(Node *node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}