#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int * a, int n) {
    int i, j, temp, opcount = 0;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-i-1; j++) {
            opcount++;
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return opcount;
}

void main() {
    int n, i, j, temp, opcount, opcountBC, opcountWC;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int * arr = (int *) malloc(n * sizeof(int));
    for (i=0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d",&arr[i]);
    }

    opcount = bubbleSort(arr, n);

    printf("Sorted array is ");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nOpcount: %d ", opcount);

    // int bc[] = {1, 2, 3, 4, 5};
    // int wc[] = {5, 4, 3, 2, 1};

    // opcountBC = bubbleSort(bc, 5);
    // opcountWC = bubbleSort(wc, 5);
    // printf("\nNumber of operations for best case is %d and for worst case is %d. (For n = %d)", opcountBC, opcountWC,5);
}