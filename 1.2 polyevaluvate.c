#include<stdio.h>
#include<math.h> 
struct polynomial
{
    int coefficient;
    int exponent;

}p[10];
int readPolynomial(struct polynomial p[])
{
    int n,i;
    printf("enter the number of terms");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the coeffecient: \n");
        scanf("%d",&p[i].coefficient);
        printf("enter the exponent: \n");
        scanf("%d",&p[i].exponent);

    }
    return n;
}
void displayPolynomial(struct polynomial p[],int n)
 {
    int i;
    for(i=0;i<n;i++)
    {
     printf("%d(x^%d)+",p[i].coefficient,p[i].exponent);    
    }
    {
        if(p[n-1].exponent>0)
        {
            printf("%d(x^%d)",p[i].coefficient,p[i].exponent);

        }
        else{
            printf("%d\n",p[n-1].coefficient);
        }
    }
}

int evaluvatePolynomial(struct polynomial p[],int n,int x)
{
    int result=0;
    for(int i=0;i<n;i++)
    {
         result+=p[i].coefficient*pow(x,p[i].exponent); 

    }
    return result;
}
void main()
{
    int n,x,result;
    n=readPolynomial(p);
    printf("the polynoamial is: ");
    displayPolynomial(p,n);
    printf("enter the value of x: ");
    scanf("%d",&x);
    result=evaluvatePolynomial(p,n,x);
    printf("the result is: %d",result);
}



