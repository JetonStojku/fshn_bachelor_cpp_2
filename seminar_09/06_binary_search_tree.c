#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a binary search tree
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

// Function to insert a value into a binary search tree
TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createTreeNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to remove a value from a binary search tree
TreeNode *remove(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = remove(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = remove(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            TreeNode *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

// Function to print all elements in the binary search tree (in-order traversal)
void printTree(TreeNode *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void printVisualizedTree(TreeNode *root, int depth)
{
    if (root != NULL)
    {
        printVisualizedTree(root->right, depth + 1);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("%d\n", root->data);
        printVisualizedTree(root->left, depth + 1);
    }
}

int main()
{
    // Create a new binary search tree
    TreeNode *tree = NULL;
    tree = insert(tree, 4);
    tree = insert(tree, 2);
    tree = insert(tree, 1);
    tree = insert(tree, 3);
    tree = insert(tree, 5);
    tree = insert(tree, 6);
    tree = insert(tree, 7);

    // Print elements of the binary search tree
    printf("Binary Search Tree: ");
    printTree(tree);
    printf("\n");
    printf("Visualized Tree: \n");
    printVisualizedTree(tree, 0);
    printf("\n");

    // Remove elements from the binary search tree
    tree = remove(tree, 5);

    // Print elements of the binary search tree
    printf("Binary Search Tree: ");
    printTree(tree);
    printf("\n");
    printf("Visualized Tree: \n");
    printVisualizedTree(tree, 0);
    printf("\n");

    return 0;
}
