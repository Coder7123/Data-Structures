#include <stdio.h>

struct SparseMatrix {
    int row, col, value;
};

int readSparseMatrix(struct SparseMatrix matrix[], int m, int n) {
    printf("Enter the number of non-zero elements: ");
    int num;
    scanf("%d", &num);

    if (num > m * n) {
        printf("Error: Too many non-zero elements.\n");
        return 0;
    }

    printf("Enter the elements in the format (row column value):\n");
    for (int i = 0; i < num; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    return num;
}

int addSparseMatrices(struct SparseMatrix matrix1[], int num1, struct SparseMatrix matrix2[], int num2, int m, int n, struct SparseMatrix result[]) {
    int resultIndex = 0;
    int i = 0, j = 0;

    while (i < num1 && j < num2) {
        if (matrix1[i].row < matrix2[j].row) {
            result[resultIndex].row = matrix1[i].row;
            result[resultIndex].col = matrix1[i].col;
            result[resultIndex].value = matrix1[i].value;
            i++;
        } else if (matrix1[i].row > matrix2[j].row) {
            result[resultIndex].row = matrix2[j].row;
            result[resultIndex].col = matrix2[j].col;
            result[resultIndex].value = matrix2[j].value;
            j++;
        } else {
            if (matrix1[i].col < matrix2[j].col) {
                result[resultIndex].row = matrix1[i].row;
                result[resultIndex].col = matrix1[i].col;
                result[resultIndex].value = matrix1[i].value;
                i++;
            } else if (matrix1[i].col > matrix2[j].col) {
                result[resultIndex].row = matrix2[j].row;
                result[resultIndex].col = matrix2[j].col;
                result[resultIndex].value = matrix2[j].value;
                j++;
            } else {
                result[resultIndex].row = matrix1[i].row;
                result[resultIndex].col = matrix1[i].col;
                result[resultIndex].value = matrix1[i].value + matrix2[j].value;
                i++;
                j++;
            }
        }
        resultIndex++;
    }

    while (i < num1) {
        result[resultIndex].row = matrix1[i].row;
        result[resultIndex].col = matrix1[i].col;
        result[resultIndex].value = matrix1[i].value;
        i++;
        resultIndex++;
    }

    while (j < num2) {
        result[resultIndex].row = matrix2[j].row;
        result[resultIndex].col = matrix2[j].col;
        result[resultIndex].value = matrix2[j].value;
        j++;
        resultIndex++;
    }

    return resultIndex;
}

void displaySparseMatrix(struct SparseMatrix matrix[], int num,int m,int n) {
    for (int k = 1; k < num; k++) {
        printf("%d %d %d\n", matrix[k].row, matrix[k].col, matrix[k].value);
    }
    matrix[0].row=m;
    matrix[0].col=n;
    matrix[0].value=num;
}

int main() {
    struct SparseMatrix matrix1[50], matrix2[50], result[100];
    int m1, n1, m2, n2,m3,n3,num1, num2;

    printf("Enter the number of rows and columns for the first sparse matrix: ");
    scanf("%d %d", &m1, &n1);
    num1 = readSparseMatrix(matrix1, m1, n1);

    printf("Enter the number of rows and columns for the second sparse matrix: ");
    scanf("%d %d", &m2, &n2);
    num2 = readSparseMatrix(matrix2, m2, n2);

    if (m1 != m2 || n1 != n2) {
        printf("Matrix dimensions do not match. Addition not possible.\n");
    } else {
        int resultSize = addSparseMatrices(matrix1, num1, matrix2, num2, m1, n1, result);
        printf("\nResultant Sparse Matrix:\n");
        displaySparseMatrix(result, resultSize,m3,n3);
    }

    return 0;
}

