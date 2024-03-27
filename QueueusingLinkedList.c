/*
#include<stdlib.h>
#include<stdio.h>


struct node
{
    int data;
    struct node*next;
};

struct Node *f = NULL;
struct Node *r = NULL;

int main(){
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;

}

void enqueue(struct node*f,struct node*r,int val)
{
    struct node*n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("Queue is Full\n");  //Full condition
    }
    else
    {
        n->data=val;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
    }
}
//Dequeue
int dequeue(struct node*f,struct node*r)
{
    int val=-1;
    struct node*ptr=f;
    if(f==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
    f=f->next;
    val=ptr->data;
    free(ptr);
    return val;
    }
}
//traversal
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
*/
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int val);
int dequeue();
void linkedListTraversal(struct node *ptr);

int main() {
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}

void enqueue(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is Full\n");  // Full condition
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) {
            f = r = n;
        } else {
            r->next = n;
            r = n;
        }
    }
}

// Dequeue
int dequeue() {
    int val = -1;
    struct node *ptr = f;
    if (f == NULL) {
        printf("Queue is Empty\n");
    } else {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

// Traversal
void linkedListTraversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


