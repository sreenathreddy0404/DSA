#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertAtBegin()
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    node *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertAtEnd()
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    node *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
    }
}

void insertBefore()
{
    int value, info;
    printf("Enter value and info : ");
    scanf("%d %d", &value, &info);
    node *newnode = createNode(value);
    if (head == NULL)
    {
        printf("List is Empty\n");
        return; 
    }
    if (head->data == info)
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }
    node *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == info)
        {
            curr->prev->next = newnode;
            newnode->next = curr;
            newnode->prev = curr->prev;
            curr->prev = newnode;
            return;
        }
        curr = curr->next;
    }
    printf("The info value is not found in list\n");
}

void insertAfter()
{
    int value, info;
    printf("Enter value and info : ");
    scanf("%d %d", &value, &info);
    node *newnode = createNode(value);
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == info)
        {
            newnode->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
            newnode->prev = temp;
            return;
        }
        temp = temp->next;
    }
    printf("The info value is not found in the list\n");
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteBefore()
{
    int info;
    printf("Enter info : ");
    scanf("%d", &info);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->data == info && head->next == NULL)
    {
        printf("NO node befor before\n");
        return;
    }
    if (head->next->data == info)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        head->prev = NULL;
        return;
    }
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == info)
        {
            node *previ = curr->prev->prev;
            free(curr->prev);
            previ->next = curr;
            curr->prev = previ;
            return;
        }
        curr = curr->next;
    }
    printf("The info value is not found in the list\n");
}

void deleteAfter()
{
    int info;
    printf("Enter info : ");
    scanf("%d", &info);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == info && temp->next == NULL)
        {
            printf("There is no node after info\n");
            return;
        }
        if (temp->data == info)
        {
            node *toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != NULL)
            {
                temp->next->prev = toDelete->prev;
            }
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
    printf("The info value is not found in the list\n");
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nList: ");
    node *current = head;
    while (current != NULL)
    {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void search()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    int info, flag = 0;
    printf("Enter data to search: ");
    scanf("%d", &info);

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == info)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if (flag == 1)
    {
        printf("\nNode is present.\n");
    }
    else
    {
        printf("\nNode is not present in list.\n");
    }
}

void freeList(node *root)
{
    node *temp = NULL;
    while (root != NULL)
    {
        temp = root;
        root = root->next;
        free(temp);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Adding node at beginning of the list.");
        printf("\n2. Adding node at end of the list.");
        printf("\n3. Adding node Before specified node.");
        printf("\n4. Adding node after specified node.");
        printf("\n5. Deleting node from beginning of the list.");
        printf("\n6. Deleting node from end of the list.");
        printf("\n7. Deleting node Before specified node.");
        printf("\n8. Deleting node after specified node.");
        printf("\n9. Print the List.");
        printf("\n10. Search a node.");
        printf("\n11. Exit.");
        printf("\nEnter your choice of operation: ");
        scanf("%d", &choice);

        if (choice == 11)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            insertAtBegintBegin();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertBefore();
            break;
        case 4:
            insertAfter();
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteBefore();
            break;
        case 8:
            deleteAfter();
            break;
        case 9:
            display();
            break;
        case 10:
            search();
            break;
        default:
            printf("\nWrong input. Try again.\n");
        }
    }

    freeList(head);
    return 0;
}