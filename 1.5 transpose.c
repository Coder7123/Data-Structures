#include <stdio.h>


void displayTranspose(int M[][3], int size) {
    printf("Triplet representation of the transpose is: \n");
    for (int i = 0; i <size+1; i++) {
        for (int j = 0; j <3; j++)
            printf(" %d ", M[i][j]);

        printf("\n");
    }
}


void transposeSparse(int A[][3],int B[][3])
{
int i,j,k,n;
B[0][0]=A[0][1];
B[0][1]=A[0][0];
B[0][2]=A[0][2];
k=1;
n=A[0][2];
for(i=0;i<A[0][1];i++)
for(j=1;j<=n;j++)

if(i==A[j][1])
{
B[k][0]=i;
B[k][1]=A[j][0];
B[k][2]=A[j][2];
k++;
}
}


void readSparseRep(int M[][3],int size) {

    printf("Enter the triplet representation of the matrix:\n");
    for (int i = 0; i <size+1; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    
}

int main() {
    int A[100][3], B[100][3], sizeA;

    printf("Enter the no of non-zero elements in matrix: ");
    scanf("%d",&sizeA);
    readSparseRep(A,sizeA);
    
    transposeSparse(A, B);

    
    displayTranspose(B, sizeA);

    return 0;
}