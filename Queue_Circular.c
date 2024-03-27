#include<stdio.h>
#include<stdlib.h>
void enqueue();
int dequeue();
int isFull();
int isEmpty();

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int main()
{
    struct circularqueue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    //enqueue few elements
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    enqueue(&q,1);
    
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    printf("Dequeuing element %d\n", dequeue(&q)); 
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q,45);

    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    if(isFull(&q))
    {
        printf("Queue is Full.\n");
    }



}
//Enqueue
void enqueue(struct circularqueue*q,int val)
{
    if(isFull(q))
    {
        printf("circularQueue is FUll.");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}
//Dequeue
int dequeue(struct circularqueue*q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("circularQueue is Empty.");
    }
    else{
        q->f=(q->f+1)%q->size;
        a= q->arr[q->f];
    }
    return a;
}
//Full
int isFull(struct circularqueue*q)
{
    if((q->r+1)%(q->size)==q->f)
    {
        return 1;//True
    }
    return 0;//False
}
//Empty
int isEmpty(struct circularqueue*q)
{
    if(q->r==q->f)
    {
        return 1;//True
    }
    return 0;//False
}
