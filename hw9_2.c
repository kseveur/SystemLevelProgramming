#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return(node);
}

bool find(Node *node, int value)
{
    if(node == NULL)
    {
        return false;
    }
    
    if(node->data == value)
    {
        return true;
    }
    
    bool answer1 = find(node->left, value);
    bool answer2 = find(node->right, value);
    return answer1 || answer2;
}


int main()
{
    Node *tree = newNode(80);
    tree->left = newNode(42);
    tree->right = newNode(92);
    int findValue = 42;
    
    if(find(tree,findValue))
    {
        printf("\nThe value %d was found!", findValue);
    } else {
        printf("\nThe value %d was NOT found!", findValue);
    }
    
    findValue = 20;
    if(find(tree,findValue))
    {
        printf("\nThe value %d was found!\n", findValue);
    } else {
        printf("\nThe value %d was NOT found!\n", findValue);
    }
}

