#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree.h"

Node *MakeNode()
{

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = 0;

    return newNode;
}

void SetNodeData(Node *node, Data data)
{

    node->data = data;
}

Data GetNodeData(Node *node)
{

    return node->data;
}

void SetLeftSubTree(Node *parentNode, Node *childNode)
{

    if (parentNode->left != NULL)
    {
        /*
            �ϴ�, �̹� ��� ��尡 �ڸ��� ��������� ���� �� �����ϱ�
        */
        free(parentNode->left);
        parentNode->left = NULL;
    }
    parentNode->left = childNode;
}

void SetRightSubTree(Node *parentNode, Node *childNode)
{

    if (parentNode->right != NULL)
    {
        /*
            �ϴ�, �̹� ��� ��尡 �ڸ��� ��������� ���� �� �����ϱ�
        */
        free(parentNode->right);
        parentNode->right = NULL;
    }
    parentNode->right = childNode;
}

Node *GetLeftSubTree(Node *node)
{

    if (node->left != NULL)
        return node->left;
    else
    {
        printf("Empty %d's left\n", node->data);
        return NULL;
    }
}
Node *GetRightSubTree(Node *node)
{

    if (node->right != NULL)
        return node->right;
    else
    {
        printf("Empty %d's right\n", node->data);
        return NULL;
    }
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
void DeleteAll(Node *node)
{

    if (node == NULL)
        return;

    DeleteAll(node->left);
    DeleteAll(node->right);
    printf("%d is deleted\n", node->data);
    free(node);
    node = NULL;
    // printf("%p\n", node);
}

Node *RemoveLeftSubTree(Node *parentNode)
{

    Node *delNode;

    if (parentNode == NULL)
        return NULL;

    delNode = parentNode->left;
    parentNode->left = NULL;

    return delNode;
}

Node *RemoveRightSubTree(Node *parentNode)
{

    Node *delNode;
    if (parentNode == NULL)
        return NULL;
    delNode = parentNode->right;
    parentNode->right = NULL;

    return delNode;
}

// �޸� �Ҹ��� �������� �ʰ�, ���� ����Ʈ���� �����Ѵ�.
void ChangeLeftSubTree(Node *parentNode, Node *sub)
{
    parentNode->left = sub;
}
// �޸� �Ҹ��� �������� �ʰ�, ������ ����Ʈ���� �����Ѵ�.
void ChangeRightSubTree(Node *parentNode, Node *sub)
{

    parentNode->right = sub;
}