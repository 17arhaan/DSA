#include <stdio.h>
#include <stdlib.h>
struct Heap {
    int *arr;
    int cid;
    int size;
};
struct Heap *heap;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minheapify(int idx) {
    int s = idx;
    int ls = 2 * idx + 1;
    int rs = 2 * idx + 2;
    if (ls < heap->cid && heap->arr[ls] < heap->arr[s]) {
        s = ls;
    }
    if (rs < heap->cid && heap->arr[rs] < heap->arr[s]) {
        s = rs;
    }
    if (s != idx) {
        swap(&heap->arr[s], &heap->arr[idx]);
        minheapify(s);
    }
}
void Initialise(int *arr, int size) {
    heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->size = size;
    heap->arr = (int *)malloc(size * sizeof(int));
    heap->cid = size;
    for (int i = 0; i < size; i++) {
        heap->arr[i] = arr[i];
    }
    for (int i = (size - 1) / 2; i >= 0; i--) {
        minheapify(i);
    }
}
int extractRoot() {
    if (heap->cid <= 0) {
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->cid];
    minheapify(0);
    return root;
}
void heapSort(int *arr, int size) {
    Initialise(arr, size);
    printf("Sorted Array in Ascending Order: ");
    while (heap->cid > 0) {
        printf("%d ", extractRoot());
    }
    printf("\n");
}
int main() {
    int size;
    printf("Input Total Number of Elements: ");
    scanf("%d", &size);
    int *elements = (int *)malloc(size * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &elements[i]);
    }
    heapSort(elements, size);
    return 0;
}