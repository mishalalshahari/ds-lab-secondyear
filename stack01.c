#include<stdio.h>
#include<stdlib.h> // for exit() function

#define MAX 5

int sarr[MAX];
int top = -1;

int isFull(){
    if(top==MAX-1)return 1;
    else return 0;
}

int isEmpty(){
    if(top== -1)return 1;
    else return 0;
}

void push(int data){
    int i;
    if(isFull()){
        printf("Stack Overflow.\n");
        exit(1);
    }
    top++;
    // loop is to shift elements and place the pushed element at 0th index
    for(i=top;i>0;i--){
        sarr[i]=sarr[i-1];
    }
    sarr[0]=data;
}

int pop(){
    int i,value;
    value=sarr[0];
    for(i=0;i<top;i++){
        sarr[i]=sarr[i+1];
    }
    top--;
    return value;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow.\n");
        exit(1);
    }
    return sarr[0];
}

void print(){
    int i;
    if(top==-1){
        printf("Stack Underflow");
        exit(1);
    }
    for(i=0;i<=top;i++){
        printf("%d  ",sarr[i]); //it will print the elements in reverse order i.e. last pushed element at 0th index
    }
    printf("\n");
}

int main(){
    int choice,data;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element of the stack.\n");
        printf("4. Print all the elements of the stack.\n");
        printf("5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            data = pop();
            printf("Deleted element is %d.\n",data);
            break;
            case 3:
            printf("The topmost element of the stack is %d.\n",peek());
            break;
            case 4:
            print();
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice.\n");
        }
    }
    return 0;
}