/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n,arr[10],pos[10],i,j=0,key,count=0;
    printf("Enter the no. of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to find: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i]==key){
            count++;
            pos[j]=i;
            j++;
        }
    }
    if(count==0){
        printf("\n\nNo such element is present.");
    }
    else{
        printf("\nElement found %d times.",count);
        printf("\nPosition in array at which the element is present: ");
        for(i=0;i<j;i++){
            printf("%d ",pos[i]+1);
        }
    }

    return 0;
}
