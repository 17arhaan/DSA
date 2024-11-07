#include<stdio.h>
int main()
{
    int a,b;
    int *ptr,*qtr;
    printf("Enter the value of A: ");
    scanf("%d",&a);

    *ptr = a;
    *ptr = *ptr + 1;
    printf("The value of A after addition using pointers: %d",*ptr);

    printf("\nThe value of B : ");
    scanf("%d",&b);

    *qtr = b;
    float *sum = *qtr + *ptr;
    printf("\nThe sum of A and B using pointers is : %d",*sum);
}