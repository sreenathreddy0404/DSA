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
TreeNode *insertValueInBST(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createnode(data);
    }
    if (root->val == data)
    {
        printf("Node already Present\n");
        return root;
    }
    if (root->val > data)
    {
        root->left = insertValueInBST(root->left, data);
    }
    else
    {
        root->right = insertValueInBST(root->right, data);
    }
    return root;
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
TreeNode *searchelement(TreeNode *root, int target)
{
    if (root == NULL || root->val == target)
    {
        return root;
    }
    if (root->val > target)
    {
        return searchelement(root->left, target);
    }
    else
    {
        return searchelement(root->right, target);
    }
}
int search(TreeNode *root, int target)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->val == target)
    {
        return 1;
    }
    if (root->val > target)
    {
        int left = search(root->left, target);
        if (left == 1)
            return 1;
    }
    else
    {
        int right = search(root->right, target);
        if (right == 1)
            return 1;
    }
    return -1;
}
int findRightMin(TreeNode* root){
    if(root->left == NULL){
        return root->val;
    }else{
        findRightMin(root->left);
    }
}
TreeNode* delete(TreeNode* root,int target){
    if(root == NULL){
        return root;
    }
    if(root->val == target){
        if(root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }else{
            int rightMin = findRightMin(root->right);
            root->val = rightMin;
            root->right = delete(root->right,rightMin);
        }
    }else if(root->val>target){
        root->left = delete(root->left,target);
    }else{
        root->right = delete(root->right,target);
    }
    return root;
}

int main()
{
    //         10
    //       /    \
    //      5      15
    //     / \    /  \
    //    1   8  13   20
    TreeNode *root = NULL;
    root = insertValueInBST(root, 10);
    root = insertValueInBST(root, 5);
    root = insertValueInBST(root, 15);
    root = insertValueInBST(root, 2);
    root = insertValueInBST(root, 8);
    root = insertValueInBST(root, 13);
    root = insertValueInBST(root, 20);
    inOrderTraversal(root);
    printf("\n");
    delete(root,5);
    inOrderTraversal(root);
    return 0;
}