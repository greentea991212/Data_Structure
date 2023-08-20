#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree.h"

int main(void)
{

    BTreeNode *bstRoot;
    BTreeNode *searchNode;

    bstMakeAndInit(&bstRoot);

    bstInsert(&bstRoot, 9);
    bstInsert(&bstRoot, 1);
    bstInsert(&bstRoot, 6);
    bstInsert(&bstRoot, 2);
    bstInsert(&bstRoot, 8);
    bstInsert(&bstRoot, 3);
    bstInsert(&bstRoot, 5);

    searchNode = bstSearch(bstRoot, 9);
    if (searchNode == NULL)
        printf("Ž������\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", bstGetNodeData(searchNode));

    searchNode = bstSearch(bstRoot, 4);
    if (searchNode == NULL)
        printf("Ž������\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", bstGetNodeData(searchNode));
    searchNode = bstSearch(bstRoot, 6);
    if (searchNode == NULL)
        printf("Ž������\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", bstGetNodeData(searchNode));
    searchNode = bstSearch(bstRoot, 7);
    if (searchNode == NULL)
        printf("Ž������\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", bstGetNodeData(searchNode));
}