#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

void inOrder(struct node*);
struct node*createNode(int);

int main(){
    // Constructing the node using functionS
    struct node*p=createNode(4);
    struct node*p1=createNode(1);
    struct node*p2=createNode(6);
    struct node*p3=createNode(5);
    struct node*p4=createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root node with left & right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    //Call Function
    inOrder(p);
    return 0;
}
//Inorder
void inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);      
    }

}
//Node Creation
struct node* createNode(int data)
{
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}