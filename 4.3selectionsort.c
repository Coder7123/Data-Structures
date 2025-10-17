#include<stdio.h>

void display(int arr[], int n) 
{
    for(int k = 0; k < n; k++) 
    {
        printf("%d ", arr[k]);
    }
}

void selectionsort(int arr[], int n) 
{
    int min, temp;
    for(int i = 0; i < n - 1; i++) 
    {   
        min = i;
        for(int j = i + 1; j < n; j++) 
        {
            if(arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        printf("\nSorting process: ");
        display(arr, n);
    }
    
}

int main() 
{
    int arr[15], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    display(arr, n);

    selectionsort(arr, n);

    printf("\nSorted array: ");
    display(arr, n);

    return 0;
}