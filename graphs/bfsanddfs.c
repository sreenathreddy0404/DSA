#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void addEdge(node *adj[], int i, int j)
{
    node *newnode = createnode(j);
    newnode->next = adj[i];
    adj[i] = newnode;

    newnode = createnode(i);
    newnode->next = adj[j];
    adj[j] = newnode;
}

void bfsTrav(node *adj[],int v,int i,int visited[]){
    int queue[10];
    int front = 0;
    int rear = 0;
    queue[rear++] = i;
    visited[i] = 1;
    while(front!=rear){
        int curr = queue[front++];
        printf("%d ",curr);

        node* temp = adj[curr];
        while(temp!=NULL){
            if(!visited[temp->data]){
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

void bfs(node *adj[],int v){
    int visited[v];
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    for(int i = 0;i<v;i++){
        if(visited[i] == 0){
            bfsTrav(adj,v,i,visited);
        }
    }
}

void dfsTrav(node* adj[],int v,int i,int visited[]){
    visited[i] = 1;
    printf("%d ",i);
    node* temp = adj[i];
    while(temp != NULL){
            if(!visited[temp->data]){
                dfsTrav(adj,v,temp->data,visited);
            }
        temp = temp->next;
    }
}

void dfs(node* adj[],int v,int i){
    int visited[v];
    for(int j=0;j<v;j++){
        visited[j] = 0;
    }
    dfsTrav(adj,v,i,visited);
        
}

void displayList(node* adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        node *temp = adj[i];
        printf("%d -> ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int v = 5;
    node *adj[v];
    for (int i = 0; i < v; i++)
    {
        adj[i] = NULL;
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

    printf("Adjacency List Representation:\n");
    displayList(adj, v);

    printf("bfs:\n");
    bfs(adj,v);

    printf("\ndfs:\n");
    dfs(adj, v,0);
}