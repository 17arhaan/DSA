#include<stdio.h>

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Split(int arr[], int left, int right) {
    int a = arr[right];
    int b = ( left - 1);
    for (int i = left ; i < right ; i++){
        if(arr[i] < a){
            b++;
            Swap(&arr[b],&arr[i]);
        }
    }
    Swap(&arr[b + 1],&arr[right]);
    return (b+1);
}

void Quicksort(int arr[], int left, int right) {
    if (left < right) {
        int sp = Split(arr, left, right);
        Quicksort(arr, left, sp - 1);
        Quicksort(arr, sp + 1, right);
    }
}

int main() {
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("Original Array -->\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Quicksort(arr, 0, size - 1);
    printf("Sorted Array -->\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
