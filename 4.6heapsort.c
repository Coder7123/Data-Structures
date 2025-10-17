#include <stdio.h>
void heap_sort(int arr[], int n);
void build_heap(int arr[], int n);
void heapify(int arr[], int n, int i);

int main()
{
    int i, n;
    int a[30];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", a+i);
    }

    heap_sort(a, n);

    printf("Sorted array is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

void heap_sort(int arr[], int n)
{
    int temp;
    build_heap(arr, n);
    for(int i = n-1; i>=0; i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr, i, 0);
    }
}
void build_heap(int arr[], int n)
{
    int i;
    for(i=(n/2)-1; i>=0; i--)
        heapify(arr, n, i);
}
void heapify(int arr[], int n, int i)
{
    int temp;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left<n && arr[left]>arr[largest])    
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i)
    {
        temp = arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr, n, largest);
    }
}