#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createnode(int data)
{
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = data;
    return newnode;
}
TreeNode *insertValueInBT(TreeNode *root, int data)
{
    if (root == NULL){
        return createnode(data);
    }
    TreeNode* queue[40];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while(front<rear){
        TreeNode* temp = queue[front++];
        if(temp->left == NULL){
            temp->left = createnode(data);
            return root;
        }else{
            queue[rear++] = temp->left;
        }
        if(temp->right == NULL){
            temp->right = createnode(data);
            return root;
        }else{
            queue[rear++] = temp->right;
        }
    }
}

void inOrderTraversal(TreeNode *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

int main(){
    int choice, value;
    TreeNode *root = NULL;
    do{
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert node in binary tree : \n");
        printf("Enter 2 to in order traversal\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            printf("Enter the value to Inset : ");
            scanf("%d", &value);
            root = insertValueInBT(root, value);
            break;
        case 2:
            inOrderTraversal(root);
            printf("\n");
            break;
        default:
            printf("Enter the valid value\n");
        }
    } while (choice);
}
