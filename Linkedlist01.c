// Creation and Traversal
#include <stdio.h>
#include <stdlib.h>
void linkedlist();

struct node
{
    int data;
    struct node*next;    // self-referencing pointer
};

 

int main()
{
    /*method1
    struct node* head ;
    struct node* second ;
    struct node* third

    head=(struct node*)malloc(sizeof(struct node));
    second =(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node)) ;
    */

    // Method 2
    // allocate memmory  for nodes of linked list in HEAP!!
    // heap because it is a dynamic memory allocation
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    // linking first and second node
    head->data = 7;
    head->next = second;

    // linking second & third node
    second->data = 11;
    second->next = third;

    // linking third node & fourth
    third->data = 66;
    third->next = fourth;

    // terminating the linked list
    fourth->data = 56;
    fourth->next = NULL;




    // Callging function
    linkedlist(head);
    return 0;
}

// Traverasal
// making function 
void linkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
            ptr = ptr->next;
    }
}

