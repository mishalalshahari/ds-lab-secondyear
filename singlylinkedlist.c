#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insertBeg();
void insertEnd();
void insertPos();
void deleteBeg();
void deleteEnd();
void deletePos();

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
int main()
{
    int choice;
    while (1)
    {

        printf("\n~~~~MENU~~~~\n");
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert at the beginning");
        printf("\n4.Insert at the end");
        printf("\n5.Insert at specified position");
        printf("\n6.Delete from beginning");
        printf("\n7.Delete from the end");
        printf("\n8.Delete from specified position");
        printf("\n9.Exit");
        printf(" Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertBeg();
            break;
        case 4:
            insertEnd();
            break;
        case 5:
            insertPos();
            break;
        case 6:
            deleteBeg();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deletePos();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\nWrong Choice:n");
            break;
        }
    }
    return 0;
}

void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Out of Memory Space:\n");
        exit(0);
    }
    printf("\n Enter the data value for the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n List is empty. \n");
        return;
    }
    else
    {
        ptr = start;
        printf("\n The List elements are : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Out of Memory Space : \n ");
        return;
    }
    printf("\n Enter the data value for the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Out of Memory Space : \n");
        return;
    }
    printf("\n Enter the data value for the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos()
{
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Out of Memory Space : \n");
        return;
    }
    printf("\n Enter the position for the new node to be inserted : ");
    scanf("%d", &pos);
    printf("\n Enter the data value of the node : ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 0, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("\n Position not found:[Handle with care]\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_begin()
{
    struct node *ptr;
    if (ptr == NULL)
    {
        printf("\n List is Empty : \n");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\n The deleted element is : %d ", ptr->data);
        free(ptr);
    }
}

void delete_end()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\n List is Empty : ");
        exit(0);
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        printf("\n The deleted element is : %d ", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\n The deleted element is : %d ", ptr->data);
        free(ptr);
    }
}

void delete_pos()
{
    int i, pos;
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\n The List is Empty : \n");
        exit(0);
    }
    else
    {
        printf("\n Enter the position(index value) of the node to be deleted : ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            ptr = start;
            start = start->next;
            printf("\n The deleted element is : %d ", ptr->data);
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    printf("\n Position not Found : \n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("\n The deleted element is : %d ", ptr->data);
            free(ptr);
        }
    }
}