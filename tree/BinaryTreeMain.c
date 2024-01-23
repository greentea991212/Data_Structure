#include <stdlib.h>
#include <stdio.h>
#include "../include/BinaryTree.h"
/*
이진트리의 만족 조건
1. 루트 노드로 하여금 두개의 서브트리가 나뉘어진다.
2. 나뉘어진 서브트리 또한 이진트리이어야 한다.
(이때, 공집합 노드도 하나의 노드로 인정한다.)
*/
int main()
{

    Node *node1 = MakeNode();
    SetNodeData(node1, 1);
    Node *node2 = MakeNode();
    SetNodeData(node2, 2);
    Node *node3 = MakeNode();
    SetNodeData(node3, 3);
    Node *node4 = MakeNode();
    SetNodeData(node4, 4);
    Node *node5 = MakeNode();
    SetNodeData(node5, 5);
    Node *node6 = MakeNode();
    SetNodeData(node6, 6);

    SetLeftSubTree(node1, node2);
    SetRightSubTree(node1, node3);
    SetLeftSubTree(node2, node4);
    SetRightSubTree(node2, node5);
    SetRightSubTree(node3, node6);

    printf("Node1's left : %d\n", GetNodeData(GetLeftSubTree(node1)));
    printf("Node2's right : %d\n\n", GetNodeData(GetRightSubTree(node2)));
    printf("preorder : ");
    Preorder(node1);
    printf("\n");

    printf("inorder : ");
    Inorder(node1);
    printf("\n");

    printf("postorder : ");
    Postorder(node1);
    printf("\n");

    DeleteAll(node1);
    return 0;
}