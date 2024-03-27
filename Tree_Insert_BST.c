//Search in BST 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

void inOrder(struct node*);
struct node*createNode(int);
struct node*search(struct node*,int);

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
    //Call Function for Insert
    insert(p, 16);
    printf("%d", p->right->right->data);
    return 0;
    
   
}
//Insert in BST
void insert(struct node *root, int key)
{
   struct node *prev = NULL;
   while(root!=NULL)
   {
       prev = root;
       if(key==root->data)
       {
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data)
       {
           root = root->left;
       }
       else
       {
           root = root->right;
       }
   }
   struct node* new = createNode(key);
   if(key<prev->data)
   {
       prev->left = new;
   }
   else
   {
       prev->right = new;
   }
}
//Search Key in BST
struct node* search(struct node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
     else if(key>root->data)
    {
        return search(root->right,key);
    }

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