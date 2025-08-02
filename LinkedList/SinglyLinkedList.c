#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;

void atBegin()
{
    int info;
    printf("Enter the Data: ");
    scanf("%d", &info);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = info;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\nData added successfully.\n");
}

void atEnd()
{
    int data;
    printf("Enter the Data: ");
    scanf("%d", &data);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Data added successfully.\n");
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    printf("\nNode is deleted successfully.\n");
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head, *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("\nNode is deleted successfully.\n");
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

void beforeInsert()
{
    int info, value;
    printf("Enter the data: ");
    scanf("%d", &info);
    printf("Enter the value before which you want to insert data: ");
    scanf("%d", &value);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = info;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }

    if (head->data == value)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *prev = head, *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            newNode->next = curr;
            prev->next = newNode;
            printf("\nData added successfully.\n");
            return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    printf("\nNode before which you want to insert doesn't exist.\n");
    free(newNode);
}

void afterInsert()
{
    int info, value;
    printf("Enter the data: ");
    scanf("%d", &info);
    printf("Enter the value after which you want to insert data: ");
    scanf("%d", &value);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = info;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("\nData added successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nNode after which you want to insert doesn't exist.\n");
    free(newNode);
}

void beforeDelete()
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    if (head->data == value)
    {
        printf("\nCan't delete as there is no node before head.\n");
        return;
    }

    node *curr = head->next, *prev = head;
    if (curr != NULL && curr->data == value)
    {
        head = curr;
        free(prev);
        printf("\nNode is deleted successfully.\n");
        return;
    }

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == value)
        {
            prev->next = curr->next;
            free(curr);
            printf("\nNode is deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("\nNode before which you want to delete doesn't exist.\n");
}

void afterDelete()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == value && curr->next == NULL)
        {
            printf("\nThere is no node to delete after %d.\n", value);
            return;
        }

        if (curr->data == value)
        {
            node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
            printf("\nNode is deleted successfully.\n");
            return;
        }
        curr = curr->next;
    }

    printf("\nNode after which you want to delete doesn't exist.\n");
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
            atBegin();
            break;
        case 2:
            atEnd();
            break;
        case 3:
            beforeInsert();
            break;
        case 4:
            afterInsert();
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            beforeDelete();
            break;
        case 8:
            afterDelete();
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
