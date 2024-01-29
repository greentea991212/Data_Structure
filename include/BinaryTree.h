#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    Data data;

} Node;

Node *MakeNode();                        // 생성된 노드의 주소를 반환한다.
void SetNodeData(Node *node, Data data); // 특정 노드에 대한 데이터를 저장한다.
Data GetNodeData(Node *node);            // 특정 노드의 데이터를 반환한다.

void SetLeftSubTree(Node *parentNode, Node *childNode);  // 해당 노드에 대해 왼쪽 서브트리를 설정한다.
void SetRightSubTree(Node *parentNode, Node *childNode); // 해당 노드에 대해 오른쪽 서브트리를 설정한다.

Node *GetLeftSubTree(Node *node);  // 특정노드의 왼쪽 서브트리에 대한 주소값을 반환 받는다.
Node *GetRightSubTree(Node *node); // 특정노드의 오른쪽 서브트리에 대한 주소값을 반환 받는다.

void Preorder(Node *node);
void Inorder(Node *node);
void Postorder(Node *node);

void DeleteAll(Node *node);

Node *RemoveLeftSubTree(Node *parentNode);  // 현재 노드의 왼쪽 서브트리를 삭제한다. 삭제한 주소값을 반환한다.
Node *RemoveRightSubTree(Node *parentNode); // 현재 노드의 오른 쪽 서브트리를 삭제한다. 삭제한 주소값을 반환한다.

void ChangeLeftSubTree(Node *parentNode, Node *sub);
void ChangeRightSubTree(Node *parentNode, Node *sub);

#endif
