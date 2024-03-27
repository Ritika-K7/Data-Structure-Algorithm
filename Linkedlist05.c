// case: Inserting after a Node

#include <stdio.h>
#include <stdlib.h>
void linkedlist();
struct node *insertafter();

struct node
{
    int data;
    struct node *next; // self-referencing pointer
};

int main()
{
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

    // terminating the linked list
    third->data = 66;
    third->next = fourth;

    // terminating the linked list
    fourth->data = 56;
    fourth->next = NULL;

    // Callging function
    printf("Before insertion\n");
    linkedlist(head);

    head = insertafter(head, second, 99);
    printf("\nInsertion after a node\n");
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

//making function for insert after a Node
struct node *insertafter(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    
    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}