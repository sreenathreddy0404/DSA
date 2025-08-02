#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int val){
    node * newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void addEdge(node* adj[], int i, int j){
    node* newnode = createnode(j);
    newnode->next = adj[i];
    adj[i] = newnode;

    newnode =createnode(i);
    newnode->next = adj[j];
    adj[j] = newnode;
}

void displayList(node* adj[],int v){
    for(int i=0; i<v ;i++){
        node* temp = adj[i];
        printf("%d -> ",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int v = 4;
    node* adj[v];
    for(int i=0;i<v;i++){
        adj[i] = NULL;
    }
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    
    printf("Adjacency List Representation:\n");
    displayList(adj,v);
}