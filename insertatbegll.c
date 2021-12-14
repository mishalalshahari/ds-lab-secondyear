#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

struct node *newNode(int num){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=num;
    node->next=NULL;
    return node;
}

void displayList(){
    struct node *temp;
    if(head == NULL) return;
    else{
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n", temp->data);   // prints the data of current node
            temp = temp->next;                 // advances the position of current node
        }
    }
} 

int main(){
    int num;
    repeat:
    scanf("%d",&num);
    if(num>-1){
        insertAtBeg(num);
    }
    goto repeat;
    displayList();
    return 0;
}