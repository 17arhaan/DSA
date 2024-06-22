#include<stdio.h>
int main()
{
    int var;
    int *ptr = &var;
    *ptr = 100;
    printf("%d\n",var);
}
