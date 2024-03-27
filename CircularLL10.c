#include <stdio.h>
#include <stdlib.h>
void linkedlist();
struct node*insertatfirst();

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
    head->data = 4;
    head->next = second;

    // linking second & third node
    second->data = 3;
    second->next = third;

    // linking third node & fourth
    third->data = 6;
    third->next = fourth;

    // terminating the linked list
    fourth->data = 1;
    fourth->next = head;

    // Calling function
    printf("Traversing circular LL");
    linkedlist(head);

    printf("inserion at first");
    head=insertatfirst(head,54);
    linkedlist(head);
    return 0;
}

// Traverasal

void linkedlist(struct node *head)
{
    struct node *ptr = head;
   do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
     while (ptr != head);
}

//Insertion at beginning 

struct node*insertatfirst(struct node*head,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node*p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
};

