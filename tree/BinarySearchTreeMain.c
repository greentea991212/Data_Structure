#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree.h"

int main(void)
{

    Node *rootNode;
    Node *searchNode;

    BstMakeAndInit(&rootNode);

    BstInsert(&rootNode, 5);
    // BstInsert(&rootNode, 8);
    BstInsert(&rootNode, 1);
    // BstInsert(&rootNode, 6);
    // BstInsert(&rootNode, 4);
    // BstInsert(&rootNode, 9);
    // BstInsert(&rootNode, 3);
    // BstInsert(&rootNode, 2);
    // BstInsert(&rootNode, 7);

    Inorder(rootNode);
    printf("\n\n");

    // searchNode = BstRemove(&rootNode, 3);

    // Inorder(rootNode);
    // printf("\n\n");

    // searchNode = BstRemove(&rootNode, 8);

    // Inorder(rootNode);
    // printf("\n\n");

    searchNode = BstRemove(&rootNode, 5);
    Inorder(rootNode);
    printf("\n\n");

    // searchNode = BstRemove(&rootNode, 6);
    // Inorder(rootNode);
    printf("\n\n");
    printf("root : %d", rootNode->data);
    // if (searchNode == NULL)
    //     printf("Å½»ö½ÇÆÐ\n");
    // else
    //     printf("%d Å½»ö¿Ï·á!\n", BstGetNodeData(searchNode));

    // searchNode = BstSearch(rootNode, 5);

    // if (searchNode == NULL)
    //     printf("Å½»ö½ÇÆÐ\n");
    // else
    //     printf("%d Å½»ö¿Ï·á!\n", BstGetNodeData(searchNode));

    // searchNode = BstSearch(rootNode, 9);

    // if (searchNode == NULL)
    //     printf("Å½»ö½ÇÆÐ\n");
    // else
    //     printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    // searchNode = BstSearch(rootNode, 6);

    // if (searchNode == NULL)
    //     printf("Å½»ö½ÇÆÐ\n");
    // else
    //     printf("%d Å½»ö¿Ï·á\n", BstGetNodeData(searchNode));

    return 0;
}