#include <stdio.h>

void insert(int *,int,int);
void del(int *,int);
void traverse(int *,int);

int main(void) {
	int arr[10],i,a,b,c;
	printf("Enter 5 elements of the array:\n");
	for(i=0;i<5;i++){
	    scanf("%d",&arr[i]);
	}
	printf("\nEnter the position and value to insert:");
	scanf("%d%d",&a,&b);
	insert(arr,a,b);
	printf("\nArray after insertion:");
	traverse(arr,6);
	printf("\nEnter the position to delete:");
	scanf("%d",&c);
	del(arr,c);
	printf("\nArray after deletion:");
	traverse(arr,5);
	return 0;
}

void traverse(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insert(int *arr,int pos,int num){
    int i;
    for(i=6;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[i]=num;
}

void del(int *arr,int pos){
    int i;
    for(i=pos-1;i<5;i++){
        arr[i]=arr[i+1];
    }
}
