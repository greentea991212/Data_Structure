#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree2.h"

// BinarySearchTree에 대한 ADT를 처음부터 구현한 코드이다.

int main()
{

    Tree bst;
    Node *searchNode;
    BinarySearchTreeInit(&bst);

    Insert(&bst, 5);
    Insert(&bst, 8);
    Insert(&bst, 1);
    Insert(&bst, 6);
    Insert(&bst, 4);
    Insert(&bst, 9);
    Insert(&bst, 3);
    Insert(&bst, 2);
    Insert(&bst, 7);

    searchNode = Search(&bst, 1);
    if (searchNode != NULL)
    {
        printf("탐색 성공 : %d\n", searchNode->data);
    }
    searchNode = Search(&bst, 5);
    if (searchNode != NULL)
    {
        printf("탐색 성공 : %d\n", searchNode->data);
    }
    searchNode = Search(&bst, 9);
    if (searchNode != NULL)
    {
        printf("탐색 성공 : %d\n", searchNode->data);
    }
    Inorder(bst.root);
    printf("\n\n");

    Remove(&bst, 5);

    Inorder(bst.root);
    printf("\n\n");

    Remove(&bst, 8);

    Inorder(bst.root);
    printf("\n\n");

    Remove(&bst, 1);
    Inorder(bst.root);
    printf("\n\n");

    Remove(&bst, 6);
    Inorder(bst.root);
    printf("\n\n");

    return 0;
}