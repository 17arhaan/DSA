#include<stdio.h>
int main()
{
    int *ptr;
    // int x = 5;
    // *ptr = &x;
    // printf("the value of p is: ",*ptr);

    char a;
    char b;
    printf("Addresses :- \nA : %p  \nB : %p",&a,&b);
    a = 10;
    *ptr = a;
    printf("\nValue of ptr / a : %d",*ptr);
    printf("\nAddress of ptr / a : %p",*ptr);
}
