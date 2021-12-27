#include <stdio.h>
#include <stdlib.h>

int arr[100], t;

void linearSearch();
void binarySearch();

int main(){
    int i;
    printf("\nEnter number of element in array : ");
    scanf("%d", &t);
    printf("\nEnter array Elements : ");
    for (i = 0; i < t; i++) scanf("%d", &arr[i]);
    printf("\nEntered Array is : ");
    for (i = 0; i < t; i++) printf("%d ", arr[i]);
    int choice;
    while (1){
        printf("\n\n************** MAIN MENU ***************\n");
        printf("\n\t Perform Search Opration \n");
        printf("\n========================================\n");
        printf("\nPlease! Select a valid choice.\n\nChoices are : \n\n1. Linear Search \n2. Binary Search \n3. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linearSearch();
            break;
        case 2:
            binarySearch();
            break;
        case 3:
            exit(1);
            break;
        }
    }
    return 0;
}

void linearSearch()
{
    int search;
    int count = 0;
    int c;
    printf("Enter a number to search\n");
    scanf("%d", &search);
    for (c = 0; c < t; c++)
    {
        if (arr[c] == search)
        {
            printf("%d is present at location %d.", search, c + 1);
            count++;
        }
    }
    if (count == 0)
        printf("%d isn't present in the array.", search);
}

void binarySearch(){
    int search, middle;
    printf("Enter value to find : ");
    scanf("%d", &search);

    int first = 0;
    int last = t;
    middle = (first + last) / 2;

    while (first < last)
    {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search)
        {
            printf("%d found at location : %d", search, middle + 1);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first >= last)
        printf("Not found! %d isn't present in the list.", search);
}