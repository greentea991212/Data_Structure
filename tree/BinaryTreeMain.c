#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree.h"

int main(void)
{

    BTreeNode *root = MakeNode();
    BTreeNode *btNode_1 = MakeNode();
    BTreeNode *btNode_2 = MakeNode();
    BTreeNode *btNode_3 = MakeNode();
    BTreeNode *btNode_4 = MakeNode();

    setData(root, 0);
    setData(btNode_1, 1);
    setData(btNode_2, 2);
    setData(btNode_3, 3);
    setData(btNode_4, 4);

    setLeftSubTree(root, btNode_1);
    setRightSubTree(root, btNode_2);
    setLeftSubTree(btNode_1, btNode_3);
    setRightSubTree(btNode_1, btNode_4);

    printf("%d\n", getData(getLeftSubTree(root)));
    printf("%d\n", getData(getLeftSubTree(getLeftSubTree(root))));

    return 0;
}