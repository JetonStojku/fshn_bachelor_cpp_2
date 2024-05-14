#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a circular doubly linked list
typedef struct CircleDoubleListNode
{
    int data;
    struct CircleDoubleListNode *prev;
    struct CircleDoubleListNode *next;
} CircleDoubleListNode;

// Function to create a new circular doubly linked list node
CircleDoubleListNode *createNode(int data)
{
    CircleDoubleListNode *newNode = (CircleDoubleListNode *)malloc(sizeof(CircleDoubleListNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a new node to the end of the circular doubly linked list
void appendNode(CircleDoubleListNode **head, int data)
{
    CircleDoubleListNode *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    else
    {
        CircleDoubleListNode *tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Function to remove a node from the circular doubly linked list
void removeNode(CircleDoubleListNode **head, int data)
{
    if (*head == NULL)
    {
        return; // List is empty
    }

    CircleDoubleListNode *current = *head;
    CircleDoubleListNode *toDelete = NULL;

    // Find the node with the data to remove
    do
    {
        if (current->data == data)
        {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (toDelete == NULL)
    {
        return; // Data not found in the list
    }

    if (toDelete == *head)
    {
        *head = (*head)->next;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    free(toDelete);
}

// Function to print all elements in the circular doubly linked list
void printList(CircleDoubleListNode *head)
{
    CircleDoubleListNode *current = head;
    printf("Circular Doubly Linked List: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    // Create a new circular doubly linked list
    CircleDoubleListNode *list = NULL;
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);

    // Print all values in the circular doubly linked list
    printList(list);

    // Remove the node with data 3
    removeNode(&list, 3);

    // Print all values in the circular doubly linked list
    printList(list);

    return 0;
}
