#include<stdio.h>

void readMatrix(int r,int c, int mat[][10])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           printf("enter the element[%d %d]: ",i+1,j+1);
           scanf("%d",&mat[i][j]);
        }
    }
}

void dispalyMatrix(int r,int c, int mat[][10])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
void sparseMatrix(int r,int c, int mat[][10])
{
	int size = 0;
	int i,j;
	for (i = 0; i < r; i++)
	{    
	 for (j = 0; j < c; j++)
	 {
			if (mat[i][j] != 0)
				size++;
	 }
	}
    

	int compactMatrix[size+1][3];
	int k = 1;
	for (i = 0; i < r; i++)
	{
		for ( j = 0; j < c; j++)
		{
			if (mat[i][j]!= 0)
			{
				compactMatrix[k][0] = i;
				compactMatrix[k][1] = j;
				compactMatrix[k][2] = mat[i][j];
				k++;
			}
		}
	}
	compactMatrix[0][0] = r;
	compactMatrix[0][1] = c;
	compactMatrix[0][2] = size;



	for (int i=0; i<size+1; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%d\t", compactMatrix[i][j]);
		}
		printf("\n");
	}

}
void sparsity(int r,int c,int mat[][10])
{
    int i,j,count=0;
    
    for (i = 0; i < r; i++)
	{
		for ( j = 0; j < c; j++)
		{
			if (mat[i][j]!= 0)
            {
                count++;
            }
		}
	}
	float zeroes=(r*c)-count;
	float spar=zeroes/(r*c);
	printf("sparsity=%f",spar);
    
}
int main()
{
    int r,c,s;
    printf("enter the number of rows: ");
    scanf("%d",&r);
    printf("enter the number of coloumns: ");
    scanf("%d",&c);
    int mat[10][10];
    readMatrix(r,c, mat);
    dispalyMatrix(r,c, mat);
    printf("\n");
    sparseMatrix(r,c, mat);
    sparsity(r,c,mat);
    return 0;
    
}





