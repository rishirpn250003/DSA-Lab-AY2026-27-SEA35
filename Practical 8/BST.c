#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
struct Node
{     
    char name[30];     
    char mobile[15];     
    struct Node *left;     
    struct Node *right;
};
/* Create a new node */ 
struct Node* createNode(char name[], char mobile[])
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);     
    strcpy(newNode->mobile, mobile);
    newNode->left = NULL;     
    newNode->right = NULL;
    return newNode;
}
/* Insert into BST */ 
struct Node* insert(struct Node *root, char name[], char mobile[])
{     
    if (root == NULL)         
    return createNode(name, mobile);
    if (strcmp(name, root->name) < 0)         
    root->left = insert(root->left, name, mobile);     
    else         
    root->right = insert(root->right, name, mobile);
    return root;
}
/* Inorder */ 
void inorder(struct Node *root)
{     if (root != NULL)
    {
        inorder(root->left);         
        printf("%s - %s\n", root->name, root->mobile);         
        inorder(root->right);
    }
}
/* Preorder */ 
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%s - %s\n", root->name, root->mobile);         
        preorder(root->left);         
        preorder(root->right);
    }
}
/* Postorder */ void postorder(struct Node *root)
{     if (root != NULL)
    {
        postorder(root->left);         
        postorder(root->right);         
        printf("%s - %s\n", root->name, root->mobile);
    }
}
/* Search */ 
void search(struct Node *root, char name[])
{     if (root == NULL)
    {
        printf("\nPerson not found!\n");         
        return;
    }
    if (strcmp(name, root->name) == 0)
    {
        printf("\nPerson Found!\n");         
        printf("Name   : %s\n", root->name);         
        printf("Mobile : %s\n", root->mobile);         
        return;
    }
    if (strcmp(name, root->name) < 0)         
    search(root->left, name);     
    else         
    search(root->right, name);
} 
int main()
{    
     
    struct Node *root = NULL;     
    int choice;     
    char name[30];     
    char mobile[15];    
     while (1)
    {
        printf("\n============================\n");         
        printf(" ONLINE DIRECTORY SYSTEM\n");         
        printf("============================\n");
        printf("1. Insert\n");         
        printf("2. Display\n");         
        printf("3. Search\n");         
        printf("4. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);         
        switch (choice)
        {             case 1:
                printf("\nEnter Name: ");                 
                scanf("%s", name);                 
                printf("Enter Mobile Number: ");                 
                scanf("%s", mobile);                 
                root = insert(root, name, mobile);                 
                printf("\nPerson added successfully!\n");
                break;             
                case 2:                 
                if (root == NULL)
                {
                    printf("\nDirectory is empty!\n");
              }                 else
                {
                    printf("\n--- INORDER ---\n");      

                    inorder(root);                    
                     printf("\n--- PREORDER ---\n");                     
                     preorder(root);                     
                     printf("\n--- POSTORDER ---\n");                     
                     postorder(root);
                }                 
                break;             
                case 3:
                if (root == NULL)
                {  printf("\nDirectory is empty!\n");
                }
                else
                {
                    printf("\nEnter name to search: ");                     
                    scanf("%s", name);                     
                    search(root, name);
                }                 
                break;             
                case 4:
                printf("\nProgram exited successfully.\n");
                exit(0);             
                default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}