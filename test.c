
#include <stdio.h>
#include <stdlib.h>
void linkedlisttraversal();
struct node *insertatfirst();
struct node *insertatIndex();

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

    // linking third node & fourth
    third->data = 66;
    third->next = fourth;

    // terminating the linked list
    fourth->data = 56;
    fourth->next = NULL;

    // Calling function
    printf("Before Insertion\n");
    linkedlisttraversal(head);
    
//     printf("\nAfter Insertion\n");
//    head = insertatfirst(head, 88);
//     linkedlisttraversal(head);
    
    printf("\nInserting in between at index\n");
    head=insertatIndex(head,90,1);
    linkedlisttraversal(head);
    return 0;
}

// Traverasal : Making function for traversal
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// making function to insert node at beginning
struct node *insertatfirst(struct node *head, int data) // struct node* :- data type for head & also for function
{                                                       // int :- data type for data value
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
}

//making function to insert in between (we are going to use index value of LL)
struct node *insertatIndex(struct node *head, int data,int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}