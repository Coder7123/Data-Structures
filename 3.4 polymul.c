#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coef, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
struct Term* insertTerm(struct Term* poly, int coef, int exp) {
    struct Term* newTerm = createTerm(coef, exp);

    // If the polynomial is empty, make the new term the head
    if (poly == NULL) {
        return newTerm;
    }

    // Traverse to the end of the polynomial and insert the new term
    struct Term* current = poly;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;

    return poly;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    // Multiply each term of poly1 with each term of poly2
    while (poly1 != NULL) {
        struct Term* currentPoly2 = poly2;
        while (currentPoly2 != NULL) {
            int coef = poly1->coefficient * currentPoly2->coefficient;
            int exp = poly1->exponent + currentPoly2->exponent;
            result = insertTerm(result, coef, exp);
            currentPoly2 = currentPoly2->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

// Function to free the memory allocated for a polynomial


int main() {
    // Create and display polynomial 1: 2x^2 + 3x + 4
    struct Term* poly1 = NULL;
    int p1,p2,c1,c2,e1,e2,i;
    printf("enter the number of terms in polynomial1: ");
    scanf("%d",&p1);
    for( i=0;i<p1;i++)
    {
        printf("enter the coefficent: ");
        scanf("%d",&c1);
        printf("enter the exponent: ");
        scanf("%d",&e1);
        poly1=insertTerm(poly1,c1,e1);
    }
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    // Create and display polynomial 2: 1x^1 + 5
    struct Term* poly2 = NULL;
    printf("enter the number of terms in polynomial2: ");
    scanf("%d",&p2);
    for(i=0;i<p2;i++)
    {
        printf("enter the coefficent: ");
        scanf("%d",&c2);
        printf("enter the exponent: ");
        scanf("%d",&e2);
        poly2=insertTerm(poly2,c2,e2);
    }
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Multiply the two polynomials and display the result
    struct Term* result = multiplyPolynomials(poly1, poly2);
    printf("Result of multiplication: ");
    displayPolynomial(result);

    
   

    return 0;
}
