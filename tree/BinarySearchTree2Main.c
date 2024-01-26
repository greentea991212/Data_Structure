#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree2.h"

int main()
{

    Tree bst;
    BinarySearchTreeInit(&bst);

    Insert(&bst, 3);
    Insert(&bst, 1);
    Insert(&bst, 6);
    Insert(&bst, 2);
    Insert(&bst, 5);
    Insert(&bst, 9);
    Insert(&bst, 8);

    printf("Tree's root : %d\n", bst.root->data);
    Inorder(bst.root);

    return 0;
}