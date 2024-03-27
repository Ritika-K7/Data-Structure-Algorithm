// Stack Operations using Linked List (PART-2) | Peek,Stacktop,StackBottom.
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
    struct node *top=NULL;
    // push
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    linkedlisttraversal(top);
    printf("Value at position 1 is : %d",peek(1));
    return 0;
}
// Peek
int peek(int pos)
{
     struct node *top=NULL;
    struct node* ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return (ptr->data);
    }
    else
    {
        return -1; // Assuming there is NO negative number in stack.
    }
}
//StackTop
int stacktop()
{
    struct node *top=NULL;
    printf("The stack top is:");
    return top->data;
}
//StackBottom
int stackbottom(struct node*ptr)
{
    if(ptr==NULL)
    {
        printf("The stack bottom is:");
        return ptr->data;       
    }
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