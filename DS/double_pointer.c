#include<stdio.h>
int main(){
    int   a;
    int  *b;
    int **c; 

    a = 58;
    b = &a;
    c = &b;

    printf("%d ",a);
    printf("%d ",*b);
    printf("%d ",**c);
    
}