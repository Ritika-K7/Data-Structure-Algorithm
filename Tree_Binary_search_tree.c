//Binary Search Tree

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
    struct node*p=createNode(5);
    struct node*p1=createNode(3);
    struct node*p2=createNode(6);
    struct node*p3=createNode(1);
    struct node*p4=createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left & right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    //Call Function
    inOrder(p);
    printf("\ncheck if the tree is BST:%d",isBST(p));
    return 0;
}

//Check if tree is BST
int isBST(struct node*root)
{
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;//False
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;//False
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1; //TRUE tree is BST
    }
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