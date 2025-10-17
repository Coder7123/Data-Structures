#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5 
int queue[maxsize] ;
int front=-1;
int rear=-1;

void enqueue()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0; 
        queue[rear] = item;  
    }  
    else   
    {  
        rear++;  
        queue[rear] = item; 
    }  
     
    printf("\nValue inserted ");  
      
}  
void dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted "); 
        printf("%d",item); 
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nelements in the queue are\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("%d\n",queue[i]);  
        }     
    }  
}  

void main ()  
{   int queue[maxsize];
    int front =-1,rear=-1;
    int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n"); 
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            break;
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  

