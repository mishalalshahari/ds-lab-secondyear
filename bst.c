#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left,*right;
};

struct node *newNode(int item){
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key){
    if(node==NULL) return newNode(key);
    if(key<node->key) node->left=insert(node->left,key);
    else if(key>node->key) node->right=insert(node->right,key);
    return node;
}

int main(){
    struct node *root=NULL;
    int i,arr[20],n;
    printf("Enter the no of elements present in BST: ");
    scanf("%d",&n);
    printf("\nEnter the elements of BST: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    root=insert(root,arr[0]);
    for(i=1;i<n;i++) insert(root,arr[i]);
    printf("\nInorder traversal of BST:\n");
    inorder(root);
    printf("\n");
    return 0;
}