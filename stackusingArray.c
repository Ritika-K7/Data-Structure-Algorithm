// Stack using an Array
#include <stdio.h>
#include <stdlib.h>
int isEmpty();
int isFull();

struct stack
{
    int size;
    int top;
    int *arr;
};

int main()
{
    // making stack
    /*
    struct stack s;
    s.size=80;
    s.top=-1;
    s.arr=(int*)malloc(s.size * sizeof(int));*/

    // making stack pointer
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an elemnt manually
    s->arr[0] = 7;
    s->arr[1] = 12;
    s->arr[2] = 3;
    s->arr[3] = 11;
    s->arr[4] = 13;
    s->arr[5] = 16;
    s->arr[6]=17;
    s->top++;

    // check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is Empty.");
    }
    else
    {
        printf("The stack is not empty.");
    }
    
    // check if stack is Full
    if (isFull(s))
    {
        printf("The stack is Full.");
    }
    else
    {
        printf("The stack is not Full.");
    }


    return 0;
}

// Condition for Empty stack.
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // implies TRUE
    }
    else
    {
        return 0; // implies FALSE
    }
}

// Condition for Full stack.
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // implies TRUE
    }
    else
    {
        return 0; // implies FALSE
    }
}