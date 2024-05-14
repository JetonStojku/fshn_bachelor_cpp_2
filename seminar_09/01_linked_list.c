#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a list
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

// Function to create a new list node
ListNode *createNode(int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a new node to the end of the list
void appendNode(ListNode **head, int data)
{
    ListNode *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ListNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print all elements in the list
void printList(ListNode *head)
{
    printf("List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to remove a node from the list
void removeNode(ListNode **head, int value)
{
    ListNode *current = *head;
    ListNode *prev = NULL;

    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        // Value not found in the list
        return;
    }

    if (prev == NULL)
    {
        // The node to be removed is the head
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}

// Function to find all odd elements in the list
void findOddElements(ListNode *head)
{
    printf("Odd elements: ");
    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            printf("%d ", head->data);
        }
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Create a new list
    ListNode *list = NULL;
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);

    // Print all values on the list
    printList(list);

    // Find all odd elements in the list
    findOddElements(list);

    // Remove the node with value 3
    removeNode(&list, 3);
    printList(list);

    return 0;
}
