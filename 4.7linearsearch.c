#include<stdio.h>
void linearSearch(int arr[], int size, int ele) 
{
    int found = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == ele) 
        {
            printf("Element %d found at index %d\n", ele, i);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element %d not found in the array\n", ele);
    }
}

int main() 
{
    int size, ele,answer = 1;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Array: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    do
    {
        
        printf("Enter the element to search: ");
        scanf("%d", &ele);

        linearSearch(arr, size, ele);
        printf("Do you want to continue , if yes enter 1 : ");
        scanf("%d",&answer);
    }while(answer == 1);
    printf("Exiting...\n");
    return 0;
}
