#include <stdio.h>
#include <stdlib.h>
#define MAX 99

void topdown(int heap[] , int index){
    int value = heap[index];
    int parent = ( index - 1)/2;
    while(index > 0 && heap[parent] < value){
        heap[index] = heap[parent];
        index = parent;
        parent = (index - 1) / 2;
    }
    heap [index ] = value;
}

void buildheap(int heap[] , int size){
    for(int i = 1 ; i< size ; i++){
        topdown(heap,i);
    }
}

void Display(int heap[] , int size){
    printf("Heap --->\n");
    for(int i = 0 ; i <size ; i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int main(){
    int heap[MAX];
    int size;
    printf("Enter the size of heap: ");
    scanf("%d",&size);

    printf("Enter the elements :- \n");
    for(int i = 0; i < size ; i++){
        printf("Element ~ { %d } : ",i+1);
        scanf("%d",&heap[i]);
    }

    buildheap(heap,size);
    Display(heap,size);
    return 0;
}