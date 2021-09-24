#include <stdio.h>

int main()
{
    int i,n,arr[30];
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\narr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe elements in the array are:\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
