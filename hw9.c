#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXINPUT 100



struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

void insertBack(Node *temp, int data)
{
    Node *current = temp;
    Node *previous = temp;
    
    Node *new1 = (Node *)malloc(sizeof(Node));
    new1->data = data;
    
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    
    new1->next = current->next;
    current->next = new1;
    new1->prev = current;
}

void printData(Node* temp)
{
    Node *current = temp;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main ()
{
    char input[MAXINPUT] = "";
    Node *doubly_list = (Node *)malloc(sizeof(Node));
    doubly_list->next = NULL;
    doubly_list->prev = NULL;
    
    int val;
    int loop = 1;
    int count = 0;
    while (loop)
    {
        printf ("\nEnter an integer to add, or type 'Q' to end: ");
        scanf ("%s", input);
        if(!isdigit(input[0]))
        {
            loop = 0;
            exit(0);
        }

        input[0] = atoi(input);
        if(count == 0)
        {
            doubly_list->data=input[0];
        } else {
            insertBack(doubly_list, input[0]);
        }
        
        printf("The List is currently: ");
        printData(doubly_list);
        count++;
        
    }
    
}

