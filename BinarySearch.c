#include <stdio.h>
int binarySearch(int val, int beg, int last, int arr[])
{
    if (beg > last)
        return -1;
    int mid = (beg + last) / 2;
    if (arr[mid] == val)
        return mid;
    else if (arr[mid] < val)
    {
        return binarySearch(val, mid + 1, last, arr);
    }
    else
    {
        return binarySearch(val, beg, mid - 1, arr);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int val = 3;
    int ans = binarySearch(val, 0, 4, a);
    if (ans != -1)

    {
        printf("%d found at %d position", val, ans + 1);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
