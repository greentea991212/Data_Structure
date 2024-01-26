#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree.h"

int main(void)
{

    Node *rootNode;
    Node *searchNode;

    BstMakeAndInit(&rootNode);

    BstInsert(&rootNode, 3);
    BstInsert(&rootNode, 1);
    BstInsert(&rootNode, 6);
    BstInsert(&rootNode, 2);
    BstInsert(&rootNode, 5);
    BstInsert(&rootNode, 9);
    BstInsert(&rootNode, 8);

    Inorder(rootNode);
    printf("\n\n");

    searchNode = BstSearch(rootNode, 3);

    if (searchNode == NULL)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    searchNode = BstSearch(rootNode, 5);

    if (searchNode == NULL)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    searchNode = BstSearch(rootNode, 9);

    if (searchNode == NULL)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    searchNode = BstSearch(rootNode, 6);

    if (searchNode == NULL)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    return 0;
}