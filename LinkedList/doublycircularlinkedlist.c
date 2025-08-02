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
    newnode->next = newnode->prev = NULL;
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        node *last = head->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
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

    node *temp = head;
    do
    {
        if (temp->data == info)
        {
            if (temp == head)
            {
                insertAtBegin();
            }
            else
            {
                newnode->prev = temp->prev;
                newnode->next = temp;
                temp->prev->next = newnode;
                temp->prev = newnode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("The info value is not found in the list\n");
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
            newnode->prev = temp;
            temp->next->prev = newnode;
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
        node *last = head->prev;
        node *temp = head;
        last->next = head->next;
        head->next->prev = last;
        head = head->next;
        free(temp);
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
        node *last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
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

    node *curr = head;

    // Special case: when head is the node where we want to delete the previous node
    if (head->data == info)
    {
        node *last = head->prev; // Get the last node
        if (last == head)
        { // If there is only one node in the list
            printf("No node before head\n");
            return;
        }

        node *toDelete = last;
        last->prev->next = head;
        head->prev = last->prev;
        free(toDelete);
        return;
    }

    // Traverse to find the node with 'info'
    do
    {
        if (curr->data == info)
        {
            node *toDelete = curr->prev;
            if (toDelete == head)
            { // If the node before is head
                head = head->next;
            }
            toDelete->prev->next = curr;
            curr->prev = toDelete->prev;
            free(toDelete);
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("The info value is not found in the list.\n");
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

    node *curr = head;

    do
    {
        if (curr->data == info)
        {
            node *toDelete = curr->next;
            if (toDelete == head)
            { // If the next node is head, no node exists after
                printf("No node after, as the next node is head.\n");
                return;
            }
            curr->next = toDelete->next;
            toDelete->next->prev = curr;
            free(toDelete);
            return;
        }
        curr = curr->next;
    } while (curr != head);

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
