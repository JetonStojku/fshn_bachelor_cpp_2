#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a tree
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to print all elements in the tree
void printTree(TreeNode *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

// Function to find all odd elements on leaf nodes of the tree
void findOddElementsInLeaf(TreeNode *root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL && root->data % 2 != 0)
        {
            printf("%d ", root->data);
        }
        findOddElementsInLeaf(root->left);
        findOddElementsInLeaf(root->right);
    }
}

int main()
{
    // Create a new tree
    TreeNode *tree = createTreeNode(1);
    tree->left = createTreeNode(2);
    tree->right = createTreeNode(3);
    tree->left->left = createTreeNode(4);
    tree->left->right = createTreeNode(5);

    // Print elements of the tree
    printf("Tree: ");
    printTree(tree);
    printf("\n");

    // Find all odd elements on leaf of the tree
    printf("Odd elements on leaf: ");
    findOddElementsInLeaf(tree);
    printf("\n");

    return 0;
}
