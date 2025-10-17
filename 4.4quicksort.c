#include<stdio.h>

int partition(int a[], int lb, int ub, int size)
{
 int pivot, start, end, temp; 
 pivot = a[lb];
 start = lb; 
 end = ub;
 while (start < end)
 {
   while(a[start] <= pivot)
   {
     start++;

   }
  while(a[end] > pivot)
  {
  end--;
  }
   if (start < end)
   {
    temp = a[start]; 
    a[start] = a[end]; 
    a[end] = temp; 
    printArray(a, size);
   }

}
    temp = a[lb]; 
    a[lb] = a[end]; 
    a[end] = temp;
    printArray(a, size); 
    return end;
}


void quickSort(int a[], int lb, int ub, int size)
{
 if (lb < ub)
 {
    int loc = partition(a, lb, ub, size); 
    quickSort(a, lb, loc - 1, size); 
    quickSort(a, loc + 1, ub, size);
 }
}


void printArray(int a[], int size)
{
  for (int i = 0; i < size; i++)
{
    printf("%d ", a[i]);
}
printf("\n");
 
}


int main()
{
  int size;
  printf("Enter the size of the array: "); 
  scanf("%d", &size);

    int a[size];
    printf("Enter the elements of the array:\n"); for (int i = 0; i < size; i++)
    {
     scanf("%d", &a[i]);
    }


    printf("Original array: "); 
    printArray(a, size);

    printf("Sorting iterations:\n");


    quickSort(a, 0, size - 1, size);


    printf("Sorted array: "); 
    printArray(a, size);

    return 0;
}
