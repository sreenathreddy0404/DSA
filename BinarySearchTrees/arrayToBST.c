#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode*left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int data){
    TreeNode* newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->val = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

TreeNode* convertArrToBST(int *arr,int low,int high){
    if(low>high) return NULL;
    int mid = (low+high)/2;
    TreeNode* root = createNode(arr[mid]);
    root->left = convertArrToBST(arr,low,mid-1);
    root->right = convertArrToBST(arr,mid+1,high);
    return root;
}

void inOrderTraversal(TreeNode* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->val);
        inOrderTraversal(root->right);
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = NULL;
    root = convertArrToBST(arr,0,n-1);
    inOrderTraversal(root);
}