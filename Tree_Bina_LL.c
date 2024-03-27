#include<stdio.h>
#include<stdlib.h>

struct node*createNode(int);
struct node{
    int data;
    struct node*left;
    struct node*right;
};
int main(){

    // Constructing the node using function
    struct node*p=createNode(2);
    struct node*p1=createNode(1);
    struct node*p2=createNode(4);

    // Linking the root node with left & right children
    p->left=p1;
    p->right=p2;

    return 0;
}

struct node* createNode(int data)
{
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}