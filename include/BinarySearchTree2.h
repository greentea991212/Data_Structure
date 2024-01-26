#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    int data;

} Node;

typedef struct _binarySearchTree
{
    Node *root;
} Tree;

Node *MakeTreeNode();
void BinarySearchTreeInit(Tree *bst);
void SetNodeData(Node *node, int data);
int GetNodeData(Node *node);

Node *GetLeftChildNode(Node *parentNode);
Node *GetRightChildNode(Node *parentNode);

void Insert(Tree *bst, int data);
Node *Search(Tree *bst, int target);

void Preorder(Node* node);
void Inorder(Node* node);
void Postorder(Node* node);

#endif
