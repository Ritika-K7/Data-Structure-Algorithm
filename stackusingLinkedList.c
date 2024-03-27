// Stack Operations using Linked List (PART-1)
#include <stdio.h>
#include <stdlib.h>
void linkedlisttraversal();
struct node *push();

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *top = NULL;
    // push
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 66);
    top = push(top, 9);
    // pop
    int element = pop(&top);
    printf("Popped element is %d\n", element);

    linkedlisttraversal(top);
    return 0;
}
// Empty
int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1; // True
    }
    else
    {
        return 0; // False
    }
}
// FULL
int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node)); // p is allocated memory dynamicall
    {
        if (p == NULL)
        {
            return 1; // True->not able to allocate the memory dynamical means that the heap is full.
        }
        else
        {
            return 0; // False
        }
    }
}
// Push
struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
// Pop
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
// Traversal
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
