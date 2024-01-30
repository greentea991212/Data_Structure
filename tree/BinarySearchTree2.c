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
    Node *parentNode = NULL; // Ž���ϰ��� �ϴ� ����� �θ��带 ����Ų��.
    Node *currentNode = NULL;
    Node *newNode;
    // �̹� ����Ž��Ʈ���� ������ ���
    currentNode = bst->root;    // ��Ʈ��忡�� ���� �����Ͽ� Ž���� �����Ѵ�.
    while (currentNode != NULL) // NULL�� ������ ���� Ž���� �Ѵ�. �ֳ��ϸ�, ũ�� �� ������ ���� ����ִ� (NULL)���� ������ ��ġ�̱� �����̴�.
    {
        parentNode = currentNode;             // �θ��带 ���� ��忡 �����Ѵ�.
        if (GetNodeData(currentNode) == data) // ����Ž��Ʈ���� Ű���� ���� �ߺ��� ������� �ʴ´�.
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
    { // parentNode�� NULL�̶�� ����, ���� ������ �����Ͱ� Ʈ���� ù ����� ���̴�.

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
    Node *parentNode = NULL;              // ������ ����� �θ���
    Node *currentNode = NULL;             // ������ ���(������)
    Node *replacementNode = NULL;         // ��ü�� ���
    Node *parentOfReplacementNode = NULL; // ��ü�� ����� �θ���
    Node *delNode = NULL;
    if (bst->root == NULL)
        return;

    SetRightChildNode(virtualRootNode, bst->root); // �����Ʈ����� ������ �ڽ����� ��Ʈ��带 �����Ѵ�.
    // ������ ��尡 ����ִ��� ã�Ƴ���.
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
    // ����1. ������ ��尡 �ܸ������ ��� (��, �׾�� �ڽ� ��尡 ���� ���)
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
    // ����2. ������ ����� �ڽĳ�尡 �ϳ��� ���
    else if (GetLeftChildNode(delNode) == NULL || GetRightChildNode(delNode) == NULL)
    {
        Node *childOfDelNode;
        // ������ ��� �� �ڽĳ�尡 ���ʿ� �ִ���, �����ʿ� �ִ��� Ž���ؾ��Ѵ�.
        // ���� ���ʿ� �ִٸ�, ������ ����� �ڽ��� ������ ����� �θ� ���ʿ� ����

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
    // ����3. ������ ����� �ڽĳ�尡 �ΰ��� ���
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
    1. ��Ʈ���� ���� ������ ��带 Ž���Ѵ�.
    2. ������ ��忡 ���� ��ü�� ��带 Ž���Ѵ�.
    2-1. ��ü�� ���� ������ ����Ʈ������ ���� ���� ��带 ä���Ѵ�.
    3. ��ü�� ����� �����͸� ������ ��忡 �����ϰ�, ������ �ڽĳ��� ������ �θ�븦 �����Ѵ�.
    �� ������ ������ �⺻���� ��Ŀ�����̴�.
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