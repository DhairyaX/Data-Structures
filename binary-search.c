#include <stdio.h>


int BS(int a[], int n ,int x)
{
    int start = 0;
    int end = n - 1;
    while (start<= end) {
        int mid = start + (end - start) / 2;
      
        if (a[mid] == x)
            return mid;
       
        if (a[mid] < x)
            start = mid + 1;
        
        else
            end = mid - 1;
    }
   
    return -1;
}


int main() {
    int a[] = {2, 5, 7, 10, 15, 18, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int x ;
    printf("enter element to be searched");
    scanf("%d",&x);
    int result = BS(a, n, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");
    return 0;
}
