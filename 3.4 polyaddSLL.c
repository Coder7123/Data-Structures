#include <stdio.h>
#include <stdlib.h> 
struct node
    {   
        float coeff;
        int expo;
        struct node* next;
    };

struct node* create_node(struct node *head, float coef, int exp)
{
    struct node *ptr;
    struct node *new = malloc(sizeof(struct node));
    new->coeff = coef;
    new->expo = exp;
    new->next = NULL;
    if (head->next==NULL)
        head->next=new;
    else{
    ptr = head->next;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next = new;
    }
    
}

void read(struct node *head)
{
    int ch, e;
    float c;
    do
    {
        printf("Enter coefficient: ");
        scanf("%f", &c);
        printf("Enter exponent: ");
        scanf("%d", &e);
        create_node(head, c, e);
        printf("Do you want to continue(1-yes/0-no): ");
        scanf("%d", &ch);
        
    }while(ch==1);
}
void display(struct node *head)
{
    struct node *temp;
    temp = head->next;
    while(temp->next!=NULL)
    {
        printf("%.1fx^%d + ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("%.1fx^%d \n", temp->coeff, temp->expo);
}

void polyadd(struct node *h1, struct node *h2, struct node *h3 )
{
    struct node *temp1, *temp2;
    temp1 = h1->next;
    temp2 = h2->next;
    while(temp1!=NULL && temp2!=NULL) 
    {
        if(temp1->expo<temp2->expo)
        {
            create_node(h3, temp2->coeff, temp2->expo);
            temp2=temp2->next;
        }
            
        
        else if(temp1->expo>temp2->expo)
        {
            create_node(h3, temp1->coeff, temp1->expo);
            temp1=temp1->next;
        }
        else
        {
            create_node(h3, temp1->coeff + temp2->coeff, temp2->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
        while(temp1!=NULL)
        {
            create_node(h3, temp1->coeff, temp1->expo);
            temp1=temp1->next;

        }
         while(temp2!=NULL)
        {
            create_node(h3, temp2->coeff, temp2->expo);
            temp2=temp2->next;
        }
}
int main()
{
    struct node *h1, *h2, *h3;
    h1 = malloc(sizeof(struct node));
    h2 = malloc(sizeof(struct node));
    h3 = malloc(sizeof(struct node));
    h1->next=NULL;
    h2->next=NULL;
    h3->next=NULL;
    printf("Polynomial Addition\n");

    printf("Polynomial A\n");
    read(h1);

    printf("Polynomial B\n");
    read(h2);
    
    printf("\npolynomial 1\n");
    display(h1);
    printf("\nPolynomial 2\n");
    display(h2);

    polyadd(h1, h2, h3);
    printf("\nResultant polynomial\n");
    display(h3);
    printf("\n");
    return 0; 
}