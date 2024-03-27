#include <stdio.h>
#include <stdlib.h>
int isEmpty();
int isFull();

// creating stack-ADT
struct stack
{
    int size;
    int top;
    int *arr;
};

int main()
{
    // creating Stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int));

    printf("Stack has been created successfully");

    printf("\nBefore pushing ,Full: %d\n", isFull(sp));
    printf("Before pushing ,Empty: %d\n", isEmpty(sp));

    push(sp, 56);
    push(sp, 6);
    push(sp, 56);
    push(sp, 11);
    push(sp, 56);
    push(sp, 5);
    push(sp, 73);
    push(sp, 6);
    push(sp, 36);
    push(sp, 56); 
    push(sp, 46); 
    push(sp,3);
    push(sp,11);
    // printf("After pushing ,Full: %d\n", isFull(sp));
    // printf("After pushing ,Empty: %d\n", isEmpty(sp));
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!

    // Run Peek
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
}

// Check Stack Empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // True
    }
    else
    {
        return 0; // False
    }
}
// Check stack Full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // True
    }
    else
    {
        return 0; // False
    }
}
// Push
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow can not push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
// Pop
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// Peek
int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top- i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}
