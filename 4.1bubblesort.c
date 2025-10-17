#include<stdio.h>

void display(int arr[],int n)
{
     for(int k = 0; k < n; k++) 
    {
        printf("%d ", arr[k]);
    }
}

int bubblesort(int arr[15],int n)
{   
    int flag=0,temp;
    for (int i=0;i<n,flag==0;i++)
    {   
        flag=1;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
              flag=0;
              printf("sorting process ");
              display(arr,n);
              printf("\n");
            }
        }
       
    }
} 

int main()
{
    
    int arr[15];
    int i,num;
    
    printf("enter the number of elements in the array: ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("enter the element: ");
        scanf("%d",&arr[i]);
        
    }
    printf("\n");
    bubblesort(arr,num);
    printf("SORTED ARRAY\n");
    for(i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}