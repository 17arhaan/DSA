#include<stdio.h>
int main(){
    int *ptr,**qtr;
    *ptr = NULL;
    **qtr = *ptr;
    printf("%p",**qtr);
}