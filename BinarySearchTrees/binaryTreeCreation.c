#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode *createnode(int data){
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = data;
    return newnode;
}
TreeNode *insertValueInBST(TreeNode *root, int data){
    if(root == NULL){
        return createnode(data);
    }
    if(root->val == data){
        printf("Node already Present\n");
        return root;
    } 
    if(root->val>data){
        root->left = insertValueInBST(root->left,data);
    }else{
        root->right = insertValueInBST(root->right,data);

    }
    return root;
}


void inOrderTraversal(TreeNode *root){
    if (root){
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

int main(){
    int choice,value;
    TreeNode* root = NULL;
    do{
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert node in binary search tree : \n");
        printf("Enter 2 to in order traversal\n");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
        switch(choice){
            case 1: 
                printf("Enter the value to Inset : ");
                scanf("%d",&value);
                root = insertValueInBST(root,value);
                break;
            case 2:
                inOrderTraversal(root);
                printf("\n");
                break;
            default:
                printf("Enter the valid value\n");
        }
    }while(choice);
}






















//         10
//        /  \
//       5    15
//      /
//     2
//    /
//   1
//     insert(10,1);
//     // root == 10;
//     root->left = insert(5,1);
//     // root == 5;
//     root->left = insert(2,1);
//     // root = 2;
//     root->left = insert(NULL,1);
//     // root == NULL
//     return newnode(1);
// TreeNode* insertValueInBST(TreeNode* root,int data){
//     TreeNode* newnode = createnode(data);
//     if(root == NULL){
//         root = newnode;
//         return root;
//     }
//     TreeNode* temp = root;
//     while(1){
//         if(data>temp->val){
//             if(temp->right == NULL) temp->right = newnode;
//             else temp = temp->right;
//         }
//         else if(data<temp->val){
//             if(temp->left == NULL) temp->left = newnode;
//             else temp = temp->left;
//         }else{
//             printf("BST Doesn't contains Duplicate Values\n");
//             return root;
//         }
//     }
//     return root;
// }