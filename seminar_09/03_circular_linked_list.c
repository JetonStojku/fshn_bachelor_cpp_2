#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a circular linked list
typedef struct CircleListNode
{
    int data;
    struct CircleListNode *next;
} CircleListNode;

// Function to create a new circular linked list node
CircleListNode *createNode(int data)
{
    CircleListNode *newNode = (CircleListNode *)malloc(sizeof(CircleListNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a new node to the end of the circular linked list
void appendNode(CircleListNode **head, int data)
{
    CircleListNode *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
    }
    else
    {
        CircleListNode *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

// Function to remove a node from the circular linked list
void removeNodeByValue(CircleListNode **head, int value)
{
    if (*head == NULL)
    {
        return; // List is empty
    }

    CircleListNode *current = *head;
    CircleListNode *prev = NULL;

    // Find the node with the value to remove
    do
    {
        if (current->data == value)
        {
            if (current == *head)
            {
                *head = current->next;
            }

            if (prev != NULL)
            {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *head);
}

// Function to print all elements in the circular linked list
void printList(CircleListNode *head)
{
    CircleListNode *current = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    // Create a new circular linked list
    CircleListNode *list = NULL;
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);

    // Print all values in the circular linked list
    printList(list);

    // Remove the node with value 3
    removeNodeByValue(&list, 3);

    // Print all values in the circular linked list
    printList(list);

    return 0;
}
