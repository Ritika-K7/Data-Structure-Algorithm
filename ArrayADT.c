#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

int main(){
    struct myArray marks;
    creatmyArray(&marks,100,5);
    setValue(&marks);
    show(&marks); 
    
}

//Creating a function called creatmyArray()
void creatmyArray(struct myArray*a,int tsize,int usize)
{   
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr=(int*)malloc(tsize*(sizeof(int)));
    //OR
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize*(sizeof(int)));
}

//Displaying Array
void show(struct myArray*a)
{
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }

}

//Enter the elements of Array
void setValue(struct myArray*a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter the elements%d",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;

        // printf("%d\n",(a->ptr)[i]);

    }

}