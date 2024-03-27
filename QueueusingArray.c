#include<stdio.h>
#include<stdlib.h>
void enqueue();
int dequeue();
int isFull();
int isEmpty();

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int main()
{
    struct queue q;
    q.size=4;
    q.f=q.r=0;
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
void enqueue(struct queue*q,int val)
{
    if(isFull(q))
    {
        printf("Queue is FUll.");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
//Dequeue
int dequeue(struct queue*q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("Queue is FUll.");
    }
    else{
        q->f++;
        a= q->arr[q->f];
    }
    return a;
}
//Full
int isFull(struct queue*q)
{
    if(q->r==q->size-1)
    {
        return 1;//True
    }
    return 0;//False
}
//Empty
int isEmpty(struct queue*q)
{
    if(q->r==q->f)
    {
        return 1;//True
    }
    return 0;//False
}