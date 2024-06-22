#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr[99];
    *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1; 
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Elements in the array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    // free(arr);
    return 0;
}
