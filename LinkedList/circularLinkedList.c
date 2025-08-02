#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
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
        newnode->next = head; // Circular link
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        { // Traverse to last node
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
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
        newnode->next = head; // Circular link
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        { // Traverse to last node
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; // Circular link
    }
}

void insertBefore()
{
    int value, info;
    printf("Enter value and info: ");
    scanf("%d %d", &value, &info);
    node *newnode = createNode(value);

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->data == info)
    {
        insertAtBegin();
        return;
    }

    node *temp = head;
    while (temp->next != head && temp->next->data != info)
    {
        temp = temp->next;
    }

    if (temp->next->data == info)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("The info value is not found in the list\n");
    }
}

void insertAfter()
{
    int value, info;
    printf("Enter value and info: ");
    scanf("%d %d", &value, &info);
    node *newnode = createNode(value);

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    node *temp = head;
    do
    {
        if (temp->data == info)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("The info value is not found in the list\n");
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        { // Traverse to last node
            temp = temp->next;
        }
        node *toDelete = head;
        temp->next = head->next;
        head = head->next;
        free(toDelete);
    }
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next->next != head)
        { // Traverse to second last node
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head; // Circular link
    }
}

void deleteBefore()
{
    int info;
    printf("Enter info: ");
    scanf("%d", &info);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        printf("No node before, only one node exists.\n");
        return;
    }

    // Special case: if the node before the head needs to be deleted
    if (head->data == info)
    {
        node *temp = head;
        while (temp->next != head)
        { // Traverse to the last node
            temp = temp->next;
        }
        node *toDelete = temp; // Delete the last node
        while (temp->next != toDelete)
        { // Traverse to the second last node
            temp = temp->next;
        }
        temp->next = head; // Circular link
        free(toDelete);
        return;
    }

    node *curr = head;
    while (curr->next->next != head && curr->next->next->data != info)
    {
        curr = curr->next;
    }

    if (curr->next->next->data == info)
    {
        node *toDelete = curr->next; // Node before the found node
        curr->next = toDelete->next;
        free(toDelete);
    }
    else
    {
        printf("The info value is not found in the list.\n");
    }
}

void deleteAfter()
{
    int info;
    printf("Enter info: ");
    scanf("%d", &info);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    do
    {
        if (temp->data == info)
        {
            if (temp->next == head)
            { // If the next node is the head, there's no node after to delete
                printf("There is no node after this node.\n");
                return;
            }

            node *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("The info value is not found in the list.\n");
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
    do
    {
        printf("%d --> ", current->data);
        current = current->next;
    } while (current != head);
    printf("HEAD\n");
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
        printf("\n10. Exit.");
        printf("\nEnter your choice of operation: ");
        scanf("%d", &choice);

        if (choice == 10)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            insertAtBegin();
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
        default:
            printf("\nWrong input. Try again.\n");
        }
    }

    return 0;
}
