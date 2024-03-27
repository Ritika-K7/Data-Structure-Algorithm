//insertion sort
#include<stdio.h>
#include<conio.h>
void insertionSort(int*A,int n);
void printfArray(int*A,int n);
int main()
{
    int A[]={12,54,65,7,23,9};
    int n=6;
    printfArray(A,n);
    insertionSort(A,n);
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
void insertionSort(int*A,int n)
{
    int temp,j;
    for(int i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0 &&A[j]>temp) //sort in acending order A[j]>key | sort in decending order A[j]<key
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}


