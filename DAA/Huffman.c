#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap *minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->array = (struct MinHeapNode**)malloc(size * sizeof(struct MinHeapNode*));
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    for (int i = size / 2 - 1; i >= 0; --i)
        percolateDown(minHeap, i);
    while (minHeap->size > 1) {
        struct MinHeapNode *left = extractMin(minHeap), *right = extractMin(minHeap);
        struct MinHeapNode *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[size], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman Codes:\n");
    HuffmanCodes(data, freq, size);
    return 0;
}
