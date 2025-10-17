#include <stdio.h>

void merge(int a[], int lb, int mid, int ub) {
    int i, j, k;
    int b[100];
    i = lb;
    j = mid + 1;
    k = lb;
    int n = ub - lb +1; 

    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }

  
    for (int i = lb; i <= ub; i++) {
        a[i] = b[i];
    }

    printf("Sorted array:");
    for (int i = lb; i <= ub; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergesort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[100];
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}