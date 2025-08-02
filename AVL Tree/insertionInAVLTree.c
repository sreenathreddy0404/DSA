#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
    int height;
}TreeNode;

//function to create a newnode
TreeNode* createNode(int data){
    TreeNode* newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; 
    // we kept the height of leaf node to 1 
    //because we are considering height for no node is 0.
    return newnode;
}

//normal function to find maximum of two numbers
int max(int a,int b){
    return (a>b)? a:b;
}

//get the height
int height(TreeNode* root){
    if(root == NULL){
        return 0;//node no is there
    }
    return root->height;
}

int getBalance(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}

//      y                               x
//     / \     Right Rotation          / \
//    x   T3   - - - - - - - >        T1   y 
//   / \       < - - - - - - -            / \
//  T1  T2     Left Rotation            T2  T3

TreeNode* leftRotation(TreeNode* root){  //x
    TreeNode* RightNode = root->right;   //y
    TreeNode* RightNodeLeft = RightNode->left;  //T2

    RightNode->left = root;  //y->left = x
    root->right = RightNodeLeft; //x->left = T2

    //notice only height of y and x will change and the height of child nodes of x and y will not change
    root->height = 1+max(height(root->left),height(root->right)); // first height of x will update
    RightNode->height = 1+max(height(RightNode->left),height(RightNode->right)); // and then height of y will update

    return RightNode; //y
}

TreeNode *rightRotation(TreeNode *root){
    TreeNode *LeftNode = root->left;
    TreeNode *LeftNodeRight = LeftNode->right;

    LeftNode->right = root;
    root->left = LeftNodeRight;

    root->height = 1 + max(height(root->left), height(root->right));
    LeftNode->height = 1 + max(height(LeftNode->left), height(LeftNode->right));
    return LeftNode;
}

TreeNode* insertNodeInAVLTree(TreeNode* root,int data){
    if(root == NULL){
        return createNode(data); // normal BST Insertion in its position
    }

    //normal BST Traversal To Insert
    if(root->val > data){
        root->left = insertNodeInAVLTree(root->left,data);
    }else if(root->val < data){
        root->right = insertNodeInAVLTree(root->right,data);
    }else{
        return root; //if the data is already exists in tree
    }

    //update height of ancestors after insertion of node;
    root->height = 1+max(height(root->left),height(root->right));

    //get the balance of node
    int balance = getBalance(root);

    //condition for right rotation
    if(balance > 1 && data < root->left->val){
        return rightRotation(root);
    }

    //condition for left rotation
    if(balance < -1 && data > root->right->val){
        return leftRotation(root);
    }

    //condition for left right rotaion
    if(balance > 1 && data > root->left->val){
        //first we do left rotation on left node
        root->left = leftRotation(root->left);
        //after that we do right rotation of root
        return rightRotation(root);
    }

    //condition for right left rotation
    if(balance < -1 && data < root->right->val){
        //first we do right roation on right node
        root->right = rightRotation(root->right);
        //after that we do left rotaion of root
        return leftRotation(root);
    }

    //return the node if the node is in balance condition
    return root;
}

void preOrderTraversal(TreeNode* root){
    if(root != NULL){
        printf("%d ", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void bfs(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    TreeNode *q[100]; // Queue for level order traversal
    int f = 0, rear = 0;

    q[rear++] = root;
    while (f < rear)
    {
        TreeNode *temp = q[f++];
        printf("%d ", temp->val);
        if (temp->left)
        {
            q[rear++] = temp->left;
        }

        if (temp->right)
        {
            q[rear++] = temp->right;
        }
    }
    return;
}
int main(){
    TreeNode* root = NULL;
    root = insertNodeInAVLTree(root,13);
    root = insertNodeInAVLTree(root,10);
    root = insertNodeInAVLTree(root,15);
    root = insertNodeInAVLTree(root,5);
    root = insertNodeInAVLTree(root, 4);
    root = insertNodeInAVLTree(root,6);
    root = insertNodeInAVLTree(root,11);
    root = insertNodeInAVLTree(root,16);
    root = insertNodeInAVLTree(root,3);
    bfs(root);
    printf("\n");
    preOrderTraversal(root);
    
    
    return 0;
}