#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n~~~~MENU~~~~");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at last");
        printf("\n3. Insert at any random position");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from last");
        printf("\n6. Delete the node after the given data");
        printf("\n7. Search");
        printf("\n8. Display");
        printf("\n9. Exit\n");
        printf("\n Enter your choice: ");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf(" Please Enter valid choice...! ");
        }
    }
}

void insertion_beginning()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\n OVERFLOW");
    else
    {
        printf("\n Enter item(data) value : ");
        scanf("%d", &item);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\n Node inserted.\n");
    }
}

void insertion_last()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        printf("\n Enter value : ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\n Node inserted.\n");
}

void insertion_specified()
{
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = head;
        printf(" Enter the location : ");
        scanf("%d", &loc);
        for (i = 2; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements : ", loc);
                return;
            }
        }
        printf(" Enter value : ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\n Node inserted : \n");
    }
}

void deletion_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\n Node deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\n Node deleted\n");
    }
}

void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\n Node deleted\n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\n Node deleted\n");
    }
}

void deletion_specified()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\n Can't delete\n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\n Node deleted\n");
    }
}

void display()
{
    struct node *ptr;
    printf("\n Printing values are :: \n");
    ptr = head;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n Empty List.!");
    }
    else
    {
        printf("\n Enter item which you want to search? : ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("\n Item found at location : %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\n Item not found.!\n");
        }
    }
}