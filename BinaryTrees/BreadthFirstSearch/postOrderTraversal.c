#include <stdio.h>
#include <stdlib.h>

// structure of node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// newnode creation
node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL){
        printf("return NULL");
        return NULL;
    }
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = val;
    return newnode;
}

// preOrderTraversal
void postOrderTraversal(node *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    /* binary tree
          1
         / \
        2   3
       / \
      4   5
    */
    node *root = createnode(1);
    node *p1 = createnode(2);
    node *p2 = createnode(3);
    node *p3 = createnode(4);
    node *p4 = createnode(5);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    postOrderTraversal(root);
    return 0;
}