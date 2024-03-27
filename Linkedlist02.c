/*
Insertion Of Node in linked list
case 1: Inserting at beginning
case 2: Inserting in between
case 3: Inserting at the end
case 4: Inserting after a Node    */

// CASE 1: inserting at the begninning   - O(1)
//CASE 2: inserting in between    -O(n)

/*#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

int main()
{
    struct node* head;
    struct node* first;
    struct node* second;
    struct node* third;
    struct node* fourth;

    struct node*ptr;         //ptr stand for new elem which is to be inserted.

    head=malloc(sizeof(struct node));
    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third=malloc(sizeof(struct node));
    fourth=malloc(sizeof(struct node));
    ptr=malloc(sizeof(struct node));

    head->data=8;
    head->next=first;

    first->data=9;
    first->next=second;

    second->data=11;
    second->next=third;

    third->data=7;
    third->next=fourth;

    fourth->data=2;
    fourth->next=NULL;

    // printf("Before Insertion");
    // while(ptr!=NULL)
    // {

    //     printf("%d",ptr->data);
    //     ptr=ptr->next;
    // }

    //Inserting node at beginning

    ptr->data=1;
    ptr->next=head;
    head=ptr;

    printf("After inserting\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }



}
 */

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
    
    printf("Inserting in between at index\n");
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
