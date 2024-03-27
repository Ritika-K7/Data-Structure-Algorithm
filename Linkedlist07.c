// Deletion in Linkedlist
//  case 1: Deleting the first node
//  case 2: Deleting a node in between
//  case 3: Deleting the last node
//  case 4: Deleting a node with given value(first node with that value -8(delete this),8,8,8,)

// case 1: Deleting the first node

#include <stdio.h>
#include <stdlib.h>
void Linkedlisttraversal();
struct node*deleteFirst();

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node)); // 7,11,66,56
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("The linked list before delection");
    printf("\n");
    Linkedlisttraversal(head);

    printf("The linked list after delection");
    printf("\n");
    head = deleteFirst(head);
    Linkedlisttraversal(head);
    return 0;
}
// traversal function
void Linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// deleting the first node
struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}