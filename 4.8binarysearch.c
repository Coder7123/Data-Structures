#include<stdio.h>
int BinarySearch(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            return BinarySearch(arr, mid + 1, right, key);
        }
        else
        {
            return BinarySearch(arr, left, mid - 1, key);
        }
    }

    return -1;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key, choice;
    do
    {
        printf("Enter the element to search: ");
        scanf("%d", &key);

        int result = BinarySearch(arr, 0, n-1, key);

        if (result != -1)
        {
            printf("Element %d found at index %d\n", key, result);
        }
        else
        {
            printf("Element %d not found in the array\n", key);
        }
        printf("Do you want to continue ? , if so enter 1 :");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("Exiting...\n");
    return 0;
}

