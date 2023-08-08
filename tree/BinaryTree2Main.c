#include <stdio.h>
#include <stdlib.h>
#include "../include/BinaryTree2.h"

void action(int data)
{

    printf("%d ", data);
}

int main(void)
{

    vistFuctionPtr = action; // 함수의 이름은 함수가 저장되어진 위치의 주소를 가지고 있다.

    BTreeNode *root = MakeBTreeNode();
    setData(root, 1);

    BTreeNode *btNode2 = MakeBTreeNode();
    setData(btNode2, 2);

    BTreeNode *btNode3 = MakeBTreeNode();
    setData(btNode3, 3);

    BTreeNode *btNode4 = MakeBTreeNode();
    setData(btNode4, 4);

    BTreeNode *btNode5 = MakeBTreeNode();
    setData(btNode5, 5);

    BTreeNode *btNode6 = MakeBTreeNode();
    setData(btNode6, 6);

    setLeftSubTree(root, btNode2);
    setRightSubTree(root, btNode3);
    setLeftSubTree(btNode2, btNode4);
    setRightSubTree(btNode2, btNode5);
    setLeftSubTree(btNode3, btNode6);

    preOrderTraverse(root, vistFuctionPtr);
    printf("\n");
    inOrderTraverse(root, vistFuctionPtr);
    printf("\n");
    postOrderTraverse(root, vistFuctionPtr);
}