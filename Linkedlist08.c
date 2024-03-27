//case 2: Deleting a node in between OR at an index

#include <stdio.h>
#include <stdlib.h>
void Linkedlisttraversal();
struct node *deleteatindex();

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
    head = deleteatindex(head, 2);
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

// deleting the elem at a given index
struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}