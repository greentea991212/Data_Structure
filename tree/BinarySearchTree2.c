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
void Insert(Tree *bst, int data)
{
    Node *currentNode = NULL;
    Node *parentNode = NULL;
    Node *newNode = NULL;

    if (bst->root == NULL)
    {

        newNode = MakeTreeNode();
        SetNodeData(newNode, data);
        bst->root = newNode;
        return;
    }
    else
    {
        currentNode = bst->root;
        while (currentNode != NULL)
        { // 특정 노드가 삽입되야될 규칙에 따라 비어있는 곳이 곧 삽입되어야 할 위치이다.
            parentNode = currentNode;
            if (GetNodeData(currentNode) == data)
                return;
            if (GetNodeData(currentNode) > data)
            {
                currentNode = GetLeftChildNode(currentNode);
            }
            else if (GetNodeData(currentNode) < data)
            {
                currentNode = GetRightChildNode(currentNode);
            }
        }
    }

    if (parentNode != NULL)
    {

        newNode = MakeTreeNode();
        SetNodeData(newNode, data);
        if (GetNodeData(parentNode) > data)
        {
            parentNode->left = newNode;
        }
        else if (GetNodeData(parentNode) < data)
        {
            parentNode->right = newNode;
        }
        else
            return;
    }
}

Node *Search(Tree *bst, int target)
{

    if (bst->root == NULL)
        return NULL;

    Node *currentNode = bst->root;
    while (currentNode != NULL)
    {

        if (GetNodeData(currentNode) == target)
            break;
        else if (GetNodeData(currentNode) > target)
        {

            currentNode = GetLeftChildNode(currentNode);
        }
        else
        {

            currentNode = GetRightChildNode(currentNode);
        }
    }

    if (currentNode != NULL)
        return currentNode;
    else
        return NULL;
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