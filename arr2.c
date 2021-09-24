/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void ArrayPrint(int *,int);
int MyMax(int *);
int SecLargest(int *);
int main()
{
    int a[]={3,6,7,8};
    int max,sl;
    ArrayPrint(a,3);
    max=MyMax(a);
    printf("\nmaximum element = %d",max);
    sl=SecLargest(a);
    printf("\nsecond largest element = %d",sl);
    return 0;
}
int MyMax(int *n){
    int max,i;
    max=n[0];
    for(i=0;i<4;i++){
        if(max<n[i])
        max=n[i];
    }
    return max;
}
int SecLargest(int *n){
    int max,i,sl=0;
    max=n[0];
    for(i=0;i<4;i++){
        if(max<n[i])
        max=n[i];
    }
    for(i=0;i<4;i++){
        if(n[i]!=max){
            if(max>n[i])
            sl=n[i];
        }
    }
    return sl;
}
void ArrayPrint(int *n,int a){
    int i;
    for(i=0;i<a;i++)
    printf("%d\t",n[i]);
}
