// case 3: Deleting the last node

#include <stdio.h>
#include <stdlib.h>
void Linkedlisttraversal();
struct node *deleteLast();

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
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

    printf("The linked list after delection of last Node");
    head = deleteLast(head);
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

// deleting the last node
struct node *deleteLast(struct node * head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}