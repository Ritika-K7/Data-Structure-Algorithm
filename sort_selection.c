//Selection sort
#include<stdio.h>
void selectionSort(int*A,int n);
void printfArray(int*A,int n);
int main()
{
    int A[]={3,5,2,13,12};
    int n=5;
    printfArray(A,n);
    selectionSort(A,n);
    printfArray(A,n);
}
void printfArray(int* A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectionSort(int *A,int n)
{
    int min ,temp;  //min[0]
    printf("Running Selection sort....\n");
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }

}