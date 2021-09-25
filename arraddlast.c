#include <stdio.h>

void ArrayAddLast(int *,int,int);
void ArrayPrint(int *,int);


int main()
{
    int num,A[20];
    A[0]=12;
    printf("Enter the number to added at last position:");
    scanf("%d",&num);
    ArrayAddLast(A,1,num);
    ArrayPrint(A,2);

    return 0;
}
void ArrayAddLast(int *Arr,int tc,int n){
    int index;
    index=tc-1;
    index=index+1;
    Arr[index]=n;
}
void ArrayPrint(int *num,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d  ",num[i]);
    }
}
