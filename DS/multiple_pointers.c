#include<stdio.h>
void isMulti(int *ptr,int *sum1)
{ 
    int ***rtr,**qtr;
    *ptr = **qtr;
    **qtr = ***rtr;
    *sum1 = ***rtr * 3;
}
int main(){

    int a;
    int sum2;

    printf("enter the number to multiply by 3: ");
    scanf("%d",&a);

    sum2 = a * 3;
    printf("Sum : %d",sum2);
    isMulti(&a,&sum2);
}