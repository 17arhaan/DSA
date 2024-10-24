#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Split(int array[], int l, int r) {
    int p = array[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (array[j] <= p) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);
    return (i + 1);
}
void QuickSort(int array[], int l, int r) {
    if (l < r) {
        int sp = Split(array, l, r);
        QuickSort(array, l, sp - 1);
        QuickSort(array, sp + 1, r);
    }
}
int main() {
    int a;
    printf("Input Size of Array : ");
    scanf("%d",&a);
    int arr[a];
    for(int i=0; i<a; i++){
        printf("Input Element at %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("Original Array------> \n");
    for(int i=0; i<a; i++){
        printf("%d ",arr[i]);
    }
    QuickSort(arr, 0, a-1);
    printf("\nSorted Array------> \n");
    for(int i=0; i<a; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}