#include<stdio.h>
#define MAX 99

void swap (int *x , int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionsort(int arr[MAX],int n){
    int min_pos;
    for ( int i = 0 ; i < n ; i++){
        min_pos = i;
        for ( int j = i+1 ; j < n ; j ++) {
            if ( arr[j] < arr [min_pos])
            min_pos = j;
        }
    if (arr[min_pos] != arr[i])
    swap(&arr[min_pos] , &arr[i]);
    }
}

void display(int arr[MAX] , int size){
    for ( int i = 0 ; i < size ; i++){
        printf("%d",arr[i]);
    }
}

int main(){
    int size , arr[MAX];
    printf("Enter the size of array: ");
    scanf("%d",&size);
    for ( int i = 0 ; i < size ; i++){
        printf("Enter Element { %d }: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nNormal Array ---->\n");
    display(arr,size);
    selectionsort(arr,size);
    printf("\nSorted Array ---->\n");
    display(arr,size);
}
