#include<stdio.h>
int main(){
    int a,b,c;
    int *p,*q,*r;

    a=6;
    b=2;

    p=&b; \\ p = address of b
    q=p;  \\ therefore q is also = address of b

    r=&c; 
    p=&a; \\ now p = address of a

    *q=8;
    *r=*p; \\ therefore r is also = address of a
    *r=a+*q+*&c; \\ 6 8 20

    printf("%d %d %d\n",a,b,c);
    printf("%d %d %d\n",*p,*q,*r);
}