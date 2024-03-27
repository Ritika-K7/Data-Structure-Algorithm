//StackTop and StackBottom.
#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>
int isEmpty();
int isFull();


//creating stack-ADT
struct stack{
    int size;
    int top;
    int *arr;
};

int main()
{
    //creating Stack
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int*)malloc(sizeof(int));

    printf("Stack has been created successfully");

    printf("\nBefore pushing ,Full: %d\n",isFull(sp));
    printf("Before pushing ,Empty: %d\n",isEmpty(sp));   

    push(sp,76);
    push(sp,6);
    push(sp,56);
    push(sp,11);
    push(sp,56);
    push(sp,5);
    push(sp,73);
    push(sp,6);
    push(sp,36);
    push(sp,56);//------->pushed 10 value
    push(sp,46);// Stack Overflow since the size of the stack is 10

    // printf("After pushing ,Full: %d\n", isFull(sp));
    // printf("After pushing ,Empty: %d\n", isEmpty(sp));
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    // printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out
    // Run Peek
    // for (int j = 1; j <= sp->top + 1; j++)
    // {
    //     printf("The value at position %d is %d\n", j, peek(sp, j));
    // }
    //Run StackTop ,StackBottom
    printf("The Topmost value of this stack is %d\n",stackTop(sp));
    printf("The Bottommost value of this stack is %d\n",stackBottom(sp));

}
//Check Stack Empty
int isEmpty(struct stack*ptr)
{
    if(ptr->top==-1)
    {
        return 1;//True
    }
    else
    {
        return 0;//False
    }
}
//Check stack Full
int isFull(struct stack*ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;//True
    }
    else
    {
        return 0;//False
    }
}
//Push
void push(struct stack*ptr,int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow can not push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
//Pop
int pop(struct stack*ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else
    {
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
//StackTop
int stackTop(struct stack*sp)
{
    return sp->arr[sp->top];
}
//StackBottom
int stackBottom(struct stack*sp)
{
    return sp->arr[0];
}
