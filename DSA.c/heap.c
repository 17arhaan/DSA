#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void topDownHeap(int heap[], int index) {
    int value = heap[index];
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] < value) {
        heap[index] = heap[parent];
        index = parent;
        parent = (index - 1) / 2;
    }

    heap[index] = value;
}

void buildHeap(int heap[], int size) {
    for (int i = 1; i < size; i++) {
        topDownHeap(heap, i);
    }
}

void displayHeap(int heap[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int heap[MAX_SIZE];
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &heap[i]);
    }
    buildHeap(heap, size);
    displayHeap(heap, size);
    return 0;
}
