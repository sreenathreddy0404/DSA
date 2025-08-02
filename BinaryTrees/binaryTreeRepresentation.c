#include<stdio.h>
#include<stdlib.h>

//structure of node
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

//newnode creation
node *createnode(int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = val;
    return newnode;
}

int main(){
    node* p = createnode(1);
    node* p1 = createnode(2);
    node* p2 = createnode(3);
    node* p3 = createnode(4);
    node* p4 = createnode(5);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    return 0;
}
