// case 3: Inseting at the end -O(n)

#include <stdio.h>
#include <stdlib.h>
void linkedlist();
struct node *insertatEnd();

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

    // Calling function
    printf("before inserting at end\n");
    linkedlist(head);
    head = insertatEnd(head,12);
    printf("\nafter inserting at end\n");
    linkedlist(head);
    return 0;
}

// Traverasal : making function

void linkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// making function to insert node at End
struct node *insertatEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data=data;
    ptr->next = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}