#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int q[MAX];
int front=-1,rear=-1;

void push(int data){
    if(front==0 && rear==MAX-1){
        printf("\nQueue Overflow!");
        return;
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else if(rear==MAX-1 && front!=0) rear=0;
    else{
        rear++;
    }
    q[rear]=data;
}

void pop(){
    if(front ==-1 || front>rear) printf("\nQueue Underflow!\n");
    else if(front==rear-1){
        printf("\nSingle element left in queue!\n");
        front++;
    }
    else front++;
}

void print(){
    int i;
    if(front==-1 || front>rear) printf("\nQueue is empty!\n");
    else{
        printf("\nElements of the queue are:\n");
        for(i=front;i<=rear;i++){
            printf("%d  ",q[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice,data;
    while(1){
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Print all the elements of the queue.");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter the element to push:");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            print();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nWrong choice");
        }
    }
    return 0;
}