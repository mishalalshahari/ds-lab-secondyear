#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};



struct node* newNode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    if(data<node->data) node->left->data=data;
    else node->right->data=data;
    node->left=NULL;
    node->right=NULL;

    return (node);
}

void printPostorder(struct node*node){
    if(node==NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ",node->data);
}

int main(){
    struct node* node=newNode(1);
    node->left=newNode(2);
    node->right=newNode(3);
    node->left->left=newNode(4);
    node->left->right=newNode(5);
    printPostorder(node);
}