#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a doubly linked list
typedef struct DoubleListNode
{
    int data;
    struct DoubleListNode *prev;
    struct DoubleListNode *next;
} DoubleListNode;

// Function to create a new doubly linked list node
DoubleListNode *createNode(int data)
{
    DoubleListNode *newNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a new node to the end of the doubly linked list
void appendNode(DoubleListNode **head, int data)
{
    DoubleListNode *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        DoubleListNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to remove a node from the doubly linked list
void removeNode(DoubleListNode **head, int value)
{
    DoubleListNode *current = *head;
    while (current != NULL && current->data != value)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        else
        {
            *head = current->next;
        }
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        free(current);
    }
}

// Function to print all elements in the doubly linked list
void printList(DoubleListNode *head)
{
    printf("Doubly Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Create a new doubly linked list
    DoubleListNode *list = NULL;
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);

    // Print all values in the doubly linked list
    printList(list);

    return 0;
}
