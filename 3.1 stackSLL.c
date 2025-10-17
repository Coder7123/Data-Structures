#include <stdio.h>  
#include <stdlib.h>  

struct node{ 
int val;   
struct node *next;  
};  
struct node *top; 
 
void push ()  
{  
    int val;  
    struct node *new = (struct node*)malloc(sizeof(struct node));   
    if(new == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value: ");  
        scanf("%d",&val);  
        if(top==NULL)  
        {         
            new->val = val;  
            new -> next = NULL;  
            top=new;  
        }   
        else   
        {  
            new->val = val;  
            new->next = top;  
            top=new;  
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (top == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = top->val;  
        ptr = top;  
        top = top->next;  
        free(ptr);  
        printf("poped item is %d",item);  
          
    }  
}  
void display()  
{  
    int i;  
    struct node *temp=top;  
    if(temp == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("elements in the stack are \n");  
        while(temp!=NULL)  
        {  
            printf("%d\n",temp->val);  
            temp= temp->next;  
        }  
    }  
}  

void push();  
void pop();  
void display();  

  
void main ()  
{  
    int choice=0;     
    
     
    while(choice != 4)  
    {  
        
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\nEnter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting");  
                break;   
            }  
            default:  
            {  
                printf("invalid choice");  
            }   
    };  
}  
} 
